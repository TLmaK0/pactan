/*
 * Material.h
 *
 *  Created on: 22-sep-2009
 *      Author: hfreire
 */

#ifndef BASICS3D_MATERIAL_H_
#define BASICS3D_MATERIAL_H_

#import "Vector3D.h"

namespace basics3D {

	class Material {
	public:
		Vector3D ambientReflectivity;
		Vector3D diffuseReflectivity;
		Vector3D transmissionFilter;
		double opticalDensity;
		int illuminationModel;
		Material();
		virtual ~Material();
	};

}


#endif /* BASICS3D_MATERIAL_H_ */
