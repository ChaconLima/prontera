#include "../pron_tsp_knn/pron_tsp_knn.hpp"
#include <prontools/exception.hpp>
#include <stdint.h>
#include <iostream>

namespace pron_tsp_knn {

    using namespace matrix_distance;
    using namespace route;
    using namespace point;
    using namespace direction;
    using namespace std;
 
    PronTspKnn::PronTspKnn(const MatrixDistance *matrixDistance): matrixDistance(*matrixDistance){

    }

    ReturnVisited PronTspKnn::getNewNeighbor(const Point *initial, const Points &pointsToBeVisited) {
        ReturnVisited destination;
        double distanceFinal = INT64_MAX;

        for (size_t point_i = 0; point_i< pointsToBeVisited.size(); point_i++) {

            Point possibility = pointsToBeVisited[point_i];
            Direction direction = this->matrixDistance.getDirection(initial, &possibility);

            if( direction.distance < distanceFinal){
                destination.point = possibility;
                destination.direction = direction;
                destination.index = point_i;
                distanceFinal = direction.distance;
            }
        }

        return destination;
    }

    Route PronTspKnn::algorithmTspKnn(){
        Route route;
        Points pointsToBeVisited = this->matrixDistance.getPoints();
        double distance = 0;
        int stoppingLoop = pointsToBeVisited.size()+1;

        Point origin = pointsToBeVisited[0];
        Point current = origin;
        pointsToBeVisited.erase(pointsToBeVisited.begin() + 0);
        route.addPoint(&origin);

        int cont = 0;
        while (pointsToBeVisited.size() != 0) {
        
            if(cont>stoppingLoop) throw exception::Exception("Error in while nearest-neighbour-algorithm","PronTspKnn::runTspKnn()");

            const ReturnVisited destination = this->getNewNeighbor(&current, pointsToBeVisited);
            route.addPoint(&destination.point);
            pointsToBeVisited.erase(pointsToBeVisited.begin() + destination.index);

            distance+=destination.direction.distance;
            current = destination.point;
            cont++;
        }
        distance += this->matrixDistance.getDirection(&current, &origin).distance;

        route.addPoint(&origin);
        route.setDistance(&distance);

        return route;
    }

    Route PronTspKnn::runTspKnn() {
        try{
            return this->algorithmTspKnn();
        }
        catch(exception::Exception& e){
            std::cout << e.getClassName() << e.getClassName() << '\n';
            throw e;
        }
    }
}