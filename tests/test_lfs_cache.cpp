#include <gtest/gtest.h>
#include "lfs_cache.hpp"

TEST(CacheTest, put) {
    Cache c(5);
    c.put(1, 1);
    c.put(2, 2);
    c.put(3, 3);
    c.print();
}
