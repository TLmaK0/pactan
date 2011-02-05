/*
 * IPaintListener.h
 *
 *  Created on: 05-ago-2009
 *      Author: hfreire
 */

#ifndef MVC_EVENTS_IPAINTLISTENER_H_
#define MVC_EVENTS_IPAINTLISTENER_H_

class IPaintListener{
public:
	virtual void paint()=0;
	virtual ~IPaintListener(){};
};

#endif /* MVC_EVENTS_IPAINTLISTENER_H_ */
