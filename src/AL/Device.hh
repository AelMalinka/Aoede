/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_AL_DEVICE_INC
#	define ENTROPY_AOEDE_AL_DEVICE_INC

#	include "../Exception.hh"

	namespace Entropy
	{
		namespace Aoede
		{
			namespace AL
			{
				class Device
				{
					public:
						Device();
						explicit Device(const std::string &);
						~Device();
						ALCdevice *Handle();
					private:
						ALCdevice *_handle;
				};

				ENTROPY_ERROR_INFO(AlDevice, std::string);
			}
		}
	}

#endif
