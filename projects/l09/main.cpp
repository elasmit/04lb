#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <typeinfo>

template<typename T, size_t size>
std::string array_to_string(const std::array<T, size>& arr)
{
    std::string res = "[";

    for (auto i : arr){
        res.append(std::to_string(i)).append(", ");
    }

    res.erase(res.end()-2, res.end());

    res += "]";

    return res;
}

template<typename T, size_t size>
T sum(const std::array<T, size>& arr)
{
    T res = 0;

    for (auto i : arr)
    {
        res += i;
    }

    return res;
}

template<typename T, size_t size>
T average(const std::array<T, size>& arr)
{
    return T(sum(arr)/arr.size());
}

int main(int argc, char *argv[])
{
    std::array<int, size_t(5)> arr = {8, 10, 82, 3, 72};

    std::cout << "Origin: " << array_to_string(arr) << std::endl;

    std::sort(arr.begin(), arr.end());

    std::cout << "Sorted: " << array_to_string(arr) << std::endl;

    std::cout << "Access element with \".at()\": " << arr.at(0) << std::endl;
    
    std::cout << "Access element with \"operator []\": " << arr[0] << std::endl;

    std::cout << "Sum of elements of array: " << sum(arr) << std::endl;

    std::cout << "Average of elements of array: " << average(arr) << std::endl;

    std::cout << "Find element \"3\" position in array: " << std::distance(arr.begin(), std::find(arr.begin(), arr.end(), 3)) << std::endl;
    
    std::replace(arr.begin(), arr.end(), 10, 99);

    std::cout << "Replace element \"10\" by \"99\" in array: " << array_to_string(arr) << std::endl;
}