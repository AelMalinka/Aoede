/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Application.hh"
#include "Sound.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede;
using namespace testing;
using namespace std;

namespace {
	TEST(Sound, Create) {
		Sound s("data/sound.flac");
	}
}
