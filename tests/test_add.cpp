#include <gtest/gtest.h>
#include "add.hpp"

TEST(MathTest, AddWorks) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
}
