/*
 * Common.cpp
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#include "Vector3D.h"

namespace basics3D{
	Vector3D::Vector3D(){
		this->x=0;
		this->y=0;
		this->z=0;
	}

	Vector3D::Vector3D(double x, double y, double z){
		this->x=x;
		this->y=y;
		this->z=z;
	}

	bool Vector3D::operator==(Vector3D vector){
		return this->x==vector.x
			&& this->y==vector.y
			&& this->z==vector.z;
	}

	bool Vector3D::operator!=(Vector3D vector){
		return !(this->operator ==(vector));
	}
}
