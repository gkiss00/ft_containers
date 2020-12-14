#include <iostream>
#include <string>
#include <stack>
#include "../stack.hpp"

int     main_stack()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << " STACK VS FT_STACK  " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::stack<int> *stack1 = new std::stack<int>();
    std::stack<int> *stack2 = new std::stack<int>();

    ft::stack<int> *ft_stack1 = new ft::stack<int>();
    ft::stack<int> *ft_stack2 = new ft::stack<int>();

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "stack    :: empty:: " << stack1->empty() << " " << stack2->empty() << std::endl;
    std::cout << "ft_stack :: empty:: " << ft_stack1->empty() << " " << ft_stack2->empty() << std::endl;

    std::cout << "######## PUSH ########" << std::endl;
    
    stack1->push(5);
    stack1->push(-21);
    stack1->push(12);

    ft_stack1->push(5);
    ft_stack1->push(-21);
    ft_stack1->push(12);

    stack2->push(8);
    stack2->push(89);
    stack2->push(-4);

    ft_stack2->push(8);
    ft_stack2->push(89);
    ft_stack2->push(-4);

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "stack    :: empty:: " << stack1->empty() << " " << stack2->empty() << std::endl;
    std::cout << "ft_stack :: empty:: " << ft_stack1->empty() << " " << ft_stack2->empty() << std::endl;

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

    std::cout << "######## TOP ########" << std::endl;
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

    std::cout << "######## CONSTRUCTOR BY COPY ########" << std::endl;
    std::stack<int> *stack_copy = new std::stack<int>(*stack2);
    ft::stack<int> *ft_stack_copy = new ft::stack<int>(*ft_stack2);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack_copy->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack_copy->size() << std::endl;
    
    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack2->top() << " " << stack_copy->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack2->top() << " " << ft_stack_copy->top() << std::endl;

    std::cout << "######## POP ########" << std::endl;
    stack2->pop();
    ft_stack2->pop();

    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack2->top() << " " << stack_copy->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack2->top() << " " << ft_stack_copy->top() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack_copy->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack_copy->size() << std::endl;

    delete(stack1);
    delete(stack_copy);
    delete(ft_stack1);
    delete(ft_stack_copy);

    return (0);
}