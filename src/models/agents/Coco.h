/*
 * Coco.h
 *
 *  Created on: 14-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_AGENTS_COCO_H_
#define MODELS_AGENTS_COCO_H_

#include "../../Models/ModelObject3D.h"
#include "../../models/animation/IAnimatedObject.h"
#include "../../models/scene/PlayGround.h"
#include "Agent.h"

namespace models{
	namespace agents{
		class Coco:public Agent, public IAnimatedObject{
			static log4cxx::LoggerPtr logger;
			static int randomCocos;

			bool _isEdible;
		public:
			PlayGround* playGround;
			Coco();
			bool isEdible();
			void setEdible(bool isEdible);
			int getClassId();
			void updateState();
		};
	}
}

#endif /* MODELS_AGENTS_COCO_H_ */
