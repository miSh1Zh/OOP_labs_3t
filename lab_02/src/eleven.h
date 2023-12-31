#pragma onces

#include <string>
#include <iostream>

using namespace std;

class Eleven
{
    public:
    
        Eleven();
        Eleven(const size_t & n, unsigned char t = 0);
        Eleven(const std::initializer_list< unsigned char> &t);
        Eleven(const std::string &t);
        Eleven(const Eleven& other);
        Eleven(Eleven&& other) noexcept;

        size_t get_size() const;
        unsigned char *get_array_ptr() const;

        Eleven assign(const Eleven& other);
        Eleven add(const Eleven& other);
        Eleven deduct(const Eleven& other);
        bool equal(const Eleven& other) const;
        bool greater(const Eleven &other) const;
        bool less(const Eleven &other) const;
        std::ostream& print(std::ostream& os);
        
        virtual ~Eleven() noexcept;
    
    private:
        size_t _size;
        unsigned char *_array;

};

