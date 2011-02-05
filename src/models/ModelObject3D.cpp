/*
 * ModelObject3D.cpp
 *
 *  Created on: 01-ago-2009
 *      Author: hfreire
 */

#include "ModelObject3D.h"

namespace models{
	log4cxx::LoggerPtr ModelObject3D::logger(log4cxx::Logger::getLogger("models.ModelObject3D"));

	void ModelObject3D::setPosition(Vector3D possition){
		this->_position=possition;
	}

	Vector3D ModelObject3D::getPossition(){
		return this->_position;
	}
}
