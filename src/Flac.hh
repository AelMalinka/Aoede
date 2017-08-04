/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_FLAC_INC
#	define ENTROPY_AOEDE_FLAC_INC

#	include "Exception.hh"
#	include <FLAC++/decoder.h>
#	include <Entropy/Tethys/Timer.hh>
#	include <cstdint>

	namespace Entropy
	{
		namespace Aoede
		{
			class Flac :
				public Tethys::Timer,
				protected FLAC::Decoder::File
			{
				public:
					Flac(const std::string &, const std::function<void(const Flac &, const std::int32_t *const [])> &);
					virtual ~Flac();
					virtual void operator () ();
					virtual unsigned int Channels() const;
					virtual unsigned int BitRate() const;
					virtual unsigned int Frequency() const;
					virtual unsigned int BlockSize() const;
				protected:
					virtual FLAC__StreamDecoderWriteStatus write_callback(const FLAC__Frame *, const FLAC__int32 *const []);
					virtual void error_callback(FLAC__StreamDecoderErrorStatus);
				private:
					std::function<void(const Flac &, const std::int32_t *const [])> _cb;
				protected:
					struct abort_t {};
				public:
					static abort_t Abort;
			};

			ENTROPY_ERROR_INFO(FlacError, FLAC__StreamDecoderErrorStatus);
		}
	}

#endif
