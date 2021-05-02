#include <iostream>
#include <vector>
#include <utility>

#ifndef ARRAY_COMMON_U
#define ARRAY_COMMON_U

namespace arrays
{   
template<class T>
    void print(const T& in, int size)
    {
        for (int i = 0; i < size; i++)
            std::cout << in[i] << std::endl;
    }

template<class T>
    void print(const std::vector<T>& in)
    {
        for (int i = 0; i < in.size(); i++)
            std::cout << in[i] << std::endl;
    }

template<typename T1, typename T2>
    void print(const std::vector<std::pair<T1, T2>>& in)
    {
        for (int i = 0; i < in.size(); i++)
            std::cout << ceil(in[i].first*100)/100 << "\t";
        std::cout << std::endl;

        for (int i = 0; i < in.size(); i++)
            std::cout << ceil(in[i].second*100)/100 << "\t";
        std::cout << std::endl;
    }

template <class T>
    T sum(const std::vector<T>& in)
    {
        T sum = 0;
        for (int i = 0; i < in.size(); i++)
            sum += in[i];

        return sum;
    }
}

#endif