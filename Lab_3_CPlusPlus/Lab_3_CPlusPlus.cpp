
#include "Vector.h"
#include <iostream>


int main()
{
    nw::Vector<double> v(10, 2);
    for (size_t i = 0; i < v.Size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

