/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Application.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede;
using namespace testing;
using namespace std;

namespace {
	TEST(Application, Create) {
		Application app;

		EXPECT_TRUE(app.getContext().isCurrent());
		EXPECT_EQ(app.getListener().Gain(), 1.0f);
	}
}
