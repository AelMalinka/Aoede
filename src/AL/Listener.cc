/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Listener.hh"

#include <glm/gtc/type_ptr.hpp>

using namespace Entropy::Aoede::AL;
using namespace Entropy::Aoede;
using namespace std;

Listener::Listener()
	: _look_at(0.0f, 0.0f, -1.0f), _up(0.0f, 1.0f, 0.0f)
{}

Dimension Listener::Gain() const
{
	Dimension ret;
	alGetListenerf(AL_GAIN, &ret);
	CHECK_AL_ERRORS("failed to get gain");
	return ret;
}

Vertex Listener::Position() const
{
	Vertex ret;
	alGetListenerfv(AL_POSITION, glm::value_ptr(ret));
	CHECK_AL_ERRORS("failed to get position");
	return ret;
}

Vertex Listener::Velocity() const
{
	Vertex ret;
	alGetListenerfv(AL_VELOCITY, glm::value_ptr(ret));
	CHECK_AL_ERRORS("failed to get velocity");
	return ret;
}

const Vertex &Listener::LookAt() const
{
	return _look_at;
}

const Vertex &Listener::Up() const
{
	return _up;
}

void Listener::setGain(const Dimension &v)
{
	alListenerf(AL_GAIN, v);
	CHECK_AL_ERRORS("failed to set gain");
}

void Listener::setPosition(const Vertex &v)
{
	alListenerfv(AL_POSITION, glm::value_ptr(v));
	CHECK_AL_ERRORS("failed to set position");
}

void Listener::setVelocity(const Vertex &v)
{
	alListenerfv(AL_VELOCITY, glm::value_ptr(v));
	CHECK_AL_ERRORS("failed to set velocity");
}

void Listener::setLookAt(const Vertex &v)
{
	_look_at = v;

	ALfloat value[] = {
		_look_at.x, _look_at.y, _look_at.z,
		_up.x, _up.y, _up.z,
	};

	alListenerfv(AL_ORIENTATION, value);
	CHECK_AL_ERRORS("failed to set look at");
}

void Listener::setUp(const Vertex &v)
{
	_up = v;

	ALfloat value[] = {
		_look_at.x, _look_at.y, _look_at.z,
		_up.x, _up.y, _up.z,
	};

	alListenerfv(AL_ORIENTATION, value);
	CHECK_AL_ERRORS("failed to set up");
}
