#include "../ft_map.hpp"
#include <iostream>
#include <string>
#include <map>

int     main_map()
{
    std::cout << "/*****************\\" << std::endl;
    std::cout << "   MAP VS FT_MAP    " << std::endl;
    std::cout << "\\*****************/" << std::endl;

    std::map<char, std::string> *map1 = new std::map<char, std::string>();
    ft::ft_map<char, std::string> *ft_map1 = new ft::ft_map<char, std::string>();
    
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

    std::map<char, std::string> *map3 = new std::map<char, std::string>();
    ft::ft_map<char, std::string> *ft_map3 = new ft::ft_map<char, std::string>();

    map3[0]['e'] = "je suis e";
    ft_map3[0]['e'] = "je suis e";
    map3[0]['d'] = "je suis d";
    ft_map3[0]['d'] = "je suis d";
    map3[0]['z'] = "je suis z";
    ft_map3[0]['z'] = "je suis z";
    map3[0]['a'] = "je suis a";
    ft_map3[0]['a'] = "je suis a";

    std::cout << "######## INSERT K : PAIR ########" << std::endl;
    map3->insert(std::pair<char, std::string>('k', "je suis k"));
    ft_map3->insert(std::pair<char, std::string>('k', "je suis k"));

    std::cout << "######## ITERATOR ########" << std::endl;
    std::map<char, std::string>::iterator begin = map3->begin();
    std::map<char, std::string>::iterator end = map3->end();
    std::map<char, std::string>::value_compare vc = map3->value_comp();
    ft::ft_map<char, std::string>::iterator ft_begin = ft_map3->begin();
    ft::ft_map<char, std::string>::iterator ft_end = ft_map3->end();
    ft::ft_map<char, std::string>::value_compare ft_vc = ft_map3->value_comp();

    while(ft_begin != ft_end || begin != end)
    {
        std::cout 
        << begin->first << " " << begin->second << " : " << vc(*begin, *begin) 
        << " | "
        << ft_begin.first << " " << ft_begin.second << " : " << ft_vc(*ft_begin, *ft_begin) 
        << std::endl;
        ++ft_begin;
        ++begin;
    }

    std::cout << "######## INSERT NEW K : PAIR ########" << std::endl;
    map3->insert(std::pair<char, std::string>('k', "je suis le nouveau k"));
    ft_map3->insert(std::pair<char, std::string>('k', "je suis le nouveau k"));

    std::cout << "######## INSERT P : ITERATOR && PAIR ########" << std::endl;
    map3->insert(begin, std::pair<char, std::string>('p', "je suis p"));
    ft_map3->insert(ft_begin, std::pair<char, std::string>('p', "je suis p"));

    std::cout << "######## REVERSE ITERATOR ########" << std::endl;
    std::map<char, std::string>::iterator rbegin = map3->begin();
    std::map<char, std::string>::iterator rend = map3->end();
    ft::ft_map<char, std::string>::reverse_iterator ft_rbegin = ft_map3->rbegin();
    ft::ft_map<char, std::string>::reverse_iterator ft_rend = ft_map3->rend();

    while(ft_rbegin != ft_rend || rbegin != rend)
    {
        std::cout
        << rbegin->first << " " << rbegin->second
        << " | "
        << ft_rbegin.first << " " << ft_rbegin.second
        << std::endl;
        ++rbegin;
        ++ft_rbegin;
    }

    std::cout << "######## ERASE K : ITERATOR ########" << std::endl;
    map3->erase(map3->find('k'));
    ft_map3->erase(ft_map3->find('k'));

    std::cout << "######## INSERT NEW-P ########" << std::endl;
    map3->insert(begin, std::pair<char, std::string>('p', "je suis le nouveau p"));
    ft_map3->insert(ft_begin, std::pair<char, std::string>('p', "je suis le nouveau p"));

    std::cout << "######## FIND E ########" << std::endl;
    std::map<char, std::string>::iterator find_begin = map3->begin();
    std::map<char, std::string>::iterator find_end = map3->end();
    ft::ft_map<char, std::string>::iterator ft_find_begin = ft_map3->find('e');
    ft::ft_map<char, std::string>::iterator ft_find_end = ft_map3->end();

    while(find_begin != find_end)
    {
        std::cout
        << find_begin->first << " " << find_begin->second
        << std::endl;
        ++find_begin;
    }
    std::cout << "-------------------------" << std::endl;
    while(ft_find_begin != ft_find_end)
    {
        std::cout
        << ft_find_begin.first << " " << ft_find_begin.second
        << std::endl;
        ++ft_find_begin;
    }

    std::cout << "######## ERASE E ########" << std::endl;
    map3->erase('e');
    ft_map3->erase('e');

    std::cout << "######## LOWER_BOUND D ########" << std::endl;
    std::map<char, std::string>::iterator lower_begin = map3->lower_bound('d');
    std::map<char, std::string>::iterator lower_end = map3->end();
    ft::ft_map<char, std::string>::iterator ft_lower_begin = ft_map3->lower_bound('d');
    ft::ft_map<char, std::string>::iterator ft_lower_end = ft_map3->end();

    while(ft_lower_begin != ft_lower_end || lower_begin != lower_end)
    {
        std::cout
        << lower_begin->first << " " << lower_begin->second
        << " | "
        << ft_lower_begin.first << " " << ft_lower_begin.second
        << std::endl;
        ++lower_begin;
        ++ft_lower_begin;
    }

    std::cout << "######## UPPER_BOUND D ########" << std::endl;
    std::map<char, std::string>::iterator upper_begin = map3->upper_bound('d');
    std::map<char, std::string>::iterator upper_end = map3->end();
    ft::ft_map<char, std::string>::iterator ft_upper_begin = ft_map3->upper_bound('d');
    ft::ft_map<char, std::string>::iterator ft_upper_end = ft_map3->end();

    while(ft_upper_begin != ft_upper_end || upper_begin != upper_end)
    {
        std::cout
        << upper_begin->first << " " << upper_begin->second
        << " | "
        << ft_upper_begin.first << " " << ft_upper_begin.second
        << std::endl;
        ++ft_upper_begin;
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

    std::map<char, std::string> *map2 = new std::map<char, std::string>();
    ft::ft_map<char, std::string> *ft_map2 = new ft::ft_map<char, std::string>();

    std::cout << "######## MAP2 = MAP1 ########" << std::endl;
    map2 = map1;
    ft_map2 = ft_map1;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map      :: size :: " << map2->size() << std::endl;
    std::cout << "ft_map   :: size :: " << ft_map2->size() << std::endl;

    std::cout << "######## CLEAR MAP1 ########" << std::endl;
    map1->clear();
    ft_map1->clear();

    std::cout << "######## EMPTY ########" << std::endl;
    std::cout << "map1     :: empty:: " << map1->empty() << std::endl;
    std::cout << "ft_map1  :: empty:: " << ft_map1->empty() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map1     :: size :: " << map1->size() << std::endl;
    std::cout << "ft_map1  :: size :: " << ft_map1->size() << std::endl;

    std::cout << "######## CONSTRUCTOR BY ITERATORS ########" << std::endl;

    std::map<char, std::string> *map4 = new std::map<char, std::string>(map3->begin(), map3->end());
    ft::ft_map<char, std::string> *ft_map4 = new ft::ft_map<char, std::string>(ft_map3->begin(), ft_map3->end());

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map3     :: size :: " << map3->size() << std::endl;
    std::cout << "ft_map3  :: size :: " << ft_map3->size() << std::endl;
    std::cout << "map4     :: size :: " << map4->size() << std::endl;
    std::cout << "ft_map4  :: size :: " << ft_map4->size() << std::endl;

    std::cout << "######## MAX_SIZE ########" << std::endl;
    std::cout << "map4     ::m_size:: " << map4->max_size() << std::endl;
    std::cout << "ft_map4  ::m_size:: " << ft_map4->max_size() << std::endl;

    std::cout << "######## INSERT R ########" << std::endl;
    map4->insert(std::pair<char, std::string>('r', "je suis r"));
    ft_map4->insert(std::pair<char, std::string>('r', "je suis r"));

    std::cout << "######## MAX_SIZE ########" << std::endl;
    std::cout << "map4     ::m_size:: " << map4->max_size() << std::endl;
    std::cout << "ft_map4  ::m_size:: " << ft_map4->max_size() << std::endl;

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map3     :: size :: " << map3->size() << std::endl;
    std::cout << "ft_map3  :: size :: " << ft_map3->size() << std::endl;
    std::cout << "map4     :: size :: " << map4->size() << std::endl;
    std::cout << "ft_map4  :: size :: " << ft_map4->size() << std::endl;

    std::cout << "######## EQUAL_RANGE R ########" << std::endl;
    std::pair<std::map<char, std::string>::iterator, std::map<char, std::string>::iterator> equal_range = map4->equal_range('r');
    std::pair<ft::ft_map<char, std::string>::iterator, ft::ft_map<char, std::string>::iterator> ft_equal_range = ft_map4->equal_range('r');
    std::cout << equal_range.first->first << std::endl;
    std::cout << ft_equal_range.first.first << std::endl;

    
    std::cout << "######## CONSTRUCTOR BY COPY ########" << std::endl;

    std::map<char, std::string> *map5 = new std::map<char, std::string>(*map4);
    ft::ft_map<char, std::string> *ft_map5 = new ft::ft_map<char, std::string>(*ft_map4);

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map4     :: size :: " << map4->size() << std::endl;
    std::cout << "ft_map4  :: size :: " << ft_map4->size() << std::endl;
    std::cout << "map5     :: size :: " << map5->size() << std::endl;
    std::cout << "ft_map5  :: size :: " << ft_map5->size() << std::endl;

    // std::cout << "######## INSERT G ########" << std::endl;
    // map5->insert(std::pair<char, std::string>('g', "je suis g"));
    // ft_map5->insert(std::pair<char, std::string>('g', "je suis g"));

    std::cout << "######## SIZE ########" << std::endl;
    std::cout << "map4     :: size :: " << map4->size() << std::endl;
    std::cout << "ft_map4  :: size :: " << ft_map4->size() << std::endl;
    std::cout << "map5     :: size :: " << map5->size() << std::endl;
    std::cout << "ft_map5  :: size :: " << ft_map5->size() << std::endl;

    delete(ft_map1);
    delete(ft_map3);
    delete(ft_map4);
    delete(map1);
    delete(map3);
    delete(map4);
    return 0;
}