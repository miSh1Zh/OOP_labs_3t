#include "eleven.h"


static size_t get_dec(const unsigned char t){
    if(t<='9' and t>='0') return t-'0';
    return 10;
}

static unsigned char get_ch(size_t t){
    if(t%11 < 10) return t+'0';
    return 'a';
}

Eleven::Eleven() : _size(0), _array{nullptr}{}

Eleven::Eleven(const size_t &n, unsigned char t)
{
    if(n == 0) throw logic_error("no number was given");
    if(not((t<='9' and t>='0') or t == 'a' or t == 'A')) throw logic_error("11-decimal number");
    else{
        _array = new unsigned char[n];
        for (size_t i = 0; i < n; ++i)
            _array[i] = t;
        _size = n;
    }
}

Eleven::Eleven(const initializer_list<unsigned char> &t)
{   
    if(t.size() == 0) throw logic_error("no number was given");
    _array = new unsigned char[t.size()];
    size_t i{t.size()-1};
    for (auto c : t)
        if((c<='9' and c>='0') or c == 'a' or c == 'A') _array[i--] = c;
        else throw logic_error("11-decimal number");
    _size = t.size();

    for(size_t i = _size - 1; _array[i] == '0' and i > 0; --i){
        _size--;
    }
}

Eleven::Eleven(const string &t)
{
    if(t.size() == 0) throw logic_error("no number was given");
    else{
        _array = new unsigned char[t.size()];
        _size  = t.size();

        for(size_t i{0}; i < _size; ++i){
            if((t[_size - 1 - i]<='9' and t[_size - 1 - i]>='0') or t[_size - 1 - i] == 'a' or t[_size - 1 - i] == 'A')_array[i] = t[_size - 1 - i];
            else throw logic_error("11-decimal number");
        }

        for(size_t i = _size - 1; _array[i] == '0' and i > 0; --i){
            _size--;
    }
    }
}

Eleven::Eleven(const Eleven &other)
{
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
}

Eleven::Eleven(Eleven &&other) noexcept
{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Eleven::~Eleven() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

size_t Eleven::get_size() const{
    return _size;
}

unsigned char *Eleven::get_array_ptr() const{
    return _array;
}

bool Eleven::equal(const Eleven &other) const
{
    bool eq{false};
    if(_size==other._size){
        size_t tmp{_size};
        eq = true;
        while(tmp){
            eq = (get_dec(_array[tmp-1]) == get_dec(other._array[tmp-1])) and eq;
            tmp--;
        }
    }
    return eq;
}

bool Eleven::less(const Eleven &other) const
{
    bool approved = false;
    
    if(not(this->equal(other)) and (this->_size <= other._size)){
        approved = true;
        size_t min_size = other._size;
        if(min_size == this->_size){
            for(size_t i{1}; (i <= min_size) and approved; ++i){
                approved = approved and (get_dec(this->_array[min_size - i]) <= get_dec(other._array[min_size - i]));
            }
        }
    }

    return approved;
}

bool Eleven::greater(const Eleven &other) const
{
    return not(this->equal(other) or this->less(other));
}

Eleven Eleven::assign(const Eleven& other){
    this->_size = other._size;
    for(size_t i{0}; i < other._size; ++i){ 
        this->_array[i] = other._array[i];
    }
    return *this;
}

Eleven Eleven::add(const Eleven &other)
{   
    size_t max_size = (this->greater(other))?_size:other._size;
    size_t min_size = (this->less(other))?_size:other._size;

    if(max_size == 0) throw logic_error("nothing to do");

    size_t tmp {0}, rest {0};

    Eleven res(max_size+1, '0'); 
    
    for(size_t i{0}; i < min_size; ++i){
        tmp = rest + get_dec(_array[i]) + get_dec(other._array[i]);
        rest = tmp / 11;
        res._array[i] = get_ch(tmp%11);
    }
    for(size_t i{min_size}; i < max_size; ++i){
        tmp = rest + get_dec((this->greater(other))?_array[i]:other._array[i]);
        rest = tmp / 11;
        res._array[i] = get_ch(tmp%11);
    }
    if(rest){
        res._array[max_size] = get_ch(rest);
    }else{
        --res._size;
    }

    this->assign(res);

    return *this;
}

Eleven Eleven::deduct(const Eleven &other)
{
    if(this->less(other)){
        throw logic_error("11-decimal number can't be negative (by task)");
    }else{
        int tmp {0}, rest {0};
        for(size_t i{0}; i < other._size; ++i){
            tmp = get_dec(_array[i]) - get_dec(other._array[i]) - rest;
            if(tmp < 0){
                rest = 1;
                tmp = 11 + tmp;
            }else{
                rest = 0;
            }
            _array[i] = get_ch(tmp);
        }
        size_t i{other._size};
        while(rest){
            tmp = get_dec(_array[i]) - rest;
            if(tmp < 0){
                rest = 1;
                tmp = 11 + tmp;
            }else{
                rest = 0;
            }
            _array[i] = get_ch(tmp); 
            ++i;
        }
        i = _size - 1;
        while(_array[i] == '0' and i > 0){
            --_size;
            --i;
        }
    }
    return *this;
}

std::ostream &Eleven::print(std::ostream &os)
{   
    for (size_t i = 1; i <= _size; ++i)
        os << _array[_size - i];
    return os;
}
