/*
 * Agent.cpp
 *
 *  Created on: 20-oct-2009
 *      Author: hfreire
 */

#include "Agent.h"


namespace opengl{
	namespace agents{
		log4cxx::LoggerPtr Agent::logger(log4cxx::Logger::getLogger("opengl.agents.Agent"));

		Agent::Agent(int millisecondsStep){
			this->fpsAnimation=25;
			this->_visible=true;
			this->clockDivider=this->fpsAnimation/CLOCKS_PER_SEC;
			this->stepLength=GAME_SQUARE_SIDE * (1000 / millisecondsStep)/this->fpsAnimation;
		}

		void Agent::draw(){
			if (_visible){
				double frame = (clock() - _changePositionTime) * clockDivider;

				int direction_x;
				int direction_y;

				if (_rotationDirection.z == 0){
					direction_x = 0;
					direction_y = -1;
				}else if (_rotationDirection.z == 90){
					direction_x = +1;
					direction_y = 0;
				}else if (_rotationDirection.z == 180){
					direction_x = 0;
					direction_y = +1;
				}else if (_rotationDirection.z == 270){
					direction_x = -1;
					direction_y = 0;
				}

				double framePos = stepLength * frame;
				double x = _lastPosition.x * GAME_SQUARE_SIDE + (framePos * direction_x);
				double y = _lastPosition.y * GAME_SQUARE_SIDE + (framePos * direction_y);
				double z = _lastPosition.z;

				RenderManager::instance()->render(
						this->wavefrontObj,
						Vector3D(x, y, z),
						Vector3D(GAME_SQUARE_SIDE,GAME_SQUARE_SIDE,GAME_SQUARE_SIDE),
						this->_rotationDirection
					);
			}
		}

		void Agent::setPosition(Vector3D position){
			_changePositionTime = clock();
			_lastPosition = _position;
			Object3D::setPosition(position);
		}

		bool Agent::isVisible(){
			return this->_visible;
		}

		void Agent::setVisible(bool visible){
			this->_visible = visible;
		}

		Agent::~Agent() {
		    // TODO Auto-generated destructor stub
		}
	}

}



