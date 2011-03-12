/*
 * Timer.h
 *
 *  Created on: 17-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_ANIMATION_TIMER_H_
#define MODELS_ANIMATION_TIMER_H_

#include <list>
#include <log4cxx/logger.h>

#include "ITimerListener.h"

//TODO: Implement timer without opengl.Display and IPaintListener...
#include "../../opengl/Display.h"
#include "../../mvc/events/IPaintListener.h"
#include <boost/thread.hpp>

using std::list;

namespace models{
	namespace animation{
		class Timer{
			static log4cxx::LoggerPtr logger;

			list<ITimerListener*> timerListeners;
		protected:
			virtual void timerEvent();
		public:
			boost::thread* timerThread;
			int milliseconds_sleep;

			Timer(int milliseconds);
			void addTimerListener(ITimerListener* timerListener);
			void removeTimerListener(ITimerListener* timerListener);
			void loop(Timer* timer);
		};
	}
}

#endif /* MODELS_ANIMATION_TIMER_H_ */
