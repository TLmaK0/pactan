/*
 * CountDown.h
 *
 *  Created on: 24-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_INFORMATION_COUNTDOWN_H_
#define OPENGL_INFORMATION_COUNTDOWN_H_

#include <stdio.h>
#include <log4cxx/logger.h>
#include <FTGL/ftgl.h>

#include "../Object3D.h"
#include "../constants.h"

#include "../../models/information/CountDown.h"

#include "../fonts/FontManager.h"

namespace opengl{
	namespace information{
		class CountDown:public opengl::Object3D{
			static log4cxx::LoggerPtr logger;
			models::information::CountDown* countDownModel;
		public:
			unsigned int counter;
			virtual void draw();
		};
	}
}

#endif /* OPENGL_INFORMATION_COUNTDOWN_H_ */
