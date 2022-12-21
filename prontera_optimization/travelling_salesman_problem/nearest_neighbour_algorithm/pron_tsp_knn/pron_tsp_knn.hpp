#ifndef PRON_TSP_KNN_HPP
#define PRON_TSP_KNN_HPP

#include <prontools/matrix_distance.hpp>
#include <prontools/route.hpp>

namespace pron_tsp_knn { 

    struct ReturnVisited {
        int index;
        point::Point point;
        direction::Direction direction;
    };
    
    class PronTspKnn {
        private:
            matrix_distance::MatrixDistance matrixDistance;
            ReturnVisited getNewNeighbor(const point::Point *initial, const point::Points &pointsToBeVisited);
            route::Route algorithmTspKnn();
        public:
            route::Route runTspKnn();
            PronTspKnn(const matrix_distance::MatrixDistance *matrixDistance);
    };
}

#endif