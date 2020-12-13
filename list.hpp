#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>

namespace ft
{

template < class T >
struct		s_elem
{
    T               content;
    struct s_elem	*prev;
    struct s_elem	*next;
};

template < class T, class Alloc = std::allocator< T > >
class list
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
		explicit    iterator(list<value_type, allocator_type> &container, int index);
        iterator(const iterator &target);
        iterator    &operator=(const iterator &target);
        ~iterator() {}
		value_type  operator*() const;
		iterator    &operator++();
		iterator    operator++(int);
        iterator    &operator--();
		iterator    operator--(int);
		bool        operator!=(const iterator &op) const;
        bool        operator==(const iterator &op) const;

	    private:
		int         _index;
		list        *_container;
	};

    class const_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        const_iterator();
		explicit    const_iterator(const list<value_type, allocator_type> &container, int index);
        const_iterator(const const_iterator &target);
        const_iterator    &operator=(const const_iterator &target);
        ~const_iterator() {}
		value_type  operator*() const;
		const_iterator    &operator++();
		const_iterator    operator++(int);
        const_iterator    &operator--();
		const_iterator    operator--(int);
		bool        operator!=(const const_iterator &op) const;
        bool        operator==(const const_iterator &op) const;

	    private:
		int         _index;
		const list        *_container;
	};

    class reverse_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        reverse_iterator();
		explicit    reverse_iterator(list<value_type, allocator_type> &container, int index);
        reverse_iterator(const reverse_iterator &target);
        reverse_iterator    &operator=(const reverse_iterator &target);
        ~reverse_iterator() {}
		value_type  operator*() const;
		reverse_iterator    &operator++();
		reverse_iterator    operator++(int);
        reverse_iterator    &operator--();
		reverse_iterator    operator--(int);
		bool        operator!=(const reverse_iterator &op) const;
        bool        operator==(const reverse_iterator &op) const;

	    private:
		int         _index;
		list        *_container;
	};

    class const_reverse_iterator
	{
	    public:
        typedef ptrdiff_t   difference_type;

        const_reverse_iterator();
		explicit    const_reverse_iterator(const list<value_type, allocator_type> &container, int index);
        const_reverse_iterator(const const_reverse_iterator &target);
        const_reverse_iterator    &operator=(const const_reverse_iterator &target);
        ~const_reverse_iterator() {}
		value_type  operator*() const;
		const_reverse_iterator    &operator++();
		const_reverse_iterator    operator++(int);
        const_reverse_iterator    &operator--();
		const_reverse_iterator    operator--(int);
		bool        operator!=(const const_reverse_iterator &op) const;
        bool        operator==(const const_reverse_iterator &op) const;

	    private:
		int         _index;
		const list        *_container;
	};

    typedef typename iterator::difference_type  difference_type;

    explicit list(const allocator_type &alloc = allocator_type());
    explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
    template <class InputIterator>
    list(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type());
    list(const list &target);
    list &operator=(const list &target);
    ~list();

    iterator                begin();
    const_iterator          begin() const;
    iterator                end();
    const_iterator          end() const;
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;

    bool        empty() const;
    size_type   size() const;
    size_type   max_size() const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    void            assign(size_type n, const value_type &val);
    template < class InputIterator >
    typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    assign(InputIterator first, InputIterator last);
    void            push_front(const value_type &val);
    void            pop_front();
    void            push_back(const value_type &val);
    void            pop_back();
    iterator        insert (iterator position, const value_type& val);
    void            insert (iterator position, size_type n, const value_type& val);
    template <class InputIterator>
    typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    insert (iterator position, InputIterator first, InputIterator last);
    typename list<T, Alloc>::iterator        erase(iterator position);
    typename list<T, Alloc>::iterator        erase(iterator first, iterator last);
    void            swap(list& x);
    void            resize (size_type n, value_type val = value_type());
    void            clear();

    void            splice (iterator position, list& x);
    void            splice (iterator position, list& x, iterator i);
    void            splice (iterator position, list& x, iterator first, iterator last);
    void            remove (const value_type& val);
    template <class Predicate>
    void            remove_if (Predicate pred);
    void            unique();
    template <class BinaryPredicate>
    void            unique (BinaryPredicate binary_pred);
    void            merge (list& x);
    template <class Compare>
    void            merge (list& x, Compare comp);
    void            sort();
    template <class Compare>
    void            sort (Compare comp);
    void            reverse();

    friend bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        struct s_elem<T> *temp(lhs._first);
        struct s_elem<T> *temp2(rhs._first);

        if (lhs.size() != rhs.size())
            return false;
        for (int i = 0; i < (int)lhs.size(); ++i)
        {
            if (temp->content != temp2->content)
                return false;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
    friend bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    friend bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        struct s_elem<T> *temp(lhs._first);
        struct s_elem<T> *temp2(rhs._first);

        if (lhs.size() != rhs.size())
            return lhs.size() < rhs.size();
        for (int i = 0; i < (int)lhs.size(); ++i)
        {
            if (temp->content != temp2->content)
                return temp->content < temp2->content;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
    friend bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    friend bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }
    friend bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
    friend void swap (list<T,Alloc>& x, list<T,Alloc>& y)
    {
        list<T, Alloc>  temp(x);
    
        x.assign(y.begin(), y.end());
        y.assign(temp.begin(), temp.end());
    }

    private:
    size_type           _size;
    struct s_elem<T>    *_first;
    Alloc               *_allocator;
    T                   *_zero;
    bool                check_iterators(iterator first, iterator last);
};

