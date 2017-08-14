/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Sound.hh"

#include <utility>

using namespace Entropy::Aoede;
using namespace std;

Sound::Sound(const string &name)
	: _data(name, bind(&Sound::DataCb, this, placeholders::_1, placeholders::_2)), _player(), _sources(), _loop(nullptr)
{}

Sound::~Sound() = default;

void Sound::Added(Tethys::UV::Loop &loop)
{
	_loop = &loop;

	// 2017-08-03 AMR HACK: back out into typical uv_work paths
	throw bad_cast();
}

void Sound::operator () ()
{
	if(!_loop)
		ENTROPY_THROW(Exception("unable to add Flac and/or Player"));

	_loop->Add(_data);
}

#include <iostream>

void Sound::DataCb(const Flac &flac, const int32_t *const buffer[])
{
	if(_sources.size() < flac.Channels()) {
		for(auto x = _sources.size(); x < flac.Channels(); x++) {
			_sources.emplace_back();
			cout << "adding source: " << _sources.back().Handle() << endl;
		}
	}

	for(auto x = 0u; x < flac.Channels(); x++) {
		_buffers.emplace_back();
		cout << "setting buffer " << _buffers.back().Handle() << " to source " << _sources[x].Handle() << endl;
		_sources[x].setBuffer(_buffers.back());
		_buffers.back().setData(buffer[x], flac.BlockSize(), flac.Frequency());
	}

	for(auto &s :  _sources) {
		_player.Add(s);
	}

	_loop->Add(_player);
}
