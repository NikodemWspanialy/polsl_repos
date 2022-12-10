#include<iostream>
#include "List.h"
#include <string>
#define LOG std::cout << std::endl;

int main() {
	std::cout << "kompilacja powidla sie :D" << std::endl;
	nw::Lista<double> lista(4, [](const size_t i) {return 1.0 + i;});
	for (const auto& el : lista) std::cout << el << std::endl;
	LOG;
	for (auto& el : lista) el *= 2.0;
	for (auto it = lista.begin(); it != lista.end(); ++it) std::cout << lista(it) << std::endl;
	LOG;
	lista.erase(lista.begin());
	for (const auto& el : lista) std::cout << el << std::endl;
	LOG;
	lista.erase(lista.end());
	for (const auto& el : lista) std::cout << el << std::endl;
	LOG;
	lista.push_back(13.3);
	for (const auto& el : lista) std::cout << el << std::endl;
	LOG;
	lista.insert(lista.end(), 16.6);
	for (const auto& el : lista) std::cout << el << std::endl;

	std::cout << "koniec";
}