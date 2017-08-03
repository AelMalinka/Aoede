/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "AL/Device.hh"
#include <gtest/gtest.h>

using namespace Entropy::Aoede::AL;
using namespace testing;
using namespace std;

namespace {
	TEST(Device, Default) {
		Device d;

		EXPECT_NE(d.Handle(), nullptr);
	}

	TEST(Device, Soft) {
		Device d("OpenAL Soft");

		EXPECT_NE(d.Handle(), nullptr);
	}
}
