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
    /* This code SEGFAULT with bith */
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

    return 0;
}