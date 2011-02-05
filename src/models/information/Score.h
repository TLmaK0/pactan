/*
 * Score.h
 *
 *  Created on: 27-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_INFORMATION_SCORE_H_
#define MODELS_INFORMATION_SCORE_H_

#include "../IModelObject.h"

namespace models{
	namespace information{
		class Score:public IModelObject{
			int score;
		public:
			Score();
			int getClassId();
			int getScore();
			void setScore(int newScore);
			void addScore(int scoreToAdd);
		};
	}
}
#endif /* MODELS_INFORMATION_SCORE_H_ */
