/*
 * InformationView.h
 *
 *  Created on: 25-ago-2009
 *      Author: hfreire
 */

#ifndef VIEWS_INFORMATIONVIEW_H_
#define VIEWS_INFORMATIONVIEW_H_

#include <list>

#include "View.h"
#include "../mvc/model/IBasicModelObject.h"
#include "../mvc/events/IKeyEvent.h"

#include "../models/IModelObject.h"
#include "../models/ModelObject3D.h"
#include "../controllers/PlayController.h"

#include "../opengl/information/CountDown.h"
#include "../opengl/information/Score.h"

namespace views{
	class InformationView: public View{
		static log4cxx::LoggerPtr logger;
	public:
		opengl::information::CountDown countDown;
		opengl::information::Score score;
		InformationView(PlayController* controller, list<IBasicModelObject*>* model);
		void render();
	};
}
#endif /* VIEWS_INFORMATIONVIEW_H_ */
