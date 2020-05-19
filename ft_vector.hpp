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
    typedef size_t  size_type;

    class iterator : public std::iterator<std::random_access_iterator_tag, value_type>
	{
	    public:

		explicit    iterator(vector<value_type, allocator_type> &container, int index);
        iterator(const iterator &target);
        iterator    &operator=(const iterator &target);
        ~iterator() {}
		value_type  operator*() const;
        iterator    operator+(const iterator &op) const;
        iterator    operator+(const size_type &op) const;
        iterator    operator-(const iterator &op) const;
        iterator    operator-(const size_type &op) const;
		iterator    &operator++();
		iterator    &operator++(int);
        iterator    &operator--();
		iterator    &operator--(int);
        bool        operator<(const iterator &op) const;
        bool        operator<=(const iterator &op) const;
        bool        operator>(const iterator &op) const;
        bool        operator>=(const iterator &op) const;
		bool        operator!=(const iterator &op) const;
        bool        operator==(const iterator &op) const;
        reference   operator[](size_type n) const;

	    private:
		int         _index;
		vector      &_container;
	};

    class const_iterator : public std::iterator<std::random_access_iterator_tag, value_type>
	{
	    public:
		explicit    const_iterator(const vector<value_type, allocator_type> &container, int index);
        ~const_iterator() {}
		value_type      operator*() const;
		const_iterator  &operator++();
		const_iterator  &operator++(int);
        const_iterator  &operator--();
		const_iterator  &operator--(int);
		bool            operator!=(const const_iterator &op) const;

	    private:
		int             _index;
		const vector    &_container;
	};

    class reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type>
	{
	    public:
		explicit    reverse_iterator(vector<value_type, allocator_type> &container, int index);
        ~reverse_iterator() {}
		value_type  operator*() const;
		reverse_iterator    &operator++();
		reverse_iterator    &operator++(int);
        reverse_iterator    &operator--();
		reverse_iterator    &operator--(int);
		bool        operator!=(const reverse_iterator &op) const;

	    private:
		int         _index;
		vector      &_container;
	};

    class const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type>
	{
	    public:
		explicit    const_reverse_iterator(const vector<value_type, allocator_type> &container, int index);
        ~const_reverse_iterator() {}
		value_type  operator*() const;
		const_reverse_iterator    &operator++();
		const_reverse_iterator    &operator++(int);
        const_reverse_iterator    &operator--();
		const_reverse_iterator    &operator--(int);
		bool        operator!=(const const_reverse_iterator &op) const;

	    private:
		int             _index;
		const vector    &_container;
	};

    explicit vector(const allocator_type &alloc = allocator_type());
    explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
    vector(const vector &target);
    vector &operator=(const vector &target);
    ~vector();

    iterator                begin();
    const_iterator          begin() const;
    iterator                end();
    const_iterator          end() const;
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;

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

    void            push_back(const value_type& val);
    void            pop_back();

    void            clear();


    private:
    T           *_tab;
    size_type   _size;
    size_type   _capacity;
    Alloc       *_allocator;
};

