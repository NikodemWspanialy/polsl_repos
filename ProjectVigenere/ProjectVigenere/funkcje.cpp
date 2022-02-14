#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include<cctype>
#include<algorithm>

#include "funkcje.h"


flaga check(int c, char* argv[], std::string& wejscie, std::string& wyjscie, std::string& klucz) {
	int iflag = 0; 
	for (int i = 1; i < c; i++) {
		if (strcmp(argv[i], "--en") == 0 or strcmp(argv[i], "--de") == 0) {
			iflag++;
			if (c != 8)   //sprawdzamy czy jest odpowiednia liczba argumentow
				return blad;
			for (int i = 0; i < (c - 1); i++) {
				if (strcmp(argv[i], "-i") == 0) {
					wejscie = argv[i + 1];
					i++;
				}
				else if (strcmp(argv[i], "-o") == 0) {
					wyjscie = argv[i + 1];
					i++;
				}
				else if (strcmp(argv[i], "-k") == 0) {
					klucz = argv[i + 1];
					i++;
				}
			}
			if (wejscie.size() == 0 or wyjscie.size() == 0 or klucz.size() == 0)
				return blad;
			if (strcmp(argv[i], "--en") == 0)
				return szyf;
			if (strcmp(argv[i], "--de") == 0)
				return deszyf;
		}

		else if (strcmp(argv[i], "--br") == 0) {// sprawdzamy czy jest flaga br
			iflag++;
			if (c != 6)   //sprawdzamy czy jest odpowiednia liczba argumentow
				return blad;
			for (int i = 0; i < (c - 1); i++) {
				if (strcmp(argv[i], "-i") == 0) {
					wejscie = argv[i + 1];
					i++;
				}
				if (strcmp(argv[i], "-o") == 0) {
					wyjscie = argv[i + 1];
					i++;
				}
			}
			if (wejscie.size() == 0 or wyjscie.size() == 0)
				return blad;
			return lamanie;
		}
	}
}

bool pobklucz(std::string& klucz) {
	std::string textklucz;
	std::fstream k;
	k.open(klucz);
	if (k.is_open()) {
		k >> textklucz;
		klucz = textklucz;
		if (klucz.size() < 1) {
			return 0;
		}
		for (int i = 0; i < klucz.size(); i++) {
			if (isupper(klucz[i]))
				klucz[i] = char(klucz[i] + 32);
			else if(!islower(klucz[i]))
				return 0;
		}
		return 1;
	}
	else
		return 0;
}

bool funkcjaGlowna(std::string& wej, std::string& wyj, std::string& klucz, flaga operacja) {
	std::fstream plikwej, plikwyj, plikklucz;
	int l;

	plikwej.open(wej, std::ios::in | std::ios_base::binary);
	plikwyj.open(wyj, std::ios_base::out | std::ios::binary | std::ios_base::trunc);

	if (!plikwej.is_open() or !plikwyj.is_open())
	{
		return 0;
	}

	plikwej.seekg(0, std::ios_base::end);
	l = plikwej.tellg();
	plikwej.seekg(0, std::ios_base::beg);
	char* buf = new char[l];
	plikwej.read(buf, l);

	if (operacja == szyf) {
		AlgSzyfrowania(buf, l, klucz);
	}
	else {
		AlgOdszyfrowania(buf, l, klucz);
	}

	plikwyj.write(buf, l);
	delete[] buf;
	plikwyj.close();
	plikwej.close();
	return 1;
}

void AlgSzyfrowania(char* buf, const int l, std::string klucz) {
	std::string alfm = "abcdefghijklmnopqrstuvwxyz";
	std::string alfd = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int puste = 0;
	for (int i = 0; i < l; i++) {
		if (int(buf[i]) < 65 or int(buf[i] > 122)) {
			puste++;
		}
		else if (islower(buf[i])) {

			int indexpow = (i - puste) % klucz.size();
			int przesunieciepion = pozycjaAlfabet(klucz[indexpow], alfm);
			int przesunieciepoziom = pozycjaAlfabet(buf[i], alfm);
			buf[i] = alfm[(przesunieciepoziom + przesunieciepion) % alfm.size()];
		}
		else if (isupper(buf[i])) {

			int indexpow = (i - puste) % klucz.size();
			int przesunieciepion = pozycjaAlfabet(klucz[indexpow], alfm);
			int przesunieciepoziom = pozycjaAlfabet(buf[i], alfd);
			buf[i] = alfd[(przesunieciepoziom + przesunieciepion) % alfd.size()];
		}
		else {
			puste++;
		}
	}
}

