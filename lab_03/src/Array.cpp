#include "Array.h"

void Array::push_back(Figure* fig){
    if(!fig->check_rot_ab()) return;
    size_t new_size = _size+1;
    Figure** tmp = new Figure*[new_size];
    for(size_t i{0}; i < _size; ++i){
        tmp[i] = _array[i];
    }
    tmp[_size] = fig;
    if(tmp!= nullptr){
        _array = tmp;
        _size = new_size;
    } 
}

Figure* Array::pop_by_ind(size_t ind){
    Figure* fig;
    if(ind >= _size){
        throw logic_error("No figure so high (try lower index)");
    }
    else{
        size_t new_size = _size-1;
        Figure** tmp = new Figure*[new_size];
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