#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::stack<int> *stack1 = new std::stack<int>();
    std::stack<int> *stack2 = new std::stack<int>();

    std::cout << "stack    :: ==    :: " << (*stack1 == *stack2) << std::endl;
    std::cout << "stack    :: !=    :: " << (*stack1 != *stack2) << std::endl;
    std::cout << "stack    :: <    :: " << (*stack1 < *stack2) << std::endl;
    std::cout << "stack    :: >    :: " << (*stack1 > *stack2) << std::endl;
    std::cout << std::endl;
    
    stack1->push(1);
    stack1->push(2);
    stack1->push(3);

    stack2->push(1);
    stack2->push(2);
    stack2->push(3);


    std::cout << "stack    :: ==    :: " << (*stack1 == *stack2) << std::endl;
    std::cout << "stack    :: !=    :: " << (*stack1 != *stack2) << std::endl;
    std::cout << "stack    :: <    :: " << (*stack1 < *stack2) << std::endl;
    std::cout << "stack    :: >    :: " << (*stack1 > *stack2) << std::endl;
    std::cout << std::endl;

    stack1->push(4);

    std::cout << "stack    :: ==    :: " << (*stack1 == *stack2) << std::endl;
    std::cout << "stack    :: !=    :: " << (*stack1 != *stack2) << std::endl;
    std::cout << "stack    :: <    :: " << (*stack1 < *stack2) << std::endl;
    std::cout << "stack    :: >    :: " << (*stack1 > *stack2) << std::endl;
    std::cout << std::endl;

    stack2->push(4);
    stack2->push(5);

    std::cout << "stack    :: ==    :: " << (*stack1 == *stack2) << std::endl;
    std::cout << "stack    :: !=    :: " << (*stack1 != *stack2) << std::endl;
    std::cout << "stack    :: <    :: " << (*stack1 < *stack2) << std::endl;
    std::cout << "stack    :: >    :: " << (*stack1 > *stack2) << std::endl;
    return (0);
}