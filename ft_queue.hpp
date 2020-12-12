#ifndef FT_QUEUE
#define FT_QUEUE

#include "./utils/ft_node.hpp"
#include <stdio.h>
#include <iostream>

namespace ft {
template<class T>
class ft_queue {
    public:
        typedef T value_type;
        typedef unsigned int size_type;
        //typedef Container container_type;
    private:
        ft_node<T> *node;
    public:
        ft_queue();
        ft_queue(const ft_queue &target);
        ft_queue &operator=(const ft_queue &target);
        ~ft_queue();

        bool empty() const;
        size_type size() const;
        value_type front();
        value_type back();
        void push(T target);
        void pop();

        bool operator==(ft_queue<T> &target);
        bool operator!=(ft_queue<T> &target);
        bool operator<(ft_queue<T> &target);
        bool operator<=(ft_queue<T> &target);
        bool operator>(ft_queue<T> &target);
        bool operator>=(ft_queue<T> &target);
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
bool ft_queue<T>::empty() const
{
    return(this->node == NULL ? (true) : (false));
}

template<class T>
typename ft_queue<T>::size_type ft_queue<T>::size() const
{
    unsigned int i;
    ft_node<T> *tmp;

    i = 0;
    tmp = this->node;
    while(tmp != NULL)
    {
        ++i;
        tmp = tmp->getNext();
    }
    return (i);
}

template<class T>
typename ft_queue<T>::value_type ft_queue<T>::front()
{
    if (this->node != NULL)
        return(this->node->getElement());
    return (0);
}

template<class T>
typename ft_queue<T>::value_type ft_queue<T>::back()
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
bool ft_queue<T>::operator==(ft_queue<T> &target)
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
bool ft_queue<T>::operator!=(ft_queue<T> &target)
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
bool ft_queue<T>::operator<(ft_queue<T> &target)
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
bool ft_queue<T>::operator<=(ft_queue<T> &target)
{
    return (this->operator<(target) || this->operator==(target));
}

template<class T>
bool ft_queue<T>::operator>(ft_queue<T> &target)
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
bool ft_queue<T>::operator>=(ft_queue<T> &target)
{
    return (this->operator>(target) || this->operator==(target));
}

}

#endif