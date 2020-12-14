#include "../queue.hpp"
#include <iostream>
#include <string>
#include <queue>

int     main_queue()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << " QUEUE VS FT_QUEUE  " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::queue<int> *queue1 = new std::queue<int>();
    std::queue<int> *queue2 = new std::queue<int>();

    ft::queue<int> *ft_queue1 = new ft::queue<int>();
    ft::queue<int> *ft_queue2 = new ft::queue<int>();

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "queue    :: empty:: " << queue1->empty() << " " << queue2->empty() << std::endl;
    std::cout << "ft_queue :: empty:: " << ft_queue1->empty() << " " << ft_queue2->empty() << std::endl;

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

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "queue    :: empty:: " << queue1->empty() << " " << queue2->empty() << std::endl;
    std::cout << "ft_queue :: empty:: " << ft_queue1->empty() << " " << ft_queue2->empty() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() << " " << queue2->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << " " << ft_queue2->size() << std::endl;

    std::cout << "######## == ########" << std::endl;
    std::cout << "queue    :: ==   :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "ft_queue :: ==   :: " << (*ft_queue1 == *ft_queue2) << std::endl;

    std::cout << "######## != ########" << std::endl;
    std::cout << "queue    :: !=   :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "ft_queue :: !=   :: " << (*ft_queue1 != *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "queue    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "ft_queue :: <    :: " << (*ft_queue1 < *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "queue    :: >    :: " << (*queue1 > *queue2) << std::endl;
    std::cout << "ft_queue :: >    :: " << (*ft_queue1 > *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "queue    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_queue :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "queue    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_queue :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "queue    :: front:: " << queue1->front() << " " << queue2->front() << std::endl;
    std::cout << "ft_queue :: front:: " << ft_queue1->front() << " " << ft_queue2->front() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

    std::cout << "######## = ########" << std::endl;
    queue2 = queue1;
    ft_queue2 = ft_queue1;

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "queue    :: front:: " << queue1->front() << " " << queue2->front() << std::endl;
    std::cout << "ft_queue :: front:: " << ft_queue1->front() << " " << ft_queue2->front() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

    std::cout << "######## POP ########" << std::endl;
    queue1->pop();
    ft_queue1->pop();

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "queue    :: front:: " << queue1->front() << " " << queue2->front() << std::endl;
    std::cout << "ft_queue :: front:: " << ft_queue1->front() << " " << ft_queue2->front() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() << " " << queue2->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << " " << ft_queue2->size() << std::endl;

    std::cout << "######## == ########" << std::endl;
    std::cout << "queue    :: ==   :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "ft_queue :: ==   :: " << (*ft_queue1 == *ft_queue2) << std::endl;

    std::cout << "######## != ########" << std::endl;
    std::cout << "queue    :: !=   :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "ft_queue :: !=   :: " << (*ft_queue1 != *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "queue    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "ft_queue :: <    :: " << (*ft_queue1 < *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "queue    :: >    :: " << (*queue1 > *queue2) << std::endl;
    std::cout << "ft_queue :: >    :: " << (*ft_queue1 > *ft_queue2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "queue    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_queue :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "queue    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_queue :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    std::cout << "######## CONSTRUCTOR BY COPY ########" << std::endl;
    std::queue<int> *queue_copy = new std::queue<int>(*queue2);
    ft::queue<int> *ft_queue_copy = new ft::queue<int>(*ft_queue2);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue2->size() << " " << queue_copy->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue2->size() << " " << ft_queue_copy->size() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue2->back() << " " << queue_copy->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue2->back() << " " << ft_queue_copy->back() << std::endl;

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "queue    :: front:: " << queue2->front() << " " << queue_copy->front() << std::endl;
    std::cout << "ft_queue :: front:: " << ft_queue2->front() << " " << ft_queue_copy->front() << std::endl;

    std::cout << "######## POP ########" << std::endl;
    queue2->pop();
    ft_queue2->pop();

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue2->size() << " " << queue_copy->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue2->size() << " " << ft_queue_copy->size() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue2->back() << " " << queue_copy->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue2->back() << " " << ft_queue_copy->back() << std::endl;

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "queue    :: front:: " << queue2->front() << " " << queue_copy->front() << std::endl;
    std::cout << "ft_queue :: front:: " << ft_queue2->front() << " " << ft_queue_copy->front() << std::endl;

    delete(ft_queue_copy);
    delete(ft_queue1);
    delete(queue1);
    delete(queue_copy);
    return (0);
}