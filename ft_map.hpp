#ifndef FT_MAP
#define FT_MAP

#include "ft_map_node.hpp"
#include <stdio.h>
#include <iostream>
#include <utility>
#include <functional>

template<class K, class V>
class ft_map {
    public:
        typedef K key_type;
        typedef V mapped_type;
        //typedef Compare key_compare;
        typedef std::pair<K, V> value_type;
        typedef unsigned int size_type;
    private:
        ft_map_node<K, V> *node;
        const unsigned int max;

        unsigned int count(ft_map_node<K, V> *target);
        ft_map_node<K, V> *copie(ft_map_node<K, V> *target);
        void supp(ft_map_node<K, V> *target);
        ft_map_node<K, V> *find(K key, ft_map_node<K, V> *target) const;
        void add(K key, ft_map_node<K, V> *target);
        void add(K key, V value, ft_map_node<K, V> *target);

    public:
        ft_map();
        ft_map(const ft_map &target);
        ft_map &operator=(const ft_map &target);
        ~ft_map();

        bool empty();
        size_type size();
        size_type max_size();
        void swap(ft_map &target);
        void clear();

        size_type count(const key_type& k) const;

        mapped_type &operator[](const key_type &target);

        class iterator : public std::iterator<std::output_iterator_tag, K>
        {
            private:
                ft_map<K, V> &target;
                unsigned int index;
            public:
                explicit iterator(ft_map<K, V> &target, unsigned int index);

                iterator &operator++();
                iterator &operator--();
                iterator &operator++(int);
                iterator &operator--(int);
                //T operator*();
                bool operator!=(ft_map::iterator &target);
        };

        ft_map::iterator begin();
        ft_map::iterator end();
        ft_map::iterator rbegin();
        ft_map::iterator rend();
};

//****************************************
//****************************************
//CONSTRUCTORS
//****************************************
//****************************************

template<class K, class V>
ft_map<K, V>::ft_map() : max(100)
{
    this->node = NULL;
}

template<class K, class V>
ft_map<K, V>::ft_map(const ft_map &target)
{
    this->node = copie(target.node);
}

template<class K, class V>
ft_map<K, V> &ft_map<K, V>::operator=(const ft_map &target)
{
    supp(this->node);
    this->node = copie(target.node);
    return (*this);
}

template<class K, class V>
ft_map<K, V>::~ft_map()
{
    supp(this->node);
}

//****************************************
//****************************************
//FUNCTIONS
//****************************************
//****************************************

template<class K, class V>
bool ft_map<K, V>::empty()
{
    return (this->node == NULL ? (true) : (false));
}

template<class K, class V>
typename ft_map<K, V>::size_type ft_map<K, V>::size()
{
    return (count(this->node));
}

template<class K, class V>
typename ft_map<K, V>::size_type ft_map<K, V>::max_size()
{
    return (this->max);
}

template<class K, class V>
void ft_map<K, V>::swap(ft_map &target)
{
    ft_map_node<K, V> *tmp;
    tmp = this->node;
    this->node = target.node;
    target.node = tmp;
}

template<class K, class V>
void ft_map<K, V>::clear()
{
    supp(this->node);
    this->node = NULL;
}

template<class K, class V>
typename ft_map<K, V>::size_type ft_map<K, V>::count(const key_type &k) const
{
    return (find(k, this->node) != NULL ? (1) : (0));
}

//****************************************
//****************************************
//FUNCTIONS ITERATE
//****************************************
//****************************************

template<class K, class V>
typename ft_map<K, V>::iterator ft_map<K, V>::begin()
{
    return (ft_map<K, V>::iterator(*this, 0));
}
template<class K, class V>
typename ft_map<K, V>::iterator ft_map<K, V>::end()
{
    return (ft_map<K, V>::iterator(*this, size()));
}
template<class K, class V>
typename ft_map<K, V>::iterator ft_map<K, V>::rbegin()
{
    return (ft_map<K, V>::iterator(*this, size()));
}
template<class K, class V>
typename ft_map<K, V>::iterator ft_map<K, V>::rend()
{
    return (ft_map<K, V>::iterator(*this, 0));
}

//****************************************
//****************************************
//OPERATORS
//****************************************
//****************************************