/* --- Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::iterator::iterator(vector<T, Alloc> &container, int index) : _container(container)
{
	this->_index = index;
}

template < class T, class Alloc >
vector<T, Alloc>::iterator::iterator(const iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator     &vector<T, Alloc>::iterator::operator=(const iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   vector<T, Alloc>::iterator::operator*() const
{
    return this->_container[this->_index];
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator+(const iterator &op) const
{
    iterator nw(this->_container, this->_index + op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator+(const size_type &op) const
{
    iterator nw(*this);

    nw._index += op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator-(const iterator &op) const
{
    iterator nw(this->_container, this->_index - op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator-(const size_type &op) const
{
    iterator nw(this->_container, this->_index - op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator     &vector<T, Alloc>::iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator     &vector<T, Alloc>::iterator::operator++(int i)
{
    (void)i;
	iterator    tmp(*this);
    this->operator++();
    return tmp;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    &vector<T, Alloc>::iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    &vector<T, Alloc>::iterator::operator--(int i)
{
    (void)i;
	iterator    tmp(*this);
    this->operator--();
    return tmp;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::iterator::operator!=(const iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::iterator::operator==(const iterator &op) const
{
	return this->_index == op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::iterator::operator<(const iterator &op) const
{
	return this->_index < op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::iterator::operator<=(const iterator &op) const
{
	return this->_index <= op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::iterator::operator>(const iterator &op) const
{
	return this->_index > op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::iterator::operator>=(const iterator &op) const
{
	return this->_index >= op._index;
}

template < class T, class Alloc >
typename Alloc::reference  vector<T, Alloc>::iterator::operator[](size_type n) const
{
    for (int i = 0; i < (int)this->_container._size; ++i)
    {
        std::cout << this->_container[n] << std::endl;
    }
    return this->_container[n];
}

/* --- Const Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::const_iterator::const_iterator(const vector<value_type, allocator_type> &container, int index) : _container(container)
{
	this->_index = index;
}

template < class T, class Alloc >
T   vector<T, Alloc>::const_iterator::operator*() const
{
    return this->_container[this->_index];
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator     &vector<T, Alloc>::const_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator     &vector<T, Alloc>::const_iterator::operator++(int i)
{
    (void)i;
	const_iterator    tmp(*this);
    this->operator++();
    return tmp;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    &vector<T, Alloc>::const_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    &vector<T, Alloc>::const_iterator::operator--(int i)
{
    (void)i;
	const_iterator    tmp(*this);
    this->operator--();
    return tmp;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_iterator::operator!=(const const_iterator &op) const
{
	return this->_index != op._index;
}

/* --- Reverse Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::reverse_iterator::reverse_iterator(vector<T, Alloc> &container, int index) : _container(container)
{
	this->_index = index;
}

template < class T, class Alloc >
T   vector<T, Alloc>::reverse_iterator::operator*() const
{
    return this->_container[this->_container.size() - this->_index - 1];
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator     &vector<T, Alloc>::reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator     &vector<T, Alloc>::reverse_iterator::operator++(int i)
{
    (void)i;
	reverse_iterator    tmp(*this);
    this->operator++();
    return tmp;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    &vector<T, Alloc>::reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    &vector<T, Alloc>::reverse_iterator::operator--(int i)
{
    (void)i;
	reverse_iterator    tmp(*this);
    this->operator--();
    return tmp;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::reverse_iterator::operator!=(const reverse_iterator &op) const
{
	return this->_index != op._index;
}

/* --- Const Reverse Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator(const vector<T, Alloc> &container, int index) : _container(container)
{
	this->_index = index;
}

template < class T, class Alloc >
T   vector<T, Alloc>::const_reverse_iterator::operator*() const
{
    return this->_container[this->_container.size() - this->_index - 1];
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator     &vector<T, Alloc>::const_reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator     &vector<T, Alloc>::const_reverse_iterator::operator++(int i)
{
    (void)i;
	const_reverse_iterator    tmp(*this);
    this->operator++();
    return tmp;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    &vector<T, Alloc>::const_reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    &vector<T, Alloc>::const_reverse_iterator::operator--(int i)
{
    (void)i;
	const_reverse_iterator    tmp(*this);
    this->operator--();
    return tmp;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_reverse_iterator::operator!=(const const_reverse_iterator &op) const
{
	return this->_index != op._index;
}

/* --- Constructors --- */

template < class T, class Alloc >
vector<T, Alloc>::vector(const allocator_type &alloc)
{
    this->_tab = NULL;
    this->_size = 0;
    this->_capacity = this->_size;
    this->_allocator = new Alloc(alloc);
}

template < class T, class Alloc >
vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
{
    (n < 0) ? throw std::length_error("vector") : 0;
    this->_size = n;
    this->_capacity = this->_size;
    this->_allocator = new Alloc(alloc);
    this->_tab = this->_allocator->allocate(this->_size);
    for (int i = 0; i < (int)this->_size; ++i)
    {
        this->_allocator->construct(&this->_tab[i], val);
    }
}

// template <typename T, typename Alloc>
// template <typename InputIterator>
// vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc)
// {
// 	this->_allocator = new Alloc(alloc);
// 	this->_size = last - first;
// 	this->_capacity = this->_size;
// 	this->_tab = this->_allocator->allocate(_size);
// 	int i = 0;
// 	for (InputIterator it = first; it != last; ++it, ++i)
// 	{
// 		this->_allocator->construct(this->_tab + i, *it);
// 	}
// }

