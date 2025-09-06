cmake_minimum_required(VERSION 3.10)
project(MyLibrary CXX)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE MYLIB_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

# Library from all sources
add_library(mylib ${MYLIB_SOURCES})

target_include_directories(mylib PUBLIC include)

# Enable testing
enable_testing()
find_package(GTest REQUIRED)

# Test for add.cpp
add_executable(test_lfs_cache tests/test_lfs_cache.cpp)
target_link_libraries(test_lfs_cache PRIVATE mylib GTest::gtest GTest::gtest_main)
add_test(NAME TestCache COMMAND test_lfs_cache)

# Test for add.cpp
add_executable(test_add tests/test_add.cpp)
target_link_libraries(test_add PRIVATE mylib GTest::gtest GTest::gtest_main)
add_test(NAME TestAdd COMMAND test_add)

# Test for multiply.cpp
add_executable(test_multiply tests/test_multiply.cpp)
target_link_libraries(test_multiply PRIVATE mylib GTest::gtest GTest::gtest_main)
add_test(NAME TestMultiply COMMAND test_multiply)

# Test for zig_zag.cpp
add_executable(test_zig_zag tests/test_zig_zag.cpp)
target_link_libraries(test_zig_zag PRIVATE mylib GTest::gtest GTest::gtest_main)
add_test(NAME TestZigZag COMMAND test_zig_zag)
