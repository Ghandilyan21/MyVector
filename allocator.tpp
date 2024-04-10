// #include "allocator.hpp"

template <typename T>
std::size_t tmm::allocator<T>::max_size() const
{
    return (static_cast<std::size_t>(-1) / sizeof(T));
}

template <typename T>
T* tmm::allocator<T>::allocate(std::size_t n)
{
    if (n > max_size())
    {
        throw std::bad_alloc();
    }
    return static_cast<T*>(::operator new(n * sizeof(T)));
}
template <typename T>
void tmm::allocator<T>::deallocate(T* p, std::size_t n)
{
    ::operator delete(p);
}

template <typename T>
template <typename... Args>
void tmm::allocator<T>::construct(T* p, Args&&... args)
{
    ::new(p) T(std::forward<Args>(args)...);
}

template <typename T>
void tmm::allocator<T>::destroy(T* p)
{
    p->~T();
}