/* --- Constructors --- */

template < class T, class Alloc >
list<T, Alloc>::list(const allocator_type &alloc)
{
    this->_first = NULL;
    this->_allocator = new Alloc(alloc);
    this->_size = 0;
    this->_zero = new T();
}

template < class T, class Alloc >
list<T, Alloc>::list(size_type n, const value_type &val, const allocator_type &alloc)
{
    struct s_elem<T> *temp;
    struct s_elem<T> *prev_temp;

    (n < 0) ? throw std::length_error("list") : 0;
    this->_allocator = new Alloc(alloc);
    this->_size = n;
    this->_zero = new T();
    this->_first = NULL;
    for (int i = 0; i < (int)n; ++i)
    {
        if (i == 0)
        {
            this->_first = new struct s_elem<T>;
            temp = this->_first;
            temp->content = val;
            temp->prev = NULL;
            if (i == (int)n - 1)
                temp->next = NULL;
            else
                temp->next = new struct s_elem<T>;
        }
        else if (i == (int)n - 1)
        {
            temp->content = val;
            temp->prev = prev_temp;
            temp->next = NULL;
        }
        else
        {
            temp->content = val;
            temp->prev = prev_temp;
            temp->next = new struct s_elem<T>;
        }
        prev_temp = temp;
        temp = temp->next;
    }
}

template <typename T, typename Alloc>
template <typename InputIterator>
list<T, Alloc>::list(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc)
{
	struct s_elem<T> *temp;
    struct s_elem<T> *prev_temp;
    InputIterator   it = first;

    // iterator    my_first = this->begin();
    // iterator    my_last = this->end();
    // int         n = 0;
    // while (my_first != my_last)
    // {
    //     if (n == 0 && first == my_first)
    //         n = 1;
    //     if (n == 1 && last == my_last)
    //         n = 2;
    //     ++my_first;
    // }
    // if (this->check_iterators(first, last) == 0)
    // {
    //     list(1, 1);
    //     return ;
    // }

    this->_allocator = new Alloc(alloc);
    this->_size = 0;
    this->_zero = new T();
    while (it != last)
    {
        ++it;
        ++(this->_size);
    }
    this->_first = NULL;
    for (int i = 0; i < (int)this->_size; ++i)
    {
        if (i == 0)
        {
            this->_first = new struct s_elem<T>;
            temp = this->_first;
            temp->content = *first;
            temp->prev = NULL;
            if (i == (int)this->_size - 1)
                temp->next = NULL;
            else
                temp->next = new struct s_elem<T>;
        }
        else if (i == (int)this->_size - 1)
        {
            temp->content = *first;
            temp->prev = prev_temp;
            temp->next = NULL;
        }
        else
        {
            temp->content = *first;
            temp->prev = prev_temp;
            temp->next = new struct s_elem<T>;
        }
        prev_temp = temp;
        temp = temp->next;
        ++first;
    }
}

