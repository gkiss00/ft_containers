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

    std::cout << "--- Push 1, 2, 3 et 4, 5, 6 dans stack1 et stack2 ---" << std::endl;
    
    stack1->push(1);
    stack1->push(2);
    stack1->push(3);

    stack2->push(4);
    stack2->push(5);
    stack2->push(6);

    ft_stack1->push(1);
    ft_stack1->push(2);
    ft_stack1->push(3);

    ft_stack2->push(4);
    ft_stack2->push(5);
    ft_stack2->push(6);

    std::cout << "stack    :: size :: " << stack1->size() << " " << stack2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack2->size() << std::endl;
    
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;

    std::cout << "--- stack2 = stack1 ---" << std::endl;

    stack2 = stack1;
    ft_stack2 = ft_stack1;

    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;

    std::cout << "--- stack1->pop ---" << std::endl;

    stack1->pop();
    ft_stack1->pop();

    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack2->size() << std::endl;

    std::cout << "--- stack1 ==  stack2 ---" << std::endl;

    std::cout << "stack    :: ==   :: " << (stack1 == stack2) << std::endl;
    std::cout << "ft_stack :: ==   :: " << (ft_stack1 == ft_stack2) << std::endl;

    ft_stack1->pop();

    std::cout << "stack    :: ==   :: " << (stack1 == stack2) << std::endl;
    std::cout << "ft_stack :: ==   :: " << (ft_stack1 == ft_stack2) << std::endl;

}