/*
 * Score.cpp
 *
 *  Created on: 27-ago-2009
 *      Author: hfreire
 */
#include "Score.h"

namespace models{
	namespace information{
		Score::Score(){
			this->score=0;
		}

		int Score::getScore(){
			return this->score;
		}

		void Score::setScore(int newScore){
			this->score=newScore;
		}

		void Score::addScore(int scoreToAdd){
			this->score+=scoreToAdd;
		}
	}
}