template < class T, class Alloc >
list<T, Alloc>::list(const list &target)
{
    struct s_elem<T> *temp;
    struct s_elem<T> *prev_temp;
    typename ft::list<T>::const_iterator   it = target.begin();

    if (target._first == NULL)
    {
        this->_first = NULL;
        this->_size = 0;
        this->_allocator = new Alloc;
        this->_zero = new T();
    }
    else
    {
        this->_allocator = new Alloc;
        this->_zero = new T();
        this->_size = target.size();
        for (int i = 0; i < (int)this->_size; ++i)
        {
            if (i == 0)
            {
                this->_first = new struct s_elem<T>;
                temp = this->_first;
                temp->content = *it;
                temp->prev = NULL;
                if (i == (int)this->_size - 1)
                    temp->next = NULL;
                else
                    temp->next = new struct s_elem<T>;
            }
            else if (i == (int)this->_size - 1)
            {
                temp->content = *it;
                temp->prev = prev_temp;
                temp->next = NULL;
            }
            else
            {
                temp->content = *it;
                temp->prev = prev_temp;
                temp->next = new struct s_elem<T>;
            }
            prev_temp = temp;
            temp = temp->next;
            ++it;
        }
    }
}

// /* --- Destructor --- */

template < class T, class Alloc >
list<T, Alloc>::~list()
{
    struct s_elem<T> *temp;

    while (this->_first != NULL)
    {
        temp = this->_first;
        this->_first = this->_first->next;
        delete temp;
    }
    delete this->_allocator;
    delete this->_zero;
}

// /* --- Assignation --- */

template < class T, class Alloc >
list<T, Alloc> &list<T, Alloc>::operator=(const list &target)
{
    struct s_elem<T> *temp;
    struct s_elem<T> *prev_temp;
    typename ft::list<T>::const_iterator   it = target.begin();

    while (this->_first != NULL)
    {
        temp = this->_first;
        this->_first = this->_first->next;
        delete temp;
    }
    if (target._first == NULL)
    {
        this->_first = NULL;
        this->_size = 0;
        this->_allocator = new Alloc;
    }
    else
    {
        this->_allocator = new Alloc;
        this->_size = target.size();
        for (int i = 0; i < (int)this->_size; ++i)
        {
            if (i == 0)
            {
                this->_first = new struct s_elem<T>;
                temp = this->_first;
                temp->content = *it;
                temp->prev = NULL;
                if (i == (int)this->_size - 1)
                    temp->next = NULL;
                else
                    temp->next = new struct s_elem<T>;
            }
            else if (i == (int)this->_size - 1)
            {
                temp->content = *it;
                temp->prev = prev_temp;
                temp->next = NULL;
            }
            else
            {
                temp->content = *it;
                temp->prev = prev_temp;
                temp->next = new struct s_elem<T>;
            }
            prev_temp = temp;
            temp = temp->next;
            ++it;
        }
    }
    return *this;
}

/* --- Iterators Functions --- */

template < class T, class Alloc >
typename list<T, Alloc>::iterator         list<T, Alloc>::begin()
{
	return list<T, Alloc>::iterator(*this, 0);
}

