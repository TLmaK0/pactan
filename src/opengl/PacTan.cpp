/*
 * PacTan.cpp
 *
 *  Created on: 26-jul-2009
 *      Author: hfreire
 */
#include "PacTan.h"

namespace opengl{
	log4cxx::LoggerPtr PacTan::logger(log4cxx::Logger::getLogger("opengl.PacTan"));

	PacTan::PacTan(){
		this->wavefrontObj=ManagerResources::instance()->getObject3D("Models3D/pactan.obj");
	}
}
