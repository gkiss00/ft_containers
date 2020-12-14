#include "./../queue.hpp"
#include "./../stack.hpp"
#include "./../vector.hpp"
#include <stack>
#include <queue>
#include <vector>

int     main_combined(){

    std::cout << "/*****************\\" << std::endl;
    std::cout << "   QUEUE AND STACK  " << std::endl;
    std::cout << "\\*****************/" << std::endl;
    std::cout << std::endl;

    std::stack<int> *std_stack1 = new std::stack<int>();
    std::queue<int> *std_queue1 = new std::queue<int>();
    std::vector<int> *std_vector1 = new std::vector<int>();

    ft::stack<int> *ft_stack1 = new ft::stack<int>();
    ft::queue<int> *ft_queue1 = new ft::queue<int>();
    ft::vector<int> *ft_vector1 = new ft::vector<int>();

    for(int i = 0; i < 10; ++i){
        std_stack1->push(i);
        std_queue1->push(i);
        std_vector1->push_back(i);
    }

    std::stack<int, std::vector<int> > *std_stack2 = new std::stack<int, std::vector<int> >(*std_vector1);
    std::queue<int, std::vector<int> > *std_queue2 = new std::queue<int, std::vector<int> >(*std_vector1);

    std::cout << std_stack2->size() << std::endl;
    std::cout << std_queue2->size() << std::endl;

    ft::stack<int, ft::vector<int> > *ft_stack2 = new ft::stack<int, ft::vector<int> >(*ft_vector1);
    ft::queue<int, ft::vector<int> > *ft_queue2 = new ft::queue<int, ft::vector<int> >(*ft_vector1);

    std::cout << ft_stack2->size() << std::endl;
    std::cout << ft_queue2->size() << std::endl;

    delete(std_stack1);
    delete(std_queue1);
    delete(std_vector1);
    delete(std_stack2);
    delete(std_queue1);
    delete(ft_stack1);
    delete(ft_queue1);
    delete(ft_vector1);
    delete(ft_stack2);
    delete(ft_queue1);
    return (0);
}