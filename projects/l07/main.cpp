#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <cmath>
#include "array_common.hpp"

typedef std::pair<double, double> paird_t;
typedef std::vector<paird_t> vecd_t;

int main(int argc, char *argv[]){

    std::cout << "Hello world!\n";

    std::vector<std::pair<double, double>> vec;

    double a = -10, b = 10, h = 0.1;

    for (double i = a; i <= b; i += h)
    {      
        double res = 0;
        if (i <= -1)
            res = std::pow(2, 1-i);
        else if ((i > -1)&&(i <= 4))
            res = 2*std::pow(i,2)-std::abs(1-i);
        else
            res = i - 1;
        vec.push_back(std::make_pair(i, res));
    }

    arrays::print(vec);

}