/*
 * Polygon.h
 *
 *  Created on: 19-sep-2009
 *      Author: hfreire
 */

#ifndef BASICS3D_POLYGON_H_
#define BASICS3D_POLYGON_H_

#include <vector>
#include "VertexData.h"
#include "Material.h"

using namespace std;

namespace basics3D {

class Polygon {
public:
	vector<VertexData*> vertexs;
	Material* material;
	Polygon();
	virtual ~Polygon();
};

}

#endif /* BASICS3D_POLYGON_H_ */
