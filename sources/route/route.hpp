#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>
#include <point/point.hpp>
#include <vector>

namespace route {

    using namespace point;
    using Points = std::vector<Point>;

    class Route {

        private:
            Points points;
            double distance;

        public:
            void addPoint(const Point *point);
            void swap(const int *index_point_first, const int *index_point_seconde);
            double getDistance();
            Points getPoints();
    };
 
}

#endif