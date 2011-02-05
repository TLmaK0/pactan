/*
 * FileReader.cpp
 *
 *  Created on: 22-sep-2009
 *      Author: hfreire
 */

#include "FileReader.h"

namespace io{
namespace files {
	log4cxx::LoggerPtr FileReader::logger(log4cxx::Logger::getLogger("io.files.FileReader"));

	void FileReader::parseFile(string path, void* resultObj){
		ifstream resourceFile(path.c_str());

		if (resourceFile.is_open()){
			string line;
			while (! resourceFile.eof() ){
				getline(resourceFile,line);
				this->parseLine(line,resultObj);
			}
			resourceFile.close();
		}else{
			LOG4CXX_ERROR(logger,"can't open file: "<<path);
			exit(-1);
		}

	}
}
}
