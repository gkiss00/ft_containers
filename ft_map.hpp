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

        void add(K key);
        void add(K key, V value);
        ft_map_node<K, V> *find(K key);

    public:
        ft_map();
        ft_map(const ft_map &target);
        ft_map &operator=(const ft_map &target);
        ~ft_map();

        bool empty();
        size_type size();
        size_type max_size();
        size_type count(const key_type& k) const;
        void swap(ft_map &target);
        void clear();

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
                bool operator==(ft_map::iterator &target);
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
ft_map<K, V>::ft_map(const ft_map &target)  : max(100)
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

template<class K, class V>
ft_map<K, V> &ft_map<K, V>::operator=(const ft_map &target)
{
    ft_map_node<K, V> *tmp;

    tmp = NULL;
    while (this->node != NULL)
    {
        tmp = this->node;
        this->node = this->node->getNext();
        delete(tmp);
    }
    this->node = target.node;
    return (*this);
}

template<class K, class V>
ft_map<K, V>::~ft_map()
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
    ft_map_node<K, V> *tmp;

    tmp = this->node;
    while (this->node != NULL)
    {
        tmp = this->node;
        this->node = this->node->getNext();
        delete(tmp);
    }
    this->node = NULL;
}

template<class K, class V>
typename ft_map<K, V>::size_type ft_map<K, V>::count(const key_type &k) const
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

//****************************************
//****************************************
//BEGIN END
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
    if(find(target) == NULL)
        add(target);
    return(find(target)->getValueR());
}

//****************************************
//****************************************
//UTILS PRIVATE
//****************************************
//****************************************

template<class K, class V>
void ft_map<K, V>::add(K key)
{
    int stop = 0;
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *last;

    save = this->node;
    last = NULL;
    while (this->node != NULL && stop == 0)
    {
        if (this->node->getKey() > key)
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

template<class K, class V>
void ft_map<K, V>::add(K key, V value)
{
    int stop = 0;
    ft_map_node<K, V> *save;
    ft_map_node<K, V> *last;

    save = this->node;
    last = NULL;
    while (this->node != NULL && stop == 0)
    {
        if (this->node->getKey() > key)
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

template<class K, class V>
ft_map_node<K, V> *ft_map<K, V>::find(K key)
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
bool ft_map<K, V>::iterator::operator==(ft_map::iterator &target)
{
    return(this->index == target.index);
}
template<class K, class V>
bool ft_map<K, V>::iterator::operator!=(ft_map::iterator &target)
{
    return(this->index != target.index);
}

#endif