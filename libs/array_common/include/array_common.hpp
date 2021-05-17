#include <iostream>
#include <vector>
#include <utility>
#include <functional>

#ifndef ARRAY_COMMON_U
#define ARRAY_COMMON_U

namespace arrays
{
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

    template <typename T>
    void print(const std::vector<T> &v) // override prints 1d vector
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

    template <typename T1, typename T2>
    void print(const std::vector<std::pair<T1, T2>> &v) // override prints 1d vector
    {
        std::string result = "[";
        for (auto i : v)
        {
            result += "(" + std::to_string(i.first) + ", " + std::to_string(i.second) + "), ";
        }
        result.erase(result.size() - 2, 2);
        result.append("]");

        std::cout << result << std::endl;
    }

    template <typename T>
    void print(const std::vector<std::vector<T>> &v) // override prints 2d vector
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
    std::string to_str(const std::vector<T> &v) // override converts to string 1d vector
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
    std::string to_str(const std::vector<std::vector<T>> &v) // override converts to string 2d vector
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
        result.erase(result.size() - 1);
        result.append("]");

        return result;
    }

    template <typename T>
    T sum(const std::vector<T> &v) // override sums 1d vector
    {
        T result = 0;
        for (auto i : v)
            result += i;

        return result;
    }

    template <typename T>
    T sum(const std::vector<std::vector<T>> &v) // override sums 2d vector
    {
        T result = 0;
        for (auto i : v)
        {
            for (auto j : i)
                result += j;
        }

        return result;
    }

    template <typename T>
    T max(const std::vector<T>& v)
    {
        T mx = v[0];
        for (auto i : v){
            if (mx < i) mx = i;
        }

        return mx;
    }

    template <typename T>
    T min(const std::vector<T>& v)
    {
        T mx = v[0];
        for (auto i : v){
            if (mx > i) mx = i;
        }

        return mx;
    }

    template <typename T>
    T max(const std::vector<std::vector<T>>& v)
    {
        T mx = v[0][0];
        for (auto i : v)
        {
            for (auto j : i)
            {
                if (mx < j) mx = j;
            }
        }

        return mx;
    }

    template <typename T>
    T min(const std::vector<std::vector<T>>& v)
    {
        T mx = v[0][0];
        for (auto i : v)
        {
            for (auto j : i)
            {
                if (mx > j) mx = j;
            }
        }

        return mx;
    }

    

}
#endif