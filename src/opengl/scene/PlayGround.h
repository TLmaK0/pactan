/*
 * PlayGround.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_SCENE_PLAYGROUND_H_
#define OPENGL_SCENE_PLAYGROUND_H_

#include <vector>
#include <log4cxx/logger.h>

#include "GL/glut.h"

#include "../Object3D.h"
#include "../constants.h"
#include "../../models/scene/PlayGround.h"
#include "../../opengl/RenderManager.h"
#include "../../utils3d/ManagerResources.h"

using namespace utils3d;
using std::vector;
using namespace models::scene;

namespace opengl{
	namespace scene{
		class PlayGround:public Object3D{
			static log4cxx::LoggerPtr logger;
			bool playGroundLoaded;

			models::scene::PlayGround* playGroundModel;

			void drawWall();
			void drawPoint();
			void drawSpecial();
			void drawMapElement(models::scene::PlayGround::MapBlockType typeElement);
		public:
			PlayGround::PlayGround();
			void draw();
			void setPlayGroundModel(models::scene::PlayGround* playGroundModel);

		};
	}
}

#endif

