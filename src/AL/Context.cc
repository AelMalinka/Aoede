/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Context.hh"

using namespace Entropy::Aoede::AL;
using namespace std;

Context::Context()
	: _handle(nullptr), _device()
{
	// 2017-08-02 AMR TODO: decide on attribute options
	_handle = alcCreateContext(_device.Handle(), nullptr);

	if(!_handle)
		ENTROPY_THROW(Exception("Failed to create context"));

	makeCurrent();
}

Context::Context(const string &name)
	: _handle(nullptr), _device(name)
{
	// 2017-08-02 AMR TODO: decide on attribute options
	_handle = alcCreateContext(_device.Handle(), nullptr);

	if(!_handle)
		ENTROPY_THROW(Exception("Failed to create context"));

	makeCurrent();
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
