add_library(valuelib value/value.h value/value.cpp)
target_include_directories(valuelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
