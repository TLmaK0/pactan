/*
 * PlayGround.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_SCENE_PLAYGROUND_H_
#define MODELS_SCENE_PLAYGROUND_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <log4cxx/logger.h>

#include "../../models/ModelObject3D.h"
#include "../../basics3D/Vector3D.h"

using std::vector;
using namespace std;
using namespace basics3D;

namespace models{
	namespace scene{
		class PlayGround:public ModelObject3D{
			static log4cxx::LoggerPtr logger;

		public:
			typedef enum {
				POINT,
				WALL,
				SPACE,
				SPECIAL
			} MapBlockType;

			int totalPoints, width, height, top, left;

			PlayGround();
			void loadMap(string mapName);
			int getClassId();
			MapBlockType getBlockTypeAtPossition(int x, int y);
			void eatPointAtPossition(int x, int y);
			Vector3D getCocosHome();
			Vector3D getPacTanHome();

		private:
			vector< vector<MapBlockType> > map;
			Vector3D cocosHome;
			Vector3D pactanHome;

			void coordToMapPossition(int* x,int* y);
			void mapPossitionToCoord(int* x,int* y);
		};

	}
}

#endif
