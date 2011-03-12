/*
 * Coco.h
 *
 *  Created on: 14-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_AGENTS_COCO_H_
#define OPENGL_AGENTS_COCO_H_

#include "Agent.h"
#include "../../utils3d/importobjects/WavefrontObj.h"


namespace opengl{
	namespace agents{
		class Coco:public Agent{
			static log4cxx::LoggerPtr logger;
		public:
			Coco(int millisecondsStep);
		};
	}
}
#endif /* OPENGL_AGENTS_COCO_H_ */