template < class T, class Alloc >
vector<T, Alloc>::vector(const vector &target)
{
    if (target._tab == NULL)
    {
        this->_tab = NULL;
        this->_size = 0;
        this->_capacity = this->_size;
        this->_allocator = new Alloc;
    }
    else
    {
        this->_size = target.size();
        this->_capacity = target.capacity();
        this->_allocator = new Alloc;
        this->_tab = this->_allocator->allocate(this->_capacity);
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->construct(&this->_tab[i], target[i]);
        }
        
    }
}

/* --- Destructor --- */

template < class T, class Alloc >
vector<T, Alloc>::~vector()
{
    if (this->_tab != NULL)
    {
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->destroy(&this->_tab[i]);
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
    }
    delete this->_allocator;
}

/* --- Assignation --- */

template < class T, class Alloc >
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &target)
{
    if (this->_tab != NULL)
    {
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->destroy(&this->_tab[i]);
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
    }
    delete this->_allocator;
    if (target._tab == NULL)
    {
        this->_tab = NULL;
        this->_size = 0;
        this->_capacity = this->_size;
        this->_allocator = new Alloc;
    }
    else
    {
        this->_size = target.size();
        this->_capacity = target.capacity();
        this->_allocator = new Alloc;
        this->_tab = this->_allocator->allocate(this->_capacity);
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->construct(&this->_tab[i], target[i]);
        }
    }
    return *this;
}

/* --- Iterators Functions --- */

template < class T, class Alloc >
typename vector<T, Alloc>::iterator         vector<T, Alloc>::begin()
{
	return vector<T, Alloc>::iterator(*this, 0);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator   vector<T, Alloc>::begin() const
{
	return vector<T, Alloc>::const_iterator(*this, 0);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator         vector<T, Alloc>::end()
{
	return vector<T, Alloc>::iterator(*this, this->_size);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator         vector<T, Alloc>::end() const
{
	return vector<T, Alloc>::const_iterator(*this, this->_size);
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator         vector<T, Alloc>::rbegin()
{
	return vector<T, Alloc>::reverse_iterator(*this, 0);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator         vector<T, Alloc>::rbegin() const
{
	return vector<T, Alloc>::const_reverse_iterator(*this, 0);
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator         vector<T, Alloc>::rend()
{
	return vector<T, Alloc>::reverse_iterator(*this, this->_size);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator         vector<T, Alloc>::rend() const
{
	return vector<T, Alloc>::const_reverse_iterator(*this, this->_size);
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
    return this->_allocator->max_size();
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
                this->_allocator->destroy(&this->_tab[i]);
            }
        }
        this->_size = n;
    }
    else if (n > this->_capacity)
    {
        T   *temp = this->_allocator->allocate(n);
        for (int i = 0; i < (int)n; ++i)
        {
            if (i < (int)this->_size)
                this->_allocator->construct(&temp[i], this->_tab[i]);
            else
                this->_allocator->construct(&temp[i], val);            
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
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
    if (n > this->_allocator->max_size())
    {
        throw std::length_error("vector");
    }
    else if (n > this->_capacity)
    {
        T   *temp = this->_allocator->allocate(n);
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->construct(&temp[i], this->_tab[i]);
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
        this->_tab = temp;
        this->_capacity = n;
    }
}

/* --- Element access --- */

template < class T, class Alloc >
typename Alloc::reference   vector<T, Alloc>::operator[](size_type n)
{
    // std::cout << "ok" << std::endl;
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

/* --- Modifiers --- */

template < class T, class Alloc >
void    vector<T, Alloc>::push_back(const value_type& val)
{
    if (this->_size + 1 <= this->_capacity)
    {
        this->_allocator->construct(&this->_tab[this->_size], val);
        this->_size += 1;
    }
    else
    {
        this->resize(this->_size + 1, val);
    }
}

template < class T, class Alloc >
void    vector<T, Alloc>::pop_back()
{
    if (this->_size > 0)
    {
        this->_allocator->destroy(&this->_tab[this->_size - 1]);
        this->_size -= 1;
    }
}

template < class T, class Alloc >
void    vector<T, Alloc>::clear()
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        this->_allocator->destroy(&this->_tab[i]);
    }
    this->_size = 0;
}

#endif