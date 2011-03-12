/*
 * CountDown.h
 *
 *  Created on: 22-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_INFORMATION_COUNTDOWN_H_
#define MODELS_INFORMATION_COUNTDOWN_H_

#include "../animation/Timer.h"
#include "../animation/ITimerListener.h"
#include "../IModelObject.h"
#include "ICountDownListener.h"

using namespace models::animation;

namespace models{
	namespace information{
		class CountDown:public ITimerListener, public IModelObject{
			static log4cxx::LoggerPtr logger;
			models::animation::Timer* timer;
			list<ICountDownListener*> countDownListeners;
		public:
			CountDown();
			void setStartCounter(int startCounter);
			void addCountDownListener(ICountDownListener* countDownListener);
			void removeCountDownListener(ICountDownListener* countDownListener);
			void start();
			void stop();
			virtual void timeEvent();
			void zeroCountDownEvent();
			int getClassId();
			unsigned int counter;
		};
	}
}
#endif /* MODELS_INFORMATION_COUNTDOWN_H_ */
