#include <iostream>
#include <string>
#include "Header.h"
#include<conio.h>
#define LOG(x) std::cout << x << std::endl;
int main()
{
    nw::Vector<char> v1;
    v1.pushback('b');
    v1.pushback('c');
    for (int i = 0; i < v1.sizeGetter(); i++) {
        std::cout << v1[i];
    }
    LOG("");
    //potega 2
    {
        int a = 1;
        nw::Vector<int> v2(10,[&a](int) mutable {a = 2 * a; return a; });
        for (int i = 0; i < v2.sizeGetter(); i++) {
            LOG(v2[i]);
        }
    }

    //ciag fib
    {
        int a = 1, b = 1;
        nw::Vector<int> vFib(10, [&](int)mutable {int a_tmp = a, b_tmp = b; a = a + b; b = a_tmp; return b_tmp; });
        for (int i = 0; i < vFib.sizeGetter(); i++) {
            LOG(vFib[i]);
        }
    }
    nw::Vector<int> vTest1(1, 1);
    nw::Vector<int> vTest2(vTest1);
    vTest1[0] = 2;
   
        LOG(vTest1[0]);
        LOG(vTest2[0]);
    _getch();
}