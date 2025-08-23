#include <gtest/gtest.h>
#include "multiply.hpp"

TEST(MathTest, MultiplyWorks) {
    EXPECT_EQ(multiply(2, 3), 6);
    EXPECT_EQ(multiply(5, 0), 0);
}
