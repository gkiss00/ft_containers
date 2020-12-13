#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft
{

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

    class iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        iterator();
		explicit    iterator(vector<value_type, allocator_type> &container, int index);
        iterator(const iterator &target);
        iterator    &operator=(const iterator &target);
        ~iterator() { /*std::cout << "je suis dans le destructeur" << std::endl;*/}
		value_type  operator*() const;
		value_type  operator->() const;
        iterator    operator+(const iterator &op) const;
        iterator    operator+(const size_type &op) const;
        iterator    operator-(const iterator &op) const;
        iterator    operator-(const size_type &op) const;
        iterator    &operator+=(const size_type &op);
        iterator    &operator-=(const size_type &op);
		iterator    &operator++();
		iterator    operator++(int);
        iterator    &operator--();
		iterator    operator--(int);
        bool        operator<(const iterator &op) const;
        bool        operator<=(const iterator &op) const;
        bool        operator>(const iterator &op) const;
        bool        operator>=(const iterator &op) const;
		bool        operator!=(const iterator &op) const;
        bool        operator==(const iterator &op) const;
        reference   operator[](size_type n) const;

	    private:
		int         _index;
		vector      *_container;
	};

    typedef typename iterator::difference_type  difference_type;

    class const_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        const_iterator();
		explicit    const_iterator(const vector<value_type, allocator_type> &container, int index);
        const_iterator(const const_iterator &target);
        const_iterator    &operator=(const const_iterator &target);
        ~const_iterator() {}
		value_type  operator*() const;
		value_type  operator->() const;
        const_iterator    operator+(const const_iterator &op) const;
        const_iterator    operator+(const size_type &op) const;
        const_iterator    operator-(const const_iterator &op) const;
        const_iterator    operator-(const size_type &op) const;
        const_iterator    &operator+=(const size_type &op);
        const_iterator    &operator-=(const size_type &op);
		const_iterator    &operator++();
		const_iterator    operator++(int);
        const_iterator    &operator--();
		const_iterator    operator--(int);
        bool        operator<(const const_iterator &op) const;
        bool        operator<=(const const_iterator &op) const;
        bool        operator>(const const_iterator &op) const;
        bool        operator>=(const const_iterator &op) const;
		bool        operator!=(const const_iterator &op) const;
        bool        operator==(const const_iterator &op) const;
        reference   operator[](size_type n) const;

	    private:
		int             _index;
		const vector    *_container;
	};

    class reverse_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        reverse_iterator();
		explicit    reverse_iterator(vector<value_type, allocator_type> &container, int index);
        reverse_iterator(const reverse_iterator &target);
        reverse_iterator    &operator=(const reverse_iterator &target);
        ~reverse_iterator() {}
		value_type  operator*() const;
		value_type  operator->() const;
        reverse_iterator    operator+(const reverse_iterator &op) const;
        reverse_iterator    operator+(const size_type &op) const;
        reverse_iterator    operator-(const reverse_iterator &op) const;
        reverse_iterator    operator-(const size_type &op) const;
        reverse_iterator    &operator+=(const size_type &op);
        reverse_iterator    &operator-=(const size_type &op);
		reverse_iterator    &operator++();
		reverse_iterator    operator++(int);
        reverse_iterator    &operator--();
		reverse_iterator    operator--(int);
        bool        operator<(const reverse_iterator &op) const;
        bool        operator<=(const reverse_iterator &op) const;
        bool        operator>(const reverse_iterator &op) const;
        bool        operator>=(const reverse_iterator &op) const;
		bool        operator!=(const reverse_iterator &op) const;
        bool        operator==(const reverse_iterator &op) const;
        reference   operator[](size_type n) const;

	    private:
		int         _index;
		vector      *_container;
	};

    class const_reverse_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        const_reverse_iterator();
		explicit    const_reverse_iterator(const vector<value_type, allocator_type> &container, int index);
        const_reverse_iterator(const const_reverse_iterator &target);
        const_reverse_iterator    &operator=(const const_reverse_iterator &target);
        ~const_reverse_iterator() {}
		value_type  operator*() const;
		value_type  operator->() const;
        const_reverse_iterator    operator+(const const_reverse_iterator &op) const;
        const_reverse_iterator    operator+(const size_type &op) const;
        const_reverse_iterator    operator-(const const_reverse_iterator &op) const;
        const_reverse_iterator    operator-(const size_type &op) const;
        const_reverse_iterator    &operator+=(const size_type &op);
        const_reverse_iterator    &operator-=(const size_type &op);
		const_reverse_iterator    &operator++();
		const_reverse_iterator    operator++(int);
        const_reverse_iterator    &operator--();
		const_reverse_iterator    operator--(int);
        bool        operator<(const const_reverse_iterator &op) const;
        bool        operator<=(const const_reverse_iterator &op) const;
        bool        operator>(const const_reverse_iterator &op) const;
        bool        operator>=(const const_reverse_iterator &op) const;
		bool        operator!=(const const_reverse_iterator &op) const;
        bool        operator==(const const_reverse_iterator &op) const;
        reference   operator[](size_type n) const;

	    private:
		int         _index;
		const vector      *_container;
	};

    explicit vector(const allocator_type &alloc = allocator_type());
    explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
    template <class InputIterator>
    vector(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type());
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

    void            assign(size_type n, const value_type &val);
    template < class InputIterator >
    typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    assign(InputIterator first, InputIterator last);
    void            push_back(const value_type &val);
    void            pop_back();
    iterator        insert (iterator position, const value_type& val);
    void            insert (iterator position, size_type n, const value_type& val);
    template <class InputIterator>
    typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    insert (iterator position, InputIterator first, InputIterator last);
    typename vector<T, Alloc>::iterator        erase(iterator position);
    typename vector<T, Alloc>::iterator        erase(iterator first, iterator last);
    void            swap(vector& x);
    void            clear();

    private:
    T           *_tab;
    size_type   _size;
    size_type   _capacity;
    Alloc       *_allocator;
};

