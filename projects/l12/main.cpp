#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

#include <array_common.hpp>

template <typename T> // stucture for math 2d vector
struct vec
{
public:
    T x, y;

    vec<int> &operator^=(vec<int> &y)
    {
        this->x ^= y.x;
        this->y ^= y.y;

        return *this;
    }
};

template <typename T>
vec<T> init_vec(T &x, T &y) // struct vec initializer
{
    vec<T> res;
    res.x = x;
    res.y = y;

    return res;
}

template <typename T>
vec<T> init_vec(T x, T y) // struct vec initializer
{
    vec<T> res;
    res.x = x;
    res.y = y;

    return res;
}

template <typename T>
void swap(T &e1, T &e2) // xor swap
{
    e1 ^= e2;
    e2 ^= e1;
    e1 ^= e2;
}

template <typename T>
void sort_rule(std::vector<T> &v, bool (*func)(T &e1, T &e2)) // sorting function requires vector and function that returns bool type as parameters
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!func(v[i], v[j]) and !(i == j))
                swap((v[i]), (v[j]));
        }
    }
}

template <typename T>
void sort_rule(std::vector<T> &v, std::function<bool(T &e1, T &e2)> func) // sorting function requires vector and lambda function that returns bool type as parameters
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!func(v[i], v[j]) and !(i == j))
                swap((v[i]), (v[j]));
        }
    }
}

bool foo1(int &a, int &b) // for std::vector<int>
{
    if (a < b)
        return true;
    return false;
}

bool foo2(vec<int> &a, vec<int> &b) // std::vector<vec<int>>
{
    if (sqrt(a.x * a.x + a.y * a.y) < sqrt(b.x * b.x + b.y * b.y))
        return true;
    return false;
}

int main(int argc, char *argv[])
{

    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Origin: " << arrays::to_str(v) << std::endl;
    sort_rule<int>(v, &foo1);
    std::cout << "Sorted: " << arrays::to_str(v) << std::endl;

    std::vector<vec<int>> v2;
    for (int i = 0; i < 8; i++) // filling array
    {
        v2.push_back(init_vec<int>(int(i + 2), int((i + 3) * 2)));
    }

    std::cout << std::endl;

    std::cout << "Origin: " << std::endl;
    for (auto i : v2)
    {
        std::cout << i.x << " : " << i.y << std::endl;
    }

    sort_rule<vec<int>>(v2, [&](vec<int> a, vec<int> b) -> bool { // lambda function perfoms as well as foo2
        if (sqrt(a.x*a.x + a.y*a.y) < sqrt(b.x*b.x + b.y*b.y)) return true;
        return false;
    });

    std::cout << "Sorted: " << std::endl;
    for (auto i : v2)
    {
        std::cout << i.x << " : " << i.y << std::endl;
    }
}