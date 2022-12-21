cmake_minimum_required(VERSION 3.16.3)
project(protera VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_subdirectory(prontera_tools)
add_subdirectory(prontera_optimization)

