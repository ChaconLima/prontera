#include "../prontools/random.hpp"
#include <stdlib.h>
#include <chrono>
#include <stdio.h>
#include <time.h>

namespace pron_random {

    Random::Random(){
        this->seed = 0;
        this->rng = gsl_rng_alloc(gsl_rng_ranlxs2);
        gsl_rng_set(this->rng, std::chrono::system_clock::now().time_since_epoch().count());
    }

    void Random::endProcess(){
        gsl_rng_free(this->rng);
    }

    int Random::getRandomInt(const unsigned long int *valueMax){
        return gsl_rng_uniform_int(this->rng, *valueMax);
    }
    double Random::getRandomPercent(){
        return gsl_rng_uniform(this->rng);
    }
    
    bool Random::getRandomBool(){
        if(gsl_rng_uniform_int(this->rng,2) == 1){
            return true;
        }

        return false;
    }
}