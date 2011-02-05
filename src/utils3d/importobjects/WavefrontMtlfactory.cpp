/*
 * WavefrontMtlfactory.cpp
 *
 *  Created on: 22-sep-2009
 *      Author: hfreire
 */

#include "WavefrontMtlfactory.h"

namespace utils3d {

	namespace importobjects {
		log4cxx::LoggerPtr WavefrontMtlfactory::logger(log4cxx::Logger::getLogger("utils3d.importobjects.WavefrontMtlfactory"));

		WavefrontMtlfactory* WavefrontMtlfactory::instance(){
			static WavefrontMtlfactory instance;
			return &instance;
		}

		WavefrontMtlfactory::WavefrontMtlfactory() {
			// TODO Auto-generated constructor stub

		}

		WavefrontMtlfactory::~WavefrontMtlfactory() {
			// TODO Auto-generated destructor stub
		}

		void* WavefrontMtlfactory::getResource(string path){
			WavefrontMtl* wavefrontMtl=new WavefrontMtl();

			this->parseFile(path,wavefrontMtl);

			return wavefrontMtl;
		}

		void WavefrontMtlfactory::parseLine(string line, void* obj3D){
			if (line.find("newmtl ")==0) newMaterial(line, (WavefrontMtl*)obj3D);
			else if(line.find("illum ")==0){
				setMaterialIluminationModel(line, (WavefrontMtl*)obj3D);
			}else if (line.find("Kd ")==0){
				setMaterialDiffuseReflectivity(line,(WavefrontMtl*)obj3D);
			}else if (line.find("Ka ")==0){
				setMaterialAmbientReflectivity(line,(WavefrontMtl*)obj3D);
			}else if (line.find("Tf ")==0){
				setMaterialTransmissionFilter(line,(WavefrontMtl*)obj3D);
			}else if (line.find("Ni ")==0){
				setMaterialOpticalDensity(line,(WavefrontMtl*)obj3D);
			}
			else {
				LOG4CXX_WARN(logger,"Keyword not implemented: "<<line);
			}
		}

		void WavefrontMtlfactory::newMaterial(string line, WavefrontMtl* obj3D){
			string materialName=line.substr(7,line.size()-7);
			obj3D->actualMaterial=new Material();
			obj3D->materials[materialName]=obj3D->actualMaterial;
			LOG4CXX_TRACE(logger,"New material: " << materialName);
		}

		void WavefrontMtlfactory::setMaterialIluminationModel(string line, WavefrontMtl* obj3D){
			string ilumination=line.substr(6,line.size()-6);
			obj3D->actualMaterial->illuminationModel=atoi(ilumination.c_str());
			LOG4CXX_DEBUG(logger,"Ilumination Model: " << obj3D->actualMaterial->illuminationModel);
		}

		void WavefrontMtlfactory::setMaterialDiffuseReflectivity(string line, WavefrontMtl* obj3D){
			readVector3D(line.substr(3,line.size()-3),&(obj3D->actualMaterial->diffuseReflectivity));
			LOG4CXX_DEBUG(logger,"Diffuse Reflectivity: " << obj3D->actualMaterial->diffuseReflectivity.x << " " << obj3D->actualMaterial->diffuseReflectivity.y << " " << obj3D->actualMaterial->diffuseReflectivity.z);
		}

		void WavefrontMtlfactory::setMaterialAmbientReflectivity(string line, WavefrontMtl* obj3D){
			readVector3D(line.substr(3,line.size()-3),&(obj3D->actualMaterial->ambientReflectivity));
			LOG4CXX_DEBUG(logger,"Ambient Reflectivity: " << obj3D->actualMaterial->ambientReflectivity.x << " " << obj3D->actualMaterial->ambientReflectivity.y << " " << obj3D->actualMaterial->ambientReflectivity.z);
		}

		void WavefrontMtlfactory::setMaterialTransmissionFilter(string line, WavefrontMtl* obj3D){
			readVector3D(line.substr(3,line.size()-3),&(obj3D->actualMaterial->transmissionFilter));
			LOG4CXX_DEBUG(logger,"Transmission Filter: " << obj3D->actualMaterial->transmissionFilter.x << " " << obj3D->actualMaterial->transmissionFilter.y << " " << obj3D->actualMaterial->transmissionFilter.z);
		}

		void WavefrontMtlfactory::setMaterialOpticalDensity(string line, WavefrontMtl* obj3D){
			obj3D->actualMaterial->opticalDensity=atof(line.substr(3,line.size()-3).c_str());
			LOG4CXX_DEBUG(logger,"Optical Density: " << obj3D->actualMaterial->opticalDensity);
		}

		void WavefrontMtlfactory::readVector3D(string vectorString, Vector3D* vector){
			string value;
			istringstream iss(vectorString, istringstream::in);

			iss >> value;
			vector->x=atof(value.c_str());

			iss >> value;
			vector->y=atof(value.c_str());

			iss >> value;
			vector->z=atof(value.c_str());
		}

	}
}
