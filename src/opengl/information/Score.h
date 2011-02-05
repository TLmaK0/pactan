/*
 * Score.h
 *
 *  Created on: 27-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_INFORMATION_SCORE_H_
#define OPENGL_INFORMATION_SCORE_H_

#include <GL/glut.h>

#include "../Object3D.h"
#include "../../models/information/Score.h"

#include "../fonts/FontManager.h"

namespace opengl{
	namespace information{
		class Score:public opengl::Object3D{
		public:
			unsigned int score;
			virtual void draw();
		};
	}
}

#endif /* OPENGL_INFORMATION_SCORE_H_ */
