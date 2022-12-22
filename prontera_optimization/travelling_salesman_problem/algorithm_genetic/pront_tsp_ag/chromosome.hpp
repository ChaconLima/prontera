#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include<prontools/prontools.hpp>

namespace chromosome{

    using namespace point;
    using namespace matrix_distance;

    class Chromosome {

        private:
            Points points;
            void createRandomChromosome();

        public:

           
            Points getPoints();
          
    };   
}

#endif