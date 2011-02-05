/*
 * ManagerResources3D.h
 *
 *  Created on: 15-sep-2009
 *      Author: hfreire
 */

#ifndef UTILS3D_MANAGERRESOURCES3D_H_
#define UTILS3D_MANAGERRESOURCES3D_H_

#include <string>
#include <map>
#include <log4cxx/logger.h>

#include "../utils3d/importobjects/WavefrontObj.h"
#include "../utils3d/importobjects/WavefrontMtl.h"
#include "../utils3d/importobjects/IImportObjectsFactory.h"
#include "../utils3d/importobjects/WavefrontObjFactory.h"
#include "../utils3d/importobjects/WavefrontMtlFactory.h"


using namespace std;
using namespace utils3d::importobjects;

namespace utils3d{
	class ManagerResources{
		static log4cxx::LoggerPtr logger;
		map<string, void*> resources;

		void* getResource(string path, IImportObjectsFactory* factory);
		ManagerResources();
	public:
		static ManagerResources* instance();

		WavefrontObj* getObject3D(string path);
		WavefrontMtl* getMaterials(string path);
	};
}
#endif /* UTILS3D_MANAGERRESOURCES3D_H_ */
