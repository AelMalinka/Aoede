/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Sound.hh"

#include <utility>

using namespace Entropy::Aoede;
using namespace std;
using namespace Entropy;

Sound::Sound(const string &name)
	: _data(name, bind(&Sound::DataCb, this, placeholders::_1, placeholders::_2)), _player(), _sources(), _buffers(), _looping(false), _loop(nullptr), _playing(false), _done(false)
{}

Sound::Sound(const string &name, bool looping)
	: _data(name, bind(&Sound::DataCb, this, placeholders::_1, placeholders::_2)), _player(), _sources(), _buffers(), _looping(looping), _loop(nullptr), _playing(false), _done(false)
{}

Sound::~Sound() = default;

void Sound::Stop()
{
	_player.Stop();
	_done = true;
}

void Sound::operator () ()
{
	if(!_loop)
		ENTROPY_THROW(Exception("unable to add Flac and/or Player"));

	_loop->Add(_data);
}

void Sound::Added(Tethys::UV::Loop &loop)
{
	_loop = &loop;

	// 2017-08-03 AMR HACK: back out into typical uv_work paths
	throw bad_cast();
}

void Sound::DataCb(const Flac &flac, const int32_t *const buffer[])
{
	if(_done) {
		throw Flac::Abort;
	}

	if(_sources.size() < flac.Channels()) {
		for(auto x = _sources.size(); x < flac.Channels(); x++) {
			_sources.emplace_back();
			_sources.back().setLooping(_looping);
		}
	}

	for(auto x = 0u; x < flac.Channels(); x++) {
		int16_t *buff = new int16_t[flac.BlockSize()];

		for(auto y = 0u; y < flac.BlockSize(); y++) {
			buff[y] = buffer[x][y];
		}

		_buffers.emplace_back();
		_buffers.back().setData(buff, flac.BlockSize() * flac.BitRate() / 8, flac.Frequency());
		_sources[x].queueBuffer(_buffers.back());

		delete[] buff;
	}

	if(!_playing) {
		for(auto &s : _sources) {
			_player.Add(s);
		}

		_player.Play();
		_loop->Add(_player);

		_playing = true;
	}
}
