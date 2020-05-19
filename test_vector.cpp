#include "ft_vector.hpp"
#include <iostream>
#include <vector>

template<class T>
void    print_vector(std::vector<T> &vector)
{
    std::cout << vector.size() << std::endl;
    for (int i = 0; i < (int)vector.size(); ++i)
    {
        std::cout << "vector[" << i << "] = " << vector[i] << std::endl;
    }
}

template<class T>
void    print_myvector(vector<T> &vector)
{
    std::cout << vector.size() << std::endl;
    for (int i = 0; i < (int)vector.size(); ++i)
    {
        std::cout << "myvector[" << i << "] = " << vector[i] << std::endl;
    }
}

int     main()
{
    std::vector<int>    vector1(3, 6);
    std::vector<int>    vector2(vector1);
    std::vector<int>    vector3 = vector2;
    vector<int>         myvector1(3, 6);
    vector<int>         myvector2(myvector1);
    vector<int>         myvector3 = myvector2;
    
    print_vector<int>(vector3);
    print_myvector<int>(myvector3);

    std::cout << " --- Size() --- " << std::endl;
    std::cout << vector3.size() << std::endl;
    std::cout << myvector3.size() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Size_max() --- " << std::endl;
    std::cout << vector3.max_size() << std::endl;
    std::cout << myvector3.max_size() << std::endl;
    std::cout << std::endl;

    std::vector<int>    v1(3, 5);
    vector<int>         m1(3, 5);
    std::vector<int>    v2(3, 5);
    vector<int>         m2(3, 5);
    std::vector<int>    v3(3, 5);
    vector<int>         m3(3, 5);

    std::cout << " --- Resize(2) --- " << std::endl;
    v1.resize(2);
    m1.resize(2);
    print_vector<int>(v1);
    print_myvector<int>(m1);
    std::cout << std::endl;

    std::cout << " --- Resize(6) --- " << std::endl;
    v2.resize(6);
    m2.resize(6);
    print_vector<int>(v2);
    print_myvector<int>(m2);
    std::cout << std::endl;

    std::cout << " --- Resize(6, 8) --- " << std::endl;
    v3.resize(6, 8);
    m3.resize(6, 8);
    print_vector<int>(v3);
    print_myvector<int>(m3);
    std::cout << std::endl;

    std::cout << " --- Capacity (allocation) --- " << std::endl;
    std::cout << v3.capacity() << std::endl;
    std::cout << m3.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Empty (no) --- " << std::endl;
    std::cout << v3.empty() << std::endl;
    std::cout << m3.empty() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Empty (yes) --- " << std::endl;
    v3.resize(0);
    m3.resize(0);
    std::cout << v3.empty() << std::endl;
    std::cout << m3.empty() << std::endl;
    std::cout << std::endl;

    std::cout << " --- Reserve --- " << std::endl;
    std::vector<int>    v4(3, 5);
    vector<int>         m4(3, 5);
    std::cout << v4.capacity() << std::endl;
    std::cout << m4.capacity() << std::endl;
    std::cout << std::endl;
    v4.reserve(1);
    m4.reserve(1);
    std::cout << v4.capacity() << std::endl;
    std::cout << m4.capacity() << std::endl;
    std::cout << std::endl;
    v4.reserve(100);
    m4.reserve(100);
    std::cout << v4.capacity() << std::endl;
    std::cout << m4.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << " --- At --- " << std::endl;
    std::cout << v4.at(0) << std::endl;
    std::cout << m4.at(0) << std::endl;
    try { std::cout << v4.at(10) << std::endl; }
    catch (std::exception &e) { std::cout << "exception : " << e.what() << std::endl; }
    try { std::cout << m4.at(10) << std::endl; }
    catch (std::exception &e) { std::cout << "exception : " << e.what() << std::endl; }
    std::cout << std::endl;

    std::cout << " --- Front --- " << std::endl;
    std::cout << v4.front() << std::endl;
    std::cout << m4.front() << std::endl;
    /* This code SEGFAULT with bith */
    // std::vector<int>    v5;
    // vector<int>    m5;
    // std::cout << v5.front() << std::endl;
    // std::cout << m5.front() << std::endl;
    const std::vector<int>    v5(1, 4);
    const vector<int>    m5(1, 4);
    const int &i = v5.front();
    const int &j = m5.front();
    std::cout << std::endl;
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << std::endl;

    std::cout << " --- Back --- " << std::endl;
    std::cout << v4.back() << std::endl;
    std::cout << m4.back() << std::endl;
    /* This code SEGFAULT with both */
    // std::vector<int>    v5;
    // vector<int>    m5;
    // std::cout << v5.front() << std::endl;
    // std::cout << m5.front() << std::endl;
    const std::vector<int>      v6(1, 4);
    const vector<int>           m6(1, 4);
    const int &i2 = v6.back();
    const int &j2 = m6.back();
    std::cout << std::endl;
    std::cout << i2 << std::endl;
    std::cout << j2 << std::endl;
    std::cout << std::endl;

    std::cout << " --- Push_back --- " << std::endl;
    std::vector<int>    v7(3, 5);
    vector<int>         m7(3, 5);
    v7.reserve(4);
    m7.reserve(4);
    v7.push_back(2);
    m7.push_back(2);
    print_vector<int>(v7);
    print_myvector<int>(m7);
    std::cout << std::endl;

    std::cout << " --- Pop_back --- " << std::endl;
    v7.pop_back();
    m7.pop_back();
    print_vector<int>(v7);
    print_myvector<int>(m7);
    std::cout << std::endl;
    
    std::cout << " --- Clear --- " << std::endl;
    v7.clear();
    m7.clear();
    print_vector<int>(v7);
    print_myvector<int>(m7);
    std::cout << std::endl;

    std::cout << " --- Verif --- " << std::endl;
    std::vector<int>    v8(3);
    vector<int>         m8(3);
    print_vector<int>(v8);
    print_myvector<int>(m8);
    std::cout << std::endl;

    std::cout << " --- Iterators --- " << std::endl;
    std::vector<int>        v9(1, 1);
    vector<int>             m9(1, 1);
    v9.push_back(2);
    v9.push_back(3);
    v9.push_back(4);
    m9.push_back(2);
    m9.push_back(3);
    m9.push_back(4);
    std::vector<int>::iterator   it = v9.begin();
    std::vector<int>::iterator   ite = v9.end();
    vector<int>::iterator   mit = m9.begin();
    vector<int>::iterator   mite = m9.end();
    ++it;
    --it;
    ++mit;
    --mit;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    while (mit != mite)
    {
        std::cout << *mit << std::endl;
        ++mit;
    }
    std::cout << std::endl;

    /* This code SEGFAULT with both */
    // std::cout << " --- Iterators --- " << std::endl;
    // std::vector<int>        v10;
    // vector<int>             m10;
    // std::vector<int>::iterator      it2 = v10.begin();
    // vector<int>::iterator           mit2 = m10.begin();
    // std::cout << *it2 << std::endl;
    // std::cout << *mit2 << std::endl;
    // std::cout << std::endl;

    std::cout << " --- Const Iterators --- " << std::endl;
    const std::vector<int>        v11(2, 5);
    const vector<int>             m11(2, 5);
    std::vector<int>::const_iterator   it3 = v11.begin();
    std::vector<int>::const_iterator   ite3 = v11.end();
    vector<int>::const_iterator   mit3 = m11.begin();
    vector<int>::const_iterator   mite3 = m11.end();
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    std::cout << std::endl;
    while (mit3 != mite3)
    {
        std::cout << *mit3 << std::endl;
        ++mit3;
    }
    std::cout << std::endl;

    std::cout << " --- Reverse Iterators --- " << std::endl;
    std::vector<int>        v12(1, 0);
    vector<int>             m12(1, 0);
    v12.push_back(1);
    m12.push_back(1);
    std::vector<int>::reverse_iterator   it4 = v12.rbegin();
    std::vector<int>::reverse_iterator   ite4 = v12.rend();
    vector<int>::reverse_iterator   mit4 = m12.rbegin();
    vector<int>::reverse_iterator   mite4 = m12.rend();
    while (it4 != ite4)
    {
        std::cout << *it4 << std::endl;
        ++it4;
    }
    std::cout << std::endl;
    while (mit4 != mite4)
    {
        std::cout << *mit4 << std::endl;
        ++mit4;
    }
    std::cout << std::endl;

    std::cout << " --- Const Reverse Iterators --- " << std::endl;
    const std::vector<int>        v13(2, 0);
    const vector<int>             m13(2, 0);
    std::vector<int>::const_reverse_iterator   it5 = v13.rbegin();
    std::vector<int>::const_reverse_iterator   ite5 = v13.rend();
    vector<int>::const_reverse_iterator   mit5 = m13.rbegin();
    vector<int>::const_reverse_iterator   mite5 = m13.rend();
    while (it5 != ite5)
    {
        std::cout << *it5 << std::endl;
        ++it5;
    }
    std::cout << std::endl;
    while (mit5 != mite5)
    {
        std::cout << *mit5 << std::endl;
        ++mit5;
    }
    std::cout << std::endl;

    std::cout << " --- Constructor Range Iterators --- " << std::endl;
    std::vector<int>    v14(4, 4);
    // vector<int>    m14(4, 4);
    std::vector<int>    v15(v14.begin(), v14.end());
    // vector<int>    m15(m14.begin(), m14.end());
    print_vector(v15);
    std::cout << std::endl;
    // print_myvector(m15);
    // std::cout << std::endl;

    std::cout << " --- Iterators ops --- " << std::endl;
    std::vector<int>    v16(4, 4);
    vector<int>         m16(4, 4);
    std::vector<int>::iterator it6(v16.begin());
    std::vector<int>::iterator ite6 = v16.end();
    vector<int>::iterator mit6(m16.begin());
    vector<int>::iterator mite6 = m16.end();

    while (it6 + 2 != ite6)
    {
        std::cout << *it6 << std::endl;
        ++it6;
    }
    std::cout << std::endl;
    while (mit6 + 2 != mite6)
    {
        std::cout << *mit6 << std::endl;
        ++mit6;
    }
    std::cout << std::endl;


    it6 = it6 + 1;
    it6 = it6 - 1;

    std::cout << "--- m16 ---" << std::endl;
    print_myvector(m16);
    std::cout << std::endl;

    // vector<int>::iterator mit7(mit6);

    mit7 = mit6 + 1; // le probleme vient de lássignation

    std::cout << "--- m16 ---" << std::endl;
    print_myvector(m16);
    std::cout << std::endl;

    // mit6 = mit6 - 1;

    std::cout << (it6 == ite6) << std::endl;
    std::cout << (it6 + 2 == ite6) << std::endl;
    std::cout << std::endl;
    std::cout << (mit6 == mite6) << std::endl;
    std::cout << (mit6 + 2 == mite6) << std::endl;
    std::cout << std::endl;

    std::cout << (it6 > ite6) << std::endl;
    std::cout << (it6 + 2 >= ite6) << std::endl;
    std::cout << std::endl;
    std::cout << (mit6 > mite6) << std::endl;
    std::cout << (mit6 + 2 >= mite6) << std::endl;
    std::cout << std::endl;

    std::cout << (it6 < ite6) << std::endl;
    std::cout << (it6 + 2 <= ite6) << std::endl;
    std::cout << std::endl;
    std::cout << (mit6 < mite6) << std::endl;
    std::cout << (mit6 + 2 <= mite6) << std::endl;
    std::cout << std::endl;

    std::cout << "--- m16 ---" << std::endl;
    print_myvector(m16);
    std::cout << std::endl;

    std::cout << it6[0] << std::endl;
    std::cout << std::endl;
    std::cout << mit6[0] << std::endl;
    std::cout << std::endl;

    return 0;
}