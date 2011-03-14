//============================================================================
// Name        : Pac-tan.cpp
// Author      : Hugo Freire
// Version     : 0.0.1
// Copyright   : LGPLv3
// Description : Pac-Tan
//============================================================================

#include <iostream>
#include "controllers/PlayController.h"
#include "log4cxx/logger.h"
#include <stdlib.h>
#include "sound/OggPlayer.h"
#include <boost/thread.hpp>

using namespace controllers;
using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("Main"));

void startSound(){
	OggPlayer ogg;
	ogg.open("resources/audio/soundtracks/Dragan_Espenschied_-_06_-_hrvat.ogg");
	ogg.play();
	ogg.close();
}

int main(int argc, char *argv[]) {
	//startSound();
	LOG4CXX_INFO(logger, "Init application.");
	boost::thread workerThread(startSound);




	PlayController *playController=new PlayController();


	return 0;
}
