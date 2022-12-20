#ifndef MATRIX_DISTANCE_HPP
#define MATRIX_DISTANCE_HPP

#include<string>
#include<tools/direction.hpp>
#include<tools/point.hpp>

namespace matrix_distance{

    using namespace std;
    using namespace direction;
    using namespace point;
    
    class MatrixDistance {
        private:
            Directions directions;
            const Points points;
            const string engine;
            void crateDirections();
            double haversine(const Point *origin, const Point *destination);
            string generationKey(const Point *origin, const Point *destination);
            string doubleToString(const double *dbl);

        public:
            MatrixDistance(const Points *points, const string *engine);
            Direction getDirection(const Point *origin, const Point *destination);
            
    };
    
}
#endif
