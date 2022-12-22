file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_library(prontools prontools/prontools.hpp ${SRC_FILES})
add_library(point prontools/point.hpp)
add_library(direction prontools/direction.hpp)
add_library(route prontools/route.hpp src/route.cpp)
add_library(matrix_distance prontools/matrix_distance.hpp src/matrix_distance.cpp)
add_library(exception prontools/exception.hpp src/exception.cpp)
add_library(random prontools/random.hpp src/random.cpp)

set_target_properties(prontools PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(point PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(direction PROPERTIES LINKER_LANGUAGE CXX)

find_package(GSL REQUIRED)    
target_link_libraries(random GSL::gsl GSL::gslcblas)

target_include_directories(prontools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(point PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(direction PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(route PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(matrix_distance PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(exception PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(random PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)
