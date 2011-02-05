//============================================================================
// Name        : Pac-tan.cpp
// Author      : Hugo Freire
// Version     :
// Copyright   : GPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "controllers/PlayController.h"
#include "log4cxx/logger.h"

using namespace controllers;
using namespace log4cxx;

LoggerPtr logger(Logger::getLogger("Main"));

int main(int argc, char *argv[]) {

	LOG4CXX_INFO(logger, "Init application.");


	PlayController *playController=new PlayController();
	playController->Start();



	return 0;
}
