#include <iostream>
#include <cmath>
#include <cstring>
#include "calc/calc.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;

    double a = -10.1f, b = 10.0f, h = 0.1f;
    bool isc = false;

    if (argc < 3)
    {
        std::cout << "Too few arguments. You should specify at least 4 arguments: initial value, end value, step and . Values will be set by default.";
        std::getchar();
    }
    else
    {
        // convertion from string to double
        a = std::atof(argv[1]);
        b = std::atof(argv[2]); 
        h = std::atof(argv[3]);

        if (strcmp(argv[4], "true"))
            isc = true;
    }

    calculator calc(a, b, h, isc);

    auto res = calc(); // using operator()() override

    std::cout << "X:"
              << "\t:\t"
              << "Y:" << std::endl;

    for (int i = 0; i < res.size(); i++)
        std::cout << std::ceil(res[i].a * 10) / 10 << "\t:\t" << std::ceil(res[i].b * 10000) / 10000 << std::endl;

    std::getchar();
}