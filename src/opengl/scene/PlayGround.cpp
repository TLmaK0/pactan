/*
 * PlayGround.cpp
 *
 *  Created on: 27-jul-2009
 *      Author: hfreire
 */
#include "PlayGround.h"
namespace opengl{
	namespace scene{
		log4cxx::LoggerPtr PlayGround::logger(log4cxx::Logger::getLogger("opengl.scene.PlayGround"));

		PlayGround::PlayGround(){
			this->playGroundLoaded=false;
		}

		void PlayGround::setPlayGroundModel(models::scene::PlayGround* playGroundModel){
			this->playGroundModel=playGroundModel;
			this->playGroundLoaded=true;
		}

		void PlayGround::draw(){
			if (this->playGroundLoaded){
				glPushMatrix ();
					glTranslated(this->_position.x + (this->playGroundModel->left * GAME_SQUARE_SIDE), this->_position.y + (this->playGroundModel->top * GAME_SQUARE_SIDE), this->_position.z);
					for(int column=this->playGroundModel->left;column < this->playGroundModel->left + this->playGroundModel->width ;column++){
						glPushMatrix ();
							for(int row=this->playGroundModel->top;row > this->playGroundModel->top - this->playGroundModel->height;row--){
								drawMapElement(this->playGroundModel->getBlockTypeAtPossition(column,row));
								glTranslated(0,-GAME_SQUARE_SIDE,0);
							}
						glPopMatrix();
						glTranslated(GAME_SQUARE_SIDE,0,0);
					}
				glPopMatrix();
			}
		}


		void PlayGround::drawMapElement(models::scene::PlayGround::MapBlockType typeElement){
			switch(typeElement){
			case models::scene::PlayGround::POINT:
				drawPoint();
				break;
			case models::scene::PlayGround::SPECIAL:
				drawSpecial();
				break;
			case models::scene::PlayGround::WALL:
				drawWall();
				break;
			default:
				break;
			}
		}

		void PlayGround::drawWall(){
			LOG4CXX_TRACE(logger,"Drawing wall");
			WavefrontObj* obj3D=ManagerResources::instance()->getObject3D("resources/models3D/wall.obj");

			RenderManager::instance()->render(obj3D,Vector3D(0,0,0), Vector3D(GAME_SQUARE_SIDE,GAME_SQUARE_SIDE,GAME_SQUARE_SIDE),Vector3D(0,0,0));
		}

		void PlayGround::drawSpecial(){
			glColor3f(1.0f,1.0f,0.0f);
			glPushMatrix();
				glTranslated(0.0f,0.0f,20.0f);
				glutSolidSphere(30,8,8);
			glPopMatrix();
		}

		void PlayGround::drawPoint(){
			glColor3f(1.0f,1.0f,0.0f);
			glPushMatrix();
				glTranslated(0.0f,0.0f,20.0f);
				glutSolidSphere(10,8,8);
			glPopMatrix();
		}
	}
}
