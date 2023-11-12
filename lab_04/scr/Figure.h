#pragma once

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>


class Figure
{
    public:
        using point = pair<T, T>;

        virtual point geom_cen() const = 0;
        virtual operator double() const = 0;
        virtual inline ostream& operator<<(ostream& os) const = 0;
        virtual inline istream& operator>>(istream& is) = 0;
};
