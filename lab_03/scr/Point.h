#pragma once
#include <string>
#include <string_view>
#include <iostream>
#include <cmath>

using namespace std;

class Point{
    public:
        Point() = default;
        Point(int x, int y) : x_pnt(x), y_pnt(y) {}
        
        int get_dist_to(Point& other) const;

        void operator=(Point& other);
        bool operator==(Point& other) const;
        
        ~Point() = default;
        int x_pnt, y_pnt;
};
