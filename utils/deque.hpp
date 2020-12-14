#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "ft_node.hpp"

namespace ft{
    template<class T>
    class deque {

        protected:
            ft_node<T> *node;
            
        public:
            
            
            deque();
            deque(const deque &target);
            virtual ~deque();

            bool empty() const;
            unsigned int size() const;
            void push(T target);

            ft_node<T> *getNode()const {return this->node;};
            
    };

    //****************************************
    //****************************************
    //COMPARAISON OPERATOR
    //****************************************
    //****************************************

    template <class T>
    deque<T>::deque(){
        this->node = NULL;
    }

    template <class T>
    deque<T>::deque(const deque &target){
        ft_node<T> *save;
        ft_node<T> *n;

        save = NULL;
        n = target.node;
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

    template <class T>
    deque<T>::~deque(){
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
    //FUNCTION
    //****************************************
    //****************************************

    template <class T>
    unsigned int deque<T>::size() const
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

    template <class T>
    void deque<T>::push(T target)
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

    template <class T>
    bool deque<T>::empty() const
    {
        return(this->node == NULL ? (true) : (false));
    }
}

#endif