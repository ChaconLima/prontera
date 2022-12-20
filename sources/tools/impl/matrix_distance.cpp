#include "../matrix_distance.hpp"
#include <tools/exception.hpp>
#include <sstream>
#include <cmath>

namespace matrix_distance{

    using namespace exception;

    MatrixDistance::MatrixDistance(const Points *points, const string *engine): points(*points), engine(*engine) {
        this->crateDirections();
    }

    Direction MatrixDistance::getDirection(const Point *origin, const Point *destination){
        string key = this->generationKey(origin, destination);
        try {
            auto seach = this->directions.find(key);
            if(seach == this->directions.end()) throw invalid_argument("key:"+key+" not found");
            Direction direction;
            direction.distance = seach->second.distance;
            return direction;
        }
        catch(const std::exception& ex) {
            throw Exception(ex.what(),"MatrixDistance::getDirection");
        }
    }

    void MatrixDistance::crateDirections() {
        for (size_t origin = 0; origin < this->points.size(); origin++) {
            for (size_t destination = 0; destination < this->points.size(); destination++){
                Direction direction;
                string key = this->generationKey(&this->points[origin], &this->points[destination]);
                direction.distance = this->haversine(&this->points[origin], &this->points[destination]);
                this->directions[key] = direction;
            }
        }
    }

    string MatrixDistance::generationKey(const Point *origin, const Point *destination){
        return this->doubleToString(&origin->latitude)+"-"+this->doubleToString(&origin->longitude)+":"+this->doubleToString(&destination->latitude)+"-"+this->doubleToString(&destination->longitude);
    }

    double MatrixDistance::haversine(const Point *origin, const Point *destination) {
        double lat1 = origin->latitude, lon1 = origin->longitude, lat2=destination->latitude, lon2 = destination->longitude;
        double dLat = (lat2 - lat1) * M_PI / 180.0;
        double dLon = (lon2 - lon1) * M_PI / 180.0;
        lat1 = (lat1) * M_PI / 180.0;
        lat2 = (lat2) * M_PI / 180.0;
        double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
        double rad = 6371;
        double c = 2 * asin(sqrt(a));
        return rad * c;
    }

    string MatrixDistance::doubleToString(const double *dbl) {
        std::ostringstream strs;
        strs << *dbl;
        std::string str = strs.str();
        return str;
    }
}