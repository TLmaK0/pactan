#include "PacTan.h"
namespace models{
	namespace agents{
		log4cxx::LoggerPtr PacTan::logger(log4cxx::Logger::getLogger("models.agents.PacTan"));

		PacTan::PacTan(){
			this->_isSpecial=false;
			this->specialCounter=0;
		}

		void PacTan::setDirection(int x, int y){
			this->directionX=x;
			this->directionY=y;
			LOG4CXX_DEBUG(logger, "Set direction: " << x << "," << y);
		}

		bool PacTan::isSpecial(){
			return this->_isSpecial;
		}

		void PacTan::setSpecial(bool isSpecial){
			this->_isSpecial=isSpecial;
			if (isSpecial) this->specialCounter=SPECIAL_COUNTER_START;
			LOG4CXX_DEBUG(logger, "IsSpecial: " << this->_isSpecial);
		}

		void PacTan::updateState(){
			if (this->specialCounter!=0){
				this->specialCounter--;
				if (this->specialCounter==0) this->setSpecial(false);
				LOG4CXX_DEBUG(logger, "SpecialCounter: " << this->specialCounter);
			}


			Vector3D possition=this->getPossition();

			if (!forehand(possition)){
				if (!turn(+1,possition)){
					if (!turn(-1,possition)) reverse(possition);
				}
			}


		}


	}
}

