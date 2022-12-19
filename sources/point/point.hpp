#ifndef POINT_HPP
#define POINT_HPP

#include <string>

namespace point{

    struct Point
    {
        std::string name;
        int id;
        double latitude;
        double longitude;
    };
}

#endif