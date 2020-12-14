#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "./utils/deque.hpp"
# include "./utils/ft_node.hpp"
# include <stdio.h>
# include <iostream>

namespace ft {
template<class T, class Container = ft::deque<T> >
class queue : public ft::deque<T>{
    public:
        typedef T value_type;
        typedef unsigned int size_type;
        typedef Container container_type;

    public:

        queue(const container_type &target = container_type());
        queue &operator=(const queue &target );

        value_type front();
        value_type back();
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

template<class T, class container_type>
queue<T, container_type>::queue(const container_type &target)
{
    ft_node<T> *tmp;
    ft_node<T> *node;

    tmp = NULL;
    node = target.getNode();
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

template<class T, class container_type>
queue<T, container_type> &queue<T, container_type>::operator=(const queue &target)
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

//****************************************
//****************************************
//FUNCTIONS
//****************************************
//****************************************

template<class T, class container_type>
typename queue<T, container_type>::value_type queue<T, container_type>::front()
{
    if (this->node != NULL)
        return(this->node->getElement());
    return (0);
}

template<class T, class container_type>
typename queue<T, container_type>::value_type queue<T, container_type>::back()
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

template<class T, class container_type>
void queue<T, container_type>::pop()
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

template<class T, class container_type>
bool queue<T, container_type>::operator==(queue<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = this->size() > target.size() ? (target.size()) : (this->size());
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

template<class T, class container_type>
bool queue<T, container_type>::operator!=(queue<T> &target)
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

template<class T, class container_type>
bool queue<T, container_type>::operator<(queue<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = this->size() > target.size() ? (target.size()) : (this->size());
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

template<class T, class container_type>
bool queue<T, container_type>::operator<=(queue<T> &target)
{
    return (this->operator<(target) || this->operator==(target));
}

template<class T, class container_type>
bool queue<T, container_type>::operator>(queue<T> &target)
{
    unsigned int size;
    ft_node<T> *node1;
    ft_node<T> *node2;

    size = this->size() > target.size() ? (target.size()) : (this->size());
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

template<class T, class container_type>
bool queue<T, container_type>::operator>=(queue<T> &target)
{
    return (this->operator>(target) || this->operator==(target));
}

}

#endif