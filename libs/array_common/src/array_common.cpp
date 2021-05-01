#include "array_common.hpp"
#include <cmath>

void arrays::print(const std::vector<std::pair<double, double>>& in)
{
    for (int i = 0; i < in.size(); i++)
        std::cout << ceil(in[i].first*100)/100 << "\t";
    std::cout << std::endl;

    for (int i = 0; i < in.size(); i++)
        std::cout << ceil(in[i].second*100)/100 << "\t";
    std::cout << std::endl;
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


    for (int i = 0; i < in.size(); i++)
        std::cout << ceil(in[i].second*100)/100 << "\t";
    std::cout << std::endl;
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

    