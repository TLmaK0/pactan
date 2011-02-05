/*
 * View.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef VIEWS_VIEW_H_
#define VIEWS_VIEW_H_

#include <iostream>
#include <list>

#include "../opengl/Display.h"
#include "../mvc/view/IView.h"
#include "../mvc/events/IKeyListener.h"
#include "../mvc/events/IPaintListener.h"
#include "../mvc/model/IBasicModelObject.h"
#include "../controllers/PlayController.h"

using namespace std;

using namespace mvc::events;
using namespace mvc::view;
using namespace controllers;

using namespace opengl;

namespace views{
	class View:public IView,public IKeyListener,public IPaintListener{
	protected:
		IController* controller;
		list<IBasicModelObject*>* model;
	public:
		View(PlayController* controller, list<IBasicModelObject*>* model);
		virtual ~View();
		void keyPressed(IKeyEvent* keyEvent);
		void paint();
	};
}

#endif

