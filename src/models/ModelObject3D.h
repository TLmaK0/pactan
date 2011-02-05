/*
 * ModelObject3D.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_MODELOBJECT3D_H_
#define MODELS_MODELOBJECT3D_H_


#include "../basics3D/Vector3D.h"
#include "../models/IModelObject.h"
#include "log4cxx/logger.h"

using namespace basics3D;

namespace models{
	class ModelObject3D:public IModelObject{
		static log4cxx::LoggerPtr logger;
	protected:
		Vector3D _position;
	public:
		void setPosition(Vector3D possition);
		Vector3D getPossition();
	};
}

#endif
