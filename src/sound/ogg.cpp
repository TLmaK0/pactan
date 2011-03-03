//http://www.devmaster.net/articles/openal-tutorials/lesson8.php

#include "ogg.h"

using namespace log4cxx;

LoggerPtr logger2(Logger::getLogger("ogg_stream"));


void ogg_stream::open(string path)
{
    int result;

    if(!(oggFile = fopen(path.c_str(), "rb")))
        throw string("Could not open Ogg file.");

    if((result = ov_open(oggFile, &oggStream, NULL, 0)) < 0)
    {
        fclose(oggFile);

        throw string("Could not open Ogg stream. ") + errorString(result);
    }

    vorbisInfo = ov_info(&oggStream, -1);
    vorbisComment = ov_comment(&oggStream, -1);

    if(vorbisInfo->channels == 1)
        format = AL_FORMAT_MONO16;
    else
        format = AL_FORMAT_STEREO16;


    alGenBuffers(BUFFERS, buffers);
    check();
    alGenSources(1, &source);
    check();

    alSource3f(source, AL_POSITION,        0.0, 0.0, 0.0);
    alSource3f(source, AL_VELOCITY,        0.0, 0.0, 0.0);
    alSource3f(source, AL_DIRECTION,       0.0, 0.0, 0.0);
    alSourcef (source, AL_ROLLOFF_FACTOR,  0.0          );
    alSourcei (source, AL_SOURCE_RELATIVE, AL_TRUE      );
}




void ogg_stream::release()
{
    alSourceStop(source);
    empty();
    alDeleteSources(1, &source);
    check();
    alDeleteBuffers(1, buffers);
    check();

    ov_clear(&oggStream);
}




void ogg_stream::display()
{
    cout
        << "version         " << vorbisInfo->version         << "\n"
        << "channels        " << vorbisInfo->channels        << "\n"
        << "rate (hz)       " << vorbisInfo->rate            << "\n"
        << "bitrate upper   " << vorbisInfo->bitrate_upper   << "\n"
        << "bitrate nominal " << vorbisInfo->bitrate_nominal << "\n"
        << "bitrate lower   " << vorbisInfo->bitrate_lower   << "\n"
        << "bitrate window  " << vorbisInfo->bitrate_window  << "\n"
        << "\n"
        << "vendor " << vorbisComment->vendor << "\n";

    for(int i = 0; i < vorbisComment->comments; i++)
        cout << "   " << vorbisComment->user_comments[i] << "\n";

    cout << endl;
}




bool ogg_stream::playback()
{
    if(playing())
        return true;

    for(int n=0;n<BUFFERS;n++){
    	if(!stream(buffers[n]))
    	        return false;
    }

    alSourceQueueBuffers(source, BUFFERS, buffers);
    alSourcePlay(source);

    return true;
}




bool ogg_stream::playing()
{
	LOG4CXX_TRACE(logger2, "playing ogg");

    ALenum state;

    alGetSourcei(source, AL_SOURCE_STATE, &state);

    return (state == AL_PLAYING);
}




bool ogg_stream::update()
{
	LOG4CXX_TRACE(logger2, "update ogg");

	int processed;
    bool active = true;

    alGetSourcei(source, AL_BUFFERS_PROCESSED, &processed);

    while(processed--)
    {
    	LOG4CXX_TRACE(logger2, processed);

        ALuint buffer;

        alSourceUnqueueBuffers(source, 1, &buffer);
        check();

        active = stream(buffer);

        alSourceQueueBuffers(source, 1, &buffer);
        check();

    }

    return active;
}




bool ogg_stream::stream(ALuint buffer)
{
    char pcm[BUFFER_SIZE];
    int  size = 0;
    int  section;
    int  result;

    while(size < BUFFER_SIZE)
    {
        result = ov_read(&oggStream, pcm + size, BUFFER_SIZE - size, 0, 2, 1, &section);

        if(result > 0)
            size += result;
        else
            if(result < 0)
                throw errorString(result);
            else
                break;
    }

    if(size == 0)
        return false;

    alBufferData(buffer, format, pcm, size, vorbisInfo->rate);
    check();

    return true;
}




void ogg_stream::empty()
{
    int queued;

    alGetSourcei(source, AL_BUFFERS_QUEUED, &queued);

    while(queued--)
    {
        ALuint buffer;

        alSourceUnqueueBuffers(source, 1, &buffer);
        check();
    }
}




void ogg_stream::check()
{
	int error = alGetError();

	switch(error)
	    {
	        case AL_NO_ERROR:
	        break;

	        case AL_INVALID_NAME:
	        	throw string("AL_INVALID_NAME");
	        break;

	        case AL_INVALID_ENUM:
	        	throw string("AL_INVALID_ENUM");
	        break;

	        case AL_INVALID_VALUE:
	        	throw string("AL_INVALID_VALUE");
	        break;

	        case AL_INVALID_OPERATION:
	        	throw string("AL_INVALID_OPERATION");
	        break;

	        case AL_OUT_OF_MEMORY:
	        	throw string("AL_OUT_OF_MEMORY");
	        break;
	    };

}



string ogg_stream::errorString(int code)
{
    switch(code)
    {
        case OV_EREAD:
            return string("Read from media.");
        case OV_ENOTVORBIS:
            return string("Not Vorbis data.");
        case OV_EVERSION:
            return string("Vorbis version mismatch.");
        case OV_EBADHEADER:
            return string("Invalid Vorbis header.");
        case OV_EFAULT:
            return string("Internal logic fault (bug or heap/stack corruption.");
        default:
            return string("Unknown Ogg error.");
    }
}
