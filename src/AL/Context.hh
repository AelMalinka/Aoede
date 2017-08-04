/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_AL_CONTEXT_INC
#	define ENTROPY_AOEDE_AL_CONTEXT_INC

#	include "Device.hh"

	namespace Entropy
	{
		namespace Aoede
		{
			namespace AL
			{
				class Context
				{
					public:
						Context();
						explicit Context(const std::string &);
						~Context();
						void makeCurrent();
						bool isCurrent() const;
					private:
						ALCcontext *_handle;
						Device _device;
				};
			}
		}
	}

#endif
