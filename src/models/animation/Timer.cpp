/*
 * Timer.cpp
 *
 *  Created on: 17-ago-2009
 *      Author: hfreire
 */

#include "Timer.h"

log4cxx::LoggerPtr Timer::logger(log4cxx::Logger::getLogger("models.animation.Timer"));


//TODO: Implement timer without opengl.Display and IPaintListener...
void Timer::paint(){
	LOG4CXX_TRACE(logger,"Paint "<<timerStep<<","<<timerStepCounter);
	if (this->timerStep!=0){
		this->timerStepCounter++;
		if (this->timerStep==this->timerStepCounter){
			this->timerEvent();
			timerStepCounter=0;
		}
	}
}

Timer::Timer(){
	timerStep=0;
	timerStepCounter=0;
}

void Timer::timerEvent(){
	LOG4CXX_TRACE(logger,"timerEvent: " << this);
	for (list<ITimerListener*>::iterator timerListener=this->timerListeners.begin(); timerListener!=this->timerListeners.end(); timerListener++){
		(*timerListener)->timeEvent();
	}
}

void Timer::start(){
	opengl::Display::instance()->addPaintListener(this);
}

void Timer::stop(){
	opengl::Display::instance()->removePaintListener(this);
}

void Timer::setStepTime(int milliseconds){
	timerStep=div(milliseconds,opengl::Display::PAINT_EVENT_STEP).quot;
	LOG4CXX_TRACE(logger,"setStepTime to "<<timerStep);
}

void Timer::addTimerListener(ITimerListener* timerListener){
	LOG4CXX_DEBUG(logger,"Add time listener " << timerListener);
	this->timerListeners.push_back(timerListener);
}

void Timer::removeTimerListener(ITimerListener* timerListener){
	LOG4CXX_DEBUG(logger,"Remove time listener " << timerListener);
	this->timerListeners.remove(timerListener);
}
