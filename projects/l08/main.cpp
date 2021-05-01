#include <iostream>
#include <string>

int main(int argc, char *argv[])
{

    std::string str1 = "Hello world!";
    std::string str2 = "hello world";
    std::string str3 = "sekai";

    // string compare

    std::cout << "string compare" << std::endl;

    std::cout << "str1 : " << str1 << std::endl;
    std::cout << "str2 : " << str2 << std::endl;

    std::cout << str1.compare(str2) << std::endl;

    // replace part of string
    
    std::cout << "\nreplace part of string" << std::endl;
    std::cout << "origin: " << str1 << std::endl;
    std::cout << str1.replace(str1.find("world"), str3.size(), str3) << std::endl;

    // string concatenation

    std::cout << "\nstring concatenation" << std::endl;
    std::cout << "origin: " << str1 << "; " << str2 << std::endl;
    std::cout << str1 + " " + str2 << std::endl;

    std::cout << str1.append(" ").append(str2) << std::endl;

    // substring

    std::cout << "\nsubstring" << std::endl;
    std::cout << "origin: " << str1 << std::endl;
    str1 = str1.substr(0, 13);
    std::cout << str1 << std::endl;

    // Insert

    std::cout << "\nInsert" << std::endl;
    std::cout << "origin: " << str1 << std::endl;
    std::cout << str1.insert(6, "world ") << std::endl;
}