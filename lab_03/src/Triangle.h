#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Figure.h"
#pragma once
class Triangle : public Figure{
    public:
        Triangle();
        Triangle(Point& pt1, Point& pt2, Point& pt3);
        string get_type() const override{
            return "Triangle";
        }

        void operator=(const Triangle& fig);
        void operator=(Triangle&& fig);
        bool operator==(const Triangle& fig) const;

        ~Triangle(){
            _n = 0;
            delete[] _array;
            _array = nullptr;
        } 
};

#endif
