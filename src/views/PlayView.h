/*
 * PlayView.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef VIEWS_PLAYVIEW_H_
#define VIEWS_PLAYVIEW_H_


#include <iostream>
#include <list>

#include "../opengl/scene/PlayGround.h"
#include "../opengl/agents/Coco.h"
#include "../opengl/PacTan.h"

#include "../models/IModelObject.h"
#include "../models/ModelObject3D.h"
#include "../models/agents/PacTan.h"
#include "../models/scene/PlayGround.h"

#include "View.h"
#include "../mvc/model/IBasicModelObject.h"
#include "../mvc/events/IKeyEvent.h"

using std::vector;

using namespace std;

using namespace models;

using namespace opengl::scene;
using namespace opengl;
using namespace views;

using namespace controllers;

using namespace opengl::agents;

namespace views{
	class PlayView: public View{
		static log4cxx::LoggerPtr logger;
	public:
		PacTan pactan;
		vector<Coco*> cocos;
		opengl::scene::PlayGround playGround;

		PlayView(PlayController* controller, list<IBasicModelObject*>* model);
		void render();
		void keyPressed(IKeyEvent* keyEvent);
	};
}
#endif

