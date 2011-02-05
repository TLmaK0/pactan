/*
 * Object.cpp
 *
 *  Created on: 05-ago-2009
 *      Author: hfreire
 */

#include "Object.h"

	bool Object::operator==(Object* object){
		return true;
	}

	bool Object::operator!=(Object* object){
		return !(this==object);
	}

