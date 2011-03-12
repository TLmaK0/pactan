/*
 * Agent.h
 *
 *  Created on: 20-oct-2009
 *      Author: hfreire
 */

#ifndef OPENGL_AGENTS_AGENT_H_
#define OPENGL_AGENTS_AGENT_H_

#include <GL/glut.h>
#include <log4cxx/logger.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>

#include "../Object3D.h"
#include "../../basics3D/Vector3D.h"
#include "../../models/agents/PacTan.h"
#include "../../utils3d/ManagerResources.h"
#include "../../utils3d/importobjects/WavefrontObj.h"
#include "../../basics3D/Polyhedron.h"
#include "../../basics3D/Polygon.h"
#include "../../basics3D/VertexData.h"
#include "../../opengl/RenderManager.h"

#include "../constants.h"

using namespace utils3d;
using namespace utils3d::importobjects;
using namespace basics3D;
using namespace std;
using namespace opengl;

namespace opengl{
	namespace agents{
		class Agent:public Object3D {
			static log4cxx::LoggerPtr logger;
			bool _visible;
			double fpsAnimation, clockDivider, _changePositionTime;
			float stepLength;
			Vector3D _lastPosition;
		protected:
			WavefrontObj* wavefrontObj;
		public:
			Agent(int millisecondsStep);
			virtual ~Agent();
			void setPosition(Vector3D position);
			void setStartPosition(Vector3D position);
			void draw();
			bool isVisible();
			void setVisible(bool visible);
		};
	}
}


#endif /* OPENGL_AGENTS_AGENT_H_ */
