#include <gtest/gtest.h>
#include "zig_zag.hpp"

TEST(MathTest, convert_from_zig_zag) {
    EXPECT_EQ(convert("PAHNAPLSIIGYIR", 3), "PAYPALISHIRING");
}

TEST(MathTest, convert_to_zig_zag) {
    EXPECT_EQ(convert_rev("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}