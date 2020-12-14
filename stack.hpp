#ifndef STACK_HPP
# define STACK_HPP


# include <stdio.h>
# include <iostream>
# include "./utils/deque.hpp"
# include "./utils/ft_node.hpp"

namespace ft {

template<class T, class Container = ft::deque<T> >
class stack : public ft::deque<T> {

    private:
        ft_node<T> *getNode() const {};

    public:
        typedef T value_type;
        typedef unsigned int size_type;
        typedef Container container_type;
        
        stack(const container_type &target = container_type());
        stack &operator=(const stack &target);

        value_type top();
        void pop();

        bool operator==(stack<T> &target);
        bool operator!=(stack<T> &target);
        bool operator<(stack<T> &target);
        bool operator<=(stack<T> &target);
        bool operator>(stack<T> &target);
        bool operator>=(stack<T> &target);
};

//****************************************
//****************************************
//CONSTRUCTOR
//****************************************
//****************************************



template<class T, class container_type>
stack<T, container_type>::stack(const container_type &target)
{
    ft_node<T> *save;
    ft_node<T> *n;

    save = NULL;
    n = target.getNode();
    for (unsigned int i = 0; i < target.size(); ++i)
    {
        if (i == 0)
        {
            this->node = new ft_node<T>(n->getElement());
            save = this->node;
        }
        else
        {
            this->node->setNext(new ft_node<T>(n->getElement()));
            this->node = this->node->getNext();
        }
        n = n->getNext();
    }
    this->node = save;
}

template<class T, class container_type>
stack<T, container_type> &stack<T, container_type>::operator=(const stack &target)
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
typename stack<T, container_type>::value_type stack<T, container_type>::top()
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
void stack<T, container_type>::pop()
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

template<class T, class container_type>
bool stack<T, container_type>::operator==(stack<T> &target)
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

template<class T, class container_type>
bool stack<T, container_type>::operator!=(stack<T> &target)
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
bool stack<T, container_type>::operator<(stack<T> &target)
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
bool stack<T, container_type>::operator<=(stack<T> &target)
{
    return (this->operator<(target) || this->operator==(target));
}

template<class T, class container_type>
bool stack<T, container_type>::operator>(stack<T> &target)
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
bool stack<T, container_type>::operator>=(stack<T> &target)
{
    return (this->operator>(target) || this->operator==(target));
}

}

#endif