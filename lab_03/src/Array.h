#include"Triangle.h"
#include"Square.h"
#include"Rectangle.h"
#pragma once

class Array{
    public:
        Array(){
            _size = 0;
            _array = nullptr;
        }

        void push_back(Figure* fig);
        Figure* pop_by_ind(size_t ind);
        
        size_t size() const {return _size;}
        Figure** array() const {return _array;}

        ~Array(){
            _size = 0;
            delete[] _array;
            _array = nullptr;
        }
    private:
        size_t _size;
        Figure** _array;
};
