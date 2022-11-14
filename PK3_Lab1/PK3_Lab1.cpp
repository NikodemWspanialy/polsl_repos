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
   
    nw::Vector<int> vTest1(1, 1);
    nw::Vector<int> vTest2(vTest1);
    vTest1[0] = 2;
   
        LOG(vTest1[0]);
        LOG(vTest2[0]);

        nw::Vector<int> v2;
        v2 = { 1,2,3,44 };
        for (int i = 0; i < v2.sizeGetter(); i++)
            LOG(v2[i]);
        nw::Vector<int> v3(1, 5);
        v2 = v3;
        for (int i = 0; i < v2.sizeGetter(); i++)
            LOG(v2[i]);
    _getch();
    nw::Vector<char>oneParamNumvber(7);
    for (int i = 0; i < oneParamNumvber.sizeGetter(); i++) {
        LOG(oneParamNumvber[i]);
    }
}