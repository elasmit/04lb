#ifndef CLASS_CALC
#define CLASS_CALC

#include <vector>

template <class _T>
struct pair
{
    _T a;
    _T b;
};

template <class _T>
pair<_T> mkpair(_T a, _T b)
{

    pair<_T> tmp;
    tmp.a = a;
    tmp.b = b;

    return tmp;
}

class calculator
{
private:
    double a, b, h;
    bool inc;

public:
    calculator(const double &, const double &, const double &, const bool &);
    std::vector<pair<double>> operator()();
    ~calculator();
};

#endif