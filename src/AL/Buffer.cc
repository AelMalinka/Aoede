/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Buffer.hh"

using namespace Entropy::Aoede::AL;
using namespace Entropy::Aoede;
using namespace std;

Buffer::Buffer()
{
	alGenBuffers(1, &_handle);
	CHECK_AL_ERRORS("Failed to generate buffer");
}

Buffer::~Buffer()
{
	alDeleteBuffers(1, &_handle);
	alGetError();
}

Buffer::Buffer(Buffer &&o)
{
	swap(_handle, o._handle);
}

const ALuint &Buffer::Handle() const
{
	return _handle;
}

void Buffer::setData(const void *data, const size_t size, const size_t freq)
{
	// 2017-08-02 AMR TODO: Support Stereo and other bitrates
	alBufferData(_handle, AL_FORMAT_MONO16, data, size, freq);
	CHECK_AL_ERRORS("Failed to set buffer data");
}
