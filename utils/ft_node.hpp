#ifndef FT_NODE
#define FT_NODE

#include <stdio.h>
#include <string>
#include <iostream>

template<class T>
class ft_node {
    private:
        T element;
        ft_node *parent;
        ft_node *next;

        ft_node();

    public:
        ft_node(T elem);
        ft_node(const ft_node<T> &target);
        ft_node &operator=(const ft_node<T> &target);
        ~ft_node();

        ft_node *getNext();
        void setNext(ft_node *target);
        T getElement();
        void setElement(T target);
};

//****************************************
//****************************************
//CONSTRUCTOR
//****************************************
//****************************************

template<class T>
ft_node<T>::ft_node()
{
    this->element = 0;
    this->parent = NULL;
    this->next = NULL;
}
template<class T>
ft_node<T>::ft_node(T elem)
{
    this->element = elem;
    this->parent = NULL;
    this->next = NULL;
}
template<class T>
ft_node<T>::ft_node(const ft_node<T> &target)
{
    this->element = target.element;
    this->parent = NULL;
    this->next = NULL;
}
template<class T>
ft_node<T> &ft_node<T>::operator=(const ft_node<T> &target)
{
    this->element = target.element;
    this->parent = NULL;
    this->next = NULL;
    return (*this);
}
template<class T>
ft_node<T>::~ft_node()
{

}

//****************************************
//****************************************
//GETTER && SETTER
//****************************************
//****************************************

template<class T>
ft_node<T> *ft_node<T>::getNext()
{
    return (this->next);
}

template<class T>
void ft_node<T>::setNext(ft_node *target)
{
    this->next = target;
}

template<class T>
T ft_node<T>::getElement()
{
    return (this->element);
}

template<class T>
void ft_node<T>::setElement(T target)
{
    this->element = target;
}

#endif