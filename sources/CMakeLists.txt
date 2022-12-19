add_library(point_lib point/point.hpp)
set_target_properties(point_lib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(point_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(route_lib route/route.hpp route/route.cpp)
target_include_directories(route_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

