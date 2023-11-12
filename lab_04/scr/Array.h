#pragma once
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

#include <memory>
#include <vector>
// //#include </usr/local/Cellar/gcc/13.2.0/include/c++/13/concepts>
// // #include <type_traits>

template <typename T>

// concept Arrayable = std::is_default_constructible<T>::val;
// template <Arrayable T>



class Array
{
    public:
        size_t _size;
        shared_ptr<T[]> _array;

        Array() : _size(0), _array(nullptr){}
        Array(const initializer_list<T>& list){
            shared_ptr<T[]> new_array = make_shared<T[]>(new T[list.size()]);
            size_t i{0};
            for(auto& elem : list){
                new_array[i] = elem;
                ++i;
            }
            if(new_array != nullptr){
                _array = new_array;
                _size = list.size();
            }
        }
        void push_back(T elem){
            size_t new_size = _size+1;
            shared_ptr<T[]> new_array = make_shared<T[]>(new T[new_size]);
            for(size_t i{0}; i < _size; ++i){
                new_array[i] = _array[i];
            }
            new_array[_size] = elem;
            if(new_array != nullptr){
                _array = new_array;
                _size = new_size;
            } 
        }
        T pop_by_ind(size_t ind){
            T fig;
            if(ind >= _size){
                throw logic_error("No elem so high (try lower index)");
            }
            if(ind < 0){
                throw logic_error("Negative index");
            }
            else{
                size_t new_size = _size-1;
                shared_ptr<T[]> tmp = make_shared<T[]>(new T[new_size]);
                for(size_t i{0}; i < ind; ++i){
                    tmp[i] = _array[i];
                }
                fig = _array[ind];
                for(size_t i{ind}; i < new_size; ++i){
                    tmp[i] = _array[i+1];
                }
                if(tmp!= nullptr){
                    _array = tmp;
                    _size = new_size;
                } 
            }
            return fig;
        }

        ~Array(){
            if(_size > 0){
                _size = 0;
                delete[] _array;
                _array = nullptr;
            }
        }
};


template <typename T>
class my_Array
{
    public:
        size_t _size;
        vector<T> _array;

        my_Array() : _size(0), _array(){}
        my_Array(const initializer_list<T>& list){
            vector<T> new_array;
            for(auto& elem : list){
                new_array.push_back(elem);
            }
            _array = new_array;
            _size = list.size();
        }
        void push_back(T elem){
            _array.push_back(elem);
            _size = _array.size();
        }
        T pop_by_ind(size_t ind){
            T fig;
            if(ind >= _size){
                throw logic_error("No elem so high (try lower index)");
            }
            if(ind < 0){
                throw logic_error("Negative index");
            }
            else{
                size_t new_size = _size-1;
                vector<T> tmp;
                for(size_t i{0}; i < ind; ++i){
                    tmp.push_back(_array[i]);
                }
                fig = _array[ind];
                for(size_t i{ind}; i < new_size; ++i){
                    tmp.push_back(_array[i+1]);
                }
                _array = tmp;
                _size = new_size;
            }
            return fig;
        }
        T get_by_ind(size_t ind){
            T fig;
            if(ind >= _size){
                throw logic_error("No elem so high (try lower index)");
            }
            if(ind < 0){
                throw logic_error("Negative index");
            }
            else{
                fig = _array[ind];
            }
            return fig;
        }

        ~my_Array() = default;
};