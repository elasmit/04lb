#include <iostream>
#include <vector>
#include "array_common.hpp"
#include <time.h>
#include <stdlib.h>
#include <chrono>

int main(int argc, char *argv[]){

    std::vector<std::vector<long double>> vec;

    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
    {   
        vec.push_back(std::vector<long double>(1000));
        for (int j = 0; j < 1000; j++) vec[i].push_back((long double)(rand())/1000);
    }

    auto start = std::chrono::steady_clock::now();
    auto res = arrays::sum(vec);
    auto end = std::chrono::steady_clock::now();

    std::cout << res << std::endl;
    std::cout << "Elapsed time in milliseconds: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
        << " ms" << std::endl;
}