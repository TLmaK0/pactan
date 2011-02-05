/*
 * FileReader.h
 *
 *  Created on: 22-sep-2009
 *      Author: hfreire
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <string>
#include <fstream>
#include <log4cxx/logger.h>

using namespace std;

namespace io{
namespace files {

	class FileReader {
		static log4cxx::LoggerPtr logger;

	protected:
		virtual void parseLine(string line, void* resultObj)=0;
	public:
		void parseFile(string path, void* resultObj);
	};
}
}


#endif /* FILEREADER_H_ */
