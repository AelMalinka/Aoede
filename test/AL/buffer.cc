/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Buffer.hh"
#include "AL/Context.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace testing;
using namespace std;

namespace {
	TEST(Buffer, Create) {
		Context c();
		Buffer b;

		EXPECT_NE(b.Handle(), 0ul);
	}
}
