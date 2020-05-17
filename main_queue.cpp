#include "ft_queue.hpp"
#include <iostream>
#include <string>
#include <queue>

int     main()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << " QUEUE VS FT_QUEUE  " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::queue<int> *queue1 = new std::queue<int>();
    std::queue<int> *queue2 = new std::queue<int>();

    ft_queue<int> *ft_queue1 = new ft_queue<int>();
    ft_queue<int> *ft_queue2 = new ft_queue<int>();

    std::cout << "########PUSH########" << std::endl;
    
    queue1->push(5);
    queue1->push(-21);
    queue1->push(12);

    queue2->push(8);
    queue2->push(89);
    queue2->push(-4);

    ft_queue1->push(5);
    ft_queue1->push(-21);
    ft_queue1->push(12);

    ft_queue2->push(8);
    ft_queue2->push(89);
    ft_queue2->push(-4);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << queue1->size() << " " << queue2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_queue1->size() << " " << ft_queue2->size() << std::endl;

    std::cout << "######## == ########" << std::endl;
    std::cout << "stack    :: ==   :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "ft_stack :: ==   :: " << (*ft_queue1 == *ft_queue2) << std::endl;

    std::cout << "######## != ########" << std::endl;
    std::cout << "stack    :: !=   :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "ft_stack :: !=   :: " << (*ft_queue1 != *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "ft_stack :: <    :: " << (*ft_queue1 < *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >    :: " << (*queue1 > *queue2) << std::endl;
    std::cout << "ft_stack :: >    :: " << (*ft_queue1 > *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "stack    :: front:: " << queue1->front() << " " << queue2->front() << std::endl;
    std::cout << "ft_stack :: front:: " << ft_queue1->front() << " " << ft_queue2->front() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "stack    :: back:: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_stack :: back:: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

    std::cout << "######## = ########" << std::endl;
    queue2 = queue1;
    ft_queue2 = ft_queue1;
    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "stack    :: front:: " << queue1->front() << " " << queue2->front() << std::endl;
    std::cout << "ft_stack :: front:: " << ft_queue1->front() << " " << ft_queue2->front() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "stack    :: back:: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_stack :: back:: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

    std::cout << "######## POP ########" << std::endl;
    queue1->pop();
    ft_queue1->pop();
    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "stack    :: front:: " << queue1->front() << " " << queue2->front() << std::endl;
    std::cout << "ft_stack :: front:: " << ft_queue1->front() << " " << ft_queue2->front() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "stack    :: back:: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_stack :: back:: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << queue1->size() << " " << queue2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_queue1->size() << " " << ft_queue2->size() << std::endl;

    std::cout << "######## == ########" << std::endl;
    std::cout << "stack    :: ==   :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "ft_stack :: ==   :: " << (*ft_queue1 == *ft_queue2) << std::endl;

    std::cout << "######## != ########" << std::endl;
    std::cout << "stack    :: !=   :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "ft_stack :: !=   :: " << (*ft_queue1 != *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "ft_stack :: <    :: " << (*ft_queue1 < *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >    :: " << (*queue1 > *queue2) << std::endl;
    std::cout << "ft_stack :: >    :: " << (*ft_queue1 > *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    delete(ft_queue1);
}