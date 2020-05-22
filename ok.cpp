

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
typename Alloc::reference  vector<bool, Alloc>::iterator::operator[](size_type n) const
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
typename Alloc::reference  vector<bool, Alloc>::const_iterator::operator[](size_type n) const
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
typename Alloc::reference  vector<bool, Alloc>::reverse_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_container->size() - this->_index + n - 1];
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
typename Alloc::reference  vector<bool, Alloc>::const_reverse_iterator::operator[](size_type n) const
{
    return this->_container[0][this->_container->size() - this->_index + n - 1];
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

template <typename T, typename Alloc>
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

template < class Alloc >
typename Alloc::reference   vector<bool, Alloc>::operator[](size_type n)
{
    // std::cout << "ok" << std::endl;
    T   &ret = this->_tab[n];
    return ret;
}

template < class Alloc >
typename Alloc::const_reference vector<bool, Alloc>::operator[](size_type n) const
{
    T   &ret = this->_tab[n];
    return ret;
}

template < class Alloc >
typename Alloc::reference vector<bool, Alloc>::at(size_type n)
{
    if (n >= this->_size)
    {
        throw std::out_of_range("vector");
    }
    T   &ret = this->_tab[n];
    return ret;
}

template < class Alloc >
typename Alloc::const_reference vector<bool, Alloc>::at(size_type n) const
{
    if (n >= this->_size)
    {
        throw std::out_of_range("vector");
    }
    T   &ret = this->_tab[n];
    return ret;
}

template < class Alloc >
typename Alloc::reference vector<bool, Alloc>::front()
{
    T   &ret = this->_tab[0];
    return ret;
}

template < class Alloc >
typename Alloc::const_reference vector<bool, Alloc>::front() const
{
    T   &ret = this->_tab[0];
    return ret;
}

template < class Alloc >
typename Alloc::reference vector<bool, Alloc>::back()
{
    T   &ret = this->_tab[this->_size - 1];
    return ret;
}

template < class Alloc >
typename Alloc::const_reference vector<bool, Alloc>::back() const
{
    T   &ret = this->_tab[this->_size - 1];
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