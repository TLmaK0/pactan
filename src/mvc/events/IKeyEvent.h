/*
 * IKeyEvent.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */
#ifndef MVC_EVENTS_IKEYEVENT_H_
#define MVC_EVENTS_IKEYEVENT_H_


namespace mvc{
	namespace events{


		class IKeyEvent{
		public:
			enum Types{
						KEY,
						SPECIAL
					};

			enum SpecialKeys{
						KEY_F1,
						KEY_F2,
						KEY_F3,
						KEY_F4,
						KEY_F5,
						KEY_F6,
						KEY_F7,
						KEY_F8,
						KEY_F9,
						KEY_F10,
						KEY_F11,
						KEY_F12,
						KEY_LEFT,
						KEY_UP,
						KEY_RIGHT,
						KEY_DOWN,
						KEY_PAGE_UP,
						KEY_PAGE_DOWN,
						KEY_HOME,
						KEY_END,
						KEY_INSERT
					};
			virtual Types getType()=0;
			virtual char getKeyChar()=0;
			virtual int getKeyCode()=0;
		};
	}
}

#endif
