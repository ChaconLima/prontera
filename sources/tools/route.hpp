#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>
#include <tools/point.hpp>

namespace route {

    using namespace point;

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