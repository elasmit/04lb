#include <iostream>
#include "../../mathlab/mathlab.hpp"

int main(int argc, char *argv[]){

    ag::vector<double> vec1(2, 3, 5);
    ag::vector<double> vec2(3, 5, 11);
    std::cout << "Printing custom class vectors:" << std::endl;
    std::cout << vec1 << " " << vec2 << std::endl;
    
    std::cout << "Acces to coordinates with operator[]:" << std::endl;
    std::cout << vec1[1] << std::endl;
    
    std::cout << "Adding and substracting custom class vectors:" << std::endl;
    std::cout << vec1 + vec2 << std::endl;
    std::cout << vec1 - vec2 << std::endl;


    std::cout << "operator+= and operator-= overrides" << std::endl;
    vec1 += ag::vector<double>(4, 3 ,2);
    std::cout << vec1<< std::endl;
    vec1 -= ag::vector<double>(4, 3 ,2);
    std::cout << vec1<< std::endl;

    ag::point<float> p1;
    ag::point<float> p2 = ag::point<float>(1.0f, 2.0f, 3.0f);
    
    std::cout << "Printing custom class points:" << std::endl;
    std::cout << p1 << " " << p2 << std::endl;

    std::cout << "Adding and substracting custom class vectors to ppoints:" << std::endl;
    std::cout << p1 + ag::vector<float>(1, 2 ,3) << std::endl;
    std::cout << p1 - ag::vector<float>(1, 2 ,3) << std::endl;

    std::cout << "operator+= and operator-= overrides" << std::endl;
    p2 += ag::vector<float>(4, 3 ,2);
    std::cout << p2<< std::endl;
    p2 -= ag::vector<float>(4, 3 ,2);
    std::cout << p2<< std::endl;

    ag::square<double> sh1(1.0f, 1.0f, 1.0f);
    ag::sphere<double> sh2(5.0f);
    std::cout << "Printing custom class shapes:" << std::endl;
    std::cout << sh1 << " : " << sh1.getSize() << " " << sh2 << " : " << sh2.getRadius() << std::endl;
    
    std::cout << "Changing custom class shapes using vetors:" << std::endl;
    std::cout << sh1 + ag::vector<double>(2, 1 ,2) << " : " << sh1.getSize() << " " << sh2  + ag::vector<double>(5, 6 ,3) << " : " << sh2.getRadius() << std::endl;
    
    std::cout << "Changing custom class shapes using methods:" << std::endl;
    std::cout << sh1.reSize(2, -3, 2) << " : " << sh1.getSize() << " " << sh2.setRadius(sh2.getRadius() + 3)  + ag::vector<double>(5, 6 ,3) << " : " << sh2.getRadius() << std::endl;

    std::cout << "Does point belong to shape using call operator:" << std::endl;
    std::cout << "point(1, 2, 3) " << (sh2(1, 2, 3) ? ("belongs ") : ("doesn't belong ")) << "to shape" << std::endl;

    ag::point<double> p3;
    std::cout << "Cin in point (takes x, y, z):" << std::endl;
    std::cin >> p3;
    std::cout << p3 << std::endl;
}