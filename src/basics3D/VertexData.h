/*
 * VertexData.h
 *
 *  Created on: 19-sep-2009
 *      Author: hfreire
 */

#ifndef BASICS3D_VERTEXDATA_H_
#define BASICS3D_VERTEXDATA_H_

#include "Vector3D.h"

namespace basics3D {

class VertexData {
public:
	Vector3D* geometric;
	Vector3D* texture;
	Vector3D* normal;
	VertexData();
	virtual ~VertexData();
};

}

#endif /* BASICS3D_VERTEXDATA_H_ */
