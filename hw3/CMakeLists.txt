cmake_minimum_required(VERSION 3.14)
project(StudentTestProject)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Define source files (include student's .cpp and .h)
set(STUDENT_SOURCES
    HashTable.cpp
    HashTable.h
    HashTableImproved.h
    HashTableImproved.cpp
    HashNode.h
    LinkedHashNode.h
    HashLinkedList
)
set(TEST_SOURCES_1
    test1.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# Create the test executable
add_executable(
  test1
  ${TEST_SOURCES_1}
  ${STUDENT_SOURCES}
)

# Enable testing
enable_testing()
# Register the test executable as a test
add_test(NAME test1 COMMAND test1)
# Link GoogleTest libraries
target_link_libraries(
  test1
  GTest::gtest_main
)

# Include GoogleTest discovery
include(GoogleTest)
gtest_discover_tests(test1)