#ifndef FT_STACK
#define FT_STACK

#include "ft_node.hpp"
#include <stdio.h>
#include <iostream>


template<class T>
class ft_stack {
    private:
        ft_node<T> *node;
    public:
        ft_stack();
        ft_stack(const ft_stack &target);
        ft_stack &operator=(const ft_stack &target);
        ~ft_stack();

        bool empty();
        unsigned int size();
        T top();
        void push(T target);
        void pop();

        friend bool operator==(const ft_stack<T> &me, const ft_stack<T> &target);
        friend bool operator!=(const ft_stack<T> &me, const ft_stack<T> &target);
        friend bool operator<(const ft_stack<T> &me, const ft_stack<T> &target);
        friend bool operator<=(const ft_stack<T> &me, const ft_stack<T> &target);
        friend bool operator>(const ft_stack<T> &me, const ft_stack<T> &target);
        friend bool operator>=(const ft_stack<T> &me, const ft_stack<T> &target);
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
    this->node = target.node;
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
unsigned int ft_stack<T>::size()
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
T ft_stack<T>::top()
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



#endif