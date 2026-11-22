cmake_minimum_required(VERSION 3.20)
project(MergeSort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Główny program
add_executable(MergeSort
        Program/main.cpp
        Program/MergeSort.h
)

# 2. Automatyczne pobranie Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# 3. Cel dla testów jednostkowych
enable_testing()

add_executable(MergeSortTests
        Testy/tests.cpp
        Program/MergeSort.h
)

target_include_directories(MergeSortTests PRIVATE Program)
target_link_libraries(MergeSortTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(MergeSortTests)