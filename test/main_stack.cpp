#include <iostream>
#include <string>
#include <stack>
#include "../stack.hpp"

int     main_stack()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << " STACK VS FT_STACK  " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::cout << std::endl;

    std::stack<int> *stack1 = new std::stack<int>();
    std::stack<int> *stack2 = new std::stack<int>();

    ft::stack<int> *ft_stack1 = new ft::stack<int>();
    ft::stack<int> *ft_stack2 = new ft::stack<int>();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "     OPERATORS      " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON ENMPTY STACK +-+-+-+-+" << std::endl;
    std::cout << std::endl;

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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*stack1 <= *stack2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_stack1 <= *ft_stack2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*stack1 >= *stack2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_stack1 >= *ft_stack2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON SAME STACK WITH SAME LEN +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->push(1);
    stack1->push(2);
    stack1->push(3);

    stack2->push(1);
    stack2->push(2);
    stack2->push(3);

    ft_stack1->push(1);
    ft_stack1->push(2);
    ft_stack1->push(3);

    ft_stack2->push(1);
    ft_stack2->push(2);
    ft_stack2->push(3);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*stack1 <= *stack2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_stack1 <= *ft_stack2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*stack1 >= *stack2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_stack1 >= *ft_stack2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON SAME STACK WITH DIFFERENT LENGTHS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->push(4);
    ft_stack1->push(4);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*stack1 <= *stack2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_stack1 <= *ft_stack2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*stack1 >= *stack2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_stack1 >= *ft_stack2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON DIFFERENT STACK WITH SAME LENGTHS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(stack1);
    delete(stack2);
    delete(ft_stack1);
    delete(ft_stack2);

    stack1 = new std::stack<int>();
    stack2 = new std::stack<int>();
    ft_stack1 = new ft::stack<int>();
    ft_stack2 = new ft::stack<int>();

    stack1->push(0);
    stack1->push(1);
    stack1->push(2);

    stack2->push(1);
    stack2->push(2);
    stack2->push(3);

    ft_stack1->push(0);
    ft_stack1->push(1);
    ft_stack1->push(2);
    
    ft_stack2->push(1);
    ft_stack2->push(2);
    ft_stack2->push(3);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*stack1 <= *stack2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_stack1 <= *ft_stack2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*stack1 >= *stack2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_stack1 >= *ft_stack2) << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ ON DIFFERENT STACK WITH DIFFERENT LENGTHS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->push(3);
    ft_stack1->push(3);
    
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

    std::cout << "######## <= ########" << std::endl;
    std::cout << "stack    :: <=   :: " << (*stack1 <= *stack2) << std::endl;
    std::cout << "ft_stack :: <=   :: " << (*ft_stack1 <= *ft_stack2) << std::endl;

    std::cout << "######## >= ########" << std::endl;
    std::cout << "stack    :: >=   :: " << (*stack1 >= *stack2) << std::endl;
    std::cout << "ft_stack :: >=   :: " << (*ft_stack1 >= *ft_stack2) << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "        EMPTY       " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON EMPTY STACKS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(stack1);
    delete(stack2);
    delete(ft_stack1);
    delete(ft_stack2);

    stack1 = new std::stack<int>();
    ft_stack1 = new ft::stack<int>();

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "stack    :: empty:: " << stack1->empty() <<  std::endl;
    std::cout << "ft_stack :: empty:: " << ft_stack1->empty() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON NON-EMPTY STACKS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->push(1);
    ft_stack1->push(1);

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "stack    :: empty:: " << stack1->empty() <<  std::endl;
    std::cout << "ft_stack :: empty:: " << ft_stack1->empty() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "        SIZE        " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ SIZE ON EMPTY STACKS +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(stack1);
    delete(ft_stack1);

    stack1 = new std::stack<int>();
    ft_stack1 = new ft::stack<int>();
    
    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() <<  std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON STACKS WITH LEN 1+-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->push(1);
    ft_stack1->push(1);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() <<  std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ EMPTY ON STACKS WITH LEN 5+-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->push(1);
    ft_stack1->push(1);
    stack1->push(1);
    ft_stack1->push(1);
    stack1->push(1);
    ft_stack1->push(1);
    stack1->push(1);
    ft_stack1->push(1);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() <<  std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "    TOP PUSH POP    " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    delete(stack1);
    delete(ft_stack1);

    stack1 = new std::stack<int>();
    ft_stack1 = new ft::stack<int>();

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ PUSH 1 2 3 4 5 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->push(1);
    stack1->push(2);
    stack1->push(3);
    stack1->push(4);
    stack1->push(5);

    ft_stack1->push(1);
    ft_stack1->push(2);
    ft_stack1->push(3);
    ft_stack1->push(4);
    ft_stack1->push(5);

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ TOP SHOULD BE 5 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top()  << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ POP +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    stack1->pop();
    ft_stack1->pop();

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ TOP SHOULD BE 4 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "          =         " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ STACK2 = STACK1 +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::cout << "######## = ########" << std::endl;
    stack2 = stack1;
    ft_stack2 = ft_stack1;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack2->size() << std::endl;

    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;

    std::cout << "######## POP STACK1 ########" << std::endl;
    stack1->pop();
    ft_stack1->pop();

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack2->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack2->size() << std::endl;

    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack2->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack2->top() << std::endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    std::cout << std::endl;
    std::cout << "/-_-_-_-_-_-_-_-_-\\" << std::endl;
    std::cout << "  COPY CONSTRUCTOR  " << std::endl;
    std::cout << "\\-_-_-_-_-_-_-_-_-/" << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ STACK_COPY(STACK1) +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    delete(stack1);
    delete(ft_stack1);

    stack1 = new std::stack<int>();
    ft_stack1 = new ft::stack<int>();

    stack1->push(1);
    stack1->push(2);
    stack1->push(3);
    stack1->push(4);
    stack1->push(5);

    ft_stack1->push(1);
    ft_stack1->push(2);
    ft_stack1->push(3);
    ft_stack1->push(4);
    ft_stack1->push(5);

    std::cout << "######## CONSTRUCTOR BY COPY ########" << std::endl;
    std::stack<int> *stack_copy = new std::stack<int>(*stack1);
    ft::stack<int> *ft_stack_copy = new ft::stack<int>(*ft_stack1);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack_copy->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack_copy->size() << std::endl;
    
    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack_copy->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack_copy->top() << std::endl;

    std::cout << "######## POP ########" << std::endl;
    stack1->pop();
    ft_stack1->pop();

    std::cout << "######## TOP ########" << std::endl;
    std::cout << "stack    :: top  :: " << stack1->top() << " " << stack_copy->top() << std::endl;
    std::cout << "ft_stack :: top  :: " << ft_stack1->top() << " " << ft_stack_copy->top() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "stack    :: size :: " << stack1->size() << " " << stack_copy->size() << std::endl;
    std::cout << "ft_stack :: size :: " << ft_stack1->size() << " " << ft_stack_copy->size() << std::endl;

    delete(stack1);
    delete(stack_copy);
    delete(ft_stack1);
    delete(ft_stack_copy);

    return (0);
}