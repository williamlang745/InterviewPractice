#include <gtest/gtest.h>
#include "zig_zag.hpp"

TEST(MathTest, AddWorks) {
    EXPECT_EQ(convert("PAHNAPLSIIGYIR", 3), "PAYPALISHIRING");
}