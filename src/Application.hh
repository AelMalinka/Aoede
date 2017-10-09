/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_APPLICATION_INC
#	define ENTROPY_AOEDE_APPLICATION_INC

#	include "Exception.hh"
#	include <Entropy/Tethys/Application.hh>
#	include "AL/Context.hh"
#	include "AL/Listener.hh"

	namespace Entropy
	{
		namespace Aoede
		{
			class Application :
				public virtual Tethys::Application
			{
				public:
					Application();
					Application(const int, char *[]);
					virtual ~Application();
					AL::Context &getContext();
					AL::Listener &getListener();
					const AL::Context &getContext() const;
					const AL::Listener &getListener() const;
				private:
					AL::Context _context;
					AL::Listener _listener;
			};
		}
	}

#endif
