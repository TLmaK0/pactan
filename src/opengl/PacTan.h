/*
 * PacTan.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_PACTAN_H_
#define OPENGL_PACTAN_H_

#include "agents/Agent.h"
#include "../utils3d/importobjects/WavefrontObj.h"


using namespace opengl::agents;

namespace opengl{

	class PacTan:public Agent{
		static log4cxx::LoggerPtr logger;
	public:
		PacTan();
	};
}
#endif
