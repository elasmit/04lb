#include <iostream>
#include <vector>
#include <utility>

#ifndef ARRAY_COMMON_U
#define ARRAY_COMMON_U

namespace arrays
{   
    template<class T>
    void print(const T& in, int size);

    template<class T>
    void print(const std::vector<T>& in);
    
    template<class T1, class T2>
    void print(const std::vector<std::pair<T1, T2>>& in);

    void print(const std::vector<std::pair<double, double>>& in);
}

#endif