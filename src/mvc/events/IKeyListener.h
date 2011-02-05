/*
 * IKeyListener.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */
#ifndef MVC_EVENTS_IKEYLISTENER_H_
#define MVC_EVENTS_IKEYLISTENER_H_

#include "IKeyEvent.h"

namespace mvc{
	namespace events{

		class IKeyListener{
		public:
			virtual void IKeyListener::keyPressed(IKeyEvent* keyEvent)=0;
		};
	}
}

#endif