void AlgOdszyfrowania(char* buf, const int l, std::string klucz) {
	std::string alfm = "abcdefghijklmnopqrstuvwxyz";
	std::string alfd = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int puste = 0;
	for (int i = 0; i < l; i++) {
		if (int(buf[i]) < 65 or int(buf[i] > 122)) {
			puste++;
		}
		else if (islower(buf[i])) {
			int indexpow = (i - puste) % klucz.size();
			int przesunieciepion = pozycjaAlfabet(klucz[indexpow], alfm);
			int przesunieciepoziom = pozycjaAlfabet(buf[i], alfm);
			if (przesunieciepion > przesunieciepoziom)
				przesunieciepoziom += 26;
			buf[i] = alfm[przesunieciepoziom - przesunieciepion];
		}
		else if (isupper(buf[i])) {
			int indexpow = (i - puste) % klucz.size();
			int przesunieciepion = pozycjaAlfabet(klucz[indexpow], alfm);
			int przesunieciepoziom = pozycjaAlfabet(buf[i], alfd);
			if (przesunieciepion > przesunieciepoziom)
				przesunieciepoziom += 26;
			buf[i] = alfd[przesunieciepoziom - przesunieciepion];
		}
		else {
			puste++;
		}
	}
}

bool zlam(std::string & wej, std::string& klucz) {
		std::string alf = "abcdefghijklmnopqrstuvwxyz"; 
		std::string najpoplit = "etainoshrdlucmfwygp";
		int l;
		std::vector<int> replay;
		std::vector<char> text;
		std::vector<char> wystapienia;
		std::vector<int> kolejnosc;
		std::string n;
		std::fstream plikwej;
		int ilosc = 0, maxilosc = 0, pomocna;
		char znak;

		plikwej.open(wej, std::ios::in, std::ios_base::binary);
		if (plikwej.good() != true) {
			std::cout << "blad odczytu plikow";
			return 0;
		}
		else {
			plikwej.seekg(0, std::ios_base::end);
			l = plikwej.tellg();
			plikwej.seekg(0, std::ios_base::beg); 
			char* buf = new char[l];
			plikwej.read(buf, l);
			plikwej.close();
			for (int i = 0; i < l; i++) {
				if (buf[i] == '\n' or buf[i] == '\r') {
					l--;
				}
				if (int(buf[i]) > 65 and int(buf[i] < 122)) {
					if (isupper(buf[i]))
						buf[i] = char(buf[i] + 32);
					text.push_back(buf[i]);
				}
			}
			int replaysize = findrep(text, replay);
			delete[] buf;
			if (replaysize == 0)
			{
				std::cout << "tekst jest za krotki aby zlamac szyfr!" << std::endl;
				return 0;
			}
			int dk = NWD(replay);
			if (dk == 0 or dk >= 20) {
				std::cout << "program nie znalazl klucza! lub jest dluzszy niz 20 znakow, co nie jest obslugiwane" << std::endl;
				return 0;
			}
			std::cout << '\n' << "dlugosc klucza = " << dk << '\n';
			for (int i = 0; i < dk; i++) {
				for (int j = 0; j < alf.size(); j++) {
					for (int k = i; k < text.size(); k = k + dk) {
						if (alf[j] == text[k]) {
							ilosc++;
						}
					}
					if (ilosc > maxilosc) {
						maxilosc = ilosc;
						znak = alf[j];
					}
					ilosc = 0;
				}
				kolejnosc.push_back(maxilosc);
				wystapienia.push_back(znak);
				maxilosc = 0;
			}


			for (int i = 0; i < wystapienia.size(); i++) {
					std::cout << kolejnosc[i] << ' ';
					std::cout << wystapienia[i] << ' ';
			}

			for (int i = 0; i < kolejnosc.size(); i++) {
				kolejnosc[i] = kolejnosc[i] * 100 + i;
			}
			std::sort (kolejnosc.begin(), kolejnosc.begin() + dk);
			for (int i = 0; i < kolejnosc.size(); i++) {
				 pomocna = kolejnosc[i] % 100;
				 znak = wystapienia[pomocna];
				 int a = pozycjaAlfabet(znak, alf);
				 znak = najpoplit[dk - i - 1];
				 int b = pozycjaAlfabet(znak, alf);
				 int c = a - b;
				 if (c < 0)
					 c = c + 26;
				 wystapienia[pomocna] = alf[c];
			}

			for (int i = 0; i < wystapienia.size(); i++) {
				klucz += wystapienia[i];
			}
		}
		return 1;
	}

