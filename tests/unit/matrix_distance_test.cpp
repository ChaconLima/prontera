#include <gtest/gtest.h>
#include <tools/route.hpp>
#include <tools/matrix_distance.hpp>
#include <tools/exception.hpp>
#include <string>

using namespace route;
using namespace point;
using namespace matrix_distance;
using namespace exception;

Route getRoute() {
    Route route;
   
    Point point0;
    point0.id = 0;
    point0.name = "Route_"+std::to_string(0);
    point0.latitude = 51.5007;
    point0.longitude = 0.1246;
    route.addPoint(&point0);

    Point point1;
    point1.id = 1;
    point1.name = "Route_"+std::to_string(1);
    point1.latitude = 40.6892;
    point1.longitude = 74.0445;

    route.addPoint(&point1);
   
    return route;
}

TEST(MatrixDistanceTest, GenerateKey){
    string a = "";
    Route route = getRoute();
    Points points = route.getPoints();
    MatrixDistance distance = MatrixDistance(&points, &a);

    Point point1;
    Point point2;

    EXPECT_THROW({
        try {
            distance.getDirection(&point1, &point2);
        }
        catch(Exception e) {
            ASSERT_EQ("MatrixDistance::getDirection", e.getClassName());
            throw e;
        }
    }, Exception);
    
}

TEST(MatrixDistanceTest, GenerateMatrixTest){

    string a = "";
    Route route = getRoute();
    Points points = route.getPoints();
    MatrixDistance matrix = MatrixDistance(&points, &a);

    Direction direction = matrix.getDirection(&points[0],&points[1]);
    ASSERT_EQ(5574.840456848555,direction.distance);
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}