template <class Alloc>
class vector < bool, Alloc >
{
    public:
    typedef bool    value_type;
    typedef Alloc   allocator_type;

    class reference
    {
        friend class vector;
        reference();
        
        public:
        ~reference();
        operator bool () const;
        reference& operator= (const bool x);
        reference& operator= (const reference& x);
        void flip();

        private:
        bool _bool;
    };

    typedef bool const_reference;
    typedef typename allocator_type::pointer	     pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef size_t  size_type;

    class iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        iterator();
		explicit    iterator(vector<value_type, allocator_type> &container, int index);
        iterator(const iterator &target);
        iterator    &operator=(const iterator &target);
        ~iterator() {}
		value_type  operator*() const;
		value_type  operator->() const;
        iterator    operator+(const iterator &op) const;
        iterator    operator+(const size_type &op) const;
        iterator    operator-(const iterator &op) const;
        iterator    operator-(const size_type &op) const;
        iterator    &operator+=(const size_type &op);
        iterator    &operator-=(const size_type &op);
		iterator    &operator++();
		iterator    operator++(int);
        iterator    &operator--();
		iterator    operator--(int);
        bool        operator<(const iterator &op) const;
        bool        operator<=(const iterator &op) const;
        bool        operator>(const iterator &op) const;
        bool        operator>=(const iterator &op) const;
		bool        operator!=(const iterator &op) const;
        bool        operator==(const iterator &op) const;
        typename vector<bool, Alloc>::reference   operator[](size_type n) const;

	    private:
		int         _index;
		vector      *_container;
	};

    typedef typename iterator::difference_type  difference_type;

    class const_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        const_iterator();
		explicit    const_iterator(const vector<value_type, allocator_type> &container, int index);
        const_iterator(const const_iterator &target);
        const_iterator    &operator=(const const_iterator &target);
        ~const_iterator() {}
		value_type  operator*() const;
		value_type  operator->() const;
        const_iterator    operator+(const const_iterator &op) const;
        const_iterator    operator+(const size_type &op) const;
        const_iterator    operator-(const const_iterator &op) const;
        const_iterator    operator-(const size_type &op) const;
        const_iterator    &operator+=(const size_type &op);
        const_iterator    &operator-=(const size_type &op);
		const_iterator    &operator++();
		const_iterator    operator++(int);
        const_iterator    &operator--();
		const_iterator    operator--(int);
        bool        operator<(const const_iterator &op) const;
        bool        operator<=(const const_iterator &op) const;
        bool        operator>(const const_iterator &op) const;
        bool        operator>=(const const_iterator &op) const;
		bool        operator!=(const const_iterator &op) const;
        bool        operator==(const const_iterator &op) const;
        typename vector<bool, Alloc>::reference   operator[](size_type n) const;

	    private:
		int         _index;
		const vector      *_container;
	};

    class reverse_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        reverse_iterator();
		explicit    reverse_iterator(vector<value_type, allocator_type> &container, int index);
        reverse_iterator(const reverse_iterator &target);
        reverse_iterator    &operator=(const reverse_iterator &target);
        ~reverse_iterator() {}
		value_type  operator*() const;
		value_type  operator->() const;
        reverse_iterator    operator+(const reverse_iterator &op) const;
        reverse_iterator    operator+(const size_type &op) const;
        reverse_iterator    operator-(const reverse_iterator &op) const;
        reverse_iterator    operator-(const size_type &op) const;
        reverse_iterator    &operator+=(const size_type &op);
        reverse_iterator    &operator-=(const size_type &op);
		reverse_iterator    &operator++();
		reverse_iterator    operator++(int);
        reverse_iterator    &operator--();
		reverse_iterator    operator--(int);
        bool        operator<(const reverse_iterator &op) const;
        bool        operator<=(const reverse_iterator &op) const;
        bool        operator>(const reverse_iterator &op) const;
        bool        operator>=(const reverse_iterator &op) const;
		bool        operator!=(const reverse_iterator &op) const;
        bool        operator==(const reverse_iterator &op) const;
        typename vector<bool, Alloc>::reference   operator[](size_type n) const;

	    private:
		int         _index;
		vector      *_container;
	};

    class const_reverse_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        const_reverse_iterator();
		explicit    const_reverse_iterator(const vector<value_type, allocator_type> &container, int index);
        const_reverse_iterator(const const_reverse_iterator &target);
        const_reverse_iterator    &operator=(const const_reverse_iterator &target);
        ~const_reverse_iterator() {}
		value_type  operator*() const;
		value_type  operator->() const;
        const_reverse_iterator    operator+(const const_reverse_iterator &op) const;
        const_reverse_iterator    operator+(const size_type &op) const;
        const_reverse_iterator    operator-(const const_reverse_iterator &op) const;
        const_reverse_iterator    operator-(const size_type &op) const;
        const_reverse_iterator    &operator+=(const size_type &op);
        const_reverse_iterator    &operator-=(const size_type &op);
		const_reverse_iterator    &operator++();
		const_reverse_iterator    operator++(int);
        const_reverse_iterator    &operator--();
		const_reverse_iterator    operator--(int);
        bool        operator<(const const_reverse_iterator &op) const;
        bool        operator<=(const const_reverse_iterator &op) const;
        bool        operator>(const const_reverse_iterator &op) const;
        bool        operator>=(const const_reverse_iterator &op) const;
		bool        operator!=(const const_reverse_iterator &op) const;
        bool        operator==(const const_reverse_iterator &op) const;
        typename vector<bool, Alloc>::reference   operator[](size_type n) const;

	    private:
		int         _index;
		const vector      *_container;
	};

    explicit vector(const allocator_type &alloc = allocator_type());
    explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
    template <class InputIterator>
    vector(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type());
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

    void            assign(size_type n, const value_type &val);
    template < class InputIterator >
    typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    assign(InputIterator first, InputIterator last);
    void            push_back(const value_type &val);
    void            pop_back();
    iterator        insert (iterator position, const value_type& val);
    void            insert (iterator position, size_type n, const value_type& val);
    template <class InputIterator>
    typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    insert (iterator position, InputIterator first, InputIterator last);
    typename vector<bool, Alloc>::iterator        erase(iterator position);
    typename vector<bool, Alloc>::iterator        erase(iterator first, iterator last);
    void            swap(vector& x);
    void            clear();

    void            flip();
    static void     swap(reference ref1, reference ref2);

    private:
    bool        *_tab;
    size_type   _size;
    size_type   _capacity;
    Alloc       *_allocator;
};

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (int i = 0; i < (int)lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    if (lhs.size() != rhs.size())
        return lhs.size() < rhs.size();
    for (int i = 0; i < (int)lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
            return lhs[i] < rhs[i];
    }
    return false;
}

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return !(rhs < lhs);
}

