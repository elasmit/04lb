#include "array_common.hpp"
#include <cmath>

template<class T>
void arrays::print(const T& in, int size)
    {
        for (int i = 0; i < size; i++)
            std::cout << in[i] << std::endl;
    }

template<class T>
    void arrays::print(const std::vector<T>& in)
    {
        for (int i = 0; i < in.size(); i++)
            std::cout << in[i] << std::endl;
    }

template<class T1, class T2>
    void arrays::print(const std::vector<std::pair<T1, T2>>& in)
    {
        for (int i = 0; i < in.size(); i++)
            std::cout << ceil(in[i].first*100)/100 << "\t";
        std::cout << std::endl;

        for (int i = 0; i < in.size(); i++)
            std::cout << ceil(in[i].second*100)/100 << "\t";
        std::cout << std::endl;
    }

void arrays::print(const std::vector<std::pair<double, double>>& in)
{
    for (int i = 0; i < in.size(); i++)
        std::cout << ceil(in[i].first*100)/100 << "\t";
    std::cout << std::endl;

    for (int i = 0; i < in.size(); i++)
        std::cout << ceil(in[i].second*100)/100 << "\t";
    std::cout << std::endl;
}