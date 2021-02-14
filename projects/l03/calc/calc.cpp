#include "calc.hpp"
#include <cmath>
#include <iostream>

calculator::calculator(const double &_a, const double &_b, const double &_h, const bool &_isInclusive)
{
    this->a = _a;
    this->b = _b;
    this->h = _h;
    this->inc = _isInclusive;
}

calculator::~calculator()
{
}

std::vector<pair<double>> calculator::operator()()
{

    std::vector<pair<double>> res(0);

    if (inc)
    {
        b += h;
        a -= h;
    }

    for (double i = a + h; i < b; i = i + h)
    {

        if (i <= -1)
            res.push_back(mkpair<double>(i, std::pow(2, i - 1)));
        if ((i > -1) && (i <= 4))
            res.push_back(mkpair<double>(i, 2 * i * i - abs(1 - i)));
        if (i > 4)
            res.push_back(mkpair<double>(i, i - 1));
    }

    return res;
}