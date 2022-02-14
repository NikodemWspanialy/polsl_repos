#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include<stdlib.h>

#include "funkcje.h"



int main(int argc, char* argv[])
{
	flaga operacja; 
	std::string wejscie;
	std::string wyjscie;
	std::string klucz;
	bool pk = 0, sz = 0, od = 0, la = 0;


    operacja = check(argc, argv, wejscie, wyjscie, klucz);
	 switch (operacja) {
		 case blad:
			 instrukcja();
			 break;
		case szyf:
			 pk = pobklucz(klucz);
			if(pk)
			 sz = funkcjaGlowna(wejscie, wyjscie, klucz, operacja);
			if (sz)
				std::cout << "szyfrowanie zakonczone";
			else
				std::cout << "blad odczytu plikow";
			break;
		case deszyf:
			pk = pobklucz(klucz);
			if (pk)
			od = funkcjaGlowna(wejscie, wyjscie, klucz, operacja);
			if (od)
				std::cout << "odszyfrowanie zakonczone";
			else
				std::cout << "blad odczytu plikow";
			break;
		case lamanie:
			la = zlam(wejscie, klucz);
			if (la) {
				std::cout << '\n' << "klucz to: " << klucz << '\n';
				std::cout << std::endl;
				od = funkcjaGlowna(wejscie, wyjscie, klucz, operacja);
				if (od == 0) {
					std::cout << "blad odczytu plikow";
					exit;
				}
				std::cout << "lamanie zakonczone";
			}
			break;
		}
}
