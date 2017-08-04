/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_EXCEPTION_INC
#	define ENTROPY_AOEDE_EXCEPTION_INC

#	include <Entropy/Exception.hh>

#	include <AL/al.h>
#	include <AL/alc.h>

	namespace Entropy
	{
		namespace Aoede
		{
			ENTROPY_EXCEPTION_BASE(Exception, "Aoede Exception");
			ENTROPY_ERROR_INFO(AlErrorCode, ALenum);
		}
	}

#	define CHECK_AL_ERRORS(x) \
		{ ALenum status = alGetError(); \
			if(status != AL_NO_ERROR) \
				::boost::throw_exception(::boost::enable_error_info(::Entropy::Aoede::Exception(x)) << \
				::boost::throw_function(BOOST_CURRENT_FUNCTION) << \
				::boost::throw_file(__FILE__) << \
				::boost::throw_line((int)__LINE__) << \
				::Entropy::Aoede::AlErrorCode(status)); \
		}

#	define CHECK_AL_ERRORS_WITH(x, z) \
		{ ALenum status = alGetError(); \
			if(status != GL_NO_ERROR) \
				::boost::throw_exception(::boost::enable_error_info(::Entropy::Aoede::Exception(x)) << \
				::boost::throw_function(BOOST_CURRENT_FUNCTION) << \
				::boost::throw_file(__FILE__) << \
				::boost::throw_line((int)__LINE__) << \
				::Entropy::Aoede::AlErrorCode(status) \
				z);\
		}

#endif
