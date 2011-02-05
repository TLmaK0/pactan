/*
 * Agent.cpp
 *
 *  Created on: 20-ago-2009
 *      Author: hfreire
 */
#include "Agent.h"

namespace models{
	namespace agents{
		log4cxx::LoggerPtr Agent::logger(log4cxx::Logger::getLogger("models.agents.Agent"));

		Agent::Agent(){
			//initial direction
			directionX=1;
			directionY=0;
		}

		void Agent::setPlayGround(PlayGround* playGround){
			this->playGround=playGround;
		}

		bool Agent::moveAgent(double x, double y){
			bool result=false;
			PlayGround::MapBlockType blockType=this->playGround->getBlockTypeAtPossition(x,y);
			//LOG4CXX_DEBUG(logger,blockType);
			if (blockType!=models::scene::PlayGround::WALL){
				this->lastPossition=this->_position;

				Vector3D position=this->_position;
				position.x=x;
				position.y=y;
				this->setPosition(position);
				LOG4CXX_TRACE(logger, "Pos: " << this->_position.x << "," << this->_position.y);
				result=true;
			}else{
				LOG4CXX_TRACE(logger, "can't move");
			}
			return result;
		}

		bool Agent::turn(int n,Vector3D position){
			bool result;
			int x,y;

			if (this->directionX==0){
				x=n;
				y=0;
			}else{
				x=0;
				y=n;
			}
			position.x+=x;
			position.y+=y;
			result=this->moveAgent(position.x,position.y);
			if (result){
				LOG4CXX_TRACE(logger,"turn "<<n);

				directionX=x;
				directionY=y;
			}
			return result;
		}

		bool Agent::reverse(Vector3D possition){
			bool result;
			int x=this->directionX*-1,y=this->directionY*-1;

			result=this->moveAgent(possition.x+x,possition.y+y);
			if (result){
				LOG4CXX_TRACE(logger,"reverse");
				directionX=x;
				directionY=y;
			}
			return result;
		}

		bool Agent::forehand(Vector3D possition){
			bool result;
			result=this->moveAgent(possition.x+this->directionX,possition.y+this->directionY);
			if (result) LOG4CXX_TRACE(logger,"forehand");
			return result;
		}

		Vector3D Agent::getLastPossition(){
			return this->lastPossition;
		}

		Vector3D Agent::getDirectionAngle(){
			Vector3D directionAngle;
			if (this->directionX>0){
				directionAngle.z=90;
			}else if (this->directionX<0){
				directionAngle.z=270;
			}else if (this->directionY>0){
				directionAngle.z=180;
			}else{
				directionAngle.z=0;
			}
			return directionAngle;
		}
	}
}
