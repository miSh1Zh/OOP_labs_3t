#include "Point.h"

int Point::get_dist_to(Point& other) const{
    return round(sqrt(pow(x_pnt - other.x_pnt, 2) + pow(y_pnt - other.y_pnt, 2)));
}

void Point::operator=(Point& other){
    x_pnt = other.x_pnt;
    y_pnt = other.y_pnt;
}

bool Point::operator==(Point& other) const{
    return ((x_pnt == other.x_pnt) and (y_pnt == other.y_pnt));
}
