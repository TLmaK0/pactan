/*
 * IImportObjectsFactory.h
 *
 *  Created on: 20-sep-2009
 *      Author: hfreire
 */

#ifndef UTILS3D_IMPORTOBJECTS_IIMPORTOBJECTSFACTORY_H_
#define UTILS3D_IMPORTOBJECTS_IIMPORTOBJECTSFACTORY_H_

namespace utils3d {

namespace importobjects {

class IImportObjectsFactory {
public:
	virtual void* getResource(string path)=0;
};

}

}

#endif /* UTILS3D_IMPORTOBJECTS_IIMPORTOBJECTSFACTORY_H_ */
