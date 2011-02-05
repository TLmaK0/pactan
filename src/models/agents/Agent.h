/*
 * Agent.h
 *
 *  Created on: 20-ago-2009
 *      Author: hfreire
 */

#ifndef MODELS_AGENTS_AGENT_H_
#define MODELS_AGENTS_AGENT_H_

#include "../ModelObject3D.h"
#include "../scene/PlayGround.h"
#include "../../basics3D/Vector3D.h"

using namespace models::scene;
using namespace basics3D;

namespace models{
	namespace agents{
		class Agent:public ModelObject3D{
			static log4cxx::LoggerPtr logger;

			Vector3D lastPossition;
			Vector3D nextPossition;
		protected:
			//to save last movement direction
			int directionX,directionY;

			bool turn(int n, Vector3D possition);
			bool reverse(Vector3D possition);
			bool forehand(Vector3D possition);

			PlayGround* playGround;
			bool moveAgent(double x, double y);
		public:
			Agent();
			void setPlayGround(PlayGround* playGround);
			Vector3D getLastPossition();
			Vector3D getDirectionAngle();
		};
	}
}
#endif /* MODELS_AGENTS_AGENT_H_ */
