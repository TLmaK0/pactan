/*
 * PacTan.cpp
 *
 *  Created on: 26-jul-2009
 *      Author: hfreire
 */
#include "PacTan.h"

namespace opengl{
	log4cxx::LoggerPtr PacTan::logger(log4cxx::Logger::getLogger("opengl.PacTan"));

	PacTan::PacTan(int millisecondsStep):Agent(millisecondsStep){
		this->wavefrontObj=ManagerResources::instance()->getObject3D("resources/models3D/pactan.obj");
	}
}
