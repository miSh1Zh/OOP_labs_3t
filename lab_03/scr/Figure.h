#ifndef FIGURE_H
#define FIGURE_H

#pragma once
#include "Point.h"

class Figure{
    public:
        virtual string get_type() const = 0;
        bool check_rot_ab() const;
        operator double() const;
        Point geometrical_centre() const;
        friend std::istream& operator>>(std::istream& is, Figure& fig);
        friend std::ostream& operator<<(std::ostream& os, Figure *fig);

        size_t size() const{
            return _n;
        }
        Point* get_array() const{
            return _array;
        };
        virtual ~Figure() = default;
    
    protected: 
        size_t _n;
        Point* _array;
};

inline std::istream& operator>>(std::istream& is, Figure& fig) {
    std::cout << "Please type in coordinates of points in " << fig.get_type() << " (Ex: <x_val> <y_val>)\n";
    for (int i = 0; i < fig.size(); i++) {
        std::cout << "Point " << i + 1 << ": "; 
        is >> fig.get_array()[i].x_pnt >> fig.get_array()[i].y_pnt;
    }
    return is;
}

inline std::ostream& operator<<(std::ostream& os, Figure *fig) {
    os << "Coordinates of " << fig->get_type() << ":\n";
    for (int i = 0; i < fig->size(); i++) {
        os << "Point " << i + 1 << ": " << '(' << fig->get_array()[i].x_pnt << ", " << fig->get_array()[i].y_pnt << ')' << '\n';
    }
    return os;
}

#endif // FIGURE_H
