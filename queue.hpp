#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "./utils/ft_node.hpp"
# include <stdio.h>
# include <iostream>

namespace ft {
template<class T>
class queue {
    public:
        typedef T value_type;
        typedef unsigned int size_type;
        //typedef Container container_type;
    private:
        ft_node<T> *node;
    public:
        queue();
        queue(const queue &target);
        queue &operator=(const queue &target);
        ~queue();

        bool empty() const;
        size_type size() const;
        value_type front();
        value_type back();
        void push(T target);
        void pop();

        bool operator==(queue<T> &target);
        bool operator!=(queue<T> &target);
        bool operator<(queue<T> &target);
        bool operator<=(queue<T> &target);
        bool operator>(queue<T> &target);
        bool operator>=(queue<T> &target);
};

//****************************************
//****************************************
//CONSTRUCTOR
//****************************************
//****************************************

template<class T>
queue<T>::queue()
{
    this->node = NULL;
}

template<class T>
queue<T>::queue(const queue &target)
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
queue<T> &queue<T>::operator=(const queue &target)
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
queue<T>::~queue()
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
bool queue<T>::empty() const
{
    return(this->node == NULL ? (true) : (false));
}

template<class T>
typename queue<T>::size_type queue<T>::size() const
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
typename queue<T>::value_type queue<T>::front()
{
    if (this->node != NULL)
        return(this->node->getElement());
    return (0);
}

template<class T>
typename queue<T>::value_type queue<T>::back()
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
void queue<T>::push(T target)
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
void queue<T>::pop()
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
bool queue<T>::operator==(queue<T> &target)
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
bool queue<T>::operator!=(queue<T> &target)
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
bool queue<T>::operator<(queue<T> &target)
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
bool queue<T>::operator<=(queue<T> &target)
{
    return (this->operator<(target) || this->operator==(target));
}

template<class T>
bool queue<T>::operator>(queue<T> &target)
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
bool queue<T>::operator>=(queue<T> &target)
{
    return (this->operator>(target) || this->operator==(target));
}

}

#endif