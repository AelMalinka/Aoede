/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Source.hh"

#include <glm/gtc/type_ptr.hpp>

using namespace Entropy::Aoede::AL;
using namespace Entropy::Aoede;
using namespace std;

Source::Source()
{
	alGenSources(1, &_handle);
	CHECK_AL_ERRORS("Failed to generate source");
}

Source::~Source()
{
	alDeleteSources(1, &_handle);
	alGetError();
}

Source::Source(Source &&o)
{
	swap(_handle, o._handle);
}

const ALuint &Source::Handle() const
{
	return _handle;
}

void Source::setBuffer(const Buffer &buffer)
{
	alSourcei(_handle, AL_BUFFER, buffer.Handle());
	CHECK_AL_ERRORS("Failed to set buffer");
}

void Source::queueBuffer(const Buffer &buffer)
{
	alSourceQueueBuffers(_handle, 1, const_cast<ALuint *>(&buffer.Handle()));
	CHECK_AL_ERRORS("Failed to queue buffer");
}

void Source::unqueueBuffer(const Buffer &buffer)
{
	alSourceUnqueueBuffers(_handle, 1, const_cast<ALuint *>(&buffer.Handle()));
	CHECK_AL_ERRORS("Failed to unqueue buffer");
}

Source::State Source::getState() const
{
	ALint i;
	State ret;

	alGetSourcei(_handle, AL_SOURCE_STATE, &i);
	CHECK_AL_ERRORS("Failed to get source state");

	switch(i) {
		case AL_INITIAL:
			ret = State::Initial;
		break;
		case AL_PLAYING:
			ret = State::Playing;
		break;
		case AL_PAUSED:
			ret = State::Paused;
		break;
		case AL_STOPPED:
			ret = State::Stopped;
		break;
		default:
			ENTROPY_THROW(Exception("Invalid Enumeration in get state"));
	}

	return ret;
}

bool Source::isPlaying() const
{
	return getState() == State::Playing;
}

bool Source::isStopped() const
{
	return getState() == State::Stopped;
}

bool Source::isPaused() const
{
	return getState() == State::Paused;
}

Dimension Source::Pitch() const
{
	Dimension ret;
	alGetSourcef(_handle, AL_PITCH, &ret);
	CHECK_AL_ERRORS("Failed to get pitch");
	return ret;
}

Dimension Source::Gain() const
{
	Dimension ret;
	alGetSourcef(_handle, AL_GAIN, &ret);
	CHECK_AL_ERRORS("Failed to get gain");
	return ret;
}

bool Source::Looping() const
{
	ALint ret;
	alGetSourcei(_handle, AL_LOOPING, &ret);
	CHECK_AL_ERRORS("Failed to get looping");
	return ret == AL_TRUE;
}

Vertex Source::Position() const
{
	Vertex ret;
	alGetSourcefv(_handle, AL_POSITION, glm::value_ptr(ret));
	CHECK_AL_ERRORS("Failed to get position");
	return ret;
}

Vertex Source::Velocity() const
{
	Vertex ret;
	alGetSourcefv(_handle, AL_VELOCITY, glm::value_ptr(ret));
	CHECK_AL_ERRORS("Failed to get velocity");
	return ret;
}

Vertex Source::Direction() const
{
	Vertex ret;
	alGetSourcefv(_handle, AL_DIRECTION, glm::value_ptr(ret));
	CHECK_AL_ERRORS("Failed to get direction");
	return ret;
}

void Source::setPitch(const Dimension &v)
{
	alSourcef(_handle, AL_PITCH, v);
	CHECK_AL_ERRORS("Failed to set pitch");
}

void Source::setGain(const Dimension &v)
{
	alSourcef(_handle, AL_GAIN, v);
	CHECK_AL_ERRORS("Failed to set gain");
}

void Source::setLooping(bool v)
{
	alSourcei(_handle, AL_LOOPING, v);
	CHECK_AL_ERRORS("Failed to set looping");
}

void Source::setPosition(const Vertex &v)
{
	alSourcefv(_handle, AL_POSITION, glm::value_ptr(v));
	CHECK_AL_ERRORS("Failed to set position");
}

void Source::setVelocity(const Vertex &v)
{
	alSourcefv(_handle, AL_VELOCITY, glm::value_ptr(v));
	CHECK_AL_ERRORS("Failed to set velocity");
}

void Source::setDirection(const Vertex &v)
{
	alSourcefv(_handle, AL_DIRECTION, glm::value_ptr(v));
	CHECK_AL_ERRORS("Failed to set direction");
}
