/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Context.hh"
#include "AL/Source.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace Entropy::Aoede;
using namespace testing;
using namespace std;

namespace {
	TEST(Source, Create) {
		Context c;
		Source s;

		EXPECT_NE(s.Handle(), 0ul);
	}
}
