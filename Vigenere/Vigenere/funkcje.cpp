#include <vector>
#include <iostream>
#include <cstring>

#include "funkcje.h"


bool prerequed(int c, char* v[], std::string alf){
	int good = 0;
	for (int i = 1; i < c; i++){ //kazde slowo
		std::string word = v[i];
		for (int j = 0; j < word.size(); j++) { //kazda literka
			for (int k = 0; k < alf.size(); k++) { //sprawdxamy cy jest w alf
				if (word[j] == alf[k])
					good++;
			}
			if (good == 1)
				good--;
			else
				return 1;
		}
	}
	return 0;
}

bool test(std::string text, std::string alf) {
	int zmienna = 0;
	for (int i = 0; i < text.size(); i++) { //kazda literka
		for (int k = 0; k < alf.size(); k++) { //sprawdxamy cy jest w alf
			if (text[i] == alf[k])
				zmienna++;
		}
		if (zmienna == 1)
			zmienna--;
		else
			return 0;
	}
	return 1;
}

bool check(int c, char* argv[], int& operacja, std::string& wejscie, std::string& wyjscie, std::string& klucz) {
	int iflag = 0; // ilosc glownych flag
	int iwej = 0; //ilosc tektow wej
	int iwyj = 0;  // ilosc tektow wyj
	int iklucz = 0;  //ilosc kluczy
	for (int i = 1; i < c; i++) {
		if (strcmp(argv[i], "--en") == 0) { // sprawdzamy czy jest flaga er
			iflag++;
			operacja = 1;
		}
	}
	for (int i = 1; i < c; i++) {
		if (strcmp(argv[i], "--de") == 0) {// sprawdzamy czy jest flaga de
			iflag++;
			operacja = 2;
		}
	}
	for (int i = 1; i < c; i++) {
		if (strcmp(argv[i], "--br") == 0) {// sprawdzamy czy jest flaga br
			iflag++;
			operacja = 3;
		}
	}
	if (iflag == 1) {// jezeli byla jedna flaga glowna to idziemy dalej
		if (operacja == 1) {   //dla en ktore ma mniej arg
			if (c != 6)   //sprawdzamy czy jest odpowiednia liczba argumentow
				return 0;
			for (int i = 1; i < c - 1; i++) {
				if (strcmp(argv[i], "-i") == 0) {// sprawdzamy czy jest flaga -i wejscowy tekst
					if (strcmp(argv[i + 1], "-o") != 0 and strcmp(argv[i + 1], "-i") != 0 and strcmp(argv[i + 1], "-k") != 0 and strcmp(argv[i + 1], "--en") != 0 and strcmp(argv[i + 1], "--de") != 0 and strcmp(argv[i + 1], "--br") != 0)
					{ // sprawdzamy czy nasteny znak to nie flaga
						iwej++;
						wejscie = argv[i + 1];
					}
					else
						return 0;
				}
				if (strcmp(argv[i], "-k") == 0) {// sprawdzamy czy jest flaga -o wyjscowy tekst
					if (strcmp(argv[i + 1], "-o") != 0 and strcmp(argv[i + 1], "-i") != 0 and strcmp(argv[i + 1], "-k") != 0 and strcmp(argv[i + 1], "--en") != 0 and strcmp(argv[i + 1], "--de") != 0 and strcmp(argv[i + 1], "--br") != 0)
					{ // sprawdzamy czy nasteny znak to nie flaga
						iklucz++;
						klucz = argv[i + 1];
					}
				}
			}
			if (iwej != 1 or iklucz != 1) //sprawdzamy czy sa dobre ilosci flag 
				return 0;
			else
				return 1;
		}
		if (operacja == 2) {   //dla odszy ktore ma mniej arg
			if (c != 6)   //sprawdzamy czy jest odpowiednia liczba argumentow
				return 0;
			for (int i = 1; i < c - 1; i++) {
				if (strcmp(argv[i], "-o") == 0) {// sprawdzamy czy jest flaga -i wejscowy tekst
					if (strcmp(argv[i + 1], "-o") != 0 and strcmp(argv[i + 1], "-i") != 0 and strcmp(argv[i + 1], "-k") != 0 and strcmp(argv[i + 1], "--en") != 0 and strcmp(argv[i + 1], "--de") != 0 and strcmp(argv[i + 1], "--br") != 0)
					{ // sprawdzamy czy nasteny znak to nie flaga
						iwyj++;
						wyjscie = argv[i + 1];
					}
					else
						return 0;
				}
				if (strcmp(argv[i], "-k") == 0) {// sprawdzamy czy jest flaga -o wyjscowy tekst
					if (strcmp(argv[i + 1], "-o") != 0 and strcmp(argv[i + 1], "-i") != 0 and strcmp(argv[i + 1], "-k") != 0 and strcmp(argv[i + 1], "--en") != 0 and strcmp(argv[i + 1], "--de") != 0 and strcmp(argv[i + 1], "--br") != 0)
					{ // sprawdzamy czy nasteny znak to nie flaga
						iklucz++;
						klucz = argv[i + 1];
					}
				}
			}
			if (iklucz != 1 or iwyj != 1) //sprawdzamy czy sa dobre ilosci flag 
				return 0;
			else
				return 1;
		}
		if (operacja == 3) {   //dla br ktore ma mniej arg
			if (c != 6)   //sprawdzamy czy jest odpowiednia liczba argumentow
				return 0;
			for (int i = 1; i < c - 1; i++) {
				if (strcmp(argv[i], "-i") == 0) {// sprawdzamy czy jest flaga -i wejscowy tekst
					if (strcmp(argv[i + 1], "-o") != 0 and strcmp(argv[i + 1], "-i") != 0 and strcmp(argv[i + 1], "-k") != 0 and strcmp(argv[i + 1], "--en") != 0 and strcmp(argv[i + 1], "--de") != 0 and strcmp(argv[i + 1], "--br") != 0)
					{ // sprawdzamy czy nasteny znak to nie flaga
						iwej++;
						wejscie = argv[i + 1];
					}
					else
						return 0;
				}
				if (strcmp(argv[i], "-o") == 0) {// sprawdzamy czy jest flaga -o wyjscowy tekst
					if (strcmp(argv[i + 1], "-o") != 0 and strcmp(argv[i + 1], "-i") != 0 and strcmp(argv[i + 1], "-k") != 0 and strcmp(argv[i + 1], "--en") != 0 and strcmp(argv[i + 1], "--de") != 0 and strcmp(argv[i + 1], "--br") != 0)
					{ // sprawdzamy czy nasteny znak to nie flaga
						iwyj++;
						wyjscie = argv[i + 1];
					}
				}
			}
			if (iwej != 1 or iwyj != 1) //sprawdzamy czy sa dobre ilosci flag 
				return 0;
			else
				return 1;
		}
	}
	else // nie ma dokladnie 1 flagi glownej
		return 0;
}
int pozycjaAlfabet(char znak, std::string alf) { 
	for (int i = 0; i < alf.size(); i++) {
		if (alf[i] == znak)
			return i;
	}
}
void szyfruj(std::string tekst, std::string klucz, std::string alf, std::string& wynik) {
	int puste = 0;
	for (int i = 0; i < tekst.size(); i++) {
		if (tekst[i] == ' ') { //jezeli spaca to przepisze spacje
			wynik += " ";
			puste++;
		}
		else {

			int indexpow = (i - puste) % klucz.size(); // abysmy caly czas uzywali klucz ktory jest krotszy od tekstu i bierze poprwke na spacje
			int przesunieciepion = pozycjaAlfabet(klucz[indexpow], alf); //sprawdza index klucza
			int przesunieciepoziom = pozycjaAlfabet(tekst[i], alf); // index tekstu
			wynik += alf[(przesunieciepoziom + przesunieciepion) % alf.size()]; //operacja szyfrowania i zamiana na literke dodanie do "wyniku"
		}
	}
}
void odszyfruj(std::string tekst, std::string klucz, std::string alf, std::string& wynik) {
	int puste = 0;
	for (int i = 0; i < tekst.size(); i++) {
		if (tekst[i] == ' ') {
			wynik += " ";
			puste++;
		}
		else {
			int indexpow = (i - puste) % klucz.size();
			int przesunieciepion = pozycjaAlfabet(klucz[indexpow], alf);
			int przesunieciepoziom = pozycjaAlfabet(tekst[i], alf);
			if (przesunieciepion > przesunieciepoziom)
				przesunieciepoziom += 26; //aby wynik nie wyszdl ujemny
			wynik += alf[przesunieciepoziom - przesunieciepion]; // operacja odszyfrowywania
		}
	}
}
void lamanie(std::string nieszyf, std::string zaszyf, std::string alf, std::string& klucz) { 
	for (int i = 0; i < nieszyf.size(); i++) {
		if (nieszyf[i] == ' ') {}
		else {
			int przesunieciepion = pozycjaAlfabet(nieszyf[i], alf);
			int przesunieciepoziom = pozycjaAlfabet(zaszyf[i], alf);
			if (przesunieciepion > przesunieciepoziom)
				przesunieciepoziom += 26;
			klucz += alf[przesunieciepoziom - przesunieciepion]; // operacja odszyfrowywania
		}
	}
}
void zamiana(std::string& s, std::string alf) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 26; j < alf.size(); j++) {
			if (s[i] == alf[j])
				s[i] = alf[j - 26];
		}
	}
}