/*
 * 3DObject.cpp
 *
 *  Created on: 01-ago-2009
 *      Author: hfreire
 */
#include "Object3D.h"

using namespace basics3D;

namespace opengl{
	void Object3D::setPosition(Vector3D position){
		this->_position=position;
	}

	void Object3D::setDirection(Vector3D direction){
		this->_rotationDirection=direction;
	}
}
