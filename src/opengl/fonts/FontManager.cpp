/*
 * FountManager.cpp
 *
 *  Created on: 26-ago-2009
 *      Author: hfreire
 */

/*
 * based on
 * http://ftgl.sourceforge.net/docs/html/ftgl-tutorial.html
 */
#include "FontManager.h"

namespace opengl{
	namespace fonts{
		log4cxx::LoggerPtr FontManager::logger(log4cxx::Logger::getLogger("opengl.fonts.FontManager"));

		FontManager::FontManager(){

		}

        FontManager* FontManager::instance(){
        	static FontManager instance;
        	return &instance;
        }

        FontManager::~FontManager()
        {
            FontIter font;
            for(font = fonts.begin(); font != fonts.end(); font++)
            {
                delete (*font).second;
            }

            fonts.clear();
        }


        FTFont* FontManager::getFont(const char *filename, int size, opengl::fonts::FontManager::FontType fontType){
        	FTFont* result;
            char buf[256];
            sprintf(buf, "%i%s%i",fontType, filename, size);
            string fontKey = string(buf);

            FontIter fontIter = fonts.find(fontKey);
            if(fontIter != fonts.end()) result=fontIter->second;
            else{
            	LOG4CXX_DEBUG(logger, "Create font " << fontType << " " << filename << " size " << size);

            	result=getFontType(fontType, filename);
            	if (result->Error()){
            		LOG4CXX_ERROR(logger, "Font " << filename << " failed to open");
            		delete result;
            	}

				if(!result->FaceSize(size))
				{
					LOG4CXX_ERROR(logger, "Font " << filename << " failed to set size " << size);
					delete result;
				}

				fonts[fontKey] = result;

            }

            return result;
        }

        FTFont* FontManager::getFontType(opengl::fonts::FontManager::FontType fontType, const char* filenamePath){
        	FTFont* result;
        	switch(fontType){
        	case FontManager::RASTER_BITMAP:
        		result=new FTBitmapFont(filenamePath);
        		break;
        	case FontManager::RASTER_PIXMAP:
        		result=new FTPixmapFont(filenamePath);
        		break;
        	case FontManager::TEXTURE_TEXTURED:
        		result=new FTTextureFont(filenamePath);
        		break;
        	case FontManager::TEXTURE_BUFFER:
        		result=new FTBufferFont(filenamePath);
        		break;
        	case FontManager::VECTOR_POLYGON:
        		result=new FTPolygonFont(filenamePath);
        		break;
        	case FontManager::VECTOR_OUTLINE:
        		result=new FTOutlineFont(filenamePath);
        		break;
        	case FontManager::VECTOR_EXTRUDED:
        		result=new FTExtrudeFont(filenamePath);
        		break;
        	}
        	return result;
        }
	}
}



