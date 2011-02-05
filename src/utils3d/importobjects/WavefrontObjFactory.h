/*
 * WavefrontObjFactory.h
 *
 *  Created on: 20-sep-2009
 *      Author: hfreire
 */

#ifndef UTILS3D_IMPORTOBJECTS_WAVEFRONTOBJFACTORY_H_
#define UTILS3D_IMPORTOBJECTS_WAVEFRONTOBJFACTORY_H_

#include <fstream>
#include <log4cxx/logger.h>

#include "../../models/ModelObject3D.h"
#include "../../basics3D/VertexData.h"
#include "../../basics3D/Vector3D.h"
#include "../../basics3D/Polygon.h"
#include "../../io/files/FileReader.h"
#include "WavefrontObj.h"
#include "IImportObjectsFactory.h"


using namespace std;
using namespace io::files;


namespace utils3d {

namespace importobjects {

class WavefrontObjFactory:public FileReader,public IImportObjectsFactory {
	WavefrontObjFactory();
	void processVertexData(string line, WavefrontObj* obj3D);
	void processGroupData(string line, WavefrontObj* obj3D);
	void processFaceData(string line, WavefrontObj* obj3D);
	void processMaterialData(string line, WavefrontObj* obj3D, string relativePath);
	void setMaterialUsed(string line, WavefrontObj* obj3D);
	Vector3D* parseStringVector(string strVector);
	VertexData* getVertexFace(string vectorString, vector<Vector3D*>* geometricVertices, vector<Vector3D*>* textureVertices, vector<Vector3D*>* vertexNormals);
public:
	static log4cxx::LoggerPtr logger;
	virtual ~WavefrontObjFactory();

	static WavefrontObjFactory* instance();
	virtual void* getResource(string path);

	virtual void parseLine(string line, void* obj3D);

};

}

}

#endif /* UTILS3D_IMPORTOBJECTS_WAVEFRONTOBJFACTORY_H_ */
