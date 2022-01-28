#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include<stdlib.h>

#include "funkcje.h"



int main(int argc, char* argv[])
{
	int oper; 
	std::string wejscie;
	std::string wyjscie;
	std::string klucz;
	bool pk = 0, sz = 0, od = 0, la = 0;


    oper = check(argc, argv, wejscie, wyjscie, klucz);
	 switch (oper) {
		 case 0:
			 instrukcja();
			 break;
		case 1:
			 pk = pobklucz(klucz);
			if(pk)
			 sz = szyfruj(wejscie, wyjscie, klucz);
			if (sz)
				std::cout << "szyfrowanie zakonczone";
			else
				std::cout << "blad odczytu plikow";
			break;
		case 2:
			pk = pobklucz(klucz);
			if(pk)
			od = odszyfruj(wejscie, wyjscie, klucz);
			if (od)
				std::cout << "odszyfrowanie zakonczone";
			else
				std::cout << "blad odczytu plikow";
			break;
		case 3:
			la = zlam(wejscie, klucz);
			if (la) {
				std::cout << '\n' << "klucz to: " << klucz << '\n';
				od = odszyfruj(wejscie, wyjscie, klucz);
				if (od == 0) {
					std::cout << "blad odczytu plikow";
					exit;
				}
				std::cout << "lamanie zakonczone";
			}
			else
				std::cout << "lamanie szyfru nie powiodlo sie";
			break;
		}
}
