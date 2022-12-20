add_library(point_lib tools/point.hpp)
add_library(direction_lib tools/direction.hpp)
add_library(route_lib tools/route.hpp tools/impl/route.cpp)
add_library(matrix_distance_lib tools/matrix_distance.hpp tools/impl/matrix_distance.cpp)
add_library(exception_lib tools/exception.hpp tools/impl/exception.cpp)

set_target_properties(point_lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(direction_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(point_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(route_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(direction_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(matrix_distance_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(exception_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

