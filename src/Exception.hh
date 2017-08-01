/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_EXCEPTION
#	define ENTROPY_AOEDE_EXCEPTION

#	include <Entropy/Exception.hh>

	namespace Entropy
	{
		namespace Aoede
		{
			ENTROPY_EXCEPTION_BASE(Exception, "Base Aoede Exception");
		}
	}

#endif
