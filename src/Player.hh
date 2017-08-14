/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_PLAYER_INC
#	define ENTROPY_AOEDE_PLAYER_INC

#	include "AL/Source.hh"
#	include <Entropy/Tethys/Timer.hh>
#	include <vector>

	namespace Entropy
	{
		namespace Aoede
		{
			class Player :
				public Tethys::Timer
			{
				public:
					Player();
					void operator () ();
					void Play();
					void Pause();
					void Stop();
					void Add(AL::Source &);
				private:
					std::vector<AL::Source *> _items;
			};
		}
	}

#endif
