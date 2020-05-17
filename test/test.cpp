#include <iostream>
#include <string>
#include <queue>
#include <queue>

int main()
{
    std::queue<int> *queue1 = new std::queue<int>();
    std::queue<int> *queue2 = new std::queue<int>();

    std::cout << "queue    :: ==    :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "queue    :: !=    :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "queue    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "queue    :: >    :: " << (*queue1 > *queue2) << std::endl;
    std::cout << std::endl;
    
    queue1->push(0);
    queue1->push(2);
    queue1->push(5);

    queue2->push(1);
    queue2->push(2);
    queue2->push(3);


    std::cout << "queue    :: ==    :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "queue    :: !=    :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "queue    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "queue    :: >    :: " << (*queue1 > *queue2) << std::endl;
    std::cout << std::endl;

    queue1->push(4);

    std::cout << "queue    :: ==    :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "queue    :: !=    :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "queue    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "queue    :: >    :: " << (*queue1 > *queue2) << std::endl;
    std::cout << std::endl;

    queue2->push(4);
    queue2->push(5);

    std::cout << "queue    :: ==    :: " << (*queue1 == *queue2) << std::endl;
    std::cout << "queue    :: !=    :: " << (*queue1 != *queue2) << std::endl;
    std::cout << "queue    :: <    :: " << (*queue1 < *queue2) << std::endl;
    std::cout << "queue    :: >    :: " << (*queue1 > *queue2) << std::endl;
    return (0);
}