template < class T, class Alloc >
typename list<T, Alloc>::const_iterator   list<T, Alloc>::begin() const
{
	return list<T, Alloc>::const_iterator(*this, 0);
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator         list<T, Alloc>::end()
{
	return list<T, Alloc>::iterator(*this, this->_size);
}

template < class T, class Alloc >
typename list<T, Alloc>::const_iterator         list<T, Alloc>::end() const
{
	return list<T, Alloc>::const_iterator(*this, this->_size);
}

template < class T, class Alloc >
typename list<T, Alloc>::reverse_iterator         list<T, Alloc>::rbegin()
{
	return list<T, Alloc>::reverse_iterator(*this, 0);
}

template < class T, class Alloc >
typename list<T, Alloc>::const_reverse_iterator         list<T, Alloc>::rbegin() const
{
	return list<T, Alloc>::const_reverse_iterator(*this, 0);
}

template < class T, class Alloc >
typename list<T, Alloc>::reverse_iterator         list<T, Alloc>::rend()
{
	return list<T, Alloc>::reverse_iterator(*this, this->_size);
}

template < class T, class Alloc >
typename list<T, Alloc>::const_reverse_iterator         list<T, Alloc>::rend() const
{
	return list<T, Alloc>::const_reverse_iterator(*this, this->_size);
}

/* --- Capacity --- */

template < class T, class Alloc >
size_t  list<T, Alloc>::size() const
{
    return this->_size;
}

template < class T, class Alloc >
size_t  list<T, Alloc>::max_size() const
{
    return this->_allocator->max_size();
}

template < class T, class Alloc >
bool    list<T, Alloc>::empty() const
{
    return (this->_size == 0 ? true : false);
}

/* --- Element access --- */

template < class T, class Alloc >
typename Alloc::reference list<T, Alloc>::front()
{
    if (this->_first == NULL)
    {
        T   &ret = *this->_zero;
        return ret;
    }
    T   &ret = this->_first->content;
    return ret;
}

template < class T, class Alloc >
typename Alloc::const_reference list<T, Alloc>::front() const
{
    if (this->_first == NULL)
    {
        T   &ret = *this->_zero;
        return ret;
    }
    T   &ret = this->_first->content;
    return ret;
}

template < class T, class Alloc >
typename Alloc::reference list<T, Alloc>::back()
{
    struct s_elem<T>    *tmp;
    tmp = this->_first;

    if (this->_first == NULL)
    {
        T   &ret = *this->_zero;
        return ret;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    T   &ret = tmp->content;
    return ret;
}

template < class T, class Alloc >
typename Alloc::const_reference list<T, Alloc>::back() const
{
    struct s_elem<T>    *tmp;
    tmp = this->_first;

    if (this->_first == NULL)
    {
        T   &ret = *this->_zero;
        return ret;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    T   &ret = tmp->content;
    return ret;
}

/* --- Modifiers --- */

template < class T, class Alloc >
template < class InputIterator >
typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type     list<T, Alloc>::assign(InputIterator first, InputIterator last)
{
    struct s_elem<T> *temp;
    struct s_elem<T> *prev_temp;
    InputIterator   it = first;

    while (this->_first != NULL)
    {
        temp = this->_first;
        this->_first = this->_first->next;
        delete temp;
    }

    this->_size = 0;
    while (it != last)
    {
        ++it;
        ++(this->_size);
    }
    this->_first = NULL;
    for (int i = 0; i < (int)this->_size; ++i)
    {
        if (i == 0)
        {
            this->_first = new struct s_elem<T>;
            temp = this->_first;
            temp->content = *first;
            temp->prev = NULL;
            if (i == (int)this->_size - 1)
                temp->next = NULL;
            else
                temp->next = new struct s_elem<T>;
        }
        else if (i == (int)this->_size - 1)
        {
            temp->content = *first;
            temp->prev = prev_temp;
            temp->next = NULL;
        }
        else
        {
            temp->content = *first;
            temp->prev = prev_temp;
            temp->next = new struct s_elem<T>;
        }
        prev_temp = temp;
        temp = temp->next;
        ++first;
    }   
}

template < class T, class Alloc >
void            list<T, Alloc>::assign(size_type n, const value_type &val)
{
    struct s_elem<T> *temp;
    struct s_elem<T> *prev_temp;

    while (this->_first != NULL)        
    {
        temp = this->_first;
        this->_first = this->_first->next;
        delete temp;
    }
    this->_size = n;
    this->_first = NULL;
    for (int i = 0; i < (int)n; ++i)
    {
        if (i == 0)
        {
            this->_first = new struct s_elem<T>;
            temp = this->_first;
            temp->content = val;
            temp->prev = NULL;
            if (i == (int)n - 1)
                temp->next = NULL;
            else
                temp->next = new struct s_elem<T>;
        }
        else if (i == (int)n - 1)
        {
            temp->content = val;
            temp->prev = prev_temp;
            temp->next = NULL;
        }
        else
        {
            temp->content = val;
            temp->prev = prev_temp;
            temp->next = new struct s_elem<T>;
        }
        prev_temp = temp;
        temp = temp->next;
    }
}

template < class T, class Alloc >
void    list<T, Alloc>::push_front(const value_type& val)
{
    struct s_elem<T> *temp;
    
    temp = new struct s_elem<T>;
    temp->content = val;
    temp->prev = NULL;
    temp->next = this->_first;
    if (this->_first != NULL)
        this->_first->prev = temp;
    this->_first = temp;
    this->_size += 1;
}

template < class T, class Alloc >
void    list<T, Alloc>::pop_front()
{
    struct s_elem<T> *temp;

    if (this->_first != NULL)
    {
        temp = this->_first;
        this->_first = this->_first->next;
        if (this->_first != NULL)
            this->_first->prev = NULL;
        delete temp;
        this->_size -= 1;
    }
}

template < class T, class Alloc >
void    list<T, Alloc>::push_back(const value_type& val)
{
    struct s_elem<T> *temp;
    struct s_elem<T> *temp2;
    
    temp = new struct s_elem<T>;
    temp->content = val;
    temp2 = this->_first;
    if (temp2 != NULL)
    {
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;;
        }
    }
    temp2->next = temp;
    temp->prev = temp2;
    temp->next = NULL;
    this->_size += 1;
}

template < class T, class Alloc >
void    list<T, Alloc>::pop_back()
{
    struct s_elem<T> *temp2;

    if (this->_size == 1)
    {
        temp2 = this->_first;
        this->_first = NULL;
        delete temp2;
        this->_size -= 1;
        return ;
    }
    temp2 = this->_first;
    if (temp2 != NULL)
    {
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;;
        }
        if (temp2->prev != NULL)
            temp2->prev->next = NULL;
        delete temp2;
        this->_size -= 1;
    }
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator     list<T, Alloc>::insert(iterator position, const value_type& val)
{
    iterator it = this->begin();

    while (it != position)
        ++it;
    this->insert(position, 1, val);
    return it;
}

template < class T, class Alloc >
void            list<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
    struct s_elem<T> *nw;
    struct s_elem<T> *prev;
    struct s_elem<T> *next;
    struct s_elem<T> *prev_temp = NULL;
    int              i = 0;
    iterator    it = this->begin();

    this->_size += n;
    prev = this->_first;
    while (it != position)
    {
        ++it;
        prev_temp = prev;
        prev = prev->next;
        ++i;
    }
    next = prev;
    if (prev_temp != NULL)
        prev = prev_temp;
    else
        prev = NULL;
    for (int j = 0; j < (int)n; ++j)
    {
        if (i + j == 0)
        {
            nw = new struct s_elem<T>;
            this->_first = nw;
            nw->content = val;
            nw->prev = NULL;
            if (j == (int)n - 1 && i + j == (int)this->_size - 1)
                nw->next = NULL;
            else if (j == (int)n - 1)
                nw->next = next;
            else
                nw->next = new struct s_elem<T>;
        }
        else if (j == 0)
        {
            nw = new struct s_elem<T>;
            prev->next = nw;
            nw->content = val;
            nw->prev = prev;
            if (j == (int)n - 1 && i + j == (int)this->_size - 1)
                nw->next = NULL;
            else if (j == (int)n - 1)
                nw->next = next;
            else
                nw->next = new struct s_elem<T>;
        }
        else if (j == (int)n - 1 && i + j == (int)this->_size - 1)
        {
            nw->content = val;
            nw->prev = prev;
            nw->next = NULL;
        }
        else if (j == (int)n - 1)
        {
            nw->content = val;
            nw->prev = prev;
            nw->next = next;
        }
        else
        {
            nw->content = val;
            nw->prev = prev;
            nw->next = new struct s_elem<T>;
        }
        prev = nw;
        nw = nw->next;
    }
}

template < class T, class Alloc >
template <class InputIterator>
typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type    list<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
{
    struct s_elem<T> *nw;
    struct s_elem<T> *prev;
    struct s_elem<T> *next;
    struct s_elem<T> *prev_temp = NULL;
    int              i = 0;
    iterator    it = this->begin();
    int n = 0;

    InputIterator it_temp = first;
    while (it_temp != last)
    {
        ++it_temp;
        ++n;
    }

    this->_size += n;
    prev = this->_first;
    while (it != position)
    {
        ++it;
        prev_temp = prev;
        prev = prev->next;
        ++i;
    }
    next = prev;
    if (prev_temp != NULL)
        prev = prev_temp;
    else
        prev = NULL;
    for (int j = 0; j < (int)n; ++j)
    {
        if (i + j == 0)
        {
            nw = new struct s_elem<T>;
            this->_first = nw;
            nw->content = *first;
            nw->prev = NULL;
            if (j == (int)n - 1 && i + j == (int)this->_size - 1)
                nw->next = NULL;
            else if (j == (int)n - 1)
                nw->next = next;
            else
                nw->next = new struct s_elem<T>;
        }
        else if (j == 0)
        {
            nw = new struct s_elem<T>;
            prev->next = nw;
            nw->content = *first;
            nw->prev = prev;
            if (j == (int)n - 1 && i + j == (int)this->_size - 1)
                nw->next = NULL;
            else if (j == (int)n - 1)
                nw->next = next;
            else
                nw->next = new struct s_elem<T>;
        }
        else if (j == (int)n - 1 && i + j == (int)this->_size - 1)
        {
            nw->content = *first;
            nw->prev = prev;
            nw->next = NULL;
        }
        else if (j == (int)n - 1)
        {
            nw->content = *first;
            nw->prev = prev;
            nw->next = next;
        }
        else
        {
            nw->content = *first;
            nw->prev = prev;
            nw->next = new struct s_elem<T>;
        }
        prev = nw;
        nw = nw->next;
        ++first;
    }
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator list<T, Alloc>::erase(iterator position)
{
    struct s_elem<T> *prev;
    struct s_elem<T> *next;
    struct s_elem<T> *prev_temp = NULL;
    int              i = 0;
    iterator         it = this->begin();

    this->_size -= 1;
    prev = this->_first;
    while (it != position)
    {
        ++it;
        prev_temp = prev;
        prev = prev->next;
        ++i;
    }
    if (prev != NULL)
        next = prev->next;
    else
        next = NULL;
    if (i == 0)
        this->_first = next;
    delete prev;
    if (prev_temp != NULL)
        prev_temp->next = next;
    else
        prev = NULL;
    if (next != NULL)
        next->prev = prev_temp;
    return it;
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator        list<T, Alloc>::erase(iterator first, iterator last)
{
    iterator    tmp = first;
    
    if (this->check_iterators(first, last) == 0)
        return first;
    while (tmp != last)
    {
        ++tmp;
    }
    --tmp;
    while (tmp != first)
    {
        this->erase(tmp);
        --tmp;
    }
    this->erase(tmp);
    return first;
}

template < class T, class Alloc >
void    list<T, Alloc>::swap(list& x)
{
    list<T, Alloc>  temp(x);
    
    x.assign(this->begin(), this->end());
    this->assign(temp.begin(), temp.end());
}

template < class T, class Alloc >
void    list<T, Alloc>::clear()
{
    struct s_elem<T> *temp;

    while (this->_first != NULL)
    {
        temp = this->_first;
        this->_first = this->_first->next;
        delete temp;
    }
    this->_size = 0;
}

template < class T, class Alloc >
void     list<T, Alloc>::resize (size_type n, value_type val)
{
    int len = this->_size;
    if (n <= this->_size)
    {
        for (int i = 0; i < (int)(len - n); ++i)
        {
            this->pop_back();
        }
        return ;
    }
    for (int i = 0; i < (int)(n - this->_size + 1); ++i)
    {
        this->push_back(val);
    }
}

template < class T, class Alloc >
void     list<T, Alloc>::remove (const value_type& val)
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (*temp == val)
            {
                this->erase(temp);
            }
            ++temp;
        }
    }
}

