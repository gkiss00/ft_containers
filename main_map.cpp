#include "ft_map.hpp"
#include <iostream>
#include <string>
#include <map>

int     main()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << "   MAP VS FT_MAP    " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::map<char, std::string> *map1 = new std::map<char, std::string>();
    std::map<char, std::string> *map2 = new std::map<char, std::string>();
    std::map<char, std::string> *map3 = new std::map<char, std::string>();
    ft_map<char, std::string> *ft_map1 = new ft_map<char, std::string>();
    ft_map<char, std::string> *ft_map2 = new ft_map<char, std::string>();
    ft_map<char, std::string> *ft_map3 = new ft_map<char, std::string>();

    map3[0]['e'] = "je suis e";
    ft_map3[0]['e'] = "je suis e";
    map3[0]['d'] = "je suis d";
    ft_map3[0]['d'] = "je suis d";
    map3[0]['z'] = "je suis z";
    ft_map3[0]['z'] = "je suis z";
    map3[0]['a'] = "je suis a";
    ft_map3[0]['a'] = "je suis a";

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "map      :: empty:: " << map1->empty() << std::endl;
    std::cout << "ft_map   :: empty:: " << ft_map1->empty() << std::endl;

    std::cout << "######## [] ########" << std::endl;
    map1[0]['a'] = "je suis a";
    ft_map1[0]['a'] = "je suis a";
    std::cout << "map      :: [a]  :: " << map1[0]['a'] << std::endl;
    std::cout << "ft_map   :: [a]  :: " << ft_map1[0]['a'] << std::endl;
    std::cout << "map      :: [b]  :: " << map1[0]['b'] << std::endl;
    std::cout << "ft_map   :: [b]  :: " << ft_map1[0]['b'] << std::endl;

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "map      :: empty:: " << map1->empty() << std::endl;
    std::cout << "ft_map   :: empty:: " << ft_map1->empty() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map      :: size :: " << map1->size() << std::endl;
    std::cout << "ft_map   :: size :: " << ft_map1->size() << std::endl;

    std::cout << "######## COUNT ########" << std::endl;
    std::cout << "map      :: count:: " << map1->count('a') << std::endl;
    std::cout << "ft_map   :: count:: " << ft_map1->count('a') << std::endl;
    std::cout << "map      :: count:: " << map1->count('p') << std::endl;
    std::cout << "ft_map   :: count:: " << ft_map1->count('p') << std::endl;

    std::cout << "######## INSERT ########" << std::endl;
    map3->insert(std::pair<char, std::string>('k', "je suis k"));
    ft_map3->insert(std::pair<char, std::string>('k', "je suis k"));

    std::cout << "######## ITERATOR ########" << std::endl;
    std::map<char, std::string>::iterator map_begin = map3->begin();
    ft_map<char, std::string>::iterator begin = ft_map3->begin();
    ft_map<char, std::string>::iterator end = ft_map3->end();

    while(begin != end)
    {
        std::cout << begin.first << " " << begin.second << std::endl;
        ++begin;
    }

    std::cout << "######## INSERT ########" << std::endl;
    map3->insert(std::pair<char, std::string>('k', "je suis le nouveau k"));
    ft_map3->insert(std::pair<char, std::string>('k', "je suis le nouveau k"));

    std::cout << "######## INSERT ########" << std::endl;
    map3->insert(map_begin, std::pair<char, std::string>('p', "je suis p"));
    ft_map3->insert(begin, std::pair<char, std::string>('p', "je suis p"));

    std::cout << "######## R-ITERATOR ########" << std::endl;
    ft_map<char, std::string>::iterator rbegin = ft_map3->rbegin();
    ft_map<char, std::string>::iterator rend = ft_map3->rend();

    while(rend != rbegin)
    {
        std::cout << rend.first << " " << rend.second << std::endl;
        ++rend;
    }

    std::cout << "######## ERASE ########" << std::endl;
    map3->erase(map3->find('k'));
    ft_map3->erase(ft_map3->find('k'));

    std::cout << "######## INSERT ########" << std::endl;
    map3->insert(map_begin, std::pair<char, std::string>('p', "je suis le nouveau p"));
    ft_map3->insert(begin, std::pair<char, std::string>('p', "je suis le nouveau p"));

    std::cout << "######## FIND ########" << std::endl;
    ft_map<char, std::string>::iterator find_begin = ft_map3->find('e');
    ft_map<char, std::string>::iterator find_end = ft_map3->end();

    while(find_begin != find_end)
    {
        std::cout << find_begin.first << " " << find_begin.second << std::endl;
        ++find_begin;
    }

    std::cout << "######## ERASE ########" << std::endl;
    map3->erase('e');
    ft_map3->erase('e');

    std::cout << "######## LOWER_BOUND ########" << std::endl;
    ft_map<char, std::string>::iterator lower_begin = ft_map3->lower_bound('d');
    ft_map<char, std::string>::iterator lower_end = ft_map3->end();

    while(lower_begin != lower_end)
    {
        std::cout << lower_begin.first << " " << lower_begin.second << std::endl;
        ++lower_begin;
    }

    std::cout << "######## UPPER_BOUND ########" << std::endl;
    ft_map<char, std::string>::iterator upper_begin = ft_map3->upper_bound('a');
    ft_map<char, std::string>::iterator upper_end = ft_map3->end();

    while(upper_begin != upper_end)
    {
        std::cout << upper_begin.first << " " << upper_begin.second << std::endl;
        ++upper_begin;
    }

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map1     :: size :: " << map1->size() << std::endl;
    std::cout << "ft_map1  :: size :: " << ft_map1->size() << std::endl;
    std::cout << "map3     :: size :: " << map3->size() << std::endl;
    std::cout << "ft_map3  :: size :: " << ft_map3->size() << std::endl;

    std::cout << "######## SWAP ########" << std::endl;
    map1->swap(map3[0]);
    ft_map1->swap(ft_map3[0]);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map1     :: size :: " << map1->size() << std::endl;
    std::cout << "ft_map1  :: size :: " << ft_map1->size() << std::endl;
    std::cout << "map3     :: size :: " << map3->size() << std::endl;
    std::cout << "ft_map3  :: size :: " << ft_map3->size() << std::endl;

    std::cout << "######## = ########" << std::endl;
    map2 = map1;
    ft_map2 = ft_map1;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map      :: size :: " << map2->size() << std::endl;
    std::cout << "ft_map   :: size :: " << ft_map2->size() << std::endl;

    std::cout << "######## CLEAR ########" << std::endl;
    map1->clear();
    ft_map1->clear();

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "map      :: empty:: " << map1->empty() << std::endl;
    std::cout << "ft_map   :: empty:: " << ft_map1->empty() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map      :: size :: " << map1->size() << std::endl;
    std::cout << "ft_map   :: size :: " << ft_map1->size() << std::endl;

    delete(ft_map1);
    delete(ft_map3);
}