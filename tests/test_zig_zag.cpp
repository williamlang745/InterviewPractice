#include <gtest/gtest.h>
#include "zig_zag.hpp"

TEST(ZigZagTest, convert_from_zig_zag) {
    EXPECT_EQ(convert("PAHNAPLSIIGYIR", 3), "PAYPALISHIRING");
}

TEST(ZigZagTest, convert_to_zig_zag) {
    EXPECT_EQ(convert_rev("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(convert_rev("AB", 1), "AB");
}