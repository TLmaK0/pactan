/*
 * CountDown.cpp
 *
 *  Created on: 22-ago-2009
 *      Author: hfreire
 */

#include "CountDown.h"
namespace models{
	namespace information{
		log4cxx::LoggerPtr CountDown::logger(log4cxx::Logger::getLogger("models.information.CountDown"));

		CountDown::CountDown(){
			this->timer.addTimerListener(this);
		}

		void CountDown::setStartCounter(int startCounter){
			this->counter=startCounter;
			this->timer.setStepTime(1000);
		}

		void CountDown::timeEvent(){
			this->counter--;
			LOG4CXX_TRACE(logger,"CountDown: " << this->counter);
			if (this->counter==0) {
				LOG4CXX_DEBUG(logger, "CountDown stop");
				this->zeroCountDownEvent();
				this->stop();
			}
		}

		void CountDown::zeroCountDownEvent(){
			for (list<ICountDownListener*>::iterator countDownListener=this->countDownListeners.begin(); countDownListener!=this->countDownListeners.end(); countDownListener++){
				(*countDownListener)->zeroCountDownEvent();
			}
		}

		void CountDown::addCountDownListener(ICountDownListener* countDownListener){
			this->countDownListeners.push_back(countDownListener);
		}

		void CountDown::removeCountDownListener(ICountDownListener* countDownListener){
			this->countDownListeners.remove(countDownListener);
		}

		void CountDown::start(){
			this->timer.start();
		}

		void CountDown::stop(){
			this->timer.stop();
		}

	}
}
