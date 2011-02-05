/*
 * Score.cpp
 *
 *  Created on: 27-ago-2009
 *      Author: hfreire
 */
#include "Score.h"

namespace opengl{
	namespace information{

		void Score::draw(){
			char text[10];
			sprintf(text,"%d",this->score);

			glPushMatrix();
				glTranslated(-1400,1400,0);
				glColor3ub(255,255,255);

				FTFont* font=opengl::fonts::FontManager::instance()->getFont("c:\\windows\\fonts\\arial.ttf",396,opengl::fonts::FontManager::TEXTURE_BUFFER);
				font->Render(text);

			glPopMatrix();
		}
	}
}
