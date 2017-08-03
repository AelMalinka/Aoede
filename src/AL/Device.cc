/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Device.hh"

using namespace Entropy::Aoede::AL;
using namespace std;

Device::Device()
	: _handle(nullptr)
{
	_handle = alcOpenDevice(nullptr);

	if(!_handle)
		ENTROPY_THROW(Exception("Failed to open device") <<
			AlDevice("default"s)
		);
}

Device::Device(const string &name)
	: _handle(nullptr)
{
	_handle = alcOpenDevice(name.c_str());

	if(!_handle)
		ENTROPY_THROW(Exception("Failed to open device") <<
			AlDevice(name)
		);
}

Device::~Device()
{
	alcCloseDevice(_handle);
}

ALCdevice *Device::Handle()
{
	return _handle;
}
