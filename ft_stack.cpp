#include "ft_stack.hpp"

//****************************************
//****************************************
//COMPARAISON OPERATOR
//****************************************
//****************************************

template<class T>
bool operator==(ft_stack<T> &me, ft_stack<T> &target)
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
bool operator!=(ft_stack<T> &me, ft_stack<T> &target)
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
bool operator<(ft_stack<T> &me, ft_stack<T> &target)
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
bool operator<=(ft_stack<T> &me, ft_stack<T> &target)
{
    return (operator<(me, target) || operator==(me, target));
}

template<class T>
bool operator>(ft_stack<T> &me, ft_stack<T> &target)
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
bool operator>=(ft_stack<T> &me, ft_stack<T> &target)
{
    return (operator>(me, target) || operator==(me, target));
}