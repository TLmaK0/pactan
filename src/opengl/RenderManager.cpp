/*
 * RenderManager.cpp
 *
 *  Created on: 24-sep-2009
 *      Author: hfreire
 */

#include "RenderManager.h"

namespace opengl {
	log4cxx::LoggerPtr RenderManager::logger(log4cxx::Logger::getLogger("opengl.RenderManager"));


	RenderManager::RenderManager() {
		// TODO Auto-generated constructor stub

	}

	RenderManager::~RenderManager() {
		// TODO Auto-generated destructor stub
	}

    void RenderManager::render(WavefrontObj* obj3D, Vector3D position, Vector3D scale, Vector3D rotationDirection){
    	Polyhedron* part;
		basics3D::Polygon* face;
		VertexData* vertexData;
		glPushMatrix ();
			glTranslated(position.x, position.y, position.z);

			glScalef( scale.x, scale.y, scale.z );

			glRotatef(rotationDirection.x,1,0,0);
			glRotatef(rotationDirection.y,0,1,0);
			glRotatef(rotationDirection.z,0,0,1);

			LOG4CXX_TRACE(logger,obj3D->elements.size()<<" parts.");
			for(map<string,Polyhedron*>::iterator polyhedron=obj3D->elements.begin(); polyhedron!=obj3D->elements.end(); polyhedron++){

				part=polyhedron->second;
				LOG4CXX_TRACE(logger,"Drawing Part "<<polyhedron->first<<". "<<part->polygons.size()
						<<" polygons.");
				for(vector<basics3D::Polygon*>::iterator polygon=part->polygons.begin(); polygon!=part->polygons.end();polygon++){
					face=(*polygon);

					glColor3f(face->material->diffuseReflectivity.x, face->material->diffuseReflectivity.y, face->material->diffuseReflectivity.z);

					LOG4CXX_TRACE(logger,"Drawing Polygon " << face->vertexs.size() << " vertices");
					glBegin(GL_POLYGON);
						for(vector<VertexData*>::iterator vertex=face->vertexs.begin();vertex!=face->vertexs.end(); vertex++){
							vertexData=(*vertex);
							LOG4CXX_TRACE(logger,"v "<<vertexData->geometric->x<<" "<<vertexData->geometric->y<<" "<<vertexData->geometric->z);
							LOG4CXX_TRACE(logger,"n "<<vertexData->normal->x<<" "<<vertexData->normal->y<<" "<<vertexData->normal->z);
							glNormal3d(vertexData->normal->x,vertexData->normal->y,vertexData->normal->z);
							glVertex3d((*vertex)->geometric->x,(*vertex)->geometric->y,(*vertex)->geometric->z);
						}
					glEnd();
				}
			}

		glPopMatrix();
    }

	RenderManager* RenderManager::instance(){
		static RenderManager instance;
		return &instance;
	}

}
