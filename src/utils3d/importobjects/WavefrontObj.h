/*
 * WavefrontObj.h
 *
 *  Created on: 15-sep-2009
 *      Author: hfreire
 */

#ifndef UTILS3D_IMPORTOBJECTS_WAVEFRONTOBJ_H_
#define UTILS3D_IMPORTOBJECTS_WAVEFRONTOBJ_H_

#include <vector>
#include <map>
#include "../../basics3D/Vector3D.h"
#include "../../basics3D/VertexData.h"
#include "../../basics3D/Polyhedron.h"
#include "WavefrontMtl.h"

using namespace basics3D;
using namespace std;

namespace utils3d{
	namespace importobjects{
		class WavefrontObj{
		public:
			Polyhedron* actualElement;
			vector<Vector3D*> geometricVertices;
			vector<Vector3D*> textureVertices;
			vector<Vector3D*> vertexNormals;
			vector<Vector3D*> parameterSpaceVertices;
			map<string,Polyhedron*> elements;
			WavefrontMtl* mtl;
			string path;
		};
	}
}
#endif /* UTILS3D_IMPORTOBJECTS_WAVEFRONTOBJ_H_ */
