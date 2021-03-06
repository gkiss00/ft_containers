#ifndef MAP_HPP
# define MAP_HPP

# include "./utils/ft_map_node.hpp"
# include <stdio.h>
# include <iostream>
# include <utility>
# include <functional>
# include <memory>

namespace ft {

template<class K, class V, class Compare = std::less<K>, class Alloc = std::allocator<ft_map_node<K, V> > >
class map {
    public:
        typedef K key_type;
        typedef V mapped_type;
        typedef std::pair<K, V> value_type;
        class key_compare {
            private:
                Compare cmp;
                key_compare(Compare c) : cmp(c) {}
        };
        class value_compare {
            private:
                Compare cmp;
                
            public:
                value_compare(Compare c) : cmp(c) {}
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return cmp(x.first, y.first);
                }
        };
        class iterator {
            private:
                map<K, V, Compare, Alloc> &target;
                unsigned int index;
                std::pair<K, V> *tab;
                iterator();
            public:
                K first;
                V second;
                explicit iterator(map<K, V, Compare, Alloc> &target, unsigned int index);
                iterator(const iterator &target);
                iterator &operator=(map<K, V, Compare, Alloc>::iterator &target);
                ~iterator();

                iterator &operator++();
                iterator &operator--();
                iterator &operator++(int);
                iterator &operator--(int);
                std::pair<K, V> &operator*();
                bool operator==(map::iterator &target);
                bool operator!=(map::iterator &target);
        };
        class const_iterator {
            private:
                const map<K, V, Compare, Alloc> &target;
                unsigned int index;
                std::pair<K, V> *tab;
                const_iterator();
            public:
                K first;
                V second;
                const_iterator(map<K, V, Compare, Alloc> &target, unsigned int index);
                const_iterator(const map<K, V, Compare, Alloc>::const_iterator &target);
                const_iterator &operator=(map<K, V, Compare, Alloc>::const_iterator &target);
                ~const_iterator();

                const_iterator &operator++();
                const_iterator &operator--();
                const_iterator &operator++(int);
                const_iterator &operator--(int);
                bool operator==(map::const_iterator &target);
                bool operator!=(map::const_iterator &target);
        };
        class reverse_iterator {
            private:
                map<K, V, Compare, Alloc> &target;
                unsigned int index;
                std::pair<K, V> *tab;
                reverse_iterator();
            public:
                K first;
                V second;
                reverse_iterator(map<K, V, Compare, Alloc> &target, unsigned int index);
                reverse_iterator(const map<K, V, Compare, Alloc>::reverse_iterator &target);
                reverse_iterator &operator=(map<K, V, Compare, Alloc>::reverse_iterator &target);
                ~reverse_iterator();

                reverse_iterator &operator++();
                reverse_iterator &operator--();
                reverse_iterator &operator++(int);
                reverse_iterator &operator--(int);
                bool operator==(map::reverse_iterator &target);
                bool operator!=(map::reverse_iterator &target);
        };
        class const_reverse_iterator {
            private:
                const map<K, V, Compare, Alloc> &target;
                unsigned int index;
                std::pair<K, V> *tab;
                const_reverse_iterator();
            public:
                K first;
                V second;
                const_reverse_iterator(map<K, V, Compare, Alloc> &target, unsigned int index);
                const_reverse_iterator(const map<K, V, Compare, Alloc>::const_reverse_iterator &target);
                const_reverse_iterator &operator=(map<K, V, Compare, Alloc>::const_reverse_iterator &target);
                ~const_reverse_iterator();

                const_reverse_iterator &operator++();
                const_reverse_iterator &operator--();
                const_reverse_iterator &operator++(int);
                const_reverse_iterator &operator--(int);
                bool operator==(map::const_reverse_iterator &target);
                bool operator!=(map::const_reverse_iterator &target);
        };
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef unsigned int size_type;

    private:
        Compare cmp;
        Alloc alloc;
        ft_map_node<K, V> *node;
        const long long unsigned int max;

        void add(K key);
        void supp(K key);
        void add(K key, V value);
        void del();
        ft_map_node<K, V> *get(unsigned int i);
        int get_index(K target);
        ft_map_node<K, V> *find_key(K key);

