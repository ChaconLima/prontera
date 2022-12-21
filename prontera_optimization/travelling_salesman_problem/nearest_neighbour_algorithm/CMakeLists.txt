
add_library(pron_tsp_knn pron_tsp_knn/pron_tsp_knn.hpp src/pron_tsp_knn.cpp)

target_link_libraries(pron_tsp_knn PRIVATE matrix_distance)

target_include_directories(pron_tsp_knn PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(pron_tsp_knn_test tests/pron_tsp_knn_test.cpp)
target_link_libraries(pron_tsp_knn_test PRIVATE GTest::GTest pron_tsp_knn prontools)
add_test(pron_tsp_knn_test pron_tsp_knn_test)