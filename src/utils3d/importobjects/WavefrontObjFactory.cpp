/*
 * WavefrontObjFactory.cpp
 *
 *  Created on: 20-sep-2009
 *      Author: hfreire
 */

#include "WavefrontObjFactory.h"
#include "../ManagerResources.h"

namespace utils3d {

namespace importobjects {

log4cxx::LoggerPtr WavefrontObjFactory::logger(log4cxx::Logger::getLogger("utils3d.importobjects.WavefrontObjFactory"));


WavefrontObjFactory* WavefrontObjFactory::instance(){
		static WavefrontObjFactory instance;
		return &instance;
}

WavefrontObjFactory::WavefrontObjFactory() {
	// TODO Auto-generated constructor stub

}

WavefrontObjFactory::~WavefrontObjFactory() {
	// TODO Auto-generated destructor stub
}

void* WavefrontObjFactory::getResource(string path){
	WavefrontObj* wavefrontObj=new WavefrontObj();

	//retrieve the folder part of the path
	size_t endFolderPos=path.find_last_of("/\\");
	wavefrontObj->path=endFolderPos!=string::npos?path.substr(0,endFolderPos+1):"";

	this->parseFile(path,wavefrontObj);

	return wavefrontObj;
}

	void WavefrontObjFactory::parseLine(string line, void* obj3D){


		LOG4CXX_TRACE(logger,"Processing: "<<line);

		if (line.find("mtllib ")==0) processMaterialData(line, (WavefrontObj*)obj3D, ((WavefrontObj*)obj3D)->path);
		else if (line.find("usemtl ")==0) setMaterialUsed(line,(WavefrontObj*)obj3D);
		else{
			switch(line[0]){
			case 'v':
				processVertexData(line, (WavefrontObj*)obj3D);
				break;
			case 'f':
				processFaceData(line, (WavefrontObj*)obj3D);
				break;
			case 'g':
				processGroupData(line, (WavefrontObj*)obj3D);
				break;
			default:
				LOG4CXX_WARN(logger,"Keyword ("<<line[0]<<") not implemented ("<<line<<")");
			}
		}
	}

	void WavefrontObjFactory::setMaterialUsed(string line, WavefrontObj* obj3D){
		string materialName=line.substr(7,line.size()-7);
		obj3D->mtl->actualMaterial=obj3D->mtl->materials[materialName];
	}

	void WavefrontObjFactory::processMaterialData(string line, WavefrontObj* obj3D, string relativePath){
		string mtlFile=relativePath.append(line.substr(7,line.size()-7));
		LOG4CXX_INFO(logger,"Reading file: "<<mtlFile);
		obj3D->mtl=ManagerResources::instance()->getMaterials(mtlFile);
	}

	void WavefrontObjFactory::processVertexData(string line, WavefrontObj* obj3D){
		Vector3D* vector;
		switch(line[1]){
		case ' ':
			vector=this->parseStringVector(line.substr(2,line.size()-2));
			obj3D->geometricVertices.push_back(vector);
			LOG4CXX_TRACE(logger,"Loaded geometric Vertices "<<obj3D->geometricVertices.size()<<" "<<vector->x<<" "<<vector->y<<" "<<vector->z);

			break;
		case 't':
			vector=this->parseStringVector(line.substr(3,line.size()-3));
			obj3D->textureVertices.push_back(vector);
			break;
		case 'n':
			vector=this->parseStringVector(line.substr(3,line.size()-3));
			obj3D->vertexNormals.push_back(vector);
			break;
		case 'p':
			Vector3D* vector=this->parseStringVector(line.substr(3,line.size()-3));
			obj3D->parameterSpaceVertices.push_back(vector);
			break;
		default:
			LOG4CXX_WARN(logger,"Keyword ("<<line[0]<<line[1]<<") not implemented");
		}
	}

	void WavefrontObjFactory::processFaceData(string line, WavefrontObj* obj3D){
		std::istringstream stm;
		int size, initVectorFaceData=0;

		basics3D::Polygon* face=new Polygon();
		face->material=obj3D->mtl->actualMaterial;

		string faceVectorsString=line.substr(2,line.size()-2);
		string vertexString;
		size=faceVectorsString.size();

		for(int n=0;n<=size;n++){
			if (faceVectorsString[n]==' '||n==size) {
				vertexString=faceVectorsString.substr(initVectorFaceData,n-initVectorFaceData);
				LOG4CXX_TRACE(logger,"Vertex "<<vertexString);
				face->vertexs.push_back(getVertexFace(vertexString, &(obj3D->geometricVertices), &(obj3D->textureVertices), &(obj3D->vertexNormals)));
				initVectorFaceData=n;
			}
		}
		obj3D->actualElement->polygons.push_back(face);
	}

	void WavefrontObjFactory::processGroupData(string line, WavefrontObj* obj3D){
		string groupName=line.substr(2,line.size()-2);
		if (obj3D->elements.count(groupName)==0){
			obj3D->actualElement=new Polyhedron();
			obj3D->elements[groupName]=obj3D->actualElement;
		}else{
			obj3D->actualElement=obj3D->elements[groupName];
		}
	}


	VertexData* WavefrontObjFactory::getVertexFace(string vectorString, vector<Vector3D*>* geometricVertices, vector<Vector3D*>* textureVertices, vector<Vector3D*>* vertexNormals){
		VertexData* faceVertex=new VertexData();
		int size=vectorString.size();
		int vectorNumber=0;
		int referencedVector;
		int initReference=0;
		string referenceVectorString;
		for(int n=0;n<=size;n++){
			if (vectorString[n]=='/'||n==size){
				//if reference don't contain data, skip
				if((n-initReference)>0){
					referenceVectorString=vectorString.substr(initReference,n-initReference).c_str();
					LOG4CXX_TRACE(logger,"Reference to string "<<referenceVectorString);
					referencedVector=atoi(referenceVectorString.c_str())-1;
					LOG4CXX_TRACE(logger,"Reference to "<<referencedVector);
					switch(vectorNumber){
					case 0:
						faceVertex->geometric=(*geometricVertices)[referencedVector];
						break;
					case 1:
						faceVertex->texture=(*textureVertices)[referencedVector];
						break;
					case 2:
						faceVertex->normal=(*vertexNormals)[referencedVector];
						break;
					}
					LOG4CXX_TRACE(logger,faceVertex->geometric->x<<" "<<faceVertex->geometric->y<<" "<<faceVertex->geometric->z);
					vectorNumber++;
				}
				initReference=n+1;
			}
		}

		return faceVertex;
	}


	Vector3D* WavefrontObjFactory::parseStringVector(string strVector){
		std::istringstream stm;
		double x=0,y=0,z=0;
		int hasSign,oldHasSign;
		string value;

		hasSign = strVector.substr(0,1)=="-"?1:0;
		stm.str(strVector.substr(0,9+hasSign));
		stm >>x;


		if (strVector.length()>(9+hasSign)){
			oldHasSign=hasSign;
			hasSign += strVector.substr(9+hasSign,1)=="-"?1:0;
			stm.str(strVector.substr(9+oldHasSign,17+hasSign));

			stm >>y;

		}


		if (strVector.length()>(18+hasSign)){
			oldHasSign=hasSign;
			hasSign += strVector.substr(18+hasSign,1)=="-"?1:0;
			stm.str(strVector.substr(18+oldHasSign,27+hasSign));

			stm >>z;
		}

		LOG4CXX_TRACE(logger,strVector<<"#"<<x<<"#"<<y<<"#"<<z<<"#");


		return new Vector3D(x,y,z);
	}


}

}
