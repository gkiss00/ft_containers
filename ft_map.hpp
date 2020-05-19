#ifndef FT_MAP
#define FT_MAP

#include "ft_map_node.hpp"
#include <stdio.h>
#include <iostream>
#include <utility>
#include <functional>

template<class K, class V, class Compare = std::less<K>>
class ft_map {
    public:
        typedef K key_type;
        typedef V mapped_type;
        typedef Compare key_compare;
        typedef bool value_compare;
        typedef std::pair<K, V> value_type;
        typedef unsigned int size_type;
    private:
        Compare cmp;
        ft_map_node<K, V> *node;
        const unsigned int max;

        void add(K key);
        void add(K key, V value);
        void del();
        ft_map_node<K, V> *get(unsigned int i);
        ft_map_node<K, V> *find_key(K key);

    public:
        class iterator {
            private:
                ft_map<K, V, Compare> &target;
                unsigned int index;
            public:
                K first;
                V second;
                explicit iterator(ft_map<K, V, Compare> &target, unsigned int index);

                iterator &operator++();
                iterator &operator--();
                iterator &operator++(int);
                iterator &operator--(int);
                bool operator==(ft_map::iterator &target);
                bool operator!=(ft_map::iterator &target);
        };
        //CONSTRUCTOR
        ft_map();
        ft_map(ft_map::iterator begin, ft_map::iterator end);
        ft_map(const ft_map &target);
        ft_map &operator=(const ft_map &target);

        //DESTRUCTOR
        ~ft_map();

        //ITERATORS
        ft_map::iterator begin();
        ft_map::iterator end();
        ft_map::iterator rbegin();
        ft_map::iterator rend();

        //CAPACITY
        bool empty();
        size_type size();
        size_type max_size();

        
        //ELEMENT ACCESS
        mapped_type &operator[](const key_type &target);

        //MODIFIERS
        void swap(ft_map &target);
        void clear();

        //OBSERVERS
        //key_compare key_comp() const;
        //value_compare value_comp() const;

        //OPERATIONS
        ft_map::iterator find (const key_type& k);
        //const_iterator find (const key_type& k) const;
        size_type count(const key_type& k) const;
        ft_map::iterator lower_bound(const key_type& k);
        //const_iterator lower_bound (const key_type& k) const;
        ft_map::iterator upper_bound (const key_type& k);
        //const_iterator upper_bound (const key_type& k) const;
        std::pair<ft_map::iterator,ft_map::iterator> equal_range(const key_type& k);
        //std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
        
};

//****************************************
//****************************************
//CONSTRUCTORS
//****************************************
//****************************************

template<class K, class V, class Compare>
ft_map<K, V, Compare>::ft_map() : max(100)
{
    this->node = NULL;
}

template<class K, class V, class Compare>
ft_map<K, V, Compare>::ft_map(ft_map<K, V, Compare>::iterator begin, ft_map<K, V, Compare>::iterator end) : max(100)
{
    ft_map_node<K, V> *save;

    save = NULL;
    if (begin.target != end.target)
        throw std::invalid_argument("Les poiteurs ciblent des cibles differentes");
    while (begin != end)
    {
        if (this->node == NULL)
        {
            this->node = new(ft_mpa_node(begin.first, begin.second));
            save = this->node;
        }
        else
        {
            this->node->setNext(new(ft_mpa_node(begin.first, begin.second)));
            this->node = this->node->getNext();
        }
    }
    this->node = save;
}

template<class K, class V, class Compare>
ft_map<K, V, Compare>::ft_map(const ft_map &target)  : max(100)
{
    ft_map_node<K, V> *save_me;
    ft_map_node<K, V> *save_target;

    save_target = target.node;
    this->node = NULL;
    while(target.node != NULL)
    {
        if (this->node == NULL)
        {
            this->node = new ft_map_node<K, V>(target.node);
            save_me = this->node;
        }
        else
        {
            this->node->setNext(new ft_map_node<K, V>(target.node));
            this->node = this->node->getNext();
        }
        target.node = target.node->getNext();
    }
    this->node = save_me;
    target.node = save_target;
}

template<class K, class V, class Compare>
ft_map<K, V, Compare> &ft_map<K, V, Compare>::operator=(const ft_map &target)
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

template<class K, class V, class Compare>
ft_map<K, V, Compare>::~ft_map()
{
    del();
}

//****************************************
//****************************************
//ITERATORS
//****************************************
//****************************************

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator ft_map<K, V, Compare>::begin()
{
    return (ft_map<K, V, Compare>::iterator(*this, 0));
}
template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator ft_map<K, V, Compare>::end()
{
    return (ft_map<K, V, Compare>::iterator(*this, size()));
}
template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator ft_map<K, V, Compare>::rbegin()
{
    return (ft_map<K, V, Compare>::iterator(*this, size()));
}
template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator ft_map<K, V, Compare>::rend()
{
    return (ft_map<K, V, Compare>::iterator(*this, 0));
}

//****************************************
//****************************************
//CAPACITY
//****************************************
//****************************************

template<class K, class V, class Compare>
bool ft_map<K, V, Compare>::empty()
{
    return (this->node == NULL ? (true) : (false));
}

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::size_type ft_map<K, V, Compare>::size()
{
    unsigned int i;
    ft_map_node<K, V> *tmp;

    i = 0;
    tmp = this->node;
    while(this->node != NULL)
    {
        ++i;
        this->node = this->node->getNext();
    }
    this->node = tmp;
    return (i);
}

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::size_type ft_map<K, V, Compare>::max_size()
{
    return (this->max);
}

