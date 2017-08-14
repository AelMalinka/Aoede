/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Player.hh"

using namespace Entropy::Aoede;
using namespace std;

Player::Player()
	: Timer(chrono::milliseconds(100)), _items()
{}

void Player::operator () ()
{
	bool playing = false;
	for(auto i : _items) {
		if(i->isPlaying() || i->isPaused()) {
			playing = true;
			break;
		}
	}

	if(!playing)
		Timer::Stop();
}

void Player::Play()
{
	vector<ALuint> items;
	for(auto i : _items) {
		items.push_back(i->Handle());
	}

	alSourcePlayv(items.size(), items.data());
}

void Player::Pause()
{
	vector<ALuint> items;
	for(auto i : _items) {
		items.push_back(i->Handle());
	}

	alSourcePausev(items.size(), items.data());
}

void Player::Stop()
{
	vector<ALuint> items;
	for(auto i : _items) {
		items.push_back(i->Handle());
	}

	alSourceStopv(items.size(), items.data());
}

void Player::Add(AL::Source &v)
{
	_items.push_back(&v);
}