    public:
        //CONSTRUCTOR
        map();
        map(iterator begin, iterator end);
        map(const map &target);
        map &operator=(const map &target);

        //DESTRUCTOR
        ~map();

        //ITERATORS
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        //CAPACITY
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        
        //ELEMENT ACCESS
        mapped_type &operator[](const key_type &target);

        //MODIFIERS
        std::pair<iterator,bool> insert (const value_type& val);
        iterator insert(iterator position, const value_type& val);
        void insert(iterator first, iterator last);
        void erase(iterator position);
        size_type erase(const key_type& k);
        void erase(iterator first, iterator last);
        void swap(map &target);
        void clear();

        //OBSERVERS
        key_compare key_comp() const;
        value_compare value_comp() const;

        //OPERATIONS
        iterator find(const key_type& k);
        const_iterator find(const key_type& k) const;
        size_type count(const key_type& k) const;
        iterator lower_bound(const key_type& k);
        const_iterator lower_bound(const key_type& k) const;
        iterator upper_bound (const key_type& k);
        const_iterator upper_bound(const key_type& k) const;
        std::pair<map::iterator,map::iterator> equal_range(const key_type& k);
        std::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
        
};

//****************************************
//****************************************
//CONSTRUCTORS
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::map() : max(2000000000)
{
    this->node = NULL;
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::map(map<K, V, Compare, Alloc>::iterator begin, map<K, V, Compare, Alloc>::iterator end) : max(2000000000)
{
    ft_map_node<K, V> *save;

    this->node = NULL;
    save = NULL;
    while (begin != end)
    {
        if (this->node == NULL)
        {
            this->node = new ft_map_node<K, V>(begin.first, begin.second);
            save = this->node;
        }
        else
        {
            this->node->setNext(new ft_map_node<K, V>(begin.first, begin.second));
            this->node = this->node->getNext();
        }
        ++begin;
    }
    this->node = save;
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::map(const map &target)  : max(2000000000)
{
    ft_map_node<K, V> *save_me;
    ft_map_node<K, V> *tmp;

    tmp = target.node;
    this->node = NULL;
    while(tmp != NULL)
    {
        if (this->node == NULL)
        {
            this->node = new ft_map_node<K, V>(*tmp);
            save_me = this->node;
        }
        else
        {
            this->node->setNext(new ft_map_node<K, V>(*tmp));
            this->node = this->node->getNext();
        }
        tmp = tmp->getNext();
    }
    this->node = save_me;
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc> &map<K, V, Compare, Alloc>::operator=(const map &target)
{
    del();
    this->node = target.node;
    return (*this);
}

//****************************************
//****************************************
//DESTRUCTOR
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::~map()
{
    del();
}

//****************************************
//****************************************
//ITERATORS
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator map<K, V, Compare, Alloc>::begin()
{
    return (map<K, V, Compare, Alloc>::iterator(*this, 0));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator map<K, V, Compare, Alloc>::begin() const
{
    return (map<K, V, Compare, Alloc>::const_iterator(*this, 0));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator map<K, V, Compare, Alloc>::end()
{
    return (map<K, V, Compare, Alloc>::iterator(*this, size()));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator map<K, V, Compare, Alloc>::end() const
{
    return (map<K, V, Compare, Alloc>::const_iterator(*this, size()));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::reverse_iterator map<K, V, Compare, Alloc>::rbegin()
{
    return (map<K, V, Compare, Alloc>::reverse_iterator(*this, 0));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_reverse_iterator map<K, V, Compare, Alloc>::rbegin() const
{
    return (map<K, V, Compare, Alloc>::const_reverse_iterator(*this, 0));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::reverse_iterator map<K, V, Compare, Alloc>::rend()
{
    return (map<K, V, Compare, Alloc>::reverse_iterator(*this, size()));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_reverse_iterator map<K, V, Compare, Alloc>::rend() const
{
    return (map<K, V, Compare, Alloc>::const_reverse_iterator(*this, size()));
}

//****************************************
//****************************************
//CAPACITY
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::empty() const
{
    return (this->node == NULL ? (true) : (false));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::size_type map<K, V, Compare, Alloc>::size() const
{
    unsigned int i;
    ft_map_node<K, V> *tmp;

    i = 0;
    tmp = this->node;
    while(tmp != NULL)
    {
        ++i;
        tmp = tmp->getNext();
    }
    return (i);
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::size_type map<K, V, Compare, Alloc>::max_size() const
{
    return this->alloc.max_size();
}

//****************************************
//****************************************
//ELEMENT ACCESS
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::mapped_type &map<K, V, Compare, Alloc>::operator[](const key_type &target)
{
    if(find_key(target) == NULL)
        add(target);
    return(find_key(target)->getValueR());
}

//****************************************
//****************************************
//MODIFIERS
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
std::pair<typename map<K, V, Compare, Alloc>::iterator,bool> map<K, V, Compare, Alloc>::insert(const value_type& val)
{
    ft_map_node<K, V> *tmp;

    tmp = NULL;
    if((tmp = find_key(val.first)) != NULL)
    {
        //tmp->setValue(val.second);
        return (std::pair<map<K, V, Compare, Alloc>::iterator, bool>(map<K, V, Compare, Alloc>::iterator(*this, get_index(val.first)), false));
    }
    else
    {
        add(val.first, val.second);
        return (std::pair<map<K, V, Compare, Alloc>::iterator, bool>(map<K, V, Compare, Alloc>::iterator(*this, get_index(val.first)), true));
    }
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator map<K, V, Compare, Alloc>::insert(map<K, V, Compare, Alloc>::iterator position, const value_type& val)
{
    (void)position;
    ft_map_node<K, V> *tmp;

    tmp = NULL;
    if((tmp = find_key(val.first)) != NULL)
    {
        //tmp->setValue(val.second);
        return (map<K, V, Compare, Alloc>::iterator(*this, get_index(val.first)));
    }
    else
    {
        add(val.first, val.second);
        return (map<K, V, Compare, Alloc>::iterator(*this, get_index(val.first)));
    }
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::insert(map<K, V, Compare, Alloc>::iterator first, map<K, V, Compare, Alloc>::iterator last)
{
    ft_map_node<K, V> *tmp;

    tmp = NULL;
    while (first != last)
    {
        tmp = NULL;
        if((tmp = find_key(first.first)) != NULL)
            std::cout << "";
            //tmp->setValue(first.second);
        else
            add(first.first, first.second);
        ++first;
    }
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::erase(map<K, V, Compare, Alloc>::iterator position)
{
    erase(position.first);
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::size_type map<K, V, Compare, Alloc>::erase(const key_type& k)
{
    if (find_key(k) != NULL)
    {
        supp(k);
        return (1);
    }
    return (0);
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::erase(map<K, V, Compare, Alloc>::iterator first, map<K, V, Compare, Alloc>::iterator last)
{
    while (first != last)
    {
        erase(first.first);
        ++first;
    }
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::swap(map &target)
{
    ft_map_node<K, V> *tmp;
    tmp = this->node;
    this->node = target.node;
    target.node = tmp;
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::clear()
{
    del();
}

//****************************************
//****************************************
//OBSERVERS
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::key_compare map<K, V, Compare, Alloc>::key_comp() const
{
    return (map<K, V, Compare, Alloc>::key_compare(this->cmp));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::value_compare map<K, V, Compare, Alloc>::value_comp() const
{
    return (map<K, V, Compare, Alloc>::value_compare(this->cmp));
}

//****************************************
//****************************************
//OPERATIONS
//****************************************
//****************************************


template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator map<K, V, Compare, Alloc>::find(const key_type& k)
{
    ft_map_node<K, V> *save;
    unsigned int i;

    i = 0;
    save = this->node;
    while(this->node != NULL)
    {
        if (this->node->getKey() == k)
            break;
        this->node = this->node->getNext();
        ++i;
    }
    this->node = save;
    return (map<K, V, Compare, Alloc>::iterator(*this, i));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator map<K, V, Compare, Alloc>::find(const key_type& k) const
{
    ft_map_node<K, V> *save;
    unsigned int i;

    i = 0;
    save = this->node;
    while(this->node != NULL)
    {
        if (this->node->getKey() == k)
            break;
        this->node = this->node->getNext();
        ++i;
    }
    this->node = save;
    return (map<K, V, Compare, Alloc>::const_iterator(*this, i));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::size_type map<K, V, Compare, Alloc>::count(const key_type &k) const
{
    ft_map_node<K, V> *tmp;

    tmp = this->node;
    while (tmp != NULL)
    {
        if (tmp->getKey() == k)
            return (1);
        tmp = tmp->getNext();
    }
    return(0);
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator map<K, V, Compare, Alloc>::lower_bound(const key_type& k)
{
    ft_map_node<K, V> *save;
    unsigned int i;

    i = 0;
    save = this->node;
    while(this->node != NULL)
    {
        if (this->node->getKey() == k)
            break;
        this->node = this->node->getNext();
        ++i;
    }
    this->node = save;
    return (map<K, V, Compare, Alloc>::iterator(*this, i));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator map<K, V, Compare, Alloc>::lower_bound(const key_type& k) const
{
    ft_map_node<K, V> *save;
    unsigned int i;

    i = 0;
    save = this->node;
    while(this->node != NULL)
    {
        if (this->node->getKey() == k)
            break;
        this->node = this->node->getNext();
        ++i;
    }
    this->node = save;
    return (map<K, V, Compare, Alloc>::const_iterator(*this, i));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator map<K, V, Compare, Alloc>::upper_bound(const key_type& k)
{
    ft_map_node<K, V> *save;
    unsigned int i;

    i = 0;
    save = this->node;
    while(this->node != NULL)
    {
        if (this->node->getKey() == k)
            break;
        this->node = this->node->getNext();
        ++i;
    }
    this->node = save;
    if (i != size())
        return (map<K, V, Compare, Alloc>::iterator(*this, i + 1));
    return (map<K, V, Compare, Alloc>::iterator(*this, i));
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator map<K, V, Compare, Alloc>::upper_bound(const key_type& k) const
{
    ft_map_node<K, V> *save;
    unsigned int i;

    i = 0;
    save = this->node;
    while(this->node != NULL)
    {
        if (this->node->getKey() == k)
            break;
        this->node = this->node->getNext();
        ++i;
    }
    this->node = save;
    if (i != size())
        return (map<K, V, Compare, Alloc>::const_iterator(*this, i + 1));
    return (map<K, V, Compare, Alloc>::const_iterator(*this, i));
}

template<class K, class V, class Compare, class Alloc>
std::pair<typename map<K, V, Compare, Alloc>::iterator, typename map<K, V, Compare, Alloc>::iterator> map<K, V, Compare, Alloc>::equal_range(const key_type& k)
{
    map<K, V, Compare, Alloc>::iterator *i1;
    map<K, V, Compare, Alloc>::iterator *i2;
    if (get_index(k) != -1)
    {
        i1 = new map<K, V, Compare, Alloc>::iterator(*this, get_index(k));
        i2 = new map<K, V, Compare, Alloc>::iterator(*this, get_index(k) + 1);
        return (std::pair<map<K, V, Compare, Alloc>::iterator, map<K, V, Compare, Alloc>::iterator>(*i1, *i2));
    }
    i1 = new map<K, V, Compare, Alloc>::iterator(*this, size());
    i2 = new map<K, V, Compare, Alloc>::iterator(*this, size());
    return (std::pair<map<K, V, Compare, Alloc>::iterator, map<K, V, Compare, Alloc>::iterator>(*i1, *i2));
}

template<class K, class V, class Compare, class Alloc>
std::pair<typename map<K, V, Compare, Alloc>::const_iterator, typename map<K, V, Compare, Alloc>::const_iterator> map<K, V, Compare, Alloc>::equal_range(const key_type& k) const
{
    map<K, V, Compare, Alloc>::const_iterator *i1;
    map<K, V, Compare, Alloc>::const_iterator *i2;
    if (get_index(k) != -1)
    {
        i1 = new map<K, V, Compare, Alloc>::const_iterator(*this, get_index(k));
        i2 = new map<K, V, Compare, Alloc>::iterator(*this, get_index(k) + 1);
        return (std::pair<map<K, V, Compare, Alloc>::const_iterator, map<K, V, Compare, Alloc>::const_iterator>(*i1, *i2));
    }
    i1 = new map<K, V, Compare, Alloc>::const_iterator(*this, size());
    i2 = new map<K, V, Compare, Alloc>::const_iterator(*this, size());
    return (std::pair<map<K, V, Compare, Alloc>::const_iterator, map<K, V, Compare, Alloc>::const_iterator>(*i1, *i2));
}

//****************************************
//****************************************
//UTILS PRIVATE
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::del()
{
    ft_map_node<K, V> *tmp;

    tmp = NULL;
    while (this->node != NULL)
    {
        tmp = this->node;
        this->node = this->node->getNext();
        delete(tmp);
    }
    this->node = NULL;
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::add(K key)
{
    int stop = 0;
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *last;

    save = this->node;
    last = NULL;
    while (this->node != NULL && stop == 0)
    {
        if (!cmp(this->node->getKey(), key))
            stop = 1;
        else
        {
            last = this->node;
            this->node = this->node->getNext();
        }
    }
    if (last == NULL)
    {
        last = alloc.allocate(sizeof(ft_map_node<K, V>));
        last->setKey(key);
        //last = new ft_map_node<K, V>(key);
        last->setNext(this->node);
        this->node = last;
    }
    else
    {
        last->setNext(alloc.allocate(sizeof(ft_map_node<K, V>)));
        last->getNext()->setKey(key);
        //last->setNext(new ft_map_node<K, V>(key));
        last->getNext()->setNext(this->node);
        this->node = save;
    }
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::add(K key, V value)
{
    int stop = 0;
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *last;

    save = this->node;
    last = NULL;
    while (this->node != NULL && stop == 0)
    {
        if (!cmp(this->node->getKey(), key))
            stop = 1;
        else
        {
            last = this->node;
            this->node = this->node->getNext();
        }
    }
    if (last == NULL)
    {
        last = alloc.allocate(sizeof(ft_map_node<K, V>));
        last->setKey(key);
        last->setValue(value);
        //last = new ft_map_node<K, V>(key, value);
        last->setNext(this->node);
        this->node = last;
    }
    else
    {
        last->setNext(alloc.allocate(sizeof(ft_map_node<K, V>)));
        last->getNext()->setKey(key);
        last->getNext()->setValue(value);
        //last->setNext(new ft_map_node<K, V>(key, value));
        last->getNext()->setNext(this->node);
        this->node = save;
    }
}

template<class K, class V, class Compare, class Alloc>
void map<K, V, Compare, Alloc>::supp(K key)
{
    int stop = 0;
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *last;
    ft_map_node<K, V> *tmp;

    save = this->node;
    last = NULL;
    tmp = NULL;
    while (this->node != NULL && stop == 0)
    {
        if (this->node->getKey() == key)
            stop = 1;
        else
        {
            last = this->node;
            this->node = this->node->getNext();
        }
    }
    if (last == NULL)
    {
        tmp = this->node->getNext();
        alloc.deallocate(this->node, sizeof(ft_map_node<K, V>));
        //delete(this->node);
        this->node = tmp;
    }
    else
    {
        tmp = this->node->getNext();
        alloc.deallocate(this->node, sizeof(ft_map_node<K, V>));
        //delete(this->node);
        last->setNext(tmp);
        this->node = save;
    }
}

template<class K, class V, class Compare, class Alloc>
ft_map_node<K, V> *map<K, V, Compare, Alloc>::find_key(K key)
{
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *tmp;

    save = this->node;
    while (this->node != NULL)
    {
        if (this->node->getKey() == key)
            break;
        this->node = this->node->getNext();
    }
    tmp = this->node;
    this->node = save;
    return (tmp);
}

template<class K, class V, class Compare, class Alloc>
ft_map_node<K, V> *map<K, V, Compare, Alloc>::get(unsigned int i)
{
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *tmp;
    unsigned int k;

    k = 0;
    tmp = NULL;
    save = this->node;
    if (i > size())
        return (NULL);
    while (k != i)
    {
        this->node = this->node->getNext();
        ++k;
    }
    tmp = this->node;
    this->node = save;
    return (tmp);
}

template<class K, class V, class Compare, class Alloc>
int map<K, V, Compare, Alloc>::get_index(K target)
{
    int i;
    ft_map_node<K, V> *save;

    i = 0;
    save = this->node;
    while (this->node != NULL)
    {
        if (this->node->getKey() == target)
        {
            this->node = save;
            return (i);
        }
        this->node = this->node->getNext();
        ++i;
    }
    this->node = save;
    return (-1);
}

//****************************************
//****************************************
//ITERATOR
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::iterator::iterator()
{
    this->index = 0;
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::iterator::iterator(map<K, V, Compare, Alloc> &target, unsigned int index) : target(target)
{
    this->index = index;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::iterator::iterator(const map<K, V, Compare, Alloc>::iterator &target) : target(target.target)
{
    this->index = target.index;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator &map<K, V, Compare, Alloc>::iterator::operator=(map<K, V, Compare, Alloc>::iterator &target)
{
    this->index = target.index;
    delete[](this->tab);
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    this->target = target.target;
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return (*this);
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::iterator::~iterator()
{
    delete[](this->tab);
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator &map<K, V, Compare, Alloc>::iterator::operator++()
{
    this->index +=1;
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return(*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator &map<K, V, Compare, Alloc>::iterator::operator--()
{
    this->index -= 1;
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return (*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator &map<K, V, Compare, Alloc>::iterator::operator++(int i)
{
    (void)i;
    iterator    tmp(*this);
    operator++();
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return tmp;
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::iterator &map<K, V, Compare, Alloc>::iterator::operator--(int i)
{
    (void)i;
    iterator    tmp(*this);
    operator--();
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return tmp;
}

template<class K, class V, class Compare, class Alloc>
std::pair<K, V> &map<K, V, Compare, Alloc>::iterator::operator*()
{
    K tmp;
    V tm;

    tmp = this->target.get(this->index)->getKey();
    tm = this->target.get(this->index)->getValue();
    std::pair<K, V> p = std::pair<K, V>(tmp, tm);
    return(this->tab[this->index]);
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::iterator::operator==(map::iterator &target)
{
    return(this->index == target.index);
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::iterator::operator!=(map::iterator &target)
{
    return(this->index != target.index);
}

//****************************************
//****************************************
//CONST ITERATOR
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_iterator::const_iterator()
{
    this->index = 0;
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_iterator::const_iterator(map<K, V, Compare, Alloc> &target, unsigned int index) : target(target)
{
    this->index = index;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_iterator::const_iterator(const map<K, V, Compare, Alloc>::const_iterator &target) : target(target.target)
{
    this->index = target.index;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator &map<K, V, Compare, Alloc>::const_iterator::operator=(map<K, V, Compare, Alloc>::const_iterator &target)
{
    this->index = target.index;
    this->target = target.target;
    delete[](this->tab);
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return (*this);
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_iterator::~const_iterator()
{
    delete[](this->tab);
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator &map<K, V, Compare, Alloc>::const_iterator::operator++()
{
    this->index +=1;
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return(*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator &map<K, V, Compare, Alloc>::const_iterator::operator--()
{
    this->index -= 1;
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return (*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator &map<K, V, Compare, Alloc>::const_iterator::operator++(int i)
{
    (void)i;
    const_iterator    tmp(*this);
    operator++();
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return tmp;
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_iterator &map<K, V, Compare, Alloc>::const_iterator::operator--(int i)
{
    (void)i;
    const_iterator    tmp(*this);
    operator--();
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return tmp;
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::const_iterator::operator==(map::const_iterator &target)
{
    return(this->index == target.index);
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::const_iterator::operator!=(map::const_iterator &target)
{
    return(this->index != target.index);
}

//****************************************
//****************************************
// REVERSE ITERATOR
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::reverse_iterator::reverse_iterator()
{
    this->index = 0;
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::reverse_iterator::reverse_iterator(map<K, V, Compare, Alloc> &target, unsigned int index) : target(target)
{
    this->index = index;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::reverse_iterator::reverse_iterator(const map<K, V, Compare, Alloc>::reverse_iterator &target) : target(target.target)
{
    this->index = target.index;
    this->target = target.target;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::reverse_iterator &map<K, V, Compare, Alloc>::reverse_iterator::operator=(map<K, V, Compare, Alloc>::reverse_iterator &target)
{
    this->index = target.index;
    this->target = target.target;
    delete[](this->tab);
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return (*this);
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::reverse_iterator::~reverse_iterator()
{
    delete[](this->tab);
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::reverse_iterator &map<K, V, Compare, Alloc>::reverse_iterator::operator++()
{
    this->index +=1;
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return(*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::reverse_iterator &map<K, V, Compare, Alloc>::reverse_iterator::operator--()
{
    this->index -= 1;
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return (*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::reverse_iterator &map<K, V, Compare, Alloc>::reverse_iterator::operator++(int i)
{
    (void)i;
    reverse_iterator    tmp(*this);
    operator++();
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return tmp;
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::reverse_iterator &map<K, V, Compare, Alloc>::reverse_iterator::operator--(int i)
{
    (void)i;
    reverse_iterator    tmp(*this);
    operator--();
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return tmp;
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::reverse_iterator::operator==(map::reverse_iterator &target)
{
    return(this->index == target.index);
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::reverse_iterator::operator!=(map::reverse_iterator &target)
{
    return(this->index != target.index);
}

//****************************************
//****************************************
//CONST REVERSE ITERATOR
//****************************************
//****************************************

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_reverse_iterator::const_reverse_iterator()
{
    this->index = 0;
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_reverse_iterator::const_reverse_iterator(map<K, V, Compare, Alloc> &target, unsigned int index) : target(target)
{
    this->index = index;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_reverse_iterator::const_reverse_iterator(const map<K, V, Compare, Alloc>::const_reverse_iterator &target) : target(target.target)
{
    this->index = target.index;
    this->target = target.target;
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_reverse_iterator &map<K, V, Compare, Alloc>::const_reverse_iterator::operator=(map<K, V, Compare, Alloc>::const_reverse_iterator &target)
{
    this->index = target.index;
    this->target = target.target;
    delete[](this->tab);
    tab = new std::pair<K, V>[this->target.size()];
    for(unsigned int i = this->index; i < this->target.size(); ++i)
    {
        std::make_pair(this->target.get(i)->getKey(), this->target.get(i)->getValue());
    }
    if (this->target.get(this->index) != NULL)
    {
        this->first = this->target.get(this->index)->getKey();
        this->second = this->target.get(this->index)->getValue();
    }
    return (*this);
}

template<class K, class V, class Compare, class Alloc>
map<K, V, Compare, Alloc>::const_reverse_iterator::~const_reverse_iterator()
{
    delete[](this->tab);
}

template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_reverse_iterator &map<K, V, Compare, Alloc>::const_reverse_iterator::operator++()
{
    this->index +=1;
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return(*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_reverse_iterator &map<K, V, Compare, Alloc>::const_reverse_iterator::operator--()
{
    this->index -= 1;
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return (*this);
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_reverse_iterator &map<K, V, Compare, Alloc>::const_reverse_iterator::operator++(int i)
{
    (void)i;
    const_reverse_iterator    tmp(*this);
    operator++();
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return tmp;
}
template<class K, class V, class Compare, class Alloc>
typename map<K, V, Compare, Alloc>::const_reverse_iterator &map<K, V, Compare, Alloc>::const_reverse_iterator::operator--(int i)
{
    (void)i;
    const_reverse_iterator    tmp(*this);
    operator--();
    if (this->target.get(this->target.size() - 1 - this->index) != NULL)
    {
        this->first = this->target.get(this->target.size() - 1 - this->index)->getKey();
        this->second = this->target.get(this->target.size() - 1 - this->index)->getValue();
    }
    return tmp;
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::const_reverse_iterator::operator==(map::const_reverse_iterator &target)
{
    return(this->index == target.index);
}
template<class K, class V, class Compare, class Alloc>
bool map<K, V, Compare, Alloc>::const_reverse_iterator::operator!=(map::const_reverse_iterator &target)
{
    return(this->index != target.index);
}

}
#endif