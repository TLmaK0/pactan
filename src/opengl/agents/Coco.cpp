/*
 * Coco.cpp
 *
 *  Created on: 14-ago-2009
 *      Author: hfreire
 */
#include "Coco.h"
namespace opengl{
	namespace agents{
		log4cxx::LoggerPtr Coco::logger(log4cxx::Logger::getLogger("opengl.agents.PacTan"));

		Coco::Coco(int millisecondsStep):Agent(millisecondsStep){
			this->wavefrontObj=ManagerResources::instance()->getObject3D("resources/models3D/phantom.obj");

		}

	}
}
