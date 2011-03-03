/*
 * Display.cpp
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */
#include "Display.h"

using namespace std;
using namespace mvc::events;

namespace opengl{

	log4cxx::LoggerPtr Display::logger(log4cxx::Logger::getLogger("opengl.Display"));

	Display::Display(){
		this->enabled=false;

		int SCREEN_WIDTH=600;
		int SCREEN_HEIGHT=400;

		int   argc   = 0;
		char *argv[] = {};
		glutInit(&argc,argv);

		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

		glutCreateWindow(WINDOW_NAME);

		glClearColor( 0, 0, 0, 0 );

		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();

		gluPerspective(30.0f,(GLfloat)SCREEN_WIDTH/(GLfloat)SCREEN_HEIGHT,0.1f,5000.0f);

		gluLookAt(0, -2300, 2000,
				0, 0, 0,
				0, 1, 0);

		glEnable(GL_DEPTH_TEST);


		glEnable(GL_CULL_FACE);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);

		enableEvents();

	}

	void Display::enableEvents(){
		glutKeyboardFunc(callBackKeyEvent);
		glutSpecialFunc(callBackSpecialKeyEvent);
		glutDisplayFunc(callBackPaintEvent);
		glutTimerFunc(Display::PAINT_EVENT_STEP, callBackForcePaintEvent, Display::PAINT_EVENT_STEP);
	}

	void Display::callBackForcePaintEvent(int value){
		instance()->raisePaintEvent();
		glutTimerFunc(value, callBackForcePaintEvent, value);
	}

	void Display::callBackSpecialKeyEvent(int key, int x, int y){
		IKeyEvent::SpecialKeys keyCode;
		switch(key){
			case GLUT_KEY_F1:
				keyCode=IKeyEvent::KEY_F1;
				break;
			case GLUT_KEY_F2:
				keyCode=IKeyEvent::KEY_F2;
				break;
			case GLUT_KEY_F3:
				keyCode=IKeyEvent::KEY_F3;
				break;
			case GLUT_KEY_F4:
				keyCode=IKeyEvent::KEY_F4;
				break;
			case GLUT_KEY_F5:
				keyCode=IKeyEvent::KEY_F5;
				break;
			case GLUT_KEY_F6:
				keyCode=IKeyEvent::KEY_F6;
				break;
			case GLUT_KEY_F7:
				keyCode=IKeyEvent::KEY_F7;
				break;
			case GLUT_KEY_F8:
				keyCode=IKeyEvent::KEY_F8;
				break;
			case GLUT_KEY_F9:
				keyCode=IKeyEvent::KEY_F9;
				break;
			case GLUT_KEY_F10:
				keyCode=IKeyEvent::KEY_F10;
				break;
			case GLUT_KEY_F11:
				keyCode=IKeyEvent::KEY_F11;
				break;
			case GLUT_KEY_F12:
				keyCode=IKeyEvent::KEY_F12;
				break;
			case GLUT_KEY_LEFT:
				keyCode=IKeyEvent::KEY_LEFT;
				break;
			case GLUT_KEY_UP:
				keyCode=IKeyEvent::KEY_UP;
				break;
			case GLUT_KEY_RIGHT:
				keyCode=IKeyEvent::KEY_RIGHT;
				break;
			case GLUT_KEY_DOWN:
				keyCode=IKeyEvent::KEY_DOWN;
				break;
			case GLUT_KEY_PAGE_UP:
				keyCode=IKeyEvent::KEY_UP;
				break;
			case GLUT_KEY_PAGE_DOWN:
				keyCode=IKeyEvent::KEY_PAGE_DOWN;
				break;
			case GLUT_KEY_HOME:
				keyCode=IKeyEvent::KEY_HOME;
				break;
			case GLUT_KEY_END:
				keyCode=IKeyEvent::KEY_END;
				break;
			case GLUT_KEY_INSERT:
				keyCode=IKeyEvent::KEY_INSERT;
				break;
		}

		instance()->raiseKeyEvent(new KeyEvent(IKeyEvent::SPECIAL,0,keyCode));
	}

	void Display::callBackKeyEvent(unsigned char key, int x, int y){
		instance()->raiseKeyEvent(new KeyEvent(IKeyEvent::KEY,key,0));
	}

	void Display::callBackPaintEvent(){
		instance()->raisePaintEvent();
	}

	void Display::raisePaintEvent(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (list<IPaintListener*>::iterator paintListener=paintListeners.begin(); paintListener!=paintListeners.end();paintListener++){
			(*paintListener)->paint();
			if ((list<IPaintListener*>::iterator)paintListener._M_node->_M_prev->_M_next!=paintListener){
				paintListener--;
			}
		}

		glutSwapBuffers();
	}

	void Display::raiseKeyEvent(IKeyEvent* keyEvent){
		for (list<IKeyListener*>::iterator keyListener=keyListeners.begin(); keyListener!=keyListeners.end(); keyListener++){
			(*keyListener)->keyPressed(keyEvent);
		}
	}


	Display* Display::instance(){
		static Display instance;
		return &instance;
	}

	void Display::enable(){
		//TODO: double lock check for thread safe
		if (!enabled){
			enabled=true;
			glutMainLoop();
		}
	}

	void Display::addKeyListener(IKeyListener* keyListener){
		this->keyListeners.push_back(keyListener);
	}

	void Display::removeKeyListener(IKeyListener* keyListener){
		this->keyListeners.remove(keyListener);
	}

	void Display::addPaintListener(IPaintListener* paintListener){
		this->paintListeners.push_back(paintListener);
	}

	void Display::removePaintListener(IPaintListener* paintListener){
		this->paintListeners.remove(paintListener);
	}

}


