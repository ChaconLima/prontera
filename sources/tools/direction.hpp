#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <string>
#include<map>

namespace direction{

    using namespace std;

    struct Direction {
        double distance;
    };

    using Directions = map<string,Direction>;
}

#endif