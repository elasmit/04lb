#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <sstream>
#include "logger/logger.hpp"

logger lgg;

double calc(const double& a, const double& b)
{   
    double res = a*b;
    
    std::stringstream lgstr;
    lgstr << "Multyplying a(" << a << ") and b(" << b << ") with result => " << res << "\n";
    lgg.log(lgstr.str().c_str());
    return res;

}

int main(int argc, char *argv[])
{
    double arr[10];
    for (int i = 0; i<10; i++) arr[i] = calc(i+3, i+5);
    
    for (int i = 0; i<10; i++) std::cout << arr[i] << "\n";

}