int NWD(std::vector<int>& v) {

	//for (int i = 0; i < v.size(); i++) {
	//	std::cout << v[i] << ' ';
	//}
	int ilosc = 0, maxilosc = 0 ,najpop;
		std::cout << '\n';
		std::vector<int> nwd;
		for (int i = 0; i < (v.size() - 1); i++) {
			int remeber = v[i + 1];
			if(v[i] == v[i+1]){}
			else {
				while (v[i] != v[i + 1]) {
					if (v[i] > v[i + 1])
						v[i] -= v[i + 1];
					else
						v[i + 1] -= v[i];
				}
				if (v[i] > 2) {
					nwd.push_back(v[i]);
				}
				v[i + 1] = remeber;
			}
		}
		for (int i = 0; i < nwd.size(); i++) {
			std::cout << nwd[i] << ' ';
		}
		for (int i = 0; i < nwd.size(); i++) {
			if (nwd[i] != 1) {
				int dzielnik = nwd[i];
				for (int j = 0; j < nwd.size(); j++) {
					if (nwd[j] == dzielnik)
						ilosc++;
				}
				if (ilosc >= maxilosc) {
					maxilosc = ilosc;
					najpop = nwd[i];
				}
				ilosc = 0;
			}
		}
		return najpop;
	}
int findrep(std::vector<char>& text, std::vector<int>& replay) {

	int d = text.size();

	for (int i = 0; i < (d / 2); i++) {
		for (int j = i + 3; j < (d - 4); j++)
			if (text[i] == text[j]) {
				if (text[i + 1] == text[j + 1]) {
					if (text[i + 2] == text[j + 2]) {
						if (text[i + 3] == text[j + 3]) {
							if ((j - i) % 2 == 0 or (j - i) % 3 == 0 or (j - i) % 5 == 0 or (j - i) % 7 == 0 or (j - i) % 11 == 0 or (j - i) % 13 == 0 or (j - i) % 17 == 0 or (j - i) % 19 == 0) {
								replay.push_back(j - i);
								//i += 3;
							}
						}
					}
				}
			}
	}
	//return replay.size();
	return 1;
}

int pozycjaAlfabet(char znak, std::string alf) {
	for (int i = 0; i < alf.size(); i++) {
		if (alf[i] == znak)
			return i;
	}
}

void instrukcja() {
	std::cout << "instrukcja wprowadzania danych do poszczegolnych zadan: " << '\n';
	std::cout << "szyfrowanie: --en -i (nzwa pliku wejsciowego nie zaszyfrowanego) -o (nazwa pliku wyjsciowego) -k (nazwa pliku z kluczem)" << '\n';
	std::cout << "odszyfrowanie: --de -i (nzwa pliku wejsciowego zaszyfrowanego) -o (nazwa pliku wyjsciowego) -k (nazwa pliku z kluczem)" << '\n';
	std::cout << "lamanie kodu: --br -i (nzwa pliku wejsciowego zaszyfrowanego) -o (nazwa pliku wyjsciowego nie zaszyfrowanego)" << '\n';
	std::cout << "teksty powinny zawierac alfabet bez polskich znakow " << '\n';
}