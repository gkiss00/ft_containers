#include <iostream>
#include <string>
#include <queue>
#include "../queue.hpp"

int     main_queue()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << " queue VS FT_queue  " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::cout << std::endl;

    std::queue<int> *queue1 = new std::queue<int>();
    std::queue<int> *queue2 = new std::queue<int>();

    ft::queue<int> *ft_queue1 = new ft::queue<int>();
    ft::queue<int> *ft_queue2 = new ft::queue<int>();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "     OPERATORS      " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON ENMPTY queue +-+-+-+-+" << std::endl;
    std::cout << std::endl;

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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "queue    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_queue :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "queue    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_queue :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON SAME queue WITH SAME LEN +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->push(1);
    queue1->push(2);
    queue1->push(3);

    queue2->push(1);
    queue2->push(2);
    queue2->push(3);

    ft_queue1->push(1);
    ft_queue1->push(2);
    ft_queue1->push(3);

    ft_queue2->push(1);
    ft_queue2->push(2);
    ft_queue2->push(3);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "queue    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_queue :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "queue    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_queue :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON SAME queue WITH DIFFERENT LENGTHS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->push(4);
    ft_queue1->push(4);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "queue    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_queue :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "queue    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_queue :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON DIFFERENT queue WITH SAME LENGTHS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(queue1);
    delete(queue2);
    delete(ft_queue1);
    delete(ft_queue2);

    queue1 = new std::queue<int>();
    queue2 = new std::queue<int>();
    ft_queue1 = new ft::queue<int>();
    ft_queue2 = new ft::queue<int>();

    queue1->push(0);
    queue1->push(1);
    queue1->push(2);

    queue2->push(1);
    queue2->push(2);
    queue2->push(3);

    ft_queue1->push(0);
    ft_queue1->push(1);
    ft_queue1->push(2);
    
    ft_queue2->push(1);
    ft_queue2->push(2);
    ft_queue2->push(3);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "queue    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_queue :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "queue    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_queue :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON DIFFERENT queue WITH DIFFERENT LENGTHS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->push(3);
    ft_queue1->push(3);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "queue    :: <=   :: " << (*queue1 <= *queue2) << std::endl;
    std::cout << "ft_queue :: <=   :: " << (*ft_queue1 <= *ft_queue2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "queue    :: >=   :: " << (*queue1 >= *queue2) << std::endl;
    std::cout << "ft_queue :: >=   :: " << (*ft_queue1 >= *ft_queue2) << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "        EMPTY       " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON EMPTY queueS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(queue1);
    delete(queue2);
    delete(ft_queue1);
    delete(ft_queue2);

    queue1 = new std::queue<int>();
    ft_queue1 = new ft::queue<int>();

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "queue    :: empty:: " << queue1->empty() <<  std::endl;
    std::cout << "ft_queue :: empty:: " << ft_queue1->empty() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON NON-EMPTY queueS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->push(1);
    ft_queue1->push(1);

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "queue    :: empty:: " << queue1->empty() <<  std::endl;
    std::cout << "ft_queue :: empty:: " << ft_queue1->empty() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "        SIZE        " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ SIZE ON EMPTY queueS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(queue1);
    delete(ft_queue1);

    queue1 = new std::queue<int>();
    ft_queue1 = new ft::queue<int>();
    
    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() <<  std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON queueS WITH LEN 1+-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->push(1);
    ft_queue1->push(1);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() <<  std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON queueS WITH LEN 5+-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->push(1);
    ft_queue1->push(1);
    queue1->push(1);
    ft_queue1->push(1);
    queue1->push(1);
    ft_queue1->push(1);
    queue1->push(1);
    ft_queue1->push(1);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() <<  std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << " FRONT BACK PUSH POP" << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    delete(queue1);
    delete(ft_queue1);

    queue1 = new std::queue<int>();
    ft_queue1 = new ft::queue<int>();

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ PUSH 1 2 3 4 5 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->push(1);
    queue1->push(2);
    queue1->push(3);
    queue1->push(4);
    queue1->push(5);

    ft_queue1->push(1);
    ft_queue1->push(2);
    ft_queue1->push(3);
    ft_queue1->push(4);
    ft_queue1->push(5);

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ BACK SHOULD BE 5 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back()  << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ FRONT SHOULD BE 1 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "queue    :: front:: " << queue1->front()  << std::endl;
    std::cout << "ft_queue :: front:: " << ft_queue1->front() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ POP +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    queue1->pop();
    ft_queue1->pop();

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ BACK SHOULD BE 5 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ FRONT SHOULD BE 2 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## FRONT ########" << std::endl;
    std::cout << "queue    :: front:: " << queue1->front()  << std::endl;
    std::cout << "ft_queue :: front:: " << ft_queue1->front() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "          =         " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ queue2 = queue1 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## = ########" << std::endl;
    queue2 = queue1;
    ft_queue2 = ft_queue1;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() << " " << queue2->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << " " << ft_queue2->size() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

    std::cout << "######## BACK queue1 ########" << std::endl;
    queue1->pop();
    ft_queue1->pop();

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() << " " << queue2->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << " " << ft_queue2->size() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << " " << queue2->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << " " << ft_queue2->back() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "  COPY CONSTRUCTOR  " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ QUEUE_COPY(queue1) +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(queue1);
    delete(ft_queue1);

    queue1 = new std::queue<int>();
    ft_queue1 = new ft::queue<int>();

    queue1->push(1);
    queue1->push(2);
    queue1->push(3);
    queue1->push(4);
    queue1->push(5);

    ft_queue1->push(1);
    ft_queue1->push(2);
    ft_queue1->push(3);
    ft_queue1->push(4);
    ft_queue1->push(5);

    std::cout << "######## CONSTRUCTOR BY COPY ########" << std::endl;
    std::queue<int> *queue_copy = new std::queue<int>(*queue1);
    ft::queue<int> *ft_queue_copy = new ft::queue<int>(*ft_queue1);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() << " " << queue_copy->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << " " << ft_queue_copy->size() << std::endl;
    
    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << " " << queue_copy->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << " " << ft_queue_copy->back() << std::endl;

    std::cout << "######## POP ########" << std::endl;
    //queue2->pop(); //segfault sometimes
    ft_queue2->pop(); //sometimes does not do the job

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "queue    :: size :: " << queue1->size() << " " << queue_copy->size() << std::endl;
    std::cout << "ft_queue :: size :: " << ft_queue1->size() << " " << ft_queue_copy->size() << std::endl;

    std::cout << "######## BACK ########" << std::endl;
    std::cout << "queue    :: back :: " << queue1->back() << " " << queue_copy->back() << std::endl;
    std::cout << "ft_queue :: back :: " << ft_queue1->back() << " " << ft_queue_copy->back() << std::endl;

    

    delete(queue1);
    delete(queue_copy);
    delete(ft_queue1);
    delete(ft_queue_copy);

    return (0);
}