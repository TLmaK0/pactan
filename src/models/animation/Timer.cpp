/*
 * Timer.cpp
 *
 *  Created on: 17-ago-2009
 *      Author: hfreire
 */

#include "Timer.h"

namespace models{
	namespace animation{

		log4cxx::LoggerPtr Timer::logger(log4cxx::Logger::getLogger("models.animation.Timer"));



		Timer::Timer(int milliseconds){
			milliseconds_sleep = milliseconds;
			timerThread = new boost::thread(&Timer::loop, this, this);
		}

		void Timer::timerEvent(){
			LOG4CXX_TRACE(logger,"timerEvent: " << this);
			for (list<ITimerListener*>::iterator timerListener=this->timerListeners.begin(); timerListener!=this->timerListeners.end(); timerListener++){
				(*timerListener)->timeEvent();
			}
		}

		void Timer::addTimerListener(ITimerListener* timerListener){
			LOG4CXX_DEBUG(logger,"Add time listener " << timerListener);
			this->timerListeners.push_back(timerListener);
		}

		void Timer::removeTimerListener(ITimerListener* timerListener){
			LOG4CXX_DEBUG(logger,"Remove time listener " << timerListener);
			this->timerListeners.remove(timerListener);
		}

		void Timer::loop(Timer* timer){
			while(timer != NULL){
				boost::this_thread::sleep(boost::posix_time::milliseconds(timer->milliseconds_sleep));
LOG4CXX_DEBUG(logger,"listener loop: " << timer);

				timer->timerEvent();
			}
		}
	}
}
