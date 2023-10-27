#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#pragma once
class Rectangle : public Figure{
    public:
        Rectangle();
        Rectangle(Point& pt1, Point& pt2, Point& pt3, Point& pt4);
        string get_type() const override{
            return "Rectangle";
        }

        void operator=(const Rectangle& fig);
        void operator=(Rectangle&& fig);
        bool operator==(const Rectangle& fig) const;

        ~Rectangle(){
            _n = 0;
            delete[] _array;
            _array = nullptr;
        } 
};

#endif
