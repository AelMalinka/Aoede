/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Buffer.hh"
#include "AL/Context.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace testing;
using namespace std;

#define TEST_BEGIN try {
#define TEST_END } catch(exception &e) { FAIL() << e << endl; }

namespace {
	TEST(Buffer, Create) {
		TEST_BEGIN
			Context c;
			Buffer b;

			EXPECT_NE(b.Handle(), 0ul);
		TEST_END
	}
}
