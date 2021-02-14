#include <iostream>

struct test
{

    int a, b, c, d;
    char key;

    double ans;

};

int main(int argc, char *argv[])
{

    std::cout << "Hello world!\n";

    std::cout << "int => " << sizeof(int) << "\n";
    std::cout << "char => " << sizeof(char) << "\n";
    std::cout << "double => " << sizeof(double) << "\n";
    std::cout << "long long => " << sizeof(long long) << "\n";
    
    int arr[10];
    std::cout << "int 10 array => " << sizeof(arr) << "\n";

    test kek;
    std::cout << "struct.int  => " << sizeof(kek.a*4) << "\n";
    std::cout << "struct.double  => " << sizeof(kek.ans) << "\n";
    std::cout << "struct.char  => " << sizeof(kek.key) << "\n";
    std::cout << "struct  => " << sizeof(kek) << "\n";

    int trr[14] = {12,12,32,15,34,23,56,32,6,73,23,68,21,12};
    for (int i = 0; i < sizeof(trr)/sizeof(int);i++)
    {
        std::cout << trr[i];
    }

}