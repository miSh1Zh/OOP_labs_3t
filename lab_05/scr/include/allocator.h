#pragma once 

#include <iostream>
#include <memory>
#include <list>
#include <deque>

using std::deque;

namespace My_Allocator {
    template <class T, size_t SIZE_B = 50000>
    class Allocator {
    public:
        static constexpr size_t max_count = SIZE_B;
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;

        Allocator() {   
            _used_blocks.resize(max_count);
            _free_blocks.resize(max_count);
            for (size_t i = 0; i < max_count; i++) {
                _free_blocks[i] = &_used_blocks[i];
            }
            _free_count = max_count;
        }

        ~Allocator() {
        #ifdef DEBUG
            if (_free_count < max_count)
                std::cout << "allocator: Memory leak?" << std::endl;
            else
                std::cout << "allocator: Memory freed" << std::endl;
        #endif
        }

        template <class U>
        struct rebind {
            using other = Allocator<U>;
        };

        T *allocate(size_t n) {
            T *result = nullptr;
            if (_free_count > 0) {
                result = (pointer)_free_blocks[--_free_count];
            }
            else {
                throw std::logic_error("allocator: No memory exception :-)");
            }
            return result;
        }

        void deallocate(pointer pnt, size_t) {
#ifdef DEBUG
            std::cout << "allocator: Deallocate block " << std::endl;
#endif      
            if (_free_count + 1 >= max_count) {
                return; 
            }
            _free_blocks[_free_count++] = pnt;
        }
        template <typename U, typename... Args>
        void construct(U *p, Args &&...args) {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p) {
            p->~T();
        }
        private:
        deque<value_type> _used_blocks;
        deque<pointer> _free_blocks;
        size_t _free_count;
    }; 

    template <class T, class U>
    constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) {
        return &lhs == &rhs;
    }

    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs) {
        return not(lhs == rhs);
    }
}