#ifndef FT_MAP
#define FT_MAP

#include "ft_map_node.hpp"
#include <stdio.h>
#include <iostream>

template<class K, class V>
class ft_map {
    private:
        ft_map_node<K, V> *node;
        const unsigned int max;
        unsigned int count(ft_map_node<K, V> *target);
        ft_map_node<K, V> *copie(ft_map_node<K, V> *target);
        void supp(ft_map_node<K, V> *target);
        ft_map_node<K, V> *find(K key, ft_map_node<K, V> *target);
        void add(K key, V value, ft_map_node<K, V> *target);

    public:
        ft_map();
        ft_map(const ft_map &target);
        ft_map &operator=(const ft_map &target);
        ~ft_map();

        bool empty();
        unsigned int size();
        unsigned int max_size();

        V &operator[](const K &target);
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
unsigned int ft_map<K, V>::size()
{
    return (count(this->node));
}

template<class K, class V>
unsigned int ft_map<K, V>::max_size()
{
    return (this->max);
}

//****************************************
//****************************************
//OPERATORS
//****************************************
//****************************************

template<class K, class V>
V &ft_map<K, V>::operator[](const K &target)
{
    std::cout << "operator in" << std::endl;
    if (find(target, this->node) == NULL)
    {
        std::cout << "pas trouve" << std::endl;
        add(target, NULL, this->node);
        std::cout << "add done" << std::endl;
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
ft_map_node<K, V> *ft_map<K, V>::find(K key, ft_map_node<K, V> *target)
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
void ft_map<K, V>::add(K key, V value, ft_map_node<K, V> *target)
{
    std::cout << "add" << std::endl;
    if (target != NULL)
    {
        std::cout << "target != NULL" << std::endl;
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
        std::cout << "target == NULL" << std::endl;
        this->node = new ft_map_node<K, V>(key, value);
    }
}

#endif