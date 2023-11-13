#include "Figure.h"
#pragma once


template <typename T>

class Triangle : public Figure<T>
{
    public:
        using point = pair<T, T>;
        point pnt1, pnt2, pnt3;
        T side;

        Triangle()
        {
            //X
            pnt1.first = 0;
            pnt2.first = 0;
            pnt3.first = 0;
            //Y
            pnt1.second = 0;
            pnt2.second = 0;
            pnt3.second = 0;

            side = 0;
        }

        Triangle(point first, point second, point third)
        {
            bool check = (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2)))) and (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(first.first - third.first, 2) + pow(first.second - third.second, 2))));
            if(check){
                //X
                pnt1.first = first.first;
                pnt2.first = second.first;
                pnt3.first = third.first;
                //Y
                pnt1.second = first.second;
                pnt2.second = second.second;
                pnt3.second = third.second;

                side = abs(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2)));
            }else{
                throw logic_error("Try another points (or check given order)");
            }
        }

        virtual point geom_cen() const override
        {
            point result;
            result.first = (pnt1.first + pnt2.first + pnt3.first)/3;
            result.second = (pnt1.second + pnt2.second + pnt3.second)/3;
            return result;

        }
        virtual operator double() const override
        {
            return static_cast<double>(side*side*sqrt(3)/4);
        }
        virtual inline ostream& operator<<(ostream& os) const override
        {
            os << "Points of Triangle:";
            os << "\nPoint 1: (" << pnt1.first << ", " << pnt1.second << ")";
            os << "\nPoint 2: (" << pnt2.first << ", " << pnt2.second << ")";
            os << "\nPoint 3: (" << pnt3.first << ", " << pnt3.second << ")";
            return os;
        }
        virtual inline istream& operator>>(istream& is) override
        {
            point first, second, third;
            cout << "Please type in coordinates of points in Triangle(Ex: <x_val> <y_val>):";
            cout << "\nPoint 1: "; is >> first.first >> first.second;
            cout << "Point 2: "; is >> second.first >> second.second;
            cout << "Point 3: "; is >> third.first >> third.second;
            
            bool check = (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2)))) and (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(first.first - third.first, 2) + pow(first.second - third.second, 2))));
            if(check){
                //X
                pnt1.first = first.first;
                pnt2.first = second.first;
                pnt3.first = third.first;
                //Y
                pnt1.second = first.second;
                pnt2.second = second.second;
                pnt3.second = third.second;

                side = abs(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2)));
            }else{
                throw logic_error("Try another points (or check given order)");
            }
            return is;
        }

        void operator=(const Triangle<T>& fig)
        {
            //X
            pnt1.first = fig.pnt1.first;
            pnt2.first = fig.pnt2.first;
            pnt3.first = fig.pnt3.first;
            //Y
            pnt1.second = fig.pnt1.second;
            pnt2.second = fig.pnt2.second;
            pnt3.second = fig.pnt3.second;

            side = fig.side;
        }
        bool operator==(const Triangle<T>& other) const
        {
            return round(static_cast<double>(*this)) == round(static_cast<double>(other));
        }
};
