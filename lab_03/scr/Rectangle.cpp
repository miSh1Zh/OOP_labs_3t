#include "Rectangle.h"
#define FIG_SIDES 4

Rectangle::Rectangle(){
    _n = FIG_SIDES;
    _array = new Point[_n];
}

Rectangle::Rectangle(Point& pt1, Point& pt2, Point& pt3, Point& pt4){
    _n = FIG_SIDES;
    _array = new Point[_n];
    _array[0] = pt1;
    _array[1] = pt2;
    _array[2] = pt3;
    _array[3] = pt4;
    if(!this->check_rot_ab()){
        throw logic_error("\nThis Rectangle has no rotation ability\n");
    }
}

void Rectangle::operator=(const Rectangle& fig){
    _n = fig._n;
    _array = new Point[_n];
    for(size_t i{0}; i < _n; ++i){
        _array[i] = fig._array[i];
    }
}

void Rectangle::operator=(Rectangle&& fig) {
    _n = fig._n;
    _array = fig._array;
    fig._n = 0;
    fig._array = nullptr;
}

bool Rectangle::operator==(const Rectangle& fig) const{
    return static_cast<double>(*this) == static_cast<double>(fig);
}
