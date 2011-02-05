/*
 * ITimerListener.h
 *
 *  Created on: 17-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_ANIMATION_ITIMERLISTENER_H_
#define MODELS_ANIMATION_ITIMERLISTENER_H_

namespace models{
	namespace animation{
		class ITimerListener{
		public:
			virtual void timeEvent()=0;
			virtual ~ITimerListener(){};
		};
	}
}

#endif /* MODELS_ANIMATION_ITIMERLISTENER_H_ */
