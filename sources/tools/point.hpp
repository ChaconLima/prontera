#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <vector>

namespace point{

    struct Point
    {
        std::string name;
        int id;
        double latitude;
        double longitude;
    };
    using Points = std::vector<Point>;
}

#endif