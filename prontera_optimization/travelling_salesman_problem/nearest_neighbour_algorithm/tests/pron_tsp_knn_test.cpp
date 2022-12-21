#include <gtest/gtest.h>
#include <pron_tsp_knn/pron_tsp_knn.hpp>


using namespace pron_tsp_knn;
using namespace matrix_distance;
using namespace route;
using namespace point;

Points getPoints() {
  
    Points points;

    Point point0;
    point0.id = 0;
    point0.name = "Route_"+std::to_string(0);
    point0.latitude = 51.5007;
    point0.longitude = 0.1246;
    points.push_back(point0);

    Point point1;
    point1.id = 1;
    point1.name = "Route_"+std::to_string(1);
    point1.latitude = 40.6892;
    point1.longitude = 74.0445;

    points.push_back(point1);

    Point point2;
    point2.id = 2;
    point2.name = "Route_"+std::to_string(2);
    point2.latitude = 41.6892;
    point2.longitude = 74.0445;

    points.push_back(point2);

    Point point3;
    point3.id = 3;
    point3.name = "Route_"+std::to_string(3);
    point3.latitude = 40.6892;
    point3.longitude = 75.0445;

    points.push_back(point3);
   
    return points;
}


TEST(PronTspKnnTest, RunTest){
    Points points = getPoints();
    std::string a = "";
    MatrixDistance matrixDistance = MatrixDistance(&points, &a);
    PronTspKnn pronTspKnn = PronTspKnn(&matrixDistance);
    Route route = pronTspKnn.runTspKnn();

    double distance = 0;
    for (size_t i = 0; i < route.getPoints().size()-1; i++) {
        distance += matrixDistance.getDirection(&route.getPoints()[i], &route.getPoints()[i+1]).distance;
    }

    ASSERT_EQ( distance, route.getDistance());
    ASSERT_EQ(0, route.getPoints()[0].id);
    ASSERT_EQ(2, route.getPoints()[1].id);
    ASSERT_EQ(1, route.getPoints()[2].id);
    ASSERT_EQ(3, route.getPoints()[3].id);
    ASSERT_EQ(0, route.getPoints()[4].id);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}