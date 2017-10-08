/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Device.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace testing;
using namespace std;

#define TEST_BEGIN try {
#define TEST_END } catch(exception &e) { FAIL() << e << endl; }

namespace {
	TEST(Device, Default) {
		TEST_BEGIN
			Device d;

			EXPECT_NE(d.Handle(), nullptr);
		TEST_END
	}

	// 2017-10-08 AMR TODO: Is this useful and/or necesary
	TEST(Device, DISABLED_Soft) {
		TEST_BEGIN
			Device d("OpenAL Soft");

			EXPECT_NE(d.Handle(), nullptr);
		TEST_END
	}
}