template < class T, class Alloc >
template <class Predicate>
void     list<T, Alloc>::remove_if (Predicate pred)
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (pred(*temp))
            {
                this->erase(temp);
            }
            ++temp;
        }
    }
}

template < class T, class Alloc >
void    list<T, Alloc>::unique()
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        T   next;
        int j = 0;
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (j < (int)this->_size - 1)
            {
                ++temp;
                next = *temp;
                --temp;
                if (*temp == next)
                {
                    this->erase(temp);
                }
            }
            ++j;
            ++temp;
        }
    }
}

template < class T, class Alloc >
template <class BinaryPredicate>
void    list<T, Alloc>::unique (BinaryPredicate binary_pred)
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        T   next;
        int j = 0;
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (j < (int)this->_size - 1)
            {
                ++temp;
                next = *temp;
                --temp;
                if (binary_pred(*temp, next))
                {
                    this->erase(temp);
                }
            }
            ++j;
            ++temp;
        }
    }
}

/* --- Operations --- */

template < class T, class Alloc >
void            list<T, Alloc>::splice (iterator position, list& x)
{
    this->insert(position, x.begin(), x.end());
    x.erase(x.begin(), x.end());
}

template < class T, class Alloc >
void            list<T, Alloc>::splice (iterator position, list& x, iterator i)
{
    this->insert(position, i, ++i);
    x.erase(i);
}

