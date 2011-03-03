/*
 * OggPlayer.h
 *
 *  Created on: 19-feb-2011
 *      Author: hfreire
 */

#ifndef SOUND_OGGPLAYER_H_
#define SOUND_OGGPLAYER_H_

#include <AL/alut.h>
#include "ogg.h"

#define BUFFER_UPDATE_SLEEP_MILLISECONDS 1000

class OggPlayer {
	ogg_stream ogg;
public:
	void open(string path);
	void play();
	void close();
};

#endif /* SOUND_OGGPLAYER_H_ */
