#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <stdio.h>
#include <gsl/gsl_rng.h>

namespace pron_random {

    class Random {
        private:
            int seed;
            gsl_rng *rng;
            
        public:
            Random();
            int getRandomInt(const unsigned long int *valueMax);
            bool getRandomBool();
            double getRandomPercent();
            void endProcess();
    };
}

#endif