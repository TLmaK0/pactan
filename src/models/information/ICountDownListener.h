/*
 * ICountDownListener.h
 *
 *  Created on: 27-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_INFORMATION_ICOUNTDOWNLISTENER_H_
#define MODELS_INFORMATION_ICOUNTDOWNLISTENER_H_

#include "../animation/ITimerListener.h"
namespace models{
	namespace information{
		class ICountDownListener:public models::animation::ITimerListener{
		public:
			virtual void zeroCountDownEvent()=0;
		};

	}
}

#endif /* MODELS_INFORMATION_ICOUNTDOWNLISTENER_H_ */
