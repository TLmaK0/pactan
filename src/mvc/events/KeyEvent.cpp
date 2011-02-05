/*
 * KeyEvent.cpp
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */
#include "KeyEvent.h"
namespace mvc{
	namespace events{
		KeyEvent::KeyEvent(Types type, char keyChar, int keyCode){
			this->type=type;
			this->keyChar=keyChar;
			this->keyCode=keyCode;
		}

		IKeyEvent::Types KeyEvent::getType(){
			return this->type;
		}

		char KeyEvent::getKeyChar(){
			return this->keyChar;
		}

		int KeyEvent::getKeyCode(){
			return this->keyCode;
		}
	}
}
