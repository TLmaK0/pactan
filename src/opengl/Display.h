/*
 * Display.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_DISPLAY_H_
#define OPENGL_DISPLAY_H_

#include "GL/glut.h"
#include <list>
#include <iostream>

#include <log4cxx/logger.h>

#include "../mvc/events/IKeyListener.h"
#include "../mvc/events/IPaintListener.h"
#include "../mvc/events/IKeyEvent.h"
#include "../mvc/events/KeyEvent.h"

#define WINDOW_NAME "Pac-Tan"


using std::list;
using namespace std;
using namespace mvc::events;

namespace opengl{

	class Display{
		static log4cxx::LoggerPtr logger;

		list<IKeyListener*> keyListeners;
		list<IPaintListener*> paintListeners;

		bool enabled;
		Display();

		void raiseKeyEvent(IKeyEvent* keyEvent);
		void raisePaintEvent();

		void enableEvents();


		static void callBackKeyEvent(unsigned char key, int x, int y);
		static void callBackSpecialKeyEvent(int key, int x, int y);
		static void callBackPaintEvent();
		static void callBackForcePaintEvent(int value);

	public:
		static const int PAINT_EVENT_STEP=33;

		static Display* instance();
		void addKeyListener(IKeyListener* keyListener);
		void removeKeyListener(IKeyListener* keyListener);
		void addPaintListener(IPaintListener* paintListener);
		void removePaintListener(IPaintListener* paintListener);
		void enable();
	};
}

#endif


