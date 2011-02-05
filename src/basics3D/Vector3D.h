/*
 * Vector3D.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef BASICS3D_VECTOR3D_H_
#define BASICS3D_VECTOR3D_H_

namespace basics3D{
	class Vector3D{
	public:
		double x,y,z;
		Vector3D();

		Vector3D(double x, double y, double z);

		bool operator==(Vector3D vector);
		bool operator!=(Vector3D vector);
	};
}
#endif /* BASICS3D_VECTOR3D_H_ */