template < class T, class Alloc >
void            list<T, Alloc>::splice (iterator position, list& x, iterator first, iterator last)
{
    this->insert(position, first, last);
    x.erase(first, last);
}

template < class T, class Alloc >
void            list<T, Alloc>::merge (list& x)
{
    if (&x == this)
        return ;
    this->insert(this->end(), x.begin(), x.end());
    x.clear();

    for (int i = 0; i < (int)this->_size; ++i)
    {
        T   next;
        int j = 0;
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (j < (int)this->_size - 1)
            {
                ++temp;
                next = *temp;
                --temp;
                if (*temp > next)
                {
                    struct s_elem<T> *temp_first = this->_first;
                    iterator temp2 = this->begin();
                    while (temp2 != temp)
                    {
                        ++temp2;
                        temp_first = temp_first->next;
                    }
                    temp_first->next->content = temp_first->content;
                    temp_first->content = next;
                }
            }
            ++j;
            ++temp;
        }
    }
}

template < class T, class Alloc >
template <class Compare>
void            list<T, Alloc>::merge (list& x, Compare comp)
{
    if (&x == this)
        return ;
    this->insert(this->end(), x.begin(), x.end());
    x.clear();

    for (int i = 0; i < (int)this->_size; ++i)
    {
        T   next;
        int j = 0;
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (j < (int)this->_size - 1)
            {
                ++temp;
                next = *temp;
                --temp;
                if (comp(*temp, next))
                {
                    struct s_elem<T> *temp_first = this->_first;
                    iterator temp2 = this->begin();
                    while (temp2 != temp)
                    {
                        ++temp2;
                        temp_first = temp_first->next;
                    }
                    temp_first->next->content = temp_first->content;
                    temp_first->content = next;
                }
            }
            ++j;
            ++temp;
        }
    }
}