template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return rhs < lhs;
}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return !(lhs < rhs);
}

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
    vector<T, Alloc>  temp(x);
    
    x.assign(y.begin(), y.end());
    y.assign(temp.begin(), temp.end());
}

/* --- Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::iterator::iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
vector<T, Alloc>::iterator::iterator(vector<T, Alloc> &container, int index) : _container(&container)
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
    this->_index = target._index;
    // std::cout << "je suis a ; arriere  " <<  target._container->back() << std::endl;
    this->_container = target._container;
    // std::cout << "je suis a ; arriere  " <<  this->_container->back() << std::endl;
    // std::cout << "je suis a ; arriere  " <<  target._container->back() << std::endl;
    this->_container = target._container;
	
    return (*this);
}

template < class T, class Alloc >
T   vector<T, Alloc>::iterator::operator*() const
{
    return this->_container[0][this->_index];
}

template < class T, class Alloc >
T   vector<T, Alloc>::iterator::operator->() const
{
    return this->_container[0][this->_index];
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator+(const iterator &op) const
{
    iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator+(const size_type &op) const
{
    iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator-(const iterator &op) const
{
    iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator-(const size_type &op) const
{
    iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    &vector<T, Alloc>::iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    &vector<T, Alloc>::iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator     &vector<T, Alloc>::iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator     vector<T, Alloc>::iterator::operator++(int i)
{
    (void)i;
    iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    &vector<T, Alloc>::iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator    vector<T, Alloc>::iterator::operator--(int i)
{
    (void)i;
    iterator it = *this;
    this->_index--;
    return it;
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
    return this->_container[0][this->_index + n];
}

/* --- Const Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::const_iterator::const_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
vector<T, Alloc>::const_iterator::const_iterator(const vector<T, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class T, class Alloc >
vector<T, Alloc>::const_iterator::const_iterator(const const_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator     &vector<T, Alloc>::const_iterator::operator=(const const_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   vector<T, Alloc>::const_iterator::operator*() const
{
    return this->_container[0][this->_index];
}

template < class T, class Alloc >
T   vector<T, Alloc>::const_iterator::operator->() const
{
    return this->_container[0][this->_index];
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    vector<T, Alloc>::const_iterator::operator+(const const_iterator &op) const
{
    const_iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    vector<T, Alloc>::const_iterator::operator+(const size_type &op) const
{
    const_iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    vector<T, Alloc>::const_iterator::operator-(const const_iterator &op) const
{
    const_iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    vector<T, Alloc>::const_iterator::operator-(const size_type &op) const
{
    const_iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    &vector<T, Alloc>::const_iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    &vector<T, Alloc>::const_iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator     &vector<T, Alloc>::const_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator     vector<T, Alloc>::const_iterator::operator++(int i)
{
    (void)i;
    const_iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    &vector<T, Alloc>::const_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_iterator    vector<T, Alloc>::const_iterator::operator--(int i)
{
    (void)i;
    const_iterator it = *this;
    this->_index--;
    return it;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_iterator::operator!=(const const_iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_iterator::operator==(const const_iterator &op) const
{
	return this->_index == op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_iterator::operator<(const const_iterator &op) const
{
	return this->_index < op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_iterator::operator<=(const const_iterator &op) const
{
	return this->_index <= op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_iterator::operator>(const const_iterator &op) const
{
	return this->_index > op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_iterator::operator>=(const const_iterator &op) const
{
	return this->_index >= op._index;
}

template < class T, class Alloc >
typename Alloc::reference  vector<T, Alloc>::const_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_index + n];
}

/* --- Reverse Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::reverse_iterator::reverse_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
vector<T, Alloc>::reverse_iterator::reverse_iterator(vector<T, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class T, class Alloc >
vector<T, Alloc>::reverse_iterator::reverse_iterator(const reverse_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator     &vector<T, Alloc>::reverse_iterator::operator=(const reverse_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   vector<T, Alloc>::reverse_iterator::operator*() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class T, class Alloc >
T   vector<T, Alloc>::reverse_iterator::operator->() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    vector<T, Alloc>::reverse_iterator::operator+(const reverse_iterator &op) const
{
    reverse_iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    vector<T, Alloc>::reverse_iterator::operator+(const size_type &op) const
{
    reverse_iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    vector<T, Alloc>::reverse_iterator::operator-(const reverse_iterator &op) const
{
    reverse_iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    vector<T, Alloc>::reverse_iterator::operator-(const size_type &op) const
{
    reverse_iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    &vector<T, Alloc>::reverse_iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    &vector<T, Alloc>::reverse_iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator     &vector<T, Alloc>::reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator     vector<T, Alloc>::reverse_iterator::operator++(int i)
{
    (void)i;
    reverse_iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    &vector<T, Alloc>::reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::reverse_iterator    vector<T, Alloc>::reverse_iterator::operator--(int i)
{
    (void)i;
    reverse_iterator it = *this;
    this->_index--;
    return it;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::reverse_iterator::operator!=(const reverse_iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::reverse_iterator::operator==(const reverse_iterator &op) const
{
	return this->_index == op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::reverse_iterator::operator<(const reverse_iterator &op) const
{
	return this->_index < op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::reverse_iterator::operator<=(const reverse_iterator &op) const
{
	return this->_index <= op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::reverse_iterator::operator>(const reverse_iterator &op) const
{
	return this->_index > op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::reverse_iterator::operator>=(const reverse_iterator &op) const
{
	return this->_index >= op._index;
}

template < class T, class Alloc >
typename Alloc::reference  vector<T, Alloc>::reverse_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_container->size() - this->_index - n - 1];
}

/* --- Const Revserse Iterator Class --- */

