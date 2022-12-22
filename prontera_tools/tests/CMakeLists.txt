
add_executable(route_test route_test.cpp)
add_executable(matrix_distance_test matrix_distance_test.cpp)
add_executable(exception_test exception_test.cpp)
add_executable(random_test random_test.cpp)

find_package(GSL REQUIRED)    
target_link_libraries(route_test PRIVATE GTest::GTest route)
target_link_libraries(matrix_distance_test PRIVATE GTest::GTest matrix_distance route exception)
target_link_libraries(exception_test PRIVATE GTest::GTest exception)
target_link_libraries(random_test PRIVATE GTest::GTest GSL::gsl GSL::gslcblas random)

add_test(route_test route_test)
add_test(matrix_distance_test matrix_distance_test)
add_test(exception_test exception_test)
add_test(random_test random_test)