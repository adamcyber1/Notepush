cmake_minimum_required(VERSION 3.8)

find_package(Gtest REQUIRED)

enable_testing()

add_executable(notepush_unittest
        test_notepush.cpp)

target_link_libraries(notepush_unittest PUBLIC
        Gtest::Gtest
        Gtest::Main
        notepush
        )

add_test(
        NAME notepush_unittest 
        COMMAND notepush_unittest
)