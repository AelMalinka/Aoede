/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_AL_BUFFER_INC
#	define ENTROPY_AOEDE_AL_BUFFER_INC

#	include "../Types.hh"

	namespace Entropy
	{
		namespace Aoede
		{
			namespace AL
			{
				class Buffer
				{
					public:
						Buffer();
						~Buffer();
						Buffer(const Buffer &) = delete;
						Buffer(Buffer &&);
						const ALuint &Handle() const;
						void setData(const void *, const std::size_t, const std::size_t);
					private:
						ALuint _handle;
				};
			}
		}
	}

#endif
