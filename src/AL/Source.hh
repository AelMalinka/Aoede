/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_AL_SOURCE_INC
#	define ENTROPY_AOEDE_AL_SOURCE_INC

#	include "Buffer.hh"

	namespace Entropy
	{
		namespace Aoede
		{
			namespace AL
			{
				class Source
				{
					public:
						enum class State
						{
							Initial = AL_INITIAL,
							Playing = AL_PLAYING,
							Paused = AL_PAUSED,
							Stopped = AL_STOPPED
						};
					public:
						Source();
						~Source();
						Source(const Source &) = delete;
						Source(Source &&);
						const ALuint &Handle() const;
						void setBuffer(const Buffer &);
						void queueBuffer(const Buffer &);
						void unqueueBuffer(const Buffer &);
						State getState() const;
						bool isPlaying() const;
						bool isStopped() const;
						bool isPaused() const;
						Dimension Pitch() const;
						Dimension Gain() const;
						bool Looping() const;
						Vertex Position() const;
						Vertex Velocity() const;
						Vertex Direction() const;
						void setPitch(const Dimension &);
						void setGain(const Dimension &);
						void setLooping(bool);
						void setPosition(const Vertex &);
						void setVelocity(const Vertex &);
						void setDirection(const Vertex &);
					private:
						ALuint _handle;
				};
			}
		}
	}

#endif
