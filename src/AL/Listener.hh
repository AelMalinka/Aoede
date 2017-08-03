/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_AL_LISTENER_INC
#	define ENTROPY_AOEDE_AL_LISTENER_INC

#	include "../Types.hh"

	namespace Entropy
	{
		namespace Aoede
		{
			namespace AL
			{
				class Listener
				{
					public:
						Listener();
						Dimension Gain() const;
						Vertex Position() const;
						Vertex Velocity() const;
						const Vertex &LookAt() const;
						const Vertex &Up() const;
						void setGain(const Dimension &);
						void setPosition(const Vertex &);
						void setVelocity(const Vertex &);
						void setLookAt(const Vertex &);
						void setUp(const Vertex &);
					private:
						Vertex _look_at;
						Vertex _up;
				};
			}
		}
	}

#endif
