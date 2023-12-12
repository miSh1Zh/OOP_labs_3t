#include "Triangle.h"
#define FIG_SIDES 3

Triangle::Triangle(){
    _n = FIG_SIDES;
    _array = new Point[_n];
}

Triangle::Triangle(Point& pt1, Point& pt2, Point& pt3){
    _n = FIG_SIDES;
    _array = new Point[_n];
    _array[0] = pt1;
    _array[1] = pt2;
    _array[2] = pt3;
    if(!this->check_rot_ab()){
        throw logic_error("\nThis Triangle has no rotation ability\n");
    }
}

void Triangle::operator=(const Triangle& fig){
    _n = fig._n;
    _array = new Point[_n];
    for(size_t i{0}; i < _n; ++i){
        _array[i] = fig._array[i];
    }
}

void Triangle::operator=(Triangle&& fig) {
    _n = fig._n;
    _array = fig._array;
    fig._n = 0;
    fig._array = nullptr;
}

bool Triangle::operator==(const Triangle& fig) const{
    return static_cast<double>(*this) == static_cast<double>(fig);
}
