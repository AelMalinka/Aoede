/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Flac.hh"

using namespace Entropy::Aoede;
using namespace std;

Flac::abort_t Flac::Abort;

// 2017-08-03 AMR TODO: tie repeat to whether there is input ready
Flac::Flac(const string &name, const function<void(const Flac &, const int32_t *const [])> &cb)
	: Timer(chrono::milliseconds(1)), File(), _cb(cb)
{
	// 2017-09-19 ARM NOTE: Windows is corrupting this if passed across as a string
	switch(init(name.c_str())) {
		case FLAC__STREAM_DECODER_INIT_STATUS_OK:
		break;
		case FLAC__STREAM_DECODER_INIT_STATUS_UNSUPPORTED_CONTAINER:
			ENTROPY_THROW(Exception("Failed to initialzie flac: unsupport container"));
		case FLAC__STREAM_DECODER_INIT_STATUS_MEMORY_ALLOCATION_ERROR:
			ENTROPY_THROW(Exception("Failed to initialize flac: memory allocation error"));
		case FLAC__STREAM_DECODER_INIT_STATUS_ERROR_OPENING_FILE:
			ENTROPY_THROW(Exception("Failed to initialize flac: unable to open file"));
		default:
			ENTROPY_THROW(Exception("Failed to initialze flac"));
	}
	if(!process_until_end_of_metadata()) {
		ENTROPY_THROW(Exception("Failed to parse metadata for flac file"));
	}
}

Flac::~Flac()
{
	finish();
}

void Flac::operator () ()
{
	FLAC__StreamDecoderState state = get_state();

	if(state != FLAC__STREAM_DECODER_END_OF_STREAM && state != FLAC__STREAM_DECODER_ABORTED)
		process_single();
	else
		Stop();
}

unsigned int Flac::Channels() const
{
	return get_channels();
}

unsigned int Flac::BitRate() const
{
	return get_bits_per_sample();
}

unsigned int Flac::Frequency() const
{
	return get_sample_rate();
}

unsigned int Flac::BlockSize() const
{
	return get_blocksize();
}

// 2017-08-03 AMR TODO: do we need frame?
FLAC__StreamDecoderWriteStatus Flac::write_callback(const FLAC__Frame *, const FLAC__int32 *const buffer[])
{
	try
	{
		_cb(*this, buffer);

		return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
	}
	catch(abort_t &)
	{
		return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
	}
}

void Flac::error_callback(FLAC__StreamDecoderErrorStatus error)
{
	ENTROPY_THROW(Exception("Flac failed") <<
		FlacError(error)
	);
}
