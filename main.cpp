#include "ft_stack.hpp"
#include <iostream>
#include <string>
#include <stack>

int     main()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << " STACK VS FT_STACK  " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::stack<int> *stack1 = new std::stack<int>();
    std::stack<int> *stack2 = new std::stack<int>();

    ft_stack<int> *ft_stack1 = new ft_stack<int>();
    ft_stack<int> *ft_stack2 = new ft_stack<int>();

    std::cout << "########PUSH########" << std::endl;
    
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
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack2->size() << std::endl;

    std::cout << "######## == ########" << std::endl;
    std::cout << "stack    :: ==   :: " << (stack1 == stack2) << std::endl;
    std::cout << "ft_stack :: ==   :: " << (ft_stack1 == ft_stack2) << std::endl;

    std::cout << "######## != ########" << std::endl;
    std::cout << "stack    :: !=   :: " << (stack1 != stack2) << std::endl;
    std::cout << "ft_stack :: !=   :: " << (ft_stack1 != ft_stack2) << std::endl;

    std::cout << "######## < ########" << std::endl;
    std::cout << "stack    :: <    :: " << (stack1 < stack2) << std::endl;
    std::cout << "ft_stack :: <    :: " << (ft_stack1 < ft_stack2) << std::endl;

    std::cout << "######## > ########" << std::endl;
    std::cout << "stack    :: >    :: " << (stack1 > stack2) << std::endl;
    std::cout << "ft_stack :: >    :: " << (ft_stack1 > ft_stack2) << std::endl;

    delete(ft_stack1);
}