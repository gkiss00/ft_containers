#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>

template < class T, class Alloc = std::allocator<T> >
class vector
{
    public:
    typedef T       value_type;
    typedef Alloc   allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer	     pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    // typedef typename iterator;
    // typedef typename const_iterator;
    // typedef typename reverse_iterator;
    // typedef typename const_reverse_iterator	;
    // typedef typename iterator_traits<iterator>::difference_type  difference_type; // ptrdiff_t
    typedef size_t  size_type;

    vector();
    vector(int size, T value = 0);
    vector(const vector &target);
    vector &operator=(const vector &target);
    ~vector();

    size_type   size() const;
    size_type   max_size() const;
    void        resize(size_type n, value_type val = value_type());
    size_type   capacity() const;
    bool        empty() const;
    void        reserve(size_type n);

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    private:
    T           *_tab;
    size_type   _size;
    size_type   _capacity;
    Alloc       _allocator;
};

/* --- Constructors --- */

template < class T, class Alloc >
vector<T, Alloc>::vector()
{
    this->_tab = NULL;
    this->_size = 0;
    this->_capacity = this->_size;
}

template < class T, class Alloc >
vector<T, Alloc>::vector(int size, T value)
{
    if (size < 0)
    {
        throw std::length_error("vector");
    }
    this->_size = size;
    this->_capacity = this->_size;
    this->_tab = this->_allocator.allocate(this->_size);
    for (int i = 0; i < (int)this->_size; ++i)
    {
        this->_tab[i] = value;
    }
}

template < class T, class Alloc >
vector<T, Alloc>::vector(const vector &target)
{
    if (target._tab == NULL)
    {
        this->_tab = NULL;
        this->_size = 0;
        this->_capacity = this->_size;
    }
    else
    {
        this->_size = target.size();
        this->_capacity = target.capacity();
        this->_tab = this->_allocator.allocate(this->_capacity);
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_tab[i] = target[i];
        }
    }
}

/* --- Destructor --- */

template < class T, class Alloc >
vector<T, Alloc>::~vector()
{
    if (this->_tab != NULL)
    {
        this->_allocator.deallocate(this->_tab, this->_capacity);
    }
}

/* --- Assignation --- */

template < class T, class Alloc >
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &target)
{
    if (target._tab == NULL)
    {
        this->_tab = NULL;
        this->_size = 0;
        this->_capacity = this->size;
    }
    else
    {
        this->_size = target.size();
        this->_capacity = target.capacity();
        this->_tab = this->_allocator.allocate(this->_capacity);
        for (int i = 0; i < this->_size; ++i)
        {
            this->_tab[i] = target[i];
        }
    }
    return *this;
}

/* --- Capacity --- */

template < class T, class Alloc >
size_t  vector<T, Alloc>::size() const
{
    return _size;
}

template < class T, class Alloc >
size_t  vector<T, Alloc>::max_size() const
{
    return this->_allocator.max_size();
}

template < class T, class Alloc >
void    vector<T, Alloc>::resize(size_type n, value_type val)
{
    if (n < this->_capacity)
    {
        for (int i = 0; i < (int)this->_size; ++i)
        {
            if (i >= (int)n)
            {
                this->_allocator.destroy(&this->_tab[i]);
            }
        }
        this->_size = n;
    }
    else if (n > this->_capacity)
    {
        T   *temp = this->_allocator.allocate(n);
        for (int i = 0; i < (int)n; ++i)
        {
            temp[i] = (i < (int)this->_size ? this->_tab[i] : val);
        }
        this->_allocator.deallocate(this->_tab, this->_capacity);
        this->_tab = temp;
        this->_size = n;
        this->_capacity = this->_size;
    }
}

template < class T, class Alloc >
size_t  vector<T, Alloc>::capacity() const
{
    return this->_capacity;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::empty() const
{
    return (this->_size == 0 ? true : false);
}

template < class T, class Alloc >
void    vector<T, Alloc>::reserve(size_type n)
{
    if (n > this->_allocator.max_size())
    {
        throw std::length_error("vector");
    }
    else if (n > this->_capacity)
    {
        T   *temp = this->_allocator.allocate(n);
        for (int i = 0; i < (int)this->_size; ++i)
        {
            temp[i] = this->_tab[i];
        }
        this->_allocator.deallocate(this->_tab, this->_capacity);
        this->_tab = temp;
        this->_capacity = n;
    }
}

/* --- Element access --- */

template < class T, class Alloc >
typename Alloc::reference   vector<T, Alloc>::operator[](size_type n)
{
    T   &ret = this->_tab[n];
    return ret;
}

template < class T, class Alloc >
typename Alloc::const_reference vector<T, Alloc>::operator[](size_type n) const
{
    T   &ret = this->_tab[n];
    return ret;
}

template < class T, class Alloc >
typename Alloc::reference vector<T, Alloc>::at(size_type n)
{
    if (n >= this->_size)
    {
        throw std::out_of_range("vector");
    }
    T   &ret = this->_tab[n];
    return ret;
}

template < class T, class Alloc >
typename Alloc::const_reference vector<T, Alloc>::at(size_type n) const
{
    if (n >= this->_size)
    {
        throw std::out_of_range("vector");
    }
    T   &ret = this->_tab[n];
    return ret;
}

template < class T, class Alloc >
typename Alloc::reference vector<T, Alloc>::front()
{
    T   &ret = this->_tab[0];
    return ret;
}

template < class T, class Alloc >
typename Alloc::const_reference vector<T, Alloc>::front() const
{
    T   &ret = this->_tab[0];
    return ret;
}

template < class T, class Alloc >
typename Alloc::reference vector<T, Alloc>::back()
{
    T   &ret = this->_tab[this->_size - 1];
    return ret;
}

template < class T, class Alloc >
typename Alloc::const_reference vector<T, Alloc>::back() const
{
    T   &ret = this->_tab[this->_size - 1];
    return ret;
}



#endif