/*
 * Polyhedron.h
 *
 *  Created on: 19-sep-2009
 *      Author: hfreire
 */

#ifndef BASICS3D_POLYHEDRON_H_
#define BASICS3D_POLYHEDRON_H_

#include <vector>
#include "../basics3D/Polygon.h"

using namespace std;

namespace basics3D {

class Polyhedron {
public:
	vector<Polygon*> polygons;
	Polyhedron();
	virtual ~Polyhedron();
};

}

#endif /* BASICS3D_POLYHEDRON_H_ */
