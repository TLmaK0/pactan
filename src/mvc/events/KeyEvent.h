/*
 * KeyEvent.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef MVC_EVENTS_KEYEVENT_H_
#define MVC_EVENTS_KEYEVENT_H_

#include "IKeyEvent.h"
#include "../../system/Object.h"

namespace mvc{
	namespace events{
		class KeyEvent:public Object,public IKeyEvent{
			Types type;
			char keyChar;
			int keyCode;
		public:
			KeyEvent::KeyEvent(Types type, char keyChar, int keyCode);

			virtual Types getType();

			virtual char getKeyChar();

			virtual int getKeyCode();
		};
	}
}

#endif

