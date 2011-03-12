#include "PlayController.h"
#include "../views/PlayView.h"
#include "../views/InformationView.h"


namespace controllers{

	log4cxx::LoggerPtr PlayController::logger(log4cxx::Logger::getLogger("controllers.PlayController"));

	PlayController::PlayController(){
		maxCocos=3;
		addCocoStep=0;
		actualLevel=1;

		this->playGround=new models::scene::PlayGround();
		this->pacTan=new models::agents::PacTan();

		this->countDown.addCountDownListener(this);

		nextLevel();

		this->playGroundView=new PlayView(this,&this->playModel);
		this->informationView=new InformationView(this,&this->informationModel);
	}

	models::agents::Coco* PlayController::getNewCoco(){
		models::agents::Coco* coco=new models::agents::Coco();
		Vector3D possition=this->playGround->getCocosHome();
		coco->setPosition(possition);
		coco->setPlayGround(this->playGround);
		LOG4CXX_TRACE(logger, "Set coco poss: " << possition.x << "," << possition.y);

		((PlayView*)this->playGroundView)->cocos.push_back(new opengl::agents::Coco());
		return coco;
	}

	void PlayController::Start(){
		this->timer = new Timer(500);
		this->timer->addTimerListener(this);

		Display::instance()->enable();
	}

	void PlayController::MovePacTanUp(){
		this->pacTan->setDirection(0,+1);
	}

	void PlayController::MovePacTanDown(){
		this->pacTan->setDirection(0,-1);
	}

	void PlayController::MovePacTanLeft(){
		this->pacTan->setDirection(-1,0);
	}

	void PlayController::MovePacTanRight(){
		this->pacTan->setDirection(+1,0);
	}

	void PlayController::zeroCountDownEvent(){
		LOG4CXX_INFO(logger,"End count down.");
		this->pacTanDead();
	}


	void PlayController::timeEvent(){
		LOG4CXX_TRACE(logger,"time event");

		if (this->cocos.size()<maxCocos){
			addCocoStep++;
			if (this->addCocoStep==STEPS_BEFORE_ADD_COCO){
				this->addCocoStep=0;

				//add new coco
				models::agents::Coco* coco=getNewCoco();
				this->cocos.push_back(coco);
				this->playModel.push_back(coco);
			}
		}

		updateStatePacTan();
		updateStateCocos();

		checkCollisions();
		if (this->playGround->totalPoints <= 0) endLevel();

		this->updateViews();
	}

	void PlayController::updateViews(){
		//Updating view
		((PlayView*)this->playGroundView)->pactan.setPosition(this->pacTan->getPossition());
		((PlayView*)this->playGroundView)->pactan.setDirection(this->pacTan->getDirectionAngle());

		int n=0;
		for(list<models::agents::Coco*>::iterator coco=this->cocos.begin();coco!=this->cocos.end();coco++){
			((PlayView*)this->playGroundView)->cocos[n]->setPosition((*coco)->getPossition());
			((PlayView*)this->playGroundView)->cocos[n]->setDirection((*coco)->getDirectionAngle());
			n++;
		}

		((PlayView*)this->playGroundView)->playGround.setPlayGroundModel(this->playGround);

		((InformationView*)this->informationView)->countDown.counter=this->countDown.counter;

		((InformationView*)this->informationView)->score.score=this->score.getScore();
	}

	void PlayController::checkCollisions(){
		Vector3D cocoPossition;
		Vector3D pacTanPossition=this->pacTan->getPossition();
		Vector3D pacTanLastPossition=this->pacTan->getLastPossition();
		bool collision;

		do{
			collision=false;
			for (list<models::agents::Coco*>::iterator coco=this->cocos.begin(); coco!=this->cocos.end(); coco++){
				cocoPossition=(*coco)->getPossition();
				Vector3D cocoLastPossition=(*coco)->getLastPossition();
				if (cocoLastPossition==pacTanLastPossition
						|| (cocoLastPossition==pacTanPossition && cocoPossition==pacTanLastPossition) ) {
					this->collisionPacTanCoco(this->pacTan,(*coco));
					collision=true;
					break;
				}
			}
		}while(collision);
	}

	void PlayController::collisionPacTanCoco(models::agents::PacTan* pacTan, models::agents::Coco* coco){
		if (pacTan->isSpecial() && coco->isEdible()) this->eatCoco(coco);
		else this->pacTanDead();
	}

	void PlayController::pacTanDead(){
		LOG4CXX_INFO(logger,"PacTan dead");
		exit(0);
	}

	void PlayController::eatCoco(models::agents::Coco* coco){
		this->score.addScore(10);
		this->cocos.remove(coco);
		((PlayView*)this->playGroundView)->cocos.pop_back();
		this->playModel.remove(coco);
	}

	void PlayController::nextLevel(){
		actualLevel++;

		this->cocos.clear();
		this->playModel.clear();
		this->informationModel.clear();
		this->countDown.stop();

		this->playModel.push_back(this->playGround);
		this->playModel.push_back(this->pacTan);

		this->informationModel.push_back(&this->countDown);
		this->informationModel.push_back(&this->score);

		std::stringstream mapName;
		mapName << "resources/maps/map" << actualLevel << ".ptm";

		this->playGround->loadMap(mapName.str());
		this->playGround->setPosition(*new Vector3D(0, 0, 0));

		this->pacTan->setPlayGround(this->playGround);
		this->pacTan->setPosition(this->playGround->getPacTanHome());


		this->countDown.setStartCounter(200);
		this->countDown.start();
	}

	void PlayController::updateStatePacTan(){
		Vector3D possition=this->pacTan->getPossition();
		models::scene::PlayGround::MapBlockType blockType=this->playGround->getBlockTypeAtPossition(possition.x,possition.y);
		switch(blockType){
		case models::scene::PlayGround::POINT:
			this->playGround->eatPointAtPossition(possition.x,possition.y);
			this->score.addScore(1);
			break;
		case models::scene::PlayGround::SPECIAL:
			this->playGround->eatPointAtPossition(possition.x,possition.y);
			this->pacTan->setSpecial(true);
			this->score.addScore(10);
			break;
		default:
			break;
		}

		this->pacTan->updateState();
	}

	void PlayController::updateStateCocos(){
		bool isPacTanSpecial=this->pacTan->isSpecial();
		for (list<models::agents::Coco*>::iterator coco=this->cocos.begin(); coco!=this->cocos.end(); coco++){
			(*coco)->setEdible(isPacTanSpecial);
			(*coco)->updateState();
		}
	}

	void PlayController::endLevel(){
		nextLevel();
	}
}
