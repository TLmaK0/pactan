/*
 * RenderManager.h
 *
 *  Created on: 24-sep-2009
 *      Author: hfreire
 */

#ifndef OPENGL_RENDERMANAGER_H_
#define OPENGL_RENDERMANAGER_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <log4cxx/logger.h>

#include "../utils3d/importobjects/WavefrontObj.h"


using namespace utils3d::importobjects;

namespace opengl {

class RenderManager {
	static log4cxx::LoggerPtr logger;

	RenderManager();
public:
	static RenderManager* instance();
    virtual ~RenderManager();
    void render(WavefrontObj* obj3D, Vector3D position, Vector3D scale, Vector3D rotationDirection);
};

}


#endif /* OPENGL_RENDERMANAGER_H_ */
