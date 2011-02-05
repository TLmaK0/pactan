/*
 * View.cpp
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */
#include "View.h"

using namespace std;

using namespace mvc::events;
using namespace opengl;

namespace views{
	View::View(PlayController* controller, list<IBasicModelObject*>* model){

		Display::instance()->addKeyListener(this);
		Display::instance()->addPaintListener(this);

		this->controller=controller;
		this->model=model;
	}

	void View::keyPressed(IKeyEvent* keyEvent){
		cout << "key char: " << keyEvent->getKeyChar();
		cout << "key code: " << keyEvent->getKeyCode();
		cout << "key type: " << keyEvent->getType();
	}

	View::~View(){
		Display::instance()->removeKeyListener(this);
	}

	void View::paint(){
		this->render();
	}

}
