#include <iostream>
#include <vector>

typedef std::vector<int> v_int;
typedef std::vector<double> v_d;
typedef std::vector<float> v_f;
typedef std::vector<long> v_l;

typedef std::vector<std::vector<int>> v2d_int;
typedef std::vector<std::vector<double>> v2d_d;
typedef std::vector<std::vector<float>> v2d_f;
typedef std::vector<std::vector<long>> v2d_l;

template<typename T>
void pirnt(std::vector<T>& v)
{
    for (auto i : v) std::cout << i << std::endl;
}

template<typename T>
void pirnt(std::vector<std::vector<T>>& v)
{
    for (auto i : v)
    {
        for (auto j : i) std::cout << j << std::endl;
    }
}

int main(int argc, char *argv[])
{
    
    

}