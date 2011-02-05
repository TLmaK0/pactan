/*
 * WavefrontMtlfactory.h
 *
 *  Created on: 22-sep-2009
 *      Author: hfreire
 */

#ifndef UTILS3D_IMPORTOBJECTS_WAVEFRONTMTLFACTORY_H_
#define UTILS3D_IMPORTOBJECTS_WAVEFRONTMTLFACTORY_H_

#include <string>
#include <log4cxx/logger.h>

#include "WavefrontMtl.h"
#include "IImportObjectsFactory.h"
#include "../../io/files/FileReader.h"

using namespace io::files;

namespace utils3d {

namespace importobjects {

class WavefrontMtlfactory:public FileReader,public IImportObjectsFactory {
	static log4cxx::LoggerPtr logger;
	WavefrontMtlfactory();

	void newMaterial(string line, WavefrontMtl* obj3D);

	void setMaterialIluminationModel(string line, WavefrontMtl* obj3D);

	void setMaterialDiffuseReflectivity(string line, WavefrontMtl* obj3D);
	void setMaterialAmbientReflectivity(string line, WavefrontMtl* obj3D);
	void setMaterialTransmissionFilter(string line, WavefrontMtl* obj3D);
	void setMaterialOpticalDensity(string line, WavefrontMtl* obj3D);

	void readVector3D(string vectorString, Vector3D* vector);

public:

    virtual ~WavefrontMtlfactory();

    static WavefrontMtlfactory* instance();

    virtual void* getResource(string path);
    virtual void parseLine(string line, void* obj3D);
};

}

}


#endif /* UTILS3D_IMPORTOBJECTS_WAVEFRONTMTLFACTORY_H_ */
