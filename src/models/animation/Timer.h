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

using std::list;
using namespace models::animation;

class Timer:public IPaintListener{
	static log4cxx::LoggerPtr logger;

	list<ITimerListener*> timerListeners;
	int timerStep;
	int timerStepCounter;
protected:
	virtual void timerEvent();
public:
	Timer();
	void stop();
	void start();
	void paint();
	void setStepTime(int milliseconds);
	void addTimerListener(ITimerListener* timerListener);
	void removeTimerListener(ITimerListener* timerListener);
};


#endif /* MODELS_ANIMATION_TIMER_H_ */
