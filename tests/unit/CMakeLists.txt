
add_executable(route_test route_test.cpp)
add_executable(matrix_distance_test matrix_distance_test.cpp)
add_executable(exception_test exception_test.cpp)

target_link_libraries(route_test PRIVATE GTest::GTest route_lib)
target_link_libraries(matrix_distance_test PRIVATE GTest::GTest matrix_distance_lib route_lib exception_lib)
target_link_libraries(exception_test PRIVATE GTest::GTest exception_lib)

add_test(route_test route_test)
add_test(matrix_distance_test matrix_distance_test)
add_test(exception_test exception_test)