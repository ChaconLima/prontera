#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>
#include "point.hpp"

namespace route {

    using namespace point;

    class Route {

        private:
            Points points;
            double distance;

        public:
            Route();
            void addPoint(const Point *point);
            void swap(const int *index_point_first, const int *index_point_seconde);
            void setDistance(const double *distance);
            double getDistance();
            Points getPoints();
    };
 
}

#endif