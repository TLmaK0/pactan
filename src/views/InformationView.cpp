/*
 * InformationView.cpp
 *
 *  Created on: 25-ago-2009
 *      Author: hfreire
 */

#include "InformationView.h"

namespace views{
	log4cxx::LoggerPtr InformationView::logger(log4cxx::Logger::getLogger("views.InformationView"));

	InformationView::InformationView(PlayController* controller, list<IBasicModelObject*>* model):View(controller,model){
	};

	void InformationView::render(){
		this->countDown.draw();
		this->score.draw();
	}
}
