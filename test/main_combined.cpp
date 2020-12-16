#include "./../queue.hpp"
#include "./../stack.hpp"
#include "./../vector.hpp"
#include "./../list.hpp"
#include <stack>
#include <queue>
#include <vector>
#include <list>

int     main_combined(){

    std::cout << "/*****************\\" << std::endl;
    std::cout << "   QUEUE AND STACK  " << std::endl;
    std::cout << "\\*****************/" << std::endl;
    std::cout << std::endl;

    std::stack<int> *std_stack1 = new std::stack<int>();
    std::queue<int> *std_queue1 = new std::queue<int>();

    std::vector<int> *std_vector1 = new std::vector<int>();
    std::list<int> *std_list1 = new std::list<int>();

    ft::stack<int> *ft_stack1 = new ft::stack<int>();
    ft::queue<int> *ft_queue1 = new ft::queue<int>();

    ft::vector<int> *ft_vector1 = new ft::vector<int>();
    ft::list<int> *ft_list1 = new ft::list<int>();

    for(int i = 0; i < 10; ++i){
        std_stack1->push(i);
        std_queue1->push(i);
        std_vector1->push_back(i);
        std_list1->push_back(i);

        ft_stack1->push(i);
        ft_queue1->push(i);
        ft_vector1->push_back(i);
        ft_list1->push_back(i);
    }

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ WITH VECTOR +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::stack<int, std::vector<int> > *std_stack2 = new std::stack<int, std::vector<int> >(*std_vector1);
    std::queue<int, std::vector<int> > *std_queue2 = new std::queue<int, std::vector<int> >(*std_vector1);

    std::cout << std_stack2->size() << std::endl;
    std::cout << std_queue2->size() << std::endl;

    ft::stack<int, ft::vector<int> > *ft_stack2 = new ft::stack<int, ft::vector<int> >(*ft_vector1);
    ft::queue<int, ft::vector<int> > *ft_queue2 = new ft::queue<int, ft::vector<int> >(*ft_vector1);

    std::cout << ft_stack2->size() << std::endl;
    std::cout << ft_queue2->size() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ WITH LIST +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::stack<int, std::list<int> > *std_stack3 = new std::stack<int, std::list<int> >(*std_list1);
    std::queue<int, std::list<int> > *std_queue3 = new std::queue<int, std::list<int> >(*std_list1);

    std::cout << std_stack3->size() << std::endl;
    std::cout << std_queue3->size() << std::endl;

    ft::stack<int, ft::list<int> > *ft_stack3 = new ft::stack<int, ft::list<int> >(*ft_list1);
    ft::queue<int, ft::list<int> > *ft_queue3 = new ft::queue<int, ft::list<int> >(*ft_list1);

    std::cout << ft_stack3->size() << std::endl;
    std::cout << ft_queue3->size() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ WITH STACK +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::stack<int, std::stack<int> > *std_stack4 = new std::stack<int, std::stack<int> >(*std_stack1);
    std::queue<int, std::stack<int> > *std_queue4 = new std::queue<int, std::stack<int> >(*std_stack1);

    std::cout << std_stack4->size() << std::endl;
    std::cout << std_queue4->size() << std::endl;

    ft::stack<int, ft::stack<int> > *ft_stack4 = new ft::stack<int, ft::stack<int> >(*ft_stack1);
    ft::queue<int, ft::stack<int> > *ft_queue4 = new ft::queue<int, ft::stack<int> >(*ft_stack1);

    std::cout << ft_stack4->size() << std::endl;
    std::cout << ft_queue4->size() << std::endl;

    std::cout << std::endl;
    std::cout << "+-+-+-+-+ WITH QUEUE +-+-+-+-+" << std::endl;
    std::cout << std::endl;

    std::stack<int, std::queue<int> > *std_stack5 = new std::stack<int, std::queue<int> >(*std_queue1);
    std::queue<int, std::queue<int> > *std_queue5 = new std::queue<int, std::queue<int> >(*std_queue1);

    std::cout << std_stack4->size() << std::endl;
    std::cout << std_queue4->size() << std::endl;

    ft::stack<int, ft::queue<int> > *ft_stack5 = new ft::stack<int, ft::queue<int> >(*ft_queue1);
    ft::queue<int, ft::queue<int> > *ft_queue5 = new ft::queue<int, ft::queue<int> >(*ft_queue1);

    std::cout << ft_stack4->size() << std::endl;
    std::cout << ft_queue4->size() << std::endl;

    
    delete(std_vector1);
    delete(std_list1);

    delete(std_stack1);
    delete(std_stack2);
    delete(std_stack3);
    delete(std_stack4);
    delete(std_stack5);

    delete(std_queue1);
    delete(std_queue2);
    delete(std_queue3);
    delete(std_queue4);
    delete(std_queue5);
    

    delete(ft_vector1);
    delete(ft_list1);

    delete(ft_stack1);
    delete(ft_stack2);
    delete(ft_stack3);
    delete(ft_stack4);
    delete(ft_stack5);

    delete(ft_queue1);
    delete(ft_queue2);
    delete(ft_queue3);
    delete(ft_queue4);
    delete(ft_queue5);
    return (0);
}