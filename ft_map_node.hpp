#ifndef FT_MAP_NODE
#define FT_MAP_NODE

#include <stdio.h>
#include <string>
#include <iostream>
#include <utility>

template<class K,class V>
class ft_map_node {
    private:
        K   key;
        V   value;
        ft_map_node *next;
        ft_map_node();
    public:
        ft_map_node(K key);
        ft_map_node(K key, V value);
        ft_map_node(const ft_map_node<K, V> &target);
        ft_map_node &operator=(const ft_map_node<K, V> &target);
        ~ft_map_node();

        K getKey();
        void setKey(K key);
        V getValue();
        V &getValueR();
        void setValue(V value);
        ft_map_node *getNext();
        void setNext(ft_map_node<K, V> *target);
};

//****************************************
//****************************************
//CONSTRUCTOR
//****************************************
//****************************************

template<class K,class V>
ft_map_node<K, V>::ft_map_node()
{
    this->key = 0;
    this->next = NULL;
}
template<class K,class V>
ft_map_node<K, V>::ft_map_node(K key)
{
    this->key = key;
    this->next = NULL;
}
template<class K,class V>
ft_map_node<K, V>::ft_map_node(K key, V value)
{
    this->key = key;
    this->value = value;
    this->next = NULL;
}
template<class K,class V>
ft_map_node<K, V>::ft_map_node(const ft_map_node<K, V> &target)
{
    this->key = target.key;
    this->value = target.value;
    this->next = NULL;
}
template<class K,class V>
ft_map_node<K, V> &ft_map_node<K, V>::operator=(const ft_map_node<K, V> &target)
{
    this->key = target.key;
    this->value = target.value;
    this->next = NULL;
    return (*this);
}
template<class K,class V>
ft_map_node<K, V>::~ft_map_node()
{

}

//****************************************
//****************************************
//GETTER AND SETTER
//****************************************
//****************************************

template<class K,class V>
K ft_map_node<K, V>::getKey()
{
    return (this->key);
}

template<class K,class V>
void ft_map_node<K, V>::setKey(K key)
{
    this->key = key;
}

template<class K,class V>
V ft_map_node<K, V>::getValue()
{
    return (this->value);
}

template<class K,class V>
V &ft_map_node<K, V>::getValueR()
{
    V &tmp = this->value;
    return (tmp);
}

template<class K,class V>
void ft_map_node<K, V>::setValue(V value)
{
    this->value = value;
}

template<class K,class V>
ft_map_node<K, V> *ft_map_node<K, V>::getNext()
{
    return (this->next);
}

template<class K,class V>
void ft_map_node<K, V>::setNext(ft_map_node<K, V> *target)
{
    this->next = target;
}

#endif