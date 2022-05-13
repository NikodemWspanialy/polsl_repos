#include <string>
#include <iostream>
#include "Figure.h"
#include <vector>
#include "Prostokat.h"
#include "Kolo.h"
#include "IDataSource.h"

int main()
{
    { //prostokaty
        std::vector<Figura*> figury;
        figury.push_back(new Prostokat(1, 2));
        figury.push_back(new Prostokat(3, 2));
        figury.push_back(new Prostokat(6, 8));

        for (const auto& el : figury) {
            std::cout << el->pole() << std::endl;
        }
        for (auto& el : figury) {
            delete el;
        }
    }
    { //kola
        std::vector<Figura*> figury;
        figury.push_back(new Kolo(1));
        figury.push_back(new Kolo(3));
        figury.push_back(new Kolo(6));

        for (const auto& el : figury) {
            std::cout << el->pole() << std::endl;
        }
        for (auto& el : figury) {
            delete el;
        }
    }
}
