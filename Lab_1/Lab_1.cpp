
#include <iostream>
#include <string>
#include "Vector.h"

int main()
{
    std::string s = "a";
    nw::Vector<int> v(10);
    for (size_t i = 0; i < v.Size(); i++) {
        std::cout << v[i] << std::endl;
    }
}
