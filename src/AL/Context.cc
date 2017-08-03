/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Context.hh"

using namespace Entropy::Aoede::AL;
using namespace std;

Context::Context(Device &d)
	: _handle(nullptr), _listener()
{
	// 2017-08-02 AMR TODO: decide on attribute options
	_handle = alcCreateContext(d.Handle(), nullptr);

	if(!_handle)
		ENTROPY_THROW(Exception("Failed to create context"));
}

Context::~Context()
{
	alcDestroyContext(_handle);
}

void Context::makeCurrent()
{
	if(!isCurrent())
		if(!alcMakeContextCurrent(_handle))
			ENTROPY_THROW(Exception("Failed to make context current"));
}

bool Context::isCurrent() const
{
	return alcGetCurrentContext() == _handle;
}

Listener *Context::operator -> ()
{
	makeCurrent();
	return &_listener;
}

const Listener *Context::operator -> () const
{
	if(!isCurrent())
		ENTROPY_THROW(Exception("unable to make context current"));
	return &_listener;
}
