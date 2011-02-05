/*
 * FontManager.h
 *
 *  Created on: 26-ago-2009
 *      Author: hfreire
 */

#ifndef OPENGL_FONTMANAGER_H_
#define OPENGL_FONTMANAGER_H_

#include <map>
#include <string>
#include <FTGL/ftgl.h>
#include <log4cxx/logger.h>


using namespace std;

typedef map<string, FTFont*> FontList;
typedef FontList::const_iterator FontIter;

namespace opengl{
	namespace fonts{
		class FontManager{
		public:
			enum FontType{
				RASTER_BITMAP,
				RASTER_PIXMAP,
				VECTOR_POLYGON,
				VECTOR_OUTLINE,
				VECTOR_EXTRUDED,
				TEXTURE_TEXTURED,
				TEXTURE_BUFFER
			};

			static FontManager* instance();
			~FontManager();
			FTFont* getFont(const char *filename, int size, opengl::fonts::FontManager::FontType fontType);
		private:

			static log4cxx::LoggerPtr logger;

			FontList fonts;

			FontManager();
			FTFont* getFontType(opengl::fonts::FontManager::FontType fontType, const char* filenamePath);
		};
	}
}

#endif /* OPENGL_FONTMANAGER_H_ */