template < class T, class Alloc >
vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator(const vector<T, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class T, class Alloc >
vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator     &vector<T, Alloc>::const_reverse_iterator::operator=(const const_reverse_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   vector<T, Alloc>::const_reverse_iterator::operator*() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class T, class Alloc >
T   vector<T, Alloc>::const_reverse_iterator::operator->() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    vector<T, Alloc>::const_reverse_iterator::operator+(const const_reverse_iterator &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    vector<T, Alloc>::const_reverse_iterator::operator+(const size_type &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    vector<T, Alloc>::const_reverse_iterator::operator-(const const_reverse_iterator &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    vector<T, Alloc>::const_reverse_iterator::operator-(const size_type &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    &vector<T, Alloc>::const_reverse_iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    &vector<T, Alloc>::const_reverse_iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator     &vector<T, Alloc>::const_reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator     vector<T, Alloc>::const_reverse_iterator::operator++(int i)
{
    (void)i;
    const_reverse_iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    &vector<T, Alloc>::const_reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename vector<T, Alloc>::const_reverse_iterator    vector<T, Alloc>::const_reverse_iterator::operator--(int i)
{
    (void)i;
    const_reverse_iterator it = *this;
    this->_index--;
    return it;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_reverse_iterator::operator!=(const const_reverse_iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_reverse_iterator::operator==(const const_reverse_iterator &op) const
{
	return this->_index == op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_reverse_iterator::operator<(const const_reverse_iterator &op) const
{
	return this->_index < op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_reverse_iterator::operator<=(const const_reverse_iterator &op) const
{
	return this->_index <= op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_reverse_iterator::operator>(const const_reverse_iterator &op) const
{
	return this->_index > op._index;
}

template < class T, class Alloc >
bool    vector<T, Alloc>::const_reverse_iterator::operator>=(const const_reverse_iterator &op) const
{
	return this->_index >= op._index;
}

template < class T, class Alloc >
typename Alloc::reference  vector<T, Alloc>::const_reverse_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_container->size() - this->_index - n - 1];
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

template <typename T, typename Alloc>
template <typename InputIterator>
vector<T, Alloc>::vector(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc)
{
	this->_allocator = new Alloc(alloc);
	this->_size = 0;
    InputIterator temp = first;
    while (temp != last)
    {
        ++this->_size;
        ++temp;
    }
	this->_capacity = this->_size;
	this->_tab = this->_allocator->allocate(_size);
	int i = 0;
	for (InputIterator it = first; it != last; ++it, ++i)
	{
		this->_allocator->construct(this->_tab + i, *it);
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
    // std::cout << "je detruis mon vector" << std::endl;
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
template < class InputIterator >
typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type     vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
    int n = 0;
    InputIterator temp = first;

    if (this->_tab != NULL)
    {
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->destroy(&this->_tab[i]);
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
    }
    for (n = 0; temp != last; ++temp)
    {
        ++n;
    }   
    this->_size = n;
    this->_capacity = this->_size;
    this->_tab = this->_allocator->allocate(this->_size);
    for (int i = 0; first != last; ++i, ++first)
    {
        this->_allocator->construct(&this->_tab[i], *first);
    }    
}

template < class T, class Alloc >
void            vector<T, Alloc>::assign(size_type n, const value_type &val)
{
    if (this->_tab != NULL)
    {
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->destroy(&this->_tab[i]);
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
    }
    this->_size = n;
    this->_capacity = this->_size;
    this->_tab = this->_allocator->allocate(this->_size);
    for (int i = 0; i < (int)this->_size; ++i)
    {
        this->_allocator->construct(&this->_tab[i], val);
    }   
}

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
typename vector<T, Alloc>::iterator     vector<T, Alloc>::insert(iterator position, const value_type& val)
{
    this->insert(position, 1, val);
    return this->begin() + position;
}

template < class T, class Alloc >
void            vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
    int i = 0;

    this->reserve(this->_size + n);
    for (iterator it = this->begin(); it != position; ++it)
        ++i;
    T   temp[this->_size + n - i];
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        temp[j] = this->_tab[i + j];
    }
    for (int j = 0; j < (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], val);
    }
    i += n;
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], temp[j]);
    }
    this->_size += n;
}

template < class T, class Alloc >
template <class InputIterator>
typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
{
    int i = 0;
    int n = 0;
    InputIterator temp2 = first;

    while (temp2 != last)
    {
        ++temp2;
        ++n;
    }
    this->reserve(this->_size + n);
    for (iterator it = this->begin(); it != position; ++it)
        ++i;
    T   temp[this->_size + n - i];
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        temp[j] = this->_tab[i + j];
    }
    for (int j = 0; j < (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], *first);
        ++first;
    }
    i += n;
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], temp[j]);
    }
    this->_size += n;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
{
    int i = 0;
    iterator temp = this->begin();

    while (temp != position)
    {
        ++i;
        ++temp;
    }
    for (int j = 0; i + j < (int)this->_size - 1; ++j)
    {
        this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], this->_tab[i + j + 1]);
    }
    this->_allocator->destroy(&this->_tab[this->_size]);
    this->_size -= 1;
    return this->begin() + i;
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator        vector<T, Alloc>::erase(iterator first, iterator last)
{
    int i = 0;
    iterator temp = this->begin();

    while (temp != first)
    {
        ++i;
        ++temp;
    }
    while (first != last)
    {
        for (int j = 0; i + j < (int)this->_size - 1; ++j)
        {
            this->_allocator->destroy(&this->_tab[i + j]);
            this->_allocator->construct(&this->_tab[i + j], this->_tab[i + j + 1]);
        }
        this->_allocator->destroy(&this->_tab[this->_size]);
        this->_size -= 1;
        ++first;
    }
    return this->begin() + i;
}

template < class T, class Alloc >
void    vector<T, Alloc>::swap(vector& x)
{
    vector<T, Alloc>  temp(x);
    
    x.assign(this->begin(), this->end());
    this->assign(temp.begin(), temp.end());
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

/* --- Bool specialization --- */

/* --- Reference class --- */

template < class Alloc >
vector<bool, Alloc>::reference::reference()
{

}

template < class Alloc >
vector<bool, Alloc>::reference::~reference()
{

}

template < class Alloc >
vector<bool, Alloc>::reference::operator bool () const
{
    return this->_bool;
}

template < class Alloc >
typename vector<bool, Alloc>::reference&  vector<bool, Alloc>::reference::operator= (const bool x)
{
    this->_bool = x;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::reference&  vector<bool, Alloc>::reference::operator= (const reference& x)
{
    this->_bool = x._bool;
    return (*this);
}

template < class Alloc >
void  vector<bool, Alloc>::reference::flip()
{
    if (this->_bool == 1)
        this->_bool = 0;
    else
        this->_bool = 1;
}

/* --- Iterator Class --- */

template < class Alloc >
vector<bool, Alloc>::iterator::iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class Alloc >
vector<bool, Alloc>::iterator::iterator(vector<bool, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class Alloc >
vector<bool, Alloc>::iterator::iterator(const iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator     &vector<bool, Alloc>::iterator::operator=(const iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class Alloc >
bool   vector<bool, Alloc>::iterator::operator*() const
{
    return this->_container[0][this->_index];
}

template < class Alloc >
bool   vector<bool, Alloc>::iterator::operator->() const
{
    return this->_container[0][this->_index];
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    vector<bool, Alloc>::iterator::operator+(const iterator &op) const
{
    iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    vector<bool, Alloc>::iterator::operator+(const size_type &op) const
{
    iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    vector<bool, Alloc>::iterator::operator-(const iterator &op) const
{
    iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    vector<bool, Alloc>::iterator::operator-(const size_type &op) const
{
    iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    &vector<bool, Alloc>::iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    &vector<bool, Alloc>::iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::iterator     &vector<bool, Alloc>::iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator     vector<bool, Alloc>::iterator::operator++(int i)
{
    (void)i;
    iterator it = *this;
    this->_index++;
    return it;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    &vector<bool, Alloc>::iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator    vector<bool, Alloc>::iterator::operator--(int i)
{
    (void)i;
    iterator it = *this;
    this->_index--;
    return it;
}

template < class Alloc >
bool    vector<bool, Alloc>::iterator::operator!=(const iterator &op) const
{
	return this->_index != op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::iterator::operator==(const iterator &op) const
{
	return this->_index == op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::iterator::operator<(const iterator &op) const
{
	return this->_index < op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::iterator::operator<=(const iterator &op) const
{
	return this->_index <= op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::iterator::operator>(const iterator &op) const
{
	return this->_index > op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::iterator::operator>=(const iterator &op) const
{
	return this->_index >= op._index;
}

template < class Alloc >
typename vector<bool, Alloc>::reference  vector<bool, Alloc>::iterator::operator[](size_type n) const
{
    return this->_container[0][this->_index + n];
}

/* --- Const Iterator Class --- */

template < class Alloc >
vector<bool, Alloc>::const_iterator::const_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class Alloc >
vector<bool, Alloc>::const_iterator::const_iterator(const vector<bool, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class Alloc >
vector<bool, Alloc>::const_iterator::const_iterator(const const_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator     &vector<bool, Alloc>::const_iterator::operator=(const const_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class Alloc >
bool   vector<bool, Alloc>::const_iterator::operator*() const
{
    return this->_container[0][this->_index];
}

template < class Alloc >
bool   vector<bool, Alloc>::const_iterator::operator->() const
{
    return this->_container[0][this->_index];
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    vector<bool, Alloc>::const_iterator::operator+(const const_iterator &op) const
{
    const_iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    vector<bool, Alloc>::const_iterator::operator+(const size_type &op) const
{
    const_iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    vector<bool, Alloc>::const_iterator::operator-(const const_iterator &op) const
{
    const_iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    vector<bool, Alloc>::const_iterator::operator-(const size_type &op) const
{
    const_iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    &vector<bool, Alloc>::const_iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    &vector<bool, Alloc>::const_iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator     &vector<bool, Alloc>::const_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator     vector<bool, Alloc>::const_iterator::operator++(int i)
{
    (void)i;
    const_iterator it = *this;
    this->_index++;
    return it;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    &vector<bool, Alloc>::const_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator    vector<bool, Alloc>::const_iterator::operator--(int i)
{
    (void)i;
    const_iterator it = *this;
    this->_index--;
    return it;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_iterator::operator!=(const const_iterator &op) const
{
	return this->_index != op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_iterator::operator==(const const_iterator &op) const
{
	return this->_index == op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_iterator::operator<(const const_iterator &op) const
{
	return this->_index < op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_iterator::operator<=(const const_iterator &op) const
{
	return this->_index <= op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_iterator::operator>(const const_iterator &op) const
{
	return this->_index > op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_iterator::operator>=(const const_iterator &op) const
{
	return this->_index >= op._index;
}

template < class Alloc >
typename vector<bool, Alloc>::reference  vector<bool, Alloc>::const_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_index + n];
}

/* --- Reverse Iterator Class --- */

template < class Alloc >
vector<bool, Alloc>::reverse_iterator::reverse_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class Alloc >
vector<bool, Alloc>::reverse_iterator::reverse_iterator(vector<bool, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class Alloc >
vector<bool, Alloc>::reverse_iterator::reverse_iterator(const reverse_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator     &vector<bool, Alloc>::reverse_iterator::operator=(const reverse_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class Alloc >
bool   vector<bool, Alloc>::reverse_iterator::operator*() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class Alloc >
bool   vector<bool, Alloc>::reverse_iterator::operator->() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    vector<bool, Alloc>::reverse_iterator::operator+(const reverse_iterator &op) const
{
    reverse_iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    vector<bool, Alloc>::reverse_iterator::operator+(const size_type &op) const
{
    reverse_iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    vector<bool, Alloc>::reverse_iterator::operator-(const reverse_iterator &op) const
{
    reverse_iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    vector<bool, Alloc>::reverse_iterator::operator-(const size_type &op) const
{
    reverse_iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    &vector<bool, Alloc>::reverse_iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    &vector<bool, Alloc>::reverse_iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator     &vector<bool, Alloc>::reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator     vector<bool, Alloc>::reverse_iterator::operator++(int i)
{
    (void)i;
    reverse_iterator it = *this;
    this->_index++;
    return it;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    &vector<bool, Alloc>::reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator    vector<bool, Alloc>::reverse_iterator::operator--(int i)
{
    (void)i;
    reverse_iterator it = *this;
    this->_index--;
    return it;
}

template < class Alloc >
bool    vector<bool, Alloc>::reverse_iterator::operator!=(const reverse_iterator &op) const
{
	return this->_index != op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::reverse_iterator::operator==(const reverse_iterator &op) const
{
	return this->_index == op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::reverse_iterator::operator<(const reverse_iterator &op) const
{
	return this->_index < op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::reverse_iterator::operator<=(const reverse_iterator &op) const
{
	return this->_index <= op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::reverse_iterator::operator>(const reverse_iterator &op) const
{
	return this->_index > op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::reverse_iterator::operator>=(const reverse_iterator &op) const
{
	return this->_index >= op._index;
}

template < class Alloc >
typename vector<bool, Alloc>::reference  vector<bool, Alloc>::reverse_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_container->size() - this->_index - n - 1];
}

/* --- Const Revserse Iterator Class --- */

template < class Alloc >
vector<bool, Alloc>::const_reverse_iterator::const_reverse_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class Alloc >
vector<bool, Alloc>::const_reverse_iterator::const_reverse_iterator(const vector<bool, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class Alloc >
vector<bool, Alloc>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator     &vector<bool, Alloc>::const_reverse_iterator::operator=(const const_reverse_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class Alloc >
bool   vector<bool, Alloc>::const_reverse_iterator::operator*() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class Alloc >
bool   vector<bool, Alloc>::const_reverse_iterator::operator->() const
{
    return this->_container[0][this->_container->size() - this->_index - 1];
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    vector<bool, Alloc>::const_reverse_iterator::operator+(const const_reverse_iterator &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index + op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    vector<bool, Alloc>::const_reverse_iterator::operator+(const size_type &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index + op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    vector<bool, Alloc>::const_reverse_iterator::operator-(const const_reverse_iterator &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index - op._index);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    vector<bool, Alloc>::const_reverse_iterator::operator-(const size_type &op) const
{
    const_reverse_iterator    nw(*this->_container, this->_index - op);
    return nw;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    &vector<bool, Alloc>::const_reverse_iterator::operator+=(const size_type &op)
{
    this->_index += op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    &vector<bool, Alloc>::const_reverse_iterator::operator-=(const size_type &op)
{
    this->_index -= op;
    return (*this);
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator     &vector<bool, Alloc>::const_reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator     vector<bool, Alloc>::const_reverse_iterator::operator++(int i)
{
    (void)i;
    const_reverse_iterator it = *this;
    this->_index++;
    return it;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    &vector<bool, Alloc>::const_reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator    vector<bool, Alloc>::const_reverse_iterator::operator--(int i)
{
    (void)i;
    const_reverse_iterator it = *this;
    this->_index--;
    return it;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_reverse_iterator::operator!=(const const_reverse_iterator &op) const
{
	return this->_index != op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_reverse_iterator::operator==(const const_reverse_iterator &op) const
{
	return this->_index == op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_reverse_iterator::operator<(const const_reverse_iterator &op) const
{
	return this->_index < op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_reverse_iterator::operator<=(const const_reverse_iterator &op) const
{
	return this->_index <= op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_reverse_iterator::operator>(const const_reverse_iterator &op) const
{
	return this->_index > op._index;
}

template < class Alloc >
bool    vector<bool, Alloc>::const_reverse_iterator::operator>=(const const_reverse_iterator &op) const
{
	return this->_index >= op._index;
}

template < class Alloc >
typename vector<bool, Alloc>::reference  vector<bool, Alloc>::const_reverse_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_container->size() - this->_index - n - 1];
}

/* --- Constructors --- */

template < class Alloc >
vector<bool, Alloc>::vector(const allocator_type &alloc)
{
    this->_tab = NULL;
    this->_size = 0;
    this->_capacity = this->_size;
    this->_allocator = new Alloc(alloc);
}

template < class Alloc >
vector<bool, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
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

template <typename Alloc>
template <typename InputIterator>
vector<bool, Alloc>::vector(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc)
{
	this->_allocator = new Alloc(alloc);
	this->_size = 0;
    InputIterator temp = first;
    while (temp != last)
    {
        ++this->_size;
        ++temp;
    }
	this->_capacity = this->_size;
	this->_tab = this->_allocator->allocate(_size);
	int i = 0;
	for (InputIterator it = first; it != last; ++it, ++i)
	{
		this->_allocator->construct(this->_tab + i, *it);
	}
}

template < class Alloc >
vector<bool, Alloc>::vector(const vector &target)
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

template < class Alloc >
vector<bool, Alloc>::~vector()
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

template < class Alloc >
vector<bool, Alloc> &vector<bool, Alloc>::operator=(const vector &target)
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

template < class Alloc >
typename vector<bool, Alloc>::iterator         vector<bool, Alloc>::begin()
{
	return vector<bool, Alloc>::iterator(*this, 0);
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator   vector<bool, Alloc>::begin() const
{
	return vector<bool, Alloc>::const_iterator(*this, 0);
}

template < class Alloc >
typename vector<bool, Alloc>::iterator         vector<bool, Alloc>::end()
{
	return vector<bool, Alloc>::iterator(*this, this->_size);
}

template < class Alloc >
typename vector<bool, Alloc>::const_iterator         vector<bool, Alloc>::end() const
{
	return vector<bool, Alloc>::const_iterator(*this, this->_size);
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator         vector<bool, Alloc>::rbegin()
{
	return vector<bool, Alloc>::reverse_iterator(*this, 0);
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator         vector<bool, Alloc>::rbegin() const
{
	return vector<bool, Alloc>::const_reverse_iterator(*this, 0);
}

template < class Alloc >
typename vector<bool, Alloc>::reverse_iterator         vector<bool, Alloc>::rend()
{
	return vector<bool, Alloc>::reverse_iterator(*this, this->_size);
}

template < class Alloc >
typename vector<bool, Alloc>::const_reverse_iterator         vector<bool, Alloc>::rend() const
{
	return vector<bool, Alloc>::const_reverse_iterator(*this, this->_size);
}

/* --- Capacity --- */

template < class Alloc >
size_t  vector<bool, Alloc>::size() const
{
    return _size;
}

template < class Alloc >
size_t  vector<bool, Alloc>::max_size() const
{
    return this->_allocator->max_size();
}

template < class Alloc >
void    vector<bool, Alloc>::resize(size_type n, value_type val)
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
        bool   *temp = this->_allocator->allocate(n);
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

template < class Alloc >
size_t  vector<bool, Alloc>::capacity() const
{
    return this->_capacity;
}

template < class Alloc >
bool    vector<bool, Alloc>::empty() const
{
    return (this->_size == 0 ? true : false);
}

template < class Alloc >
void    vector<bool, Alloc>::reserve(size_type n)
{
    if (n > this->_allocator->max_size())
    {
        throw std::length_error("vector");
    }
    else if (n > this->_capacity)
    {
        bool   *temp = this->_allocator->allocate(n);
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

template < class Alloc >
typename vector<bool, Alloc>::reference   vector<bool, Alloc>::operator[](size_type n)
{
    reference   ret;
    ret = this->_tab[n];
    return ret;
}

template < class Alloc >
bool vector<bool, Alloc>::operator[](size_type n) const
{
    bool   &ret = this->_tab[n];
    return ret;
}

template < class Alloc >
typename vector<bool, Alloc>::reference vector<bool, Alloc>::at(size_type n)
{
    if (n >= this->_size)
    {
        throw std::out_of_range("vector");
    }
    bool   &ret = this->_tab[n];
    return ret;
}

template < class Alloc >
bool vector<bool, Alloc>::at(size_type n) const
{
    if (n >= this->_size)
    {
        throw std::out_of_range("vector");
    }
    bool   &ret = this->_tab[n];
    return ret;
}

template < class Alloc >
typename vector<bool, Alloc>::reference vector<bool, Alloc>::front()
{
    bool   &ret = this->_tab[0];
    return ret;
}

template < class Alloc >
bool vector<bool, Alloc>::front() const
{
    bool   &ret = this->_tab[0];
    return ret;
}

template < class Alloc >
typename vector<bool, Alloc>::reference vector<bool, Alloc>::back()
{
    bool   &ret = this->_tab[this->_size - 1];
    return ret;
}

template < class Alloc >
bool vector<bool, Alloc>::back() const
{
    bool   &ret = this->_tab[this->_size - 1];
    return ret;
}

/* --- Modifiers --- */

template < class Alloc >
template < class InputIterator >
typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type     vector<bool, Alloc>::assign(InputIterator first, InputIterator last)
{
    int n = 0;
    InputIterator temp = first;

    if (this->_tab != NULL)
    {
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->destroy(&this->_tab[i]);
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
    }
    for (n = 0; temp != last; ++temp)
    {
        ++n;
    }   
    this->_size = n;
    this->_capacity = this->_size;
    this->_tab = this->_allocator->allocate(this->_size);
    for (int i = 0; first != last; ++i, ++first)
    {
        this->_allocator->construct(&this->_tab[i], *first);
    }    
}

template < class Alloc >
void            vector<bool, Alloc>::assign(size_type n, const value_type &val)
{
    if (this->_tab != NULL)
    {
        for (int i = 0; i < (int)this->_size; ++i)
        {
            this->_allocator->destroy(&this->_tab[i]);
        }
        this->_allocator->deallocate(this->_tab, this->_capacity);
    }
    this->_size = n;
    this->_capacity = this->_size;
    this->_tab = this->_allocator->allocate(this->_size);
    for (int i = 0; i < (int)this->_size; ++i)
    {
        this->_allocator->construct(&this->_tab[i], val);
    }   
}

template < class Alloc >
void    vector<bool, Alloc>::push_back(const value_type& val)
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

template < class Alloc >
void    vector<bool, Alloc>::pop_back()
{
    if (this->_size > 0)
    {
        this->_allocator->destroy(&this->_tab[this->_size - 1]);
        this->_size -= 1;
    }
}

template < class Alloc >
typename vector<bool, Alloc>::iterator     vector<bool, Alloc>::insert(iterator position, const value_type& val)
{
    this->insert(position, 1, val);
    return this->begin() + position;
}

template < class Alloc >
void            vector<bool, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
    int i = 0;

    this->reserve(this->_size + n);
    for (iterator it = this->begin(); it != position; ++it)
        ++i;
    bool   temp[this->_size + n - i];
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        temp[j] = this->_tab[i + j];
    }
    for (int j = 0; j < (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], val);
    }
    i += n;
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], temp[j]);
    }
    this->_size += n;
}

template < class Alloc >
template <class InputIterator>
typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    vector<bool, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
{
    int i = 0;
    int n = 0;
    InputIterator temp2 = first;

    while (temp2 != last)
    {
        ++temp2;
        ++n;
    }
    this->reserve(this->_size + n);
    for (iterator it = this->begin(); it != position; ++it)
        ++i;
    bool   temp[this->_size + n - i];
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        temp[j] = this->_tab[i + j];
    }
    for (int j = 0; j < (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], *first);
        ++first;
    }
    i += n;
    for (int j = 0; i + j < (int)this->_size + (int)n; ++j)
    {
        if (i + j < (int)this->_size)
            this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], temp[j]);
    }
    this->_size += n;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator vector<bool, Alloc>::erase(iterator position)
{
    int i = 0;
    iterator temp = this->begin();

    while (temp != position)
    {
        ++i;
        ++temp;
    }
    for (int j = 0; i + j < (int)this->_size - 1; ++j)
    {
        this->_allocator->destroy(&this->_tab[i + j]);
        this->_allocator->construct(&this->_tab[i + j], this->_tab[i + j + 1]);
    }
    this->_allocator->destroy(&this->_tab[this->_size]);
    this->_size -= 1;
    return this->begin() + i;
}

template < class Alloc >
typename vector<bool, Alloc>::iterator        vector<bool, Alloc>::erase(iterator first, iterator last)
{
    int i = 0;
    iterator temp = this->begin();

    while (temp != first)
    {
        ++i;
        ++temp;
    }
    while (first != last)
    {
        for (int j = 0; i + j < (int)this->_size - 1; ++j)
        {
            this->_allocator->destroy(&this->_tab[i + j]);
            this->_allocator->construct(&this->_tab[i + j], this->_tab[i + j + 1]);
        }
        this->_allocator->destroy(&this->_tab[this->_size]);
        this->_size -= 1;
        ++first;
    }
    return this->begin() + i;
}

template < class Alloc >
void    vector<bool, Alloc>::swap(vector& x)
{
    vector<bool, Alloc>  temp(x);
    
    x.assign(this->begin(), this->end());
    this->assign(temp.begin(), temp.end());
}

template < class Alloc >
void    vector<bool, Alloc>::clear()
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        this->_allocator->destroy(&this->_tab[i]);
    }
    this->_size = 0;
}

template < class Alloc >
void    vector<bool, Alloc>::flip()
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        if (this->_tab[i] == 0)
            this->_tab[i] = true;
        else
            this->_tab[i] = false;
    }
}

template < class Alloc >
void     vector<bool, Alloc>::swap(reference ref1, reference ref2)
{
    reference temp = ref1;

    ref1 = ref2;
    ref2 = temp;
}

}

#endif