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

#define TEST_BEGIN try {
#define TEST_END } catch(exception &e) { FAIL() << e << endl; }

namespace {
	TEST(Source, Create) {
		TEST_BEGIN
			Context c;
			Source s;

			EXPECT_NE(s.Handle(), 0ul);
		TEST_END
	}
}
