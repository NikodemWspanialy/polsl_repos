// Lab_2.cpp

#include <iostream>
#include "Complex.h"
using namespace nw;
int main()
{
    std::cout << "----------------------\n";
    std::cout << "Labolatorium PK2 lab_2\n";
    std::cout << "----------------------\n";


    Complex c(3.1,-2.7);
    std::cout << c << "\n";

    c += 5;
    std::cout << c << "\n";

    ++c;
    std::cout << c << "\n";
    std::cout << "----------------------\n";
    std::cout << c++ << "\n";
    std::cout << c << "\n";
    std::cout << (c * 2) << "\n";
    std::cout << (2 * c) << "\n";
    std::cout << "----------------------\n";
    c = Complex(4.6, 3.0);
    Complex c1(1,1);
    std::cout << c * c1 << std::endl;
   // std::cout << (c / 5) << "\n";

}

