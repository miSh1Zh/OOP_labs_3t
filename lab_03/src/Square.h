#ifndef SQUARE_H
#define SQUARE_H
#include "Figure.h"
#pragma once
class Square : public Figure{
    public:
        Square();
        Square(Point& pt1, Point& pt2, Point& pt3, Point& pt4);
        string get_type() const override{
            return "Square";
        }

        void operator=(const Square& fig);
        void operator=(Square&& fig);
        bool operator==(const Square& fig) const;

        ~Square(){
            _n = 0;
            delete[] _array;
            _array = nullptr;
        } 
};

#endif
