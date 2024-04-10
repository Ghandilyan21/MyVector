#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <iostream>

namespace tmm{

template <typename T>
class allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;
    
    allocator() = default;
    ~allocator() = default;

    T* allocate(std::size_t n);
    void deallocate(T* p, std::size_t n);
    std::size_t max_size() const;
    template <typename... Args>
    void construct(T* p, Args&&... args);
    void destroy(T* p);
};   
}
#include "allocator.tpp"
#endif