template<class K, class V>
typename ft_map<K, V>::mapped_type &ft_map<K, V>::operator[](const key_type &target)
{
    if (find(target, this->node) == NULL)
    {
        add(target, this->node);
    }
    return (find(target, this->node)->getValueR());
}

//****************************************
//****************************************
//UTILS PRIVATE
//****************************************
//****************************************

template<class K, class V>
unsigned int ft_map<K, V>::count(ft_map_node<K, V> *target)
{
    unsigned int size;

    size = 0;
    if (target != NULL)
    {
        ++size;
        if (target->getLeft() != NULL)
            size += count(target->getLeft());
        if (target->getRight() != NULL)
            size += count(target->getRight());
    }
    return (size);
}

template<class K, class V>
ft_map_node<K, V> *ft_map<K, V>::copie(ft_map_node<K, V> *target)
{
    ft_map_node<K, V> *nw;

    nw = NULL;
    if (target != NULL)
    {
        nw = new ft_map_node<K, V>(target->getKey(), target->getValue());
        if (target->getLeft() != NULL)
            nw->setLeft(copie(target->getLeft()));
        if (target->getRight() != NULL)
            nw->setRight(copie(target->getRight()));
    }
    return (nw);
}

template<class K, class V>
void ft_map<K, V>::supp(ft_map_node<K, V> *target)
{
    if (target != NULL)
    {
        if (target->getLeft() != NULL)
            supp(target->getLeft());
        if (target->getRight() != NULL)
            supp(target->getRight());
        delete(target);
        target = NULL;
    }
}

template<class K, class V>
ft_map_node<K, V> *ft_map<K, V>::find(K key, ft_map_node<K, V> *target) const
{
    if(target != NULL)
    {
        if (target->getKey() == key)
            return (target);
        if (target->getLeft() != NULL)
        {
            if (find(key, target->getLeft()) != NULL)
                return (find(key, target->getLeft()));
        }
        if (target->getRight() != NULL)
        {
            if (find(key, target->getRight()) != NULL)
                return (find(key, target->getRight()));
        }
    }
    return (NULL);
}

template<class K, class V>
void ft_map<K, V>::add(K key, ft_map_node<K, V> *target)
{
    if (target != NULL)
    {
        if (key < target->getKey())
        {
            if (target->getLeft() == NULL)
                target->setLeft(new ft_map_node<K, V>(key));
            else
                add(key, target->getLeft());    
        }
        else
        {
            if (target->getRight() == NULL)
                target->setRight(new ft_map_node<K, V>(key));
            else
                add(key, target->getRight());
        }
    }
    else
    {
        this->node = new ft_map_node<K, V>(key);
    }
}

template<class K, class V>
void ft_map<K, V>::add(K key, V value, ft_map_node<K, V> *target)
{
    if (target != NULL)
    {
        if (key < target->getKey())
        {
            if (target->getLeft() == NULL)
                target->setLeft(new ft_map_node<K, V>(key, value));
            else
                add(key, value, target->getLeft());    
        }
        else
        {
            if (target->getRight() == NULL)
                target->setRight(new ft_map_node<K, V>(key, value));
            else
                add(key, value, target->getRight());
        }
    }
    else
    {
        this->node = new ft_map_node<K, V>(key, value);
    }
}

//****************************************
//****************************************
//ITERATOR
//****************************************
//****************************************

template<class K, class V>
ft_map<K, V>::iterator::iterator(ft_map<K, V> &target, unsigned int index) : target(target)
{
    this->index = index;
}

template<class K, class V>
typename ft_map<K, V>::iterator &ft_map<K, V>::iterator::operator++()
{
    this->index +=1;
    return(*this);
}
template<class K, class V>
typename ft_map<K, V>::iterator &ft_map<K, V>::iterator::operator--()
{
    this->index -= 1;
    return (*this);
}
template<class K, class V>
typename ft_map<K, V>::iterator &ft_map<K, V>::iterator::operator++(int i)
{
    (void)i;
    iterator    tmp(*this);
    operator++();
    return tmp;
}
template<class K, class V>
typename ft_map<K, V>::iterator &ft_map<K, V>::iterator::operator--(int i)
{
    (void)i;
    iterator    tmp(*this);
    operator--();
    return tmp;
}
template<class K, class V>
bool ft_map<K, V>::iterator::operator!=(ft_map::iterator &target)
{
    return(this->index != target.index);
}

#endif