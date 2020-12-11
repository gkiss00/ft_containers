#include "ft_list.hpp"
#include <list>

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

struct is_odd2 {
  bool operator() (const int& value, const int& value2) { (void)value2; return (value%2)==1; }
};

template < class T >
void print_list(std::list<T> l)
{
    typename std::list<T>::iterator  it = l.begin();
    typename std::list<T>::iterator  ite = l.end();

    while (it != ite)
    {
        std::cout << "list = " << *it << std::endl;
        ++it;
    }
}

template < class T >
void print_mylist(ft::list<T> l)
{
    typename ft::list<T>::iterator  it(l.begin());
    typename ft::list<T>::iterator  ite(l.end());

    while (it != ite)
    {
        std::cout << "mylist = " << *it << std::endl;
        ++it;
    }
}

int main()
{
    std::list<int>      l1(3, 4);
    std::list<int>      l2(l1);
    std::list<int>      l3 = l2;
    ft::list<int>       ml1(3, 4);
    ft::list<int>       ml2(ml1);
    ft::list<int>       ml3 = ml2;

    print_list(l3);
    print_mylist(ml3);
    std::cout << std::endl;

    std::cout << " --- Size ---" << std::endl;
    std::cout << l3.size() << std::endl;
    std::cout << ml3.size() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Max size ---" << std::endl;
    std::cout << l3.max_size() << std::endl;
    std::cout << ml3.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Empty ---" << std::endl;
    std::cout << l3.empty() << std::endl;
    std::cout << ml3.empty() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Reverse it ---" << std::endl;
    l3.push_back(1);
    ml3.push_back(1);
    std::list<int> ::reverse_iterator     it(l3.rbegin());
    std::list<int> ::reverse_iterator     ite(l3.rend());
    ft::list<int> ::reverse_iterator     mit(ml3.rbegin());
    ft::list<int> ::reverse_iterator     mite(ml3.rend());

    while (it != ite)
    {
        std::cout << "= " << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    while (mit != mite)
    {
        std::cout << "= " << *mit << std::endl;
        ++mit;
    }
    std::cout << std::endl;

    std::cout << " --- Const Reverse it ---" << std::endl;
    const std::list<int>        l4(3, 4);
    const ft::list<int>         ml4(3, 4);
    std::list<int> ::const_reverse_iterator     it2(l4.rbegin());
    std::list<int> ::const_reverse_iterator     ite2(l4.rend());
    ft::list<int> ::const_reverse_iterator     mit2(ml4.rbegin());
    ft::list<int> ::const_reverse_iterator     mite2(ml4.rend());

    while (it2 != ite2)
    {
        std::cout << "= " << *it2 << std::endl;
        ++it2;
    }
    std::cout << std::endl;
    while (mit2 != mite2)
    {
        std::cout << "= " << *mit2 << std::endl;
        ++mit2;
    }
    std::cout << std::endl;

    std::cout << " --- It Constructor ---" << std::endl;
    std::list<int>  l5(l3.begin(), l3.end());
    ft::list<int>  ml5(ml3.begin(), ml3.end());
    print_list(l5);
    print_mylist(ml5);
    std::cout << std::endl;

    std::cout << " --- Front back ---" << std::endl;
    std::list<int>  l6(0);
    ft::list<int>  ml6(0);

    std::cout << l6.front() << std::endl;
    std::cout << ml6.front() << std::endl;
    std::cout << std::endl;
    std::cout << l6.back() << std::endl;
    std::cout << ml6.back() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Assign ---" << std::endl;
    std::list<int>  l7(0);
    ft::list<int>  ml7(0);

    l7.assign(2, 3);
    print_list(l7);
    ml7.assign(2, 3);
    print_mylist(ml7);
    l7.assign(l3.begin(), l3.end());
    print_list(l7);
    ml7.assign(ml3.begin(), ml3.end());
    print_mylist(ml7);
    std::cout << std::endl;

    std::cout << " --- Push pop ---" << std::endl;
    std::list<int>  l8(1, 1);
    ft::list<int>  ml8(1, 1);

    l8.push_front(9);
    print_list(l8);
    ml8.push_front(9);
    print_mylist(ml8);

    l8.pop_front();
    print_list(l8);
    ml8.pop_front();
    print_mylist(ml8);
    std::cout << std::endl;

    l8.push_back(9);
    print_list(l8);
    ml8.push_back(9);
    print_mylist(ml8);

    l8.pop_back();
    print_list(l8);
    ml8.pop_back();
    print_mylist(ml8);
    std::cout << std::endl;

    std::cout << " --- Insert ---" << std::endl;
    std::list<int>  l9(3, 3);
    ft::list<int>  ml9(3, 3);
    std::list<int>::iterator    it9(l9.begin());
    ft::list<int>::iterator     mit9(ml9.begin());
    it9 = l9.insert(it9++, 4);
    print_list(l9);
    std::cout << *it9 << std::endl;
    mit9 = ml9.insert(mit9++, 4);
    print_mylist(ml9);
    std::cout << *mit9 << std::endl;
    std::cout << std::endl;

    std::cout << " --- Insert ---" << std::endl;
    std::list<int>  l10(2, 2);
    ft::list<int>  ml10(2, 2);
    std::list<int>::iterator    it10(l10.begin());
    ft::list<int>::iterator     mit10(ml10.begin());

    std::list<int>::iterator    start(l9.begin());
    ft::list<int>::iterator     mstart(ml9.begin());
    std::list<int>::iterator    end(l9.end());
    ft::list<int>::iterator     mend(ml9.end());
    l10.insert(++it10, start, end);
    print_list(l10);
    ml10.insert(++mit10, mstart, mend);
    print_mylist(ml10);
    std::cout << std::endl;

    std::cout << " --- Erase ---" << std::endl;
    std::list<int>::iterator    it11(l10.begin());
    ft::list<int>::iterator     mit11(ml10.begin());
    l10.erase(it11);
    print_list(l10);
    ml10.erase(mit11);
    print_mylist(ml10);
    std::cout << std::endl;

    std::cout << " --- Erase it ---" << std::endl;
    std::list<int>  l12(2, 2);
    ft::list<int>  ml12(2, 2);
    std::list<int>::iterator    it12(l12.begin());
    ft::list<int>::iterator     mit12(ml12.begin());
    std::list<int>::iterator    ite12(l12.end());
    ft::list<int>::iterator     mite12(ml12.end());
    l12.erase(++it12, --ite12);
    print_list(l12);
    ml12.erase(++mit12, --mite12);
    print_mylist(ml12);
    std::cout << std::endl;

    std::cout << " --- Erase it ---" << std::endl;
    std::list<int>  l13(3, 1);
    ft::list<int>  ml13(3, 1);
    l12.swap(l13);
    print_list(l12);
    print_list(l13);
    ml12.swap(ml13);
    print_mylist(ml12);
    print_mylist(ml13);
    std::cout << std::endl;

    std::cout << " --- Clear ---" << std::endl;
    l13.clear();
    print_list(l13);
    ml13.clear();
    print_mylist(ml13);
    std::cout << std::endl;

    std::cout << " --- Resize ---" << std::endl;
    l12.resize(5);
    print_list(l12);
    ml12.resize(5);
    print_mylist(ml12);
    std::cout << std::endl;

    std::cout << " --- Resize ---" << std::endl;
    l12.resize(1);
    print_list(l12);
    ml12.resize(1);
    print_mylist(ml12);
    std::cout << std::endl;

    std::cout << " --- Slice All ---" << std::endl;
    std::list<int>  l14(3, 1);
    ft::list<int>  ml14(3, 1);
    std::list<int>  l15(3, 2);
    ft::list<int>  ml15(3, 2);
    l14.splice(l14.begin(), l15);
    print_list(l14);
    ml14.splice(ml14.begin(), ml15);
    print_mylist(ml14);
    print_list(l15);
    print_mylist(ml15);
    std::cout << std::endl;


    std::cout << " --- Slice 1 ---" << std::endl;
    std::list<int>  l16(3, 1);
    ft::list<int>  ml16(3, 1);
    std::list<int>  l17(3, 2);
    ft::list<int>  ml17(3, 2);
    l16.splice(l16.begin(), l17, l17.begin());
    print_list(l16);
    ml16.splice(ml16.begin(), ml17, ml17.begin());
    print_mylist(ml16);
    print_list(l17);
    print_mylist(ml17);
    std::cout << std::endl;

    std::cout << " --- Slice it ---" << std::endl;
    std::list<int>  l18(3, 1);
    ft::list<int>  ml18(3, 1);
    std::list<int>  l19(3, 2);
    ft::list<int>  ml19(3, 2);
    l18.splice(l18.begin(), l19, l19.begin(), l19.end());
    print_list(l18);
    ml18.splice(ml18.begin(), ml19, ml19.begin(), ml19.end());
    print_mylist(ml18);
    print_list(l19);
    print_mylist(ml19);
    std::cout << std::endl;

    std::cout << " --- Remove ---" << std::endl;
    std::list<int>  l20(3, 1);
    ft::list<int>  ml20(3, 1);
    
    l20.push_back(10);
    ml20.push_back(10);
    l20.remove(1);
    print_list(l20);
    ml20.remove(1);
    print_mylist(ml20);
    std::cout << std::endl;

    std::cout << " --- Remove if ---" << std::endl;
    std::list<int>  l21(3, 1);
    ft::list<int>  ml21(3, 1);
    
    l21.push_back(10);
    ml21.push_back(10);
    l21.remove_if (is_odd());  
    print_list(l21);
    ml21.remove_if (is_odd());  
    print_mylist(ml21);
    std::cout << std::endl;

    std::cout << " --- Unique ---" << std::endl;
    std::list<int>  l22(3, 1);
    ft::list<int>  ml22(3, 1);
    l22.unique();  
    print_list(l22);
    ml22.unique();  
    print_mylist(ml22);
    std::cout << std::endl;

    std::cout << " --- Unique if ---" << std::endl;
    std::list<int>  l23(3, 2);
    ft::list<int>  ml23(3, 2);
    l23.unique(is_odd2());  
    print_list(l23);
    ml23.unique(is_odd2());  
    print_mylist(ml23);
    std::cout << std::endl;


    std::cout << " --- Merge ---" << std::endl;
    std::list<int>  l24(3, 8);
    ft::list<int>  ml24(3, 8);
    std::list<int>  l25(3, 4);
    ft::list<int>  ml25(3, 4);

    l24.merge(l25);  
    print_list(l24);
    print_list(l25);
    ml24.merge(ml25);  
    print_mylist(ml24);
    print_mylist(ml25);
    std::cout << std::endl;

    std::cout << " --- Merge if ---" << std::endl;
    std::list<int>  l26(3, 8);
    ft::list<int>  ml26(3, 8);
    std::list<int>  l27(3, 4);
    ft::list<int>  ml27(3, 4);

    l26.merge(l27, is_odd2());  
    print_list(l26);
    print_list(l27);
    ml26.merge(ml27, is_odd2());  
    print_mylist(ml26);
    print_mylist(ml27);
    std::cout << std::endl;

    std::cout << " --- Sort ---" << std::endl;
    std::list<int>  l28(1, 3);
    ft::list<int>  ml28(1, 3);
    l28.push_back(7);
    l28.push_back(2);
    l28.push_back(5);
    l28.push_back(8);
    ml28.push_back(7);
    ml28.push_back(2);
    ml28.push_back(5);
    ml28.push_back(8);

    l28.sort();
    ml28.sort();
    print_list(l28);
    print_mylist(ml28);
    std::cout << std::endl;

    std::cout << " --- Sort ---" << std::endl;
    l28.reverse();
    ml28.reverse();
    print_list(l28);
    print_mylist(ml28);
    std::cout << std::endl;

    std::cout << " --- Op ---" << std::endl;
    std::cout << (l12 == l13) << std::endl;
    std::cout << (ml12 == ml13) << std::endl;
    std::cout << (l12 != l13) << std::endl;
    std::cout << (ml12 != ml13) << std::endl;
    std::cout << (l12 < l13) << std::endl;
    std::cout << (ml12 < ml13) << std::endl;
    std::cout << (l12 <= l13) << std::endl;
    std::cout << (ml12 <= ml13) << std::endl;
    std::cout << (l12 > l13) << std::endl;
    std::cout << (ml12 > ml13) << std::endl;
    std::cout << (l12 >= l13) << std::endl;
    std::cout << (ml12 >= ml13) << std::endl;
    std::cout << std::endl;

    std::cout << " --- Swap ---" << std::endl;
    swap(l23, l24);
    swap(ml23, ml24);
    print_list(l23);
    print_mylist(ml23);
    print_list(l24);
    print_mylist(ml24);
    std::cout << std::endl;

    return 0;
}