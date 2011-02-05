/*
 * WavefrontMtl.h
 *
 *  Created on: 21-sep-2009
 *      Author: hfreire
 */

#ifndef UTILS3D_IMPORTOBJECTS_WAVEFRONTMTL_H_
#define UTILS3D_IMPORTOBJECTS_WAVEFRONTMTL_H_

#include "../../basics3d/Material.h"
#include <map>
#include <string>

using namespace std;
using namespace basics3D;

namespace utils3d {

namespace importobjects {

		class WavefrontMtl {

		public:
			Material* actualMaterial;
			map<string,Material*> materials;
		};

	}

}


#endif /* UTILS3D_IMPORTOBJECTS_WAVEFRONTMTL_H_ */