template < class T, class Alloc >
void            list<T, Alloc>::sort()
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        T   next;
        int j = 0;
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (j < (int)this->_size - 1)
            {
                ++temp;
                next = *temp;
                --temp;
                if (*temp > next)
                {
                    struct s_elem<T> *temp_first = this->_first;
                    iterator temp2 = this->begin();
                    while (temp2 != temp)
                    {
                        ++temp2;
                        temp_first = temp_first->next;
                    }
                    temp_first->next->content = temp_first->content;
                    temp_first->content = next;
                }
            }
            ++j;
            ++temp;
        }
    }
}

template < class T, class Alloc >
template <class Compare>
void            list<T, Alloc>::sort (Compare comp)
{
    for (int i = 0; i < (int)this->_size; ++i)
    {
        T   next;
        int j = 0;
        iterator temp = this->begin();
        while (temp != this->end())
        {
            if (j < (int)this->_size - 1)
            {
                ++temp;
                next = *temp;
                --temp;
                if (comp(*temp, next))
                {
                    struct s_elem<T> *temp_first = this->_first;
                    iterator temp2 = this->begin();
                    while (temp2 != temp)
                    {
                        ++temp2;
                        temp_first = temp_first->next;
                    }
                    temp_first->next->content = temp_first->content;
                    temp_first->content = next;
                }
            }
            ++j;
            ++temp;
        }
    }
}

template < class T, class Alloc >
void            list<T, Alloc>::reverse()
{
    struct s_elem<T> *temp = this->_first;
    struct s_elem<T> *temp_first = this->_first;
    struct s_elem<T> *temp_bef = NULL;

    while (temp_first != NULL)
    {
        temp = temp_first->next;
        temp_first->next = temp_first->prev;
        temp_first->prev = temp;
        temp_bef = temp_first;
        temp_first = temp_first->prev;
    }
    this->_first = temp_bef;
}

/* --- Iterator Class --- */

