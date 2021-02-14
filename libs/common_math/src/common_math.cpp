#include "common_math.h"

#include<ctime>
#include<cstdlib>

double common::math::generate_random(double min, double max)
{
    std::srand(std::time(NULL));
    double r = (double) std::rand() / RAND_MAX;
    return min + r*(max - min);
}


int common::math::generate_random(int min, int max, bool exclusive)
{
    std::srand(std::time(NULL));
    return min + std::rand() % (max - min + exclusive);    
}

double common::math::compute_sequence_value(double x, double a0, common::math::sequenct_item_t q, int start_pos, int count) {
    if (!q) {
        return NAN;
    }

    double S = 0;

    for (int n = start_pos; n <= count; ++n)
    {
        S += a0;
        a0 *= q(x, n);
    }
    return S;
}