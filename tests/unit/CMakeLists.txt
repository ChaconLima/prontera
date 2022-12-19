
add_executable(route_test route_test.cpp)
target_link_libraries(route_test PRIVATE GTest::GTest route_lib)
add_test(route_test route_test)