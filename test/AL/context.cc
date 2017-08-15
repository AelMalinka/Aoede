/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Context.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace testing;
using namespace std;

#define TEST_BEGIN try {
#define TEST_END } catch(exception &e) { FAIL() << e << endl; }

namespace {
	TEST(Context, MakeCurrent) {
		TEST_BEGIN
			Context a, b, c;

			a.makeCurrent();
			EXPECT_TRUE(a.isCurrent());
			EXPECT_FALSE(b.isCurrent());
			EXPECT_FALSE(c.isCurrent());

			b.makeCurrent();
			EXPECT_FALSE(a.isCurrent());
			EXPECT_TRUE(b.isCurrent());
			EXPECT_FALSE(c.isCurrent());

			c.makeCurrent();
			EXPECT_FALSE(a.isCurrent());
			EXPECT_FALSE(b.isCurrent());
			EXPECT_TRUE(c.isCurrent());
		TEST_END
	}
}
