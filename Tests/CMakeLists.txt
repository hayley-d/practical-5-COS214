cmake_minimum_required(VERSION 3.28)
project(P5Tests)

set(CMAKE_CXX_STANDARD 17)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/src/*.h")

# Test executable for Google Test
add_executable(tests tests/light_test.cpp tests/smart_room_test.cpp ${SOURCE_FILES} ${HEADER_FILES})

# Link Google Test and pthread to the test executable
target_link_libraries(tests gtest gtest_main pthread)

# Enable testing
enable_testing()
add_test(NAME all_tests COMMAND tests)
