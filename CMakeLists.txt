cmake_minimum_required(VERSION 3.16.3)
project(protera VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(sources)
add_subdirectory(standalone)
add_subdirectory(tests)


