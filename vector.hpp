#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "allocator.hpp"

namespace tmm 
{
  template<typename T, typename Allocator = tmm::allocator<T>>
  class vector 
  {
  public:
    // types
    using value_type             = T;
    using pointer                = T*;
    using const_pointer          = const pointer;
    using reference              = value_type&;
    using const_reference        = const value_type&;
    using size_type              = std::size_t;
    using allocator_type         = Allocator;
   public:    
    class const_iterator 
    {
        friend class vector<value_type, Allocator>;
    public:
      using value_type             = T;
      using pointer                = T*;
      using const_pointer          = const pointer;
    protected:
        pointer ptr;
        explicit const_iterator(pointer ptr);
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        const_iterator(const_iterator&& rhv);
        ~const_iterator();

        const const_iterator& operator=(const const_iterator& rhv);
        const const_iterator& operator=(const_iterator&& rhv);
        const_reference operator*() const;
        const_pointer operator->() const;

        const const_iterator operator+(size_type val) const;
        const const_iterator operator-(size_type val) const;
        const_iterator& operator-=(size_type val);
        const_iterator& operator+=(size_type val);
        const const_iterator& operator++();
        const const_iterator operator++(int);
        const const_iterator& operator--();
        const const_iterator operator--(int);

        const_reference operator[](size_type ind) const;

        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
        bool operator<(const const_iterator& rhv) const;
        bool operator>(const const_iterator& rhv) const;
        bool operator<=(const const_iterator& rhv) const;
        bool operator>=(const const_iterator& rhv) const;
    };

    class iterator : public const_iterator {
      friend class vector<value_type, Allocator>;
    protected:
        explicit iterator(pointer ptr);
    public:
        iterator();
        iterator(const iterator& rhv);
        iterator(iterator&& rhv);
        
        iterator operator+(size_type val);
        iterator operator-(size_type val);
        iterator& operator-=(size_type val);
        iterator& operator+=(size_type val);
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);

        reference operator*();
        pointer operator->();
        reference operator[](size_type ind);
    };

public:    
    class const_reverse_iterator {
        friend class vector<value_type, Allocator>;
    private:
        pointer ptr;
    protected:
        explicit const_reverse_iterator(pointer ptr);
    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv);
        const_reverse_iterator(const_reverse_iterator&& rhv);

        ~const_reverse_iterator();

        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv);
        const const_reverse_iterator& operator=(const_reverse_iterator&& rhv);

        const_reference operator*() const;
        const_pointer operator->() const;

        const const_reverse_iterator operator+(size_type val) const;
        const const_reverse_iterator operator-(size_type val) const;
        const_reverse_iterator& operator-=(size_type val);
        const_reverse_iterator& operator+=(size_type val);
        const const_reverse_iterator& operator++();
        const const_reverse_iterator operator++(int);
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator--(int);

        const_reference operator[](size_type ind) const;

        bool operator==(const const_reverse_iterator& rhv) const;
        bool operator!=(const const_reverse_iterator& rhv) const;
        bool operator<(const const_reverse_iterator& rhv) const;
        bool operator>(const const_reverse_iterator& rhv) const;
        bool operator<=(const const_reverse_iterator& rhv) const;
        bool operator>=(const const_reverse_iterator& rhv) const;
    };

    class reverse_iterator : public const_reverse_iterator {
        friend class vector<value_type, Allocator>;
    protected:
        explicit reverse_iterator(pointer ptr);
    public:
        reverse_iterator();
        reverse_iterator(const reverse_iterator& rhv);
        reverse_iterator(reverse_iterator&& rhv);
        reverse_iterator operator+(size_type val);
        reverse_iterator operator-(size_type val);
        reverse_iterator& operator-=(size_type val);
        reverse_iterator& operator+=(size_type val);
        reverse_iterator& operator++();
        reverse_iterator operator++(int);
        reverse_iterator& operator--();
        reverse_iterator operator--(int);

        reference operator*();
        pointer operator->();
        reference operator[](size_type ind);
    };


    // construct/copy/destroy
    constexpr vector();
    constexpr vector(const vector& x);
    constexpr vector(vector&&) noexcept;
    constexpr vector(std::initializer_list<T> list);
    constexpr  ~vector();

    constexpr vector& operator=(const vector& x);
    constexpr vector& operator=(vector&& x)noexcept;
    constexpr vector& operator=(std::initializer_list<T>);
    
    constexpr void assign(size_type n, const T& u);
    constexpr void assign(std::initializer_list<T>);
 
    // iterators
    constexpr iterator begin() noexcept;
    constexpr const_iterator begin() const noexcept;
    constexpr iterator end() noexcept;
    constexpr const_iterator end() const noexcept;
    
    constexpr reverse_iterator rbegin() noexcept;
    constexpr const_reverse_iterator rbegin() const noexcept;
    constexpr reverse_iterator rend() noexcept;
    constexpr const_reverse_iterator rend() const noexcept;
        
    constexpr const_iterator         cbegin() const noexcept;
    constexpr const_iterator         cend() const noexcept;
    constexpr const_reverse_iterator crbegin() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;
        
    // capacity
    [[nodiscard]] constexpr bool empty() const noexcept;
    constexpr size_type size() const;
    constexpr size_type max_size() const noexcept; // grac chi
    constexpr size_type capacity() const noexcept;
    constexpr void      resize(size_type sz);
    constexpr void      reverse();
    constexpr void      shrink_to_fit();
 
    // element access
    constexpr reference       operator[](size_type n);
    constexpr const_reference operator[](size_type n) const;
    constexpr const_reference at(size_type n) const;
    constexpr reference       at(size_type n);
    constexpr reference       front();
    constexpr const_reference front() const;
    constexpr reference       back();
    constexpr const_reference back() const;
 
    // data access
    constexpr pointer       data() noexcept;
    constexpr const_pointer data() const noexcept;

    // modifiers
    constexpr void push_back(const T& x);
    constexpr void push_back(T&& x);
    constexpr void pop_back();
    constexpr void clear() noexcept;
    private:
        allocator_type m_allocator{Allocator()};
        pointer m_arr;
        size_type m_size;
        size_type m_capacity;
        constexpr void resize();   
  };
}
#include "vector.tpp"
#endif // VECTOR_H