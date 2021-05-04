#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> v_int;
typedef std::vector<double> v_d;
typedef std::vector<float> v_f;
typedef std::vector<long> v_l;

typedef std::vector<std::vector<int>> v2d_int;
typedef std::vector<std::vector<double>> v2d_d;
typedef std::vector<std::vector<float>> v2d_f;
typedef std::vector<std::vector<long>> v2d_l;

template <typename T>
void print(const std::vector<T> &v)
{
    std::string result = "[";
    for (auto i : v)
    {
        result += std::to_string(i) + ", ";
    }
    result.erase(result.size() - 2, 2);
    result.append("]");

    std::cout << result << std::endl;
}

template <typename T>
void print(const std::vector<std::vector<T>> &v)
{
    std::string result = "[";
    for (auto i : v)
    {
        result += "[";
        for (auto j : i)
        {
            result += std::to_string(j) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]\n");
    }
    result.erase(result.end());
    result.append("]");

    std::cout << result << std::endl;
}

template <typename T>
std::string to_str(const std::vector<T> &v)
{
    std::string result = "[";
    for (auto i : v)
    {
        result += std::to_string(i) + ", ";
    }
    result.erase(result.size() - 2, 2);
    result.append("]");

    return result;
}

template <typename T>
std::string to_str(const std::vector<std::vector<T>> &v)
{
    std::string result = "[";
    for (auto i : v)
    {
        result += "[";
        for (auto j : i)
        {
            result += std::to_string(j) + ", ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]\n");
    }
    result.erase(result.size()-1);
    result.append("]");

    return result;
}

template <typename T>
T sum(const std::vector<T> &v)
{
    T result = 0;
    for (auto i : v) result += i;

    return result;
}

template <typename T>
T sum(const std::vector<std::vector<T>> &v)
{
    T result = 0;
    for (auto i : v)
    {
        for (auto j : i) result += j;
    }

    return result;
}

int main(int argc, char *argv[])
{

    v_int v1d = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "Origin: " << to_str(v1d) << std::endl;
    std::cout << "Sum: " << sum(v1d) << std::endl;
    std::cout << "Average: " << sum(v1d)/v1d.size() << std::endl;

    v2d_int v2d;
    for (int i = 0; i < 5; i++)
    {
        v2d.push_back(v_int(5));
        for (int j = 0; j < 5; j++) v2d[i][j] = j;
    }
    
    std::cout << "Origin: " << to_str(v2d) << std::endl;
    std::cout << "Sum: " << sum(v2d) << std::endl;
    int amout = 0;
    for (auto i : v2d) amout += i.size();
    std::cout << "Average: " << sum(v2d)/amout << std::endl;
}