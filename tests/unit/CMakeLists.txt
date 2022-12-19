

add_executable(value_test value_test.cpp)
add_executable(route_test route_test.cpp)

target_link_libraries(value_test PRIVATE GTest::GTest valuelib)
target_link_libraries(route_test PRIVATE GTest::GTest route_lib)

add_test(value_test value_test)
add_test(route_test route_test)