#include "Figure.h"
#pragma once 

template <typename T>

class Square : public Figure<T>
{
    public:
        using point = pair<T, T>;
        point pnt1, pnt2, pnt3, pnt4;
        T side;

        Square()
        {
            //X
            pnt1.first = 0;
            pnt2.first = 0;
            pnt3.first = 0;
            pnt4.first = 0;
            //Y
            pnt1.second = 0;
            pnt2.second = 0;
            pnt3.second = 0;
            pnt4.second = 0;

            side = 0;
        }

        Square(point first, point second, point third, point fourth)
        {
            bool check = (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2)))) and (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(fourth.first - third.first, 2) + pow(fourth.second - third.second, 2))));
            if(check){
                //X
                pnt1.first = first.first;
                pnt2.first = second.first;
                pnt3.first = third.first;
                pnt4.first = fourth.first;
                //Y
                pnt1.second = first.second;
                pnt2.second = second.second;
                pnt3.second = third.second;
                pnt4.second = fourth.second;

                side = abs(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2)));
            }else{
                throw logic_error("Try another points (or check given order)");
            }
        }

        virtual point geom_cen() const override
        {
            point result;
            result.first = (pnt1.first + pnt2.first + pnt3.first + pnt4.first)/4;
            result.second = (pnt1.second + pnt2.second + pnt3.second + pnt4.second)/4;
            return result;

        }
        virtual operator double() const override
        {
            return static_cast<double>(side*side);
        }
        virtual inline ostream& operator<<(ostream& os) const override
        {
            os << "Points of Square:";
            os << "\nPoint 1: (" << pnt1.first << ", " << pnt1.second << ")";
            os << "\nPoint 2: (" << pnt2.first << ", " << pnt2.second << ")";
            os << "\nPoint 3: (" << pnt3.first << ", " << pnt3.second << ")";
            os << "\nPoint 4: (" << pnt4.first << ", " << pnt4.second << ")";
            return os;
        }
        virtual inline istream& operator>>(istream& is) override
        {
            point first, second, third, fourth;
            cout << "Please type in coordinates of points in Square(Ex: <x_val> <y_val>)";
            cout << "\nPoint 1: "; is >> first.first >> first.second;
            cout << "Point 2: "; is >> second.first >> second.second;
            cout << "Point 3: "; is >> third.first >> third.second;
            cout << "Point 4: "; is >> fourth.first >> fourth.second;
            
            bool check = (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2)))) and (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) == round(sqrt(pow(fourth.first - third.first, 2) + pow(fourth.second - third.second, 2))));
            if(check){
                //X
                pnt1.first = first.first;
                pnt2.first = second.first;
                pnt3.first = third.first;
                pnt4.first = fourth.first;
                //Y
                pnt1.second = first.second;
                pnt2.second = second.second;
                pnt3.second = third.second;
                pnt4.second = fourth.second;

                side = abs(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2)));
            }else{
                throw logic_error("Try another points (or check given order)");
            }
            return is;
        }

        void operator=(const Square<T>& fig)
        {
            //X
            pnt1.first = fig.pnt1.first;
            pnt2.first = fig.pnt2.first;
            pnt3.first = fig.pnt3.first;
            pnt4.first = fig.pnt4.first;
            //Y
            pnt1.second = fig.pnt1.second;
            pnt2.second = fig.pnt2.second;
            pnt3.second = fig.pnt3.second;
            pnt4.second = fig.pnt4.second;
        }
        bool operator==(const Square<T>& other) const
        {
            return static_cast<double>(*this) == static_cast<double>(other);
        }
};