template < class T, class Alloc >
list<T, Alloc>::iterator::iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
list<T, Alloc>::iterator::iterator(list<T, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class T, class Alloc >
list<T, Alloc>::iterator::iterator(const iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator     &list<T, Alloc>::iterator::operator=(const iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   list<T, Alloc>::iterator::operator*() const
{
    struct s_elem<T> *temp = this->_container->_first;

    for (int i = 0; i < this->_index; ++i)
    {
        temp = temp->next;
    }
    return temp->content;
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator     &list<T, Alloc>::iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator     list<T, Alloc>::iterator::operator++(int i)
{
    (void)i;
    iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator    &list<T, Alloc>::iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::iterator    list<T, Alloc>::iterator::operator--(int i)
{
    (void)i;
    iterator it = *this;
    this->_index--;
    return it;
}

template < class T, class Alloc >
bool    list<T, Alloc>::iterator::operator!=(const iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    list<T, Alloc>::iterator::operator==(const iterator &op) const
{
	return this->_index == op._index;
}

/* --- Const Iterator Class --- */

template < class T, class Alloc >
list<T, Alloc>::const_iterator::const_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
list<T, Alloc>::const_iterator::const_iterator(const list<T, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class T, class Alloc >
list<T, Alloc>::const_iterator::const_iterator(const const_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_iterator     &list<T, Alloc>::const_iterator::operator=(const const_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   list<T, Alloc>::const_iterator::operator*() const
{
    struct s_elem<T> *temp = this->_container->_first;

    for (int i = 0; i < this->_index; ++i)
    {
        temp = temp->next;
    }
    return temp->content;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_iterator     &list<T, Alloc>::const_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_iterator     list<T, Alloc>::const_iterator::operator++(int i)
{
    (void)i;
    const_iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_iterator    &list<T, Alloc>::const_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_iterator    list<T, Alloc>::const_iterator::operator--(int i)
{
    (void)i;
    const_iterator it = *this;
    this->_index--;
    return it;
}

template < class T, class Alloc >
bool    list<T, Alloc>::const_iterator::operator!=(const const_iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    list<T, Alloc>::const_iterator::operator==(const const_iterator &op) const
{
	return this->_index == op._index;
}

/* --- Reverse Iterator Class --- */

template < class T, class Alloc >
list<T, Alloc>::reverse_iterator::reverse_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
list<T, Alloc>::reverse_iterator::reverse_iterator(list<T, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class T, class Alloc >
list<T, Alloc>::reverse_iterator::reverse_iterator(const reverse_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename list<T, Alloc>::reverse_iterator     &list<T, Alloc>::reverse_iterator::operator=(const reverse_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   list<T, Alloc>::reverse_iterator::operator*() const
{
    struct s_elem<T> *temp = this->_container->_first;

    for (int i = 0; i < (int)this->_container->size() - this->_index - 1; ++i)
    {
        temp = temp->next;
    }
    return temp->content;
}

template < class T, class Alloc >
typename list<T, Alloc>::reverse_iterator     &list<T, Alloc>::reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::reverse_iterator     list<T, Alloc>::reverse_iterator::operator++(int i)
{
    (void)i;
    reverse_iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename list<T, Alloc>::reverse_iterator    &list<T, Alloc>::reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::reverse_iterator    list<T, Alloc>::reverse_iterator::operator--(int i)
{
    (void)i;
    reverse_iterator it = *this;
    this->_index--;
    return it;
}

template < class T, class Alloc >
bool    list<T, Alloc>::reverse_iterator::operator!=(const reverse_iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    list<T, Alloc>::reverse_iterator::operator==(const reverse_iterator &op) const
{
	return this->_index == op._index;
}

/* --- Const Reverse Iterator Class --- */

template < class T, class Alloc >
list<T, Alloc>::const_reverse_iterator::const_reverse_iterator()
{
    this->_container = NULL;
	this->_index = 0;
}

template < class T, class Alloc >
list<T, Alloc>::const_reverse_iterator::const_reverse_iterator(const list<T, Alloc> &container, int index) : _container(&container)
{
	this->_index = index;
}

template < class T, class Alloc >
list<T, Alloc>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator &target) : _container(target._container)
{
	this->_index = target._index;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_reverse_iterator     &list<T, Alloc>::const_reverse_iterator::operator=(const const_reverse_iterator &target)
{
    this->_container = target._container;
	this->_index = target._index;
    return (*this);
}

template < class T, class Alloc >
T   list<T, Alloc>::const_reverse_iterator::operator*() const
{
    struct s_elem<T> *temp = this->_container->_first;

    for (int i = 0; i < (int)this->_container->size() - this->_index - 1; ++i)
    {
        temp = temp->next;
    }
    return temp->content;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_reverse_iterator     &list<T, Alloc>::const_reverse_iterator::operator++()
{
	this->_index++;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_reverse_iterator     list<T, Alloc>::const_reverse_iterator::operator++(int i)
{
    (void)i;
    const_reverse_iterator it = *this;
    this->_index++;
    return it;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_reverse_iterator    &list<T, Alloc>::const_reverse_iterator::operator--()
{
	this->_index--;
	return *this;
}

template < class T, class Alloc >
typename list<T, Alloc>::const_reverse_iterator    list<T, Alloc>::const_reverse_iterator::operator--(int i)
{
    (void)i;
    const_reverse_iterator it = *this;
    this->_index--;
    return it;
}

template < class T, class Alloc >
bool    list<T, Alloc>::const_reverse_iterator::operator!=(const const_reverse_iterator &op) const
{
	return this->_index != op._index;
}

template < class T, class Alloc >
bool    list<T, Alloc>::const_reverse_iterator::operator==(const const_reverse_iterator &op) const
{
	return this->_index == op._index;
}

template < class T, class Alloc >
bool    list<T, Alloc>::check_iterators(iterator first, iterator last)
{
    iterator    my_first = this->begin();
    iterator    my_last = this->end();
    int         n = 0;

    while (my_first != my_last)
    {
        if (n == 0 && first == my_first)
            n = 1;
        if (n == 1 && last == my_last)
            n = 2;
        ++my_first;
    }
    return n == 2;
}


}

#endif