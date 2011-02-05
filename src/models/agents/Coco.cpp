/*
 * Coco.cpp
 *
 *  Created on: 14-ago-2009
 *      Author: hfreire
 */
#include "Coco.h"

namespace models{
	namespace agents{
		log4cxx::LoggerPtr Coco::logger(log4cxx::Logger::getLogger("models.agents.Coco"));
		int Coco::randomCocos=4294967290;

		Coco::Coco(){
			this->_isEdible=false;
		}

		bool Coco::isEdible(){
			return this->_isEdible;
		}

		void Coco::setEdible(bool isEdible){
			this->_isEdible=isEdible;
		}


		void Coco::updateState(){
			Vector3D possition=this->getPossition();

			//use randomCocos to generate diferent sid when multiple cocos has updateState at same time
			srand((unsigned)time(0)+randomCocos++);

			int changeDirection=rand()%3;
			LOG4CXX_TRACE(logger,"init deceission");
			if (changeDirection==0){
				LOG4CXX_TRACE(logger,"ChangeDirection");
				changeDirection=rand()%10;
				if (changeDirection<3){
					LOG4CXX_TRACE(logger,"intent turn +1");
					if (!turn(+1,possition)) if (!turn(-1,possition)) if (!forehand(possition)) reverse(possition);
				}
				else if (changeDirection<7){
					LOG4CXX_TRACE(logger,"intent turn +2");
					if (!turn(-1,possition)) if (!turn(+1,possition)) if (!forehand(possition)) reverse(possition);
				}else{
					LOG4CXX_TRACE(logger,"intent reverse");
					if (!reverse(possition)) if (!turn(+1,possition)) if (!turn(-1,possition)) forehand(possition);
				}
			}else{
				LOG4CXX_TRACE(logger,"intent forehand");
				if (!forehand(possition)) if (!turn(+1,possition)) if (!turn(-1,possition)) reverse(possition);
			}
			LOG4CXX_TRACE(logger,"end decision");
		}
	}
}
