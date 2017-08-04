/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Context.hh"
#include "AL/Listener.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace Entropy::Aoede;
using namespace testing;
using namespace std;

namespace {
	TEST(Listener, Create) {
		Context c;
		Listener l;

		Vertex pos(0.0f, 0.0f, 0.0f),
				vel(0.0f, 0.0f, 0.0f),
				at(0.0f, 0.0f, -1.0f),
				up(0.0f, 1.0f, 0.0f);

		EXPECT_EQ(l.Gain(), 1.0f);
		EXPECT_EQ(l.Position(), pos);
		EXPECT_EQ(l.Velocity(), vel);
		EXPECT_EQ(l.LookAt(), at);
		EXPECT_EQ(l.Up(), up);
	}
}
