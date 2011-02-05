/*
 * ManagerResources3D.cpp
 *
 *  Created on: 15-sep-2009
 *      Author: hfreire
 */
#include "ManagerResources.h"

namespace utils3d{
	log4cxx::LoggerPtr ManagerResources::logger(log4cxx::Logger::getLogger("utils3d.ManagerResources3D"));

	ManagerResources::ManagerResources(){

	}

	ManagerResources* ManagerResources::instance(){
		static ManagerResources instance;
		return &instance;
	}

	void* ManagerResources::getResource(string path, IImportObjectsFactory* factory){
		void* result;
		if (this->resources.count(path)>0) result=this->resources[path];
		else {
			result=factory->getResource(path);
			this->resources[path]=result;
		}

		return result;
	}


	WavefrontObj* ManagerResources::getObject3D(string path){
		return (WavefrontObj*)getResource(path, WavefrontObjFactory::instance());
	}


	WavefrontMtl* ManagerResources::getMaterials(string path){
		return (WavefrontMtl*)getResource(path, WavefrontMtlfactory::instance());
	}
}
