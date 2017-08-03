/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Context.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace testing;
using namespace std;

namespace {
	TEST(Context, MakeCurrent) {
		Device d;
		Context a(d), b(d), c(d);

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
	}
}
