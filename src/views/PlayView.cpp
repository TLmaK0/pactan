#include "PlayView.h"

namespace views{
	log4cxx::LoggerPtr PlayView::logger(log4cxx::Logger::getLogger("views.PlayView"));

	PlayView::PlayView(PlayController* controller, list<IBasicModelObject*>* model):View(controller,model){
	}

	void PlayView::keyPressed(IKeyEvent* keyEvent){
		if (keyEvent->getType()==IKeyEvent::SPECIAL){
			switch (keyEvent->getKeyCode()){
				case IKeyEvent::KEY_UP:
					((PlayController*)this->controller)->MovePacTanUp();
					break;
				case IKeyEvent::KEY_DOWN:
					((PlayController*)this->controller)->MovePacTanDown();
					break;
				case IKeyEvent::KEY_LEFT:
					((PlayController*)this->controller)->MovePacTanLeft();
					break;
				case IKeyEvent::KEY_RIGHT:
					((PlayController*)this->controller)->MovePacTanRight();
					break;
			}
		}
	}

	void PlayView::render(){
		this->pactan->draw();

		for(vector<Coco*>::iterator coco=this->cocos.begin();coco!=this->cocos.end();coco++){
			(*coco)->draw();
		}

		this->playGround.draw();
	}
}
