#ifndef VECTOR_TPP
#define VECTOR_TPP

template<class T, class Allocator>
using Const_iterator = typename tmm::vector<T, Allocator>::const_iterator;
template<class T, class Allocator>
using Iterator = typename tmm::vector<T, Allocator>::iterator;
template<class T, class Allocator>
using Reverce_iterator = typename tmm::vector<T, Allocator>::reverse_iterator;
template<class T, class Allocator>
using Const_reverce_iterator = typename tmm::vector<T, Allocator>::const_reverse_iterator;

// const_iterator implementation
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_iterator::const_iterator()
    :   ptr{nullptr}
{
   
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_iterator::const_iterator(pointer p)
    :   ptr{p}
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_iterator::const_iterator(const const_iterator& rhv)
    :   ptr{rhv.ptr}
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_iterator::const_iterator(const_iterator&& rhv)
    :   ptr{rhv.ptr}
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_iterator::~const_iterator()
{
    ptr = nullptr;
}
// Assignment operators
template<class T, class Allocator>
const Const_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_iterator::operator=(const const_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}
template<class T, class Allocator>
const Const_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_iterator::operator=(const_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::const_iterator::operator*() const
{
    return *ptr;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_pointer tmm::vector<T, Allocator>::const_iterator::operator->() const
{
    return ptr;
}
template<class T, class Allocator>
const Const_iterator<T, Allocator> tmm::vector<T, Allocator>::const_iterator::operator+(size_type val) const
{
    return const_iterator(ptr + val);
}
template<class T, class Allocator>
const Const_iterator<T, Allocator> tmm::vector<T, Allocator>::const_iterator::operator-(size_type val) const
{
    return const_iterator(ptr - val);
}      
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_iterator& tmm::vector<T, Allocator>::const_iterator::operator+=(size_type val)
{
    ptr += val;
    return *this;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_iterator& tmm::vector<T, Allocator>::const_iterator::operator-=(size_type val)
{
    ptr -= val;
    return *this;
}
template<class T, class Allocator>
const Const_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_iterator::operator++()
{
    ++ptr;
    return *(this);
}
template<class T, class Allocator>
const Const_iterator<T, Allocator> tmm::vector<T, Allocator>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}
template<class T, class Allocator>
const Const_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_iterator::operator--()
{
    --ptr;
    return *(this);
}
template<class T, class Allocator>
const Const_iterator<T, Allocator> tmm::vector<T, Allocator>::const_iterator::operator--(int)
{
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::const_iterator::operator[](size_type ix) const
{
    return ptr[ix];
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_iterator::operator==(const const_iterator& rhv) const
{
    return ptr == rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_iterator::operator!=(const const_iterator& rhv) const
{
    return ptr != rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_iterator::operator<(const const_iterator& rhv) const
{
    return ptr < rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_iterator::operator>(const const_iterator& rhv) const
{
    return ptr > rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_iterator::operator<=(const const_iterator& rhv) const
{
    return ptr <= rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_iterator::operator>=(const const_iterator& rhv) const
{
    return ptr >= rhv.ptr;
}
// Iterator implementation
template<class T, class Allocator>
tmm::vector<T, Allocator>::iterator::iterator()
    :   tmm::vector<T, Allocator>::const_iterator()
{
    
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::iterator::iterator(pointer p)
    :   tmm::vector<T, Allocator>::const_iterator(p)
{
    
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::iterator::iterator(const iterator& rhv)
    :   tmm::vector<T, Allocator>::const_iterator(rhv)
{
    
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::iterator::iterator(iterator&& rhv)
    :   tmm::vector<T, Allocator>::const_iterator(rhv)
{
    
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::iterator::operator*()
{
    return *(this->ptr);
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::pointer tmm::vector<T, Allocator>::iterator::operator->() 
{
    return this->ptr;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::iterator::operator[](size_type ind) 
{
    return (this->ptr)[ind];
}
template<class T, class Allocator>
Iterator<T, Allocator> tmm::vector<T, Allocator>::iterator::operator+(size_type val)
{
    return iterator((this->ptr) + val);
}
template<class T, class Allocator>
Iterator<T, Allocator> tmm::vector<T, Allocator>::iterator::operator-(size_type val)
{
    return iterator((this->ptr) - val);
}      
template<class T, class Allocator>
Iterator<T, Allocator>& tmm::vector<T, Allocator>::iterator::operator+=(size_type val)
{
    (this->ptr) += val; 
    return *(this);
}
template<class T, class Allocator>
Iterator<T, Allocator>& tmm::vector<T, Allocator>::iterator::operator-=(size_type val)
{
    (this->ptr) -= val;
    return *(this);
}
template<class T, class Allocator>
Iterator<T, Allocator>& tmm::vector<T, Allocator>::iterator::operator++()
{
    ++(this->ptr);
    return *(this);
}
template<class T, class Allocator>
Iterator<T, Allocator> tmm::vector<T, Allocator>::iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}
template<class T, class Allocator>
Iterator<T, Allocator>& tmm::vector<T, Allocator>::iterator::operator--()
{
    --(this->ptr);
    return *(this);
}
template<class T, class Allocator>
Iterator<T, Allocator> tmm::vector<T, Allocator>::iterator::operator--(int)
{
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}
// reverce iterator implementation
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator()
    :   ptr{nullptr}
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(pointer p)
    :   ptr{p}
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv)
    :   ptr{rhv.ptr}
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(const_reverse_iterator&& rhv)
    :   ptr{rhv.ptr}
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reverse_iterator::~const_reverse_iterator()
{
    ptr = nullptr;
}
// Assignment operators
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_reverse_iterator::operator=(const const_reverse_iterator& rhv)
{
    ptr = rhv.ptr;
    return *this;
}
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_reverse_iterator::operator=(const_reverse_iterator&& rhv)
{
    ptr = rhv.ptr;
    return *this;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::const_reverse_iterator::operator*() const
{
    return *ptr;  
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_pointer tmm::vector<T, Allocator>::const_reverse_iterator::operator->() const
{
    return ptr;
}
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::const_reverse_iterator::operator+(size_type val) const
{
    return const_reverse_iterator(this->ptr - val);
}
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::const_reverse_iterator::operator-(size_type val) const
{
    return const_reverse_iterator(this->ptr + val);
}      
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reverse_iterator& tmm::vector<T, Allocator>::const_reverse_iterator::operator+=(size_type val)
{
    (this->ptr)-= val;
    return *this;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reverse_iterator& tmm::vector<T, Allocator>::const_reverse_iterator::operator-=(size_type val)
{
    (this->ptr) += val;
    return *this;
}
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_reverse_iterator::operator++()
{
    --ptr;
    return *(this);
}
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::const_reverse_iterator::operator++(int)
{
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator>& tmm::vector<T, Allocator>::const_reverse_iterator::operator--()
{
    ++ptr;
    return *(this);
}
template<class T, class Allocator>
const Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::const_reverse_iterator::operator--(int)
{
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::const_reverse_iterator::operator[](size_type ix) const
{
    return ptr[ix];
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_reverse_iterator::operator==(const const_reverse_iterator& rhv) const
{
    return ptr == rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhv) const
{
    return ptr != rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_reverse_iterator::operator<(const const_reverse_iterator& rhv) const
{
    return ptr < rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_reverse_iterator::operator>(const const_reverse_iterator& rhv) const
{
    return ptr > rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_reverse_iterator::operator<=(const const_reverse_iterator& rhv) const
{
    return ptr <= rhv.ptr;
}
template<class T, class Allocator>
bool tmm::vector<T, Allocator>::const_reverse_iterator::operator>=(const const_reverse_iterator& rhv) const
{
    return ptr >= rhv.ptr;
}
// reverce iterator implementation
template<class T, class Allocator>
tmm::vector<T, Allocator>::reverse_iterator::reverse_iterator()
    :   tmm::vector<T, Allocator>::const_reverse_iterator()
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::reverse_iterator::reverse_iterator(pointer p)
    :   tmm::vector<T, Allocator>::const_reverse_iterator(p)
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::reverse_iterator::reverse_iterator(const reverse_iterator& rhv)
    :   tmm::vector<T, Allocator>::const_reverse_iterator(rhv)
{

}
template<class T, class Allocator>
tmm::vector<T, Allocator>::reverse_iterator::reverse_iterator(reverse_iterator&& rhv)
    :   tmm::vector<T, Allocator>::const_reverse_iterator(rhv)
{

}
// Assignment operators
template<class T, class Allocator>
tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::reverse_iterator::operator*()
{
    return *(this->ptr);  
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::pointer tmm::vector<T, Allocator>::reverse_iterator::operator->()
{
    return (this->ptr);
}
template<class T, class Allocator>
Reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::reverse_iterator::operator+(size_type val)
{
    return reverse_iterator((this->ptr) - val);
}
template<class T, class Allocator>
Reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::reverse_iterator::operator-(size_type val)
{
    return reverse_iterator((this->ptr) + val);
}      
template<class T, class Allocator>
tmm::vector<T, Allocator>::reverse_iterator& tmm::vector<T, Allocator>::reverse_iterator::operator+=(size_type val)
{
    this->ptr -= val;
    return *this;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::reverse_iterator& tmm::vector<T, Allocator>::reverse_iterator::operator-=(size_type val)
{
    this->ptr += val;
    return *this;
}
template<class T, class Allocator>
Reverce_iterator<T, Allocator>& tmm::vector<T, Allocator>::reverse_iterator::operator++()
{
    --(this->ptr);
    return *(this);
}
template<class T, class Allocator>
Reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::reverse_iterator::operator++(int)
{
    reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}
template<class T, class Allocator>
Reverce_iterator<T, Allocator>& tmm::vector<T, Allocator>::reverse_iterator::operator--()
{
    ++(this->ptr);
    return *(this);
}
template<class T, class Allocator>
Reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::reverse_iterator::operator--(int)
{
    reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}
template<class T, class Allocator>
tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::reverse_iterator::operator[](size_type ix)
{
    return (this->ptr)[ix];
}
// Vector implementation
// Construction and Initialization
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::vector()
    :   m_size{}
    ,   m_capacity{}
    ,   m_arr{nullptr}
{
    
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::vector(const vector& rhs)
{
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_arr = m_allocator.allocate(m_capacity);
    for (size_type i = 0; i < m_size; ++i)
    {
        m_allocator.construct(m_arr + i, rhs.m_arr[i]);
    }
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::vector(vector&& rhs) noexcept
    :   m_size{rhs.m_size}
    ,   m_capacity{rhs.m_capacity}
    ,   m_arr{rhs.m_arr}
{
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    rhs.m_capacity = 0;
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::vector(std::initializer_list<T> list)
    :   m_size{list.size()}
    ,   m_capacity{m_size}
    ,   m_arr{m_allocator.allocate(list.size())}
{
    for(int i = 0; auto& val : list)
    {
        m_allocator.construct(m_arr + i, val);
        ++i;
    }    
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::~vector()
{
    clear();
    m_allocator.deallocate(m_arr, m_size);
}
// Assignment and Initialization
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>& tmm::vector<T, Allocator>::operator=(const vector& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    clear();
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_arr = m_allocator.allocate(m_capacity);
    for (size_type i = 0; i < m_size; ++i)
    {
        m_allocator.construct(m_arr + i, rhs.m_arr[i]);
    }
    return *this;
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>& tmm::vector<T, Allocator>::operator=(vector&& rhs)noexcept
{
    clear();
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_arr = rhs.m_arr;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    rhs.m_capacity = 0;
    return *this;
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>& tmm::vector<T, Allocator>::operator=(std::initializer_list<T> list)
{
    clear();
    m_size = list.size();
    m_capacity = m_size;
    m_arr = m_allocator.allocate(m_capacity); 
    for (size_t i = 0; auto& val : list)
    {
       m_allocator.construct(m_arr + i, val);
       ++i;
    }
    return *this;
}

template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::clear() noexcept
{
    for(std::size_t i = 0; i < m_size; ++i)
    {
        m_allocator.destroy(m_arr + i);
    }
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::assign(size_type n, const T& u)
{
    resize(n);
    for (size_t i = 0; i < m_size; ++i)
    {
        m_arr[i] = u;
    }
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::assign(std::initializer_list<T> list)
{
    resize(list.size());
    for (size_t i = 0; T val : list)
    {
        m_arr[i] = val;
        ++i;
    }
}
template <typename T, typename Allocator>
constexpr Iterator<T, Allocator> tmm::vector<T, Allocator>::begin() noexcept
{
    return tmm::vector<T, Allocator>::iterator(tmm::vector<T, Allocator>::m_arr);
}
template <typename T, typename Allocator>
constexpr Const_iterator<T, Allocator> tmm::vector<T, Allocator>::begin() const noexcept
{
    return tmm::vector<T, Allocator>::const_iterator(tmm::vector<T, Allocator>::m_arr);
}
template <typename T, typename Allocator>
constexpr Iterator<T, Allocator> tmm::vector<T, Allocator>::end() noexcept
{
    return  begin() + tmm::vector<T, Allocator>::m_size;
}
template <typename T, typename Allocator>
constexpr Const_iterator<T, Allocator> tmm::vector<T, Allocator>::end() const noexcept
{
    return  begin() + tmm::vector<T, Allocator>::m_size;
}
template <typename T, typename Allocator>
constexpr Reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::rbegin() noexcept
{
    return  tmm::vector<T, Allocator>::reverse_iterator(tmm::vector<T, Allocator>::m_arr + tmm::vector<T, Allocator>::m_size - 1);
}
template <typename T, typename Allocator>
constexpr Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::rbegin() const noexcept
{
    return  tmm::vector<T, Allocator>::const_reverse_iterator(tmm::vector<T, Allocator>::m_arr + tmm::vector<T, Allocator>::m_size - 1);
}
template <typename T, typename Allocator>
constexpr Reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::rend() noexcept
{
    return tmm::vector<T, Allocator>::reverse_iterator(tmm::vector<T, Allocator>::m_arr);
    return  rbegin() + tmm::vector<T, Allocator>::m_size;
}
template <typename T, typename Allocator>
constexpr Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::rend() const noexcept
{
    return tmm::vector<T, Allocator>::const_reverse_iterator(tmm::vector<T, Allocator>::m_arr);
}
template <typename T, typename Allocator>
constexpr Const_iterator<T, Allocator> tmm::vector<T, Allocator>::cbegin() const noexcept
{
    return tmm::vector<T, Allocator>::const_iterator(tmm::vector<T, Allocator>::m_arr);
}
template <typename T, typename Allocator>
constexpr Const_iterator<T, Allocator> tmm::vector<T, Allocator>::cend() const noexcept
{
    return  cbegin() + tmm::vector<T, Allocator>::m_size;
}
template <typename T, typename Allocator>
constexpr Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::crbegin() const noexcept
{
    return tmm::vector<T, Allocator>::const_reverse_iterator(tmm::vector<T, Allocator>::m_arr);
}
template <typename T, typename Allocator>
constexpr Const_reverce_iterator<T, Allocator> tmm::vector<T, Allocator>::crend() const noexcept
{
    return  cbegin() + tmm::vector<T, Allocator>::m_size;
}
// Capacity
template <typename T, typename Allocator>
[[nodiscard]] constexpr bool tmm::vector<T, Allocator>::empty() const noexcept
{
    return !m_size;
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::size_type tmm::vector<T, Allocator>::size() const
{
    return m_size;
}

template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::size_type tmm::vector<T, Allocator>::capacity() const noexcept 
{
    return m_capacity;
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::resize()
{
    m_capacity = m_capacity == 0? 1 : m_capacity *= 2;
    pointer tmp = m_allocator.allocate(m_capacity);
    for (size_type i = 0; i < m_size; ++i)
    {
        m_allocator.construct(tmp + i, m_arr[i]);
        m_allocator.destroy(m_arr + i);
    }
    m_allocator.deallocate(m_arr, m_size);
    m_arr = tmp;
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::resize(size_type sz)
{
    m_capacity = sz;
    pointer tmp = m_allocator.allocate(m_capacity);
    for (size_type i = 0; i < sz; ++i)
    {
        m_allocator.construct(tmp + i, m_arr[i]);
        
    }
    for (size_type i = 0; i < m_size; ++i)
    {
        m_allocator.destroy(m_arr + i);
    }
    m_allocator.deallocate(m_arr, m_size);
    m_size = sz;
    m_arr = tmp;
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::reverse()
{
    if (m_size <= 1)
    {
        return;
    }
    for (size_type i = 0; i < m_size / 2; ++i) {
        swap(m_arr[i], m_arr[m_size - i - 1]);
    }
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::shrink_to_fit()
{
    m_capacity = m_size;
    pointer mytmp = m_allocator.allocate(m_capacity);
    for (size_type i = 0; i < m_size; ++i)
    {
        m_allocator.construct(mytmp + i, m_arr[i]);
        m_allocator.destroy(m_arr + i);
    }
    m_allocator.deallocate(m_arr, m_size);
    m_arr = mytmp;
}
// Element Access
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::operator[](size_type index)
{
    return m_arr[index];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::operator[](size_type index) const
{
    return m_arr[index];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::at(size_type index) const
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("");
    }
    return m_arr[index];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::at(size_type index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("");
    }
    return m_arr[index];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::front()
{
    return m_arr[0];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::front() const
{
    return m_arr[0];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::reference tmm::vector<T, Allocator>::back()
{
    return m_arr[m_size - 1];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::const_reference tmm::vector<T, Allocator>::back() const
{
    return m_arr[m_size - 1];
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::pointer tmm::vector<T, Allocator>::data() noexcept
{
    return m_arr;
}
template <typename T, typename Allocator>
constexpr tmm::vector<T, Allocator>::const_pointer tmm::vector<T, Allocator>::data() const noexcept
{
    return m_arr;
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::push_back(const T& value)
{
    if (m_size == m_capacity)
    {
        resize();
    }
    m_arr[m_size] = value;
    ++m_size;
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::push_back(T&& value)   
{
    if (m_size == m_capacity)
    {
        resize();
    }
    m_arr[m_size] = std::move(value);
    ++m_size;
}
template <typename T, typename Allocator>
constexpr void tmm::vector<T, Allocator>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
    else
    {
        throw std::exception();
    }
}
#endif //VECTOR_TPP