//****************************************
//****************************************
//ELEMENT ACCESS
//****************************************
//****************************************

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::mapped_type &ft_map<K, V, Compare>::operator[](const key_type &target)
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

template<class K, class V, class Compare>
void ft_map<K, V, Compare>::swap(ft_map &target)
{
    ft_map_node<K, V> *tmp;
    tmp = this->node;
    this->node = target.node;
    target.node = tmp;
}

template<class K, class V, class Compare>
void ft_map<K, V, Compare>::clear()
{
    del();
}

//****************************************
//****************************************
//OPERATIONS
//****************************************
//****************************************


template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator ft_map<K, V, Compare>::find(const key_type& k)
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
    return (ft_map<K, V, Compare>::iterator(*this, i));
}

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::size_type ft_map<K, V, Compare>::count(const key_type &k) const
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

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator ft_map<K, V, Compare>::lower_bound(const key_type& k)
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
    return (ft_map<K, V, Compare>::iterator(*this, i));
}

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator ft_map<K, V, Compare>::upper_bound (const key_type& k)
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
        return (ft_map<K, V, Compare>::iterator(*this, i + 1));
    return (ft_map<K, V, Compare>::iterator(*this, i));
}

//****************************************
//****************************************
//UTILS PRIVATE
//****************************************
//****************************************

template<class K, class V, class Compare>
void ft_map<K, V, Compare>::del()
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

template<class K, class V, class Compare>
void ft_map<K, V, Compare>::add(K key)
{
    int stop = 0;
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *last;

    save = this->node;
    last = NULL;
    while (this->node != NULL && stop == 0)
    {
        if (cmp(this->node->getKey(), key))
            stop = 1;
        else
        {
            last = this->node;
            this->node = this->node->getNext();
        }
    }
    if (last == NULL)
    {
        last = new ft_map_node<K, V>(key);
        last->setNext(this->node);
        this->node = last;
    }
    else
    {
        last->setNext(new ft_map_node<K, V>(key));
        last->getNext()->setNext(this->node);
        this->node = save;
    }
}

template<class K, class V, class Compare>
void ft_map<K, V, Compare>::add(K key, V value)
{
    int stop = 0;
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *last;

    save = this->node;
    last = NULL;
    while (this->node != NULL && stop == 0)
    {
        if (cmp(this->node->getKey(), key))
            stop = 1;
        else
        {
            last = this->node;
            this->node = this->node->getNext();
        }
    }
    if (last == NULL)
    {
        last = new ft_map_node<K, V>(key, value);
        last->setNext(this->node);
        this->node = last;
    }
    else
    {
        last->setNext(new ft_map_node<K, V>(key, value));
        last->getNext()->setNext(this->node);
        this->node = save;
    }
}

template<class K, class V, class Compare>
ft_map_node<K, V> *ft_map<K, V, Compare>::find_key(K key)
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

template<class K, class V, class Compare>
ft_map_node<K, V> *ft_map<K, V, Compare>::get(unsigned int i)
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

//****************************************
//****************************************
//ITERATOR
//****************************************
//****************************************

template<class K, class V, class Compare>
ft_map<K, V, Compare>::iterator::iterator(ft_map<K, V, Compare> &target, unsigned int index) : target(target)
{
    this->index = index;
    if (this->target.get(this->index) != NULL)
        this->first = this->target.get(this->index)->getKey();
    if (this->target.get(this->index) != NULL)
        this->second = this->target.get(this->index)->getValue();
}

template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator &ft_map<K, V, Compare>::iterator::operator++()
{
    this->index +=1;
    if (this->target.get(this->index) != NULL)
        this->first = this->target.get(this->index)->getKey();
    if (this->target.get(this->index) != NULL)
        this->second = this->target.get(this->index)->getValue();
    return(*this);
}
template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator &ft_map<K, V, Compare>::iterator::operator--()
{
    this->index -= 1;
    if (this->target.get(this->index) != NULL)
        this->first = this->target.get(this->index)->getKey();
    if (this->target.get(this->index) != NULL)
        this->second = this->target.get(this->index)->getValue();
    return (*this);
}
template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator &ft_map<K, V, Compare>::iterator::operator++(int i)
{
    (void)i;
    iterator    tmp(*this);
    operator++();
    if (this->target.get(this->index) != NULL)
        this->first = this->target.get(this->index)->getKey();
    if (this->target.get(this->index) != NULL)
        this->second = this->target.get(this->index)->getValue();
    return tmp;
}
template<class K, class V, class Compare>
typename ft_map<K, V, Compare>::iterator &ft_map<K, V, Compare>::iterator::operator--(int i)
{
    (void)i;
    iterator    tmp(*this);
    operator--();
    if (this->target.get(this->index) != NULL)
        this->first = this->target.get(this->index)->getKey();
    if (this->target.get(this->index) != NULL)
        this->second = this->target.get(this->index)->getValue();
    return tmp;
}
template<class K, class V, class Compare>
bool ft_map<K, V, Compare>::iterator::operator==(ft_map::iterator &target)
{
    return(this->index == target.index);
}
template<class K, class V, class Compare>
bool ft_map<K, V, Compare>::iterator::operator!=(ft_map::iterator &target)
{
    return(this->index != target.index);
}

#endif