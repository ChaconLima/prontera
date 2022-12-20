#include "../route.hpp"
#include <bits/stdc++.h>

namespace route {

    double Route::getDistance(){
        return this->distance;
    } 

    Points Route::getPoints(){
        return this->points;
    }

    void Route::addPoint(const Point *point){
        this->points.push_back(*point);
    }

    void Route::swap(const int *index_point_first, const int *index_point_seconde){

        Point point_first = this->points[*index_point_first];
        Point point_seconde = this->points[*index_point_seconde];

        point_first.id = *index_point_seconde;
        point_seconde.id = *index_point_first;

        this->points[*index_point_first] = point_first;
        this->points[*index_point_seconde] = point_seconde;

        std::swap(this->points[*index_point_first], this->points[*index_point_seconde]);
    }
}


