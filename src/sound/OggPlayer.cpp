#include "OggPlayer.h"
#include <boost/thread.hpp>

	void OggPlayer::open(string path){
		int   argc   = 0;
		char *argv[] = {};
		alutInit(&argc,argv);
		ogg.open(path);
	}

	void OggPlayer::play(){
		if(!ogg.playback())
			throw string("Ogg refused to play.");

		while(ogg.update())
		{
			if(!ogg.playing())
			{
				if(!ogg.playback())
					throw string("Ogg abruptly stopped.");
				else
					cout << "Ogg stream was interrupted.\n";
			}
			boost::this_thread::sleep(boost::posix_time::milliseconds(BUFFER_UPDATE_SLEEP_MILLISECONDS));
		}
	}
	void OggPlayer::close(){
		ogg.release();
		alutSleep(1);
		alutExit();
	}
