#include "ft_stack.hpp"
#include "ft_queue.hpp"
#include "ft_map.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>

int     main()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << " STACK VS FT_STACK  " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::stack<int> *stack1 = new std::stack<int>();
    std::stack<int> *stack2 = new std::stack<int>();

    ft_stack<int> *ft_stack1 = new ft_stack<int>();
    ft_stack<int> *ft_stack2 = new ft_stack<int>();

    std::cout << "######## PUSH ########" << std::endl;
    
    stack1->push(5);
    stack1->push(-21);
    stack1->push(12);

    stack2->push(8);
    stack2->push(89);
    stack2->push(-4);

    ft_stack1->push(5);
    ft_stack1->push(-21);
    ft_stack1->push(12);

    ft_stack2->push(8);
    ft_stack2->push(89);
    ft_stack2->push(-4);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack2->size() << std::endl;

    std::cout << "######## == ########" << std::endl;
    std::cout << "stack    :: ==   :: " << (*stack1 == *stack2) << std::endl;
    std::cout << "ft_stack :: ==   :: " << (*ft_stack1 == *ft_stack2) << std::endl;

    std::cout << "######## != ########" << std::endl;
    std::cout << "stack    :: !=   :: " << (*stack1 != *stack2) << std::endl;
    std::cout << "ft_stack :: !=   :: " << (*ft_stack1 != *ft_stack2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <    :: " << (*stack1 < *stack2) << std::endl;
    std::cout << "ft_stack :: <    :: " << (*ft_stack1 < *ft_stack2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >    :: " << (*stack1 > *stack2) << std::endl;
    std::cout << "ft_stack :: >    :: " << (*ft_stack1 > *ft_stack2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*stack1 <= *stack2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_stack1 <= *ft_stack2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*stack1 >= *stack2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_stack1 >= *ft_stack2) << std::endl;

    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;

    std::cout << "######## = ########" << std::endl;
    stack2 = stack1;
    ft_stack2 = ft_stack1;
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;

    std::cout << "######## POP ########" << std::endl;
    stack1->pop();
    ft_stack1->pop();
    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;
    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack2->size() << std::endl;

    std::cout << "######## == ########" << std::endl;
    std::cout << "stack    :: ==   :: " << (*stack1 == *stack2) << std::endl;
    std::cout << "ft_stack :: ==   :: " << (*ft_stack1 == *ft_stack2) << std::endl;

    std::cout << "######## != ########" << std::endl;
    std::cout << "stack    :: !=   :: " << (*stack1 != *stack2) << std::endl;
    std::cout << "ft_stack :: !=   :: " << (*ft_stack1 != *ft_stack2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <    :: " << (*stack1 < *stack2) << std::endl;
    std::cout << "ft_stack :: <    :: " << (*ft_stack1 < *ft_stack2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >    :: " << (*stack1 > *stack2) << std::endl;
    std::cout << "ft_stack :: >    :: " << (*ft_stack1 > *ft_stack2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*stack1 <= *stack2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_stack1 <= *ft_stack2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*stack1 >= *stack2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_stack1 >= *ft_stack2) << std::endl;



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


    std::cout << "/*****************\\" << std::endl;
    std::cout << "   MAP VS FT_MAP    " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::map<char, std::string> map1;
    ft_map<char, std::string> ft_map1;

    map1['a'] = "je suis a";
    ft_map1['a'] = "je suis a";
    std::cout << "map      :: [a]  :: " << map1['a'] << std::endl;
    std::cout << "ft_map   :: [a]  :: " << ft_map1['a'] << std::endl;

    delete(ft_stack1);
    delete(ft_queue2);
}