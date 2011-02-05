/*
 * PacTan.h
 *
 *  Created on: 02-ago-2009
 *      Author: hfreire
 */


#ifndef MODELS_AGENTS_PACTAN_H_
#define MODELS_AGENTS_PACTAN_H_

#include <log4cxx/logger.h>

#include "../../models/agents/Agent.h"

namespace models{
	namespace agents{
		class PacTan:public Agent{
			static const int SPECIAL_COUNTER_START=30;

			static log4cxx::LoggerPtr logger;

			int lastMovX,lastMovY;
			bool _isSpecial;
			int specialCounter;
		public:
			PacTan();
			bool isSpecial();
			void setSpecial(bool isSpecial);
			int getClassId();
			void setDirection(int x, int y);
			void updateState();
		};
	}
}
#endif

