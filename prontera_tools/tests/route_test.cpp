#include <gtest/gtest.h>
#include <prontools/route.hpp>
#include <string>
#include <random>


using namespace point;
using namespace route;

Route getRoute(const int *size) {
    Route route;
    double fMin = 18.00;
    double fMax = 25.00;
    double f = (double)rand() / RAND_MAX;
  
    for (int i = 0; i < *size; i++) {
        Point point;
        point.id = i;
        point.name = "Route_"+std::to_string(i);
        point.latitude = fMin + f * (fMax - fMin);
        point.longitude = fMin + f * (fMax - fMin);

        route.addPoint(&point);
    }
    return route;
}

/*
*
*/
TEST(RouteTest, AddPoint){

    int size = 100;
    Route route = getRoute(&size);
    Points points = route.getPoints();

    for (int i = 0; i < points.size(); i++) {

        Point point = points[i];
        ASSERT_EQ(i, point.id);
        ASSERT_EQ("Route_"+std::to_string(i), point.name);
    }
    
    ASSERT_EQ(size, route.getPoints().size());
}

/*
*
*/
TEST(RouteTest, SwapPoint){
    int size = 100;
    int first = 10;
    int seconde = 50;

    Route route = getRoute(&size);
    Points points = route.getPoints();

    Point point_first = points[first];
    Point point_seconde = points[seconde];

    route.swap(&first, &seconde);
    points = route.getPoints();

    Point point_first_execution = points[first];
    Point point_seconde_execution = points[seconde];

    ASSERT_EQ(first, point_first_execution.id);
    ASSERT_EQ(seconde, point_seconde_execution.id);

    ASSERT_EQ(point_first.name, point_seconde_execution.name);
    ASSERT_EQ(point_seconde.name, point_first_execution.name);
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}