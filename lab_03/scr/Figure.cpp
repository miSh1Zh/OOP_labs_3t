#include "Figure.h"


bool Figure::check_rot_ab() const {
    bool ability = true;
    for (int i = 0; i < _n; i++) {
        if (round(_array[i].get_dist_to(_array[(i + 1)%_n])) != round(_array[(i+2)%_n].get_dist_to(_array[(i+3)%_n]))) {
            throw logic_error{"That's not a correct figure!"};
            ability = false;
        }
    }
    if(this->get_type() == "Square"){
        if (round(_array[0].get_dist_to(_array[(1)])) != round(_array[(1)%_n].get_dist_to(_array[(2)%_n]))) {
            throw logic_error{"That's not a correct figure!"};
            ability = false;
        }
    }
    return ability;
}

Point Figure::geometrical_centre() const {
    
    if(!this->check_rot_ab()) return Point(1e8, 1e8);
    Point result(0, 0);
    for (size_t i{0}; i < _n; i++) {
        //cout << _array[i].x_pnt << ' ' << _array[i].y_pnt << '\n';
        result.x_pnt += _array[i].x_pnt;
        result.y_pnt += _array[i].y_pnt;
    }
    result.y_pnt = result.y_pnt / _n; 
    result.x_pnt = result.x_pnt / _n;
    //cout << result.x_pnt << ' ' << result.y_pnt << '\n';
    return result;
}

Figure::operator double() const {
    if(this->check_rot_ab()) return round(_n * _array[1].get_dist_to(_array[0]) * _array[2].get_dist_to(_array[1]) / 4) * (1 / tan(M_PI / _n));
}
