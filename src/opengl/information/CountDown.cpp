/*
 * CountDown.cpp
 *
 *  Created on: 24-ago-2009
 *      Author: hfreire
 */
#include "CountDown.h"



namespace opengl{
	namespace information{

		log4cxx::LoggerPtr CountDown::logger(log4cxx::Logger::getLogger("opengl.information.CountDown"));


		void CountDown::draw(){
			LOG4CXX_TRACE(logger,"Draw CountDown");
			char text[10];
			sprintf(text,"%d",this->counter);

			glPushMatrix();
				glTranslated(900,1400,0);
				glColor3ub(255,255,255);

				FTFont* font=opengl::fonts::FontManager::instance()->getFont("c:\\windows\\fonts\\arial.ttf",396,opengl::fonts::FontManager::TEXTURE_BUFFER);
				font->Render(text);

			glPopMatrix();

		}
	}
}
