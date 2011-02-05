/*
 * Object3D.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_OBJECT3D_H_
#define OPENGL_OBJECT3D_H_

#include "../MVC/View/IViewableObject.h"
#include "../basics3D/Vector3D.h"

using namespace basics3D;

namespace opengl{
	class Object3D:public IViewableObject{
	protected:
		Vector3D _position;
		Vector3D _rotationDirection;
	public:
		void setPosition(Vector3D position);
		void setDirection(Vector3D direction);
	};
}

#endif

