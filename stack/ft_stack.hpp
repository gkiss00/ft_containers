#ifndef FT_STACK
#define FT_STACK


#include <stdio.h>
#include <iostream>
#include "./../utils/ft_node.hpp"

namespace ft {

template<class T>
class ft_stack {
    public:
        typedef T value_type;
        typedef unsigned int size_type;
    private:
        ft_node<T> *node;
    public:
        ft_stack();
        ft_stack(const ft_stack &target);
        ft_stack &operator=(const ft_stack &target);
        ~ft_stack();

        bool empty();
        size_type size();
        value_type top();
        void push(T target);
        void pop();

        bool operator==(ft_stack<T> &target);
        bool operator!=(ft_stack<T> &target);
        bool operator<(ft_stack<T> &target);
        bool operator<=(ft_stack<T> &target);
        bool operator>(ft_stack<T> &target);
        bool operator>=(ft_stack<T> &target);
};

//****************************************
//****************************************
//CONSTRUCTOR
//****************************************
//****************************************

template<class T>
ft_stack<T>::ft_stack()
{
    this->node = NULL;
}

template<class T>
ft_stack<T>::ft_stack(const ft_stack &target)
{
    ft_node<T> *tmp;
    ft_node<T> *node;

    tmp = NULL;
    node = target.node;
    for (unsigned int i = 0; i < target.size(); ++i)
    {
        if (i == 0)
        {
            this->node = new ft_node<T>(node->getElement());
            tmp = this->node;
        }
        else
        {
            this->node->setNext(new ft_node<T>(node->getElement()));
            this->node = this->node->getNext();
        }
        node = node->getNext();
    }
    this->node = tmp;
}

template<class T>
ft_stack<T> &ft_stack<T>::operator=(const ft_stack &target)
{
    ft_node<T> *tmp;

    tmp = this->node;
    while (this->node != NULL)
    {
        tmp = this->node;
        this->node = this->node->getNext();
        delete(tmp);
    }
    this->node = target.node;
    return (*this);
}

template<typename T>
ft_stack<T>::~ft_stack()
{
    ft_node<T> *tmp;

    tmp = this->node;
    while (this->node != NULL)
    {
        tmp = this->node;
        this->node = this->node->getNext();
        delete(tmp);
    }
}

//****************************************
//****************************************
//FUNCTIONS
//****************************************
//****************************************

template<class T>
bool ft_stack<T>::empty()
{
    return(this->node == NULL ? (true) : (false));
}

template<class T>
typename ft_stack<T>::size_type ft_stack<T>::size()
{
    unsigned int i;
    ft_node<T> *tmp;

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

template<class T>
typename ft_stack<T>::value_type ft_stack<T>::top()
{
    ft_node<T> *tmp;
    ft_node<T> *ret;

    tmp = this->node;
    while(this->node != NULL && this->node->getNext() != NULL)
    {
        this->node = this->node->getNext();
    }
    ret = this->node;
    this->node = tmp;
    if (ret != NULL)
        return (ret->getElement());
    return (0);
}

template<class T>
void ft_stack<T>::push(T target)
{
    ft_node<T> *tmp;
    ft_node<T> *nw;

    nw = new ft_node<T>(target);
    tmp = this->node;
    if (tmp == NULL)
        this->node = nw;
    else
    {
        while(this->node->getNext() != NULL)
            this->node = this->node->getNext();
        this->node->setNext(nw);
        this->node = tmp;
    }
}

template<class T>
void ft_stack<T>::pop()
{
    ft_node<T> *start;
    ft_node<T> *precedent;

    start = this->node;
    if (this->node != NULL)
    {
        if (this->node->getNext() == NULL)
        {
            delete(this->node);
            this->node = NULL;
        }
        else
        {
            while(this->node != NULL && this->node->getNext() != NULL)
            {
                precedent = this->node;
                this->node = this->node->getNext();
            }
            delete(this->node);
            precedent->setNext(NULL);
            this->node = start;
        }
    }
}

//****************************************
//****************************************
//COMPARAISON OPERATOR
//****************************************
//****************************************

template<class T>
bool ft_stack<T>::operator==(ft_stack<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = this->size() > target.size() ? (this->size()) : (target.size());
    node1 = this->node;
    node2 = target.node;
    if ((this->size()) != (target.size()))
        return (false);
    for(unsigned int i = 0; i < size; ++i)
    {
        if (node1->getElement() != node2->getElement())
            return (false);
        node1 = node1->getNext();
        node2 = node2->getNext();
    }
    return (true);
}

template<class T>
bool ft_stack<T>::operator!=(ft_stack<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = this->size() > target.size() ? (this->size()) : (target.size());
    node1 = this->node;
    node2 = target.node;
    if ((this->size()) != (target.size()))
        return (true);
    for(unsigned int i = 0; i < size; ++i)
    {
        if (node1->getElement() != node2->getElement())
            return (true);
        node1 = node1->getNext();
        node2 = node2->getNext();
    }
    return (false);
}

template<class T>
bool ft_stack<T>::operator<(ft_stack<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = this->size() > target.size() ? (this->size()) : (target.size());
    node1 = this->node;
    node2 = target.node;
    for(unsigned int i = 0; i < size; ++i)
    {
        if (node1->getElement() != node2->getElement())
            return (node1->getElement() < node2->getElement() ? (true) : (false));
        node1 = node1->getNext();
        node2 = node2->getNext();
    }
    if ((this->size()) < (target.size()))
        return (true);
    return (false);
}

template<class T>
bool ft_stack<T>::operator<=(ft_stack<T> &target)
{
    return (this->operator<(target) || this->operator==(target));
}

template<class T>
bool ft_stack<T>::operator>(ft_stack<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = this->size() > target.size() ? (this->size()) : (target.size());
    node1 = this->node;
    node2 = target.node;
    for(unsigned int i = 0; i < size; ++i)
    {
        if (node1->getElement() != node2->getElement())
            return (node1->getElement() > node2->getElement() ? (true) : (false));
        node1 = node1->getNext();
        node2 = node2->getNext();
    }
    if ((this->size()) > (target.size()))
        return (true);
    return (false);
}

template<class T>
bool ft_stack<T>::operator>=(ft_stack<T> &target)
{
    return (this->operator>(target) || this->operator==(target));
}

}

#endif