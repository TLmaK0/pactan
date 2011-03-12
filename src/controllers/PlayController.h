/*
 * PlayController.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef CONTROLLERS_PLAYCONTROLLER_H_
#define CONTROLLERS_PLAYCONTROLLER_H_

#include <list>
#include <string>
#include <log4cxx/logger.h>

#include "../mvc/view/IView.h"
#include "../mvc/controller/IController.h"

#include "../models/agents/PacTan.h"
#include "../models/agents/Coco.h"
#include "../models/scene/PlayGround.h"
#include "../models/animation/ITimerListener.h"
#include "../models/animation/Timer.h"
#include "../models/IModelObject.h"
#include "../basics3D/Vector3D.h"
#include "../models/information/CountDown.h"
#include "../models/information/Score.h"
#include "../models/information/ICountDownListener.h"

using namespace models::information;

using namespace mvc::controller;

using namespace mvc::view;

using namespace models::animation;

namespace controllers{
	class PlayController:public IController, public ICountDownListener{
		static const int STEPS_BEFORE_ADD_COCO=3;

		static log4cxx::LoggerPtr logger;


		Timer* timer;

		int addCocoStep;
		int cocoToStart;
		int specialCounter;

		unsigned int actualLevel;

		models::agents::PacTan* pacTan;
		models::scene::PlayGround* playGround;
		models::information::CountDown countDown;
		models::information::Score score;

		unsigned int maxCocos;
		list<models::agents::Coco*> cocos;
		list<IBasicModelObject*> playModel;
		list<IBasicModelObject*> informationModel;

		IView* playGroundView;
		IView* informationView;

		void updateStatePacTan();
		void loadCocos(vector<IBasicModelObject*>* model);
		void eatPoint(int x, int y);
		void MovePacTan(int x, int y);
		void endLevel();
		void updateStateCocos();
		void generateCocos();
		models::agents::Coco* getNewCoco();
		void checkCollisions();
		void collisionPacTanCoco(models::agents::PacTan* pacTan, models::agents::Coco* coco);
		void pacTanDead();
		void eatCoco(models::agents::Coco* coco);
		void updateViews();

	public:
		PlayController();
		void Start();
		void MovePacTanUp();
		void MovePacTanDown();
		void MovePacTanLeft();
		void MovePacTanRight();
		void timeEvent();
		void zeroCountDownEvent();
		void nextLevel();
	};
}
#endif

