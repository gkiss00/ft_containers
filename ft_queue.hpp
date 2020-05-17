#ifndef FT_QUEUE
#define FT_QUEUE

#include "ft_node.hpp"
#include <stdio.h>
#include <iostream>


template<class T>
class ft_queue {
    private:
        ft_node<T> *node;
    public:
        ft_queue();
        ft_queue(const ft_queue &target);
        ft_queue &operator=(const ft_queue &target);
        ~ft_queue();

        bool empty();
        unsigned int size();
        T front();
        T back();
        void push(T target);
        void pop();

        friend bool operator==(const ft_queue<T> &me, const ft_queue<T> &target);
        friend bool operator!=(const ft_queue<T> &me, const ft_queue<T> &target);
        friend bool operator<(const ft_queue<T> &me, const ft_queue<T> &target);
        friend bool operator<=(const ft_queue<T> &me, const ft_queue<T> &target);
        friend bool operator>(const ft_queue<T> &me, const ft_queue<T> &target);
        friend bool operator>=(const ft_queue<T> &me, const ft_queue<T> &target);
};

//****************************************
//****************************************
//CONSTRUCTOR
//****************************************
//****************************************

template<class T>
ft_queue<T>::ft_queue()
{
    this->node = NULL;
}

template<class T>
ft_queue<T>::ft_queue(const ft_queue &target)
{
    this->node = target.node;
}

template<class T>
ft_queue<T> &ft_queue<T>::operator=(const ft_queue &target)
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
ft_queue<T>::~ft_queue()
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
bool ft_queue<T>::empty()
{
    return(this->node == NULL ? (true) : (false));
}

template<class T>
unsigned int ft_queue<T>::size()
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
T ft_queue<T>::front()
{
    if (this->node != NULL)
        return(this->node->getElement());
    return (0);
}

template<class T>
T ft_queue<T>::back()
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
void ft_queue<T>::push(T target)
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
void ft_queue<T>::pop()
{
    ft_node<T> *tmp;

    tmp = NULL;
    if (this->node != NULL)
    {
        tmp = this->node->getNext();
        delete(this->node);
        this->node = tmp;
    }
}

//****************************************
//****************************************
//COMPARAISON OPERATOR
//****************************************
//****************************************

template<class T>
inline bool operator==(const ft_queue<T> &me, const ft_queue<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = me.size() > target.size() ? (me.size()) : (target.size());
    node1 = me.node;
    node2 = target.node;
    if ((me.size()) != (target.size()))
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
inline bool operator!=(const ft_queue<T> &me, const ft_queue<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = me.size() > target.size() ? (me.size()) : (target.size());
    
    if ((me.size()) != (target.size()))
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
inline bool operator<(const ft_queue<T> &me, const ft_queue<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = me.size() > target.size() ? (me.size()) : (target.size());
    node1 = me.node;
    node2 = target.node;
    for(unsigned int i = 0; i < size; ++i)
    {
        if (node1->getElement() != node2->getElement())
            return (node1->getElement() < node2->getElement() ? (true) : (false));
        node1 = node1->getNext();
        node2 = node2->getNext();
    }
    if ((me.size()) < (target.size()))
        return (true);
    return (false);
}

template<class T>
inline bool operator<=(const ft_queue<T> &me, const ft_queue<T> &target)
{
    return (operator<(me, target) || operator==(me, target));
}

template<class T>
inline bool operator>(const ft_queue<T> &me, const ft_queue<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = me.size() > target.size() ? (me.size()) : (target.size());
    node1 = me.node;
    node2 = target.node;
    for(unsigned int i = 0; i < size; ++i)
    {
        if (node1->getElement() != node2->getElement())
            return (node1->getElement() > node2->getElement() ? (true) : (false));
        node1 = node1->getNext();
        node2 = node2->getNext();
    }
    if ((me.size()) > (target.size()))
        return (true);
    return (false);
}

template<class T>
bool operator>=(const ft_queue<T> &me, const ft_queue<T> &target)
{
    return (operator>(me, target) || operator==(me, target));
}

#endif