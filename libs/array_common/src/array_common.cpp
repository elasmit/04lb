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

template <class T>
    T arrays::sum(const std::vector<T>& in)
    {
        T sum = 0;
        for (int i = 0; i < in.size(); i++)
            sum += in[i];

        return sum;
    }

    int arrays::sum(const std::vector<int>& in)
    {
        int sum = 0;
        for (int i = 0; i < in.size(); i++)
            sum += in[i];

        return sum;
    }

    double arrays::sum(const std::vector<double>& in)
    {
        double sum = 0;
        for (int i = 0; i < in.size(); i++)
            sum += in[i];

        return sum;
    }

    float arrays::sum(const std::vector<float>& in)
    {
        float sum = 0;
        for (float i = 0; i < in.size(); i++)
            sum += in[i];

        return sum;
    }

    