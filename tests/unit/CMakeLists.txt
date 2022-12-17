

add_executable(value_test value_test.cpp)
target_link_libraries(value_test PRIVATE GTest::GTest valuelib)

add_test(value_test value_test)