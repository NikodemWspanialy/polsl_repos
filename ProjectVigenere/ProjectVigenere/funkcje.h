#ifndef FUNKCJE_H
#define FUNKCJE_H


enum flaga
{
	szyf,
	deszyf,
	lamanie,
	blad,
};
/**
* @brief Funkcja sprawdza poprawnoœæ oraz iloœæ przes³anych argumentów
* @return zwraca liczbe przypisana do konkretnej operacji, ktora chce wykonac uzytkownik
		0 - blad
		1 - szyfrowani
		2 - odszyfrowanie
		3 - lamanie
* @param C liczba argumentow przekazanego przez uzytkownika
* @param argv[] argumenty przekazane
* @param wejscie napis opisujacy nazwe pliku wejsciowego odczytywany w funkcji
* @param wyjscie napis opisujacy nazwe pliku wyjsciowego odczytywany w funkcji
* @param klucz napis opisuj¹cy nazwe pliku z kluczem odczytywany w funkcji*/
flaga check(int c, char* argv[], std::string& wejscie, std::string& wyjscie, std::string& klucz);



/**
* @brief Funkcja otwiera plik z kluczem, jezeli jest to mozliwe to pobiera z pliku klucz, naspetnie sprawdza poprawnosc klucza(czy nie ma nie legalnych znakow)
* @return zwraca true, jezeli odczytywanie i poprawnosc klucza jest poprane 
		zwraca false, jezeli odczytywanie i poprawnosc klucza jest niepoprane
* @param klucz wchodzi do funcji jako nazwa pliku z kluczem, jezeli uda sie odczytac klucz to jest w tej zmiennej zapisany klucz*/
bool pobklucz(std::string& klucz);


/**
* @brief Funkcja otwiera pliki wejsciowe i wyjsciowe, sprawdza pomyslnosc operacji, uruchamia nastepna funcje zalezna od argumentu "operacja" 
* @return zwraca true, jezeli operacja wykonala sie pomyslnie
* 		zwraca false, jezeli operacja nie wykonala sie poprawnie
* @param wej nazwa pliku wejsciowego
* @param wyj nazwa pliku wyjsciowego
* @param klucz ciag znakow ktory jest kluczem do szyfrowania
* @param operacja okresla rodzaj operacji, jaka wykonuje program**/
bool funkcjaGlowna(std::string &wej, std::string& wyj, std::string& klucz, const int& operacja);


/**
* 
*/
void AlgOdszyfrowania(char* buf, const int l, std::string klucz);


/**
*
*/
void AlgSzyfrowania(char* buf, const int l, std::string klucz);


/**
* @brief
* 
* @return zwraca true, jezeli operacja wykonala sie pomyslnie
		zwraca false, jezeli operacja nie wykonala sie poprawnie
* @param wej nazwa pliku z tekstem do lamania klucza/szyfru
* @param klucz fukcja zapisuje w ten zmiennej zlamany klucz*/
bool zlam(std::string& wej, std::string& klucz);



int findrep(std::vector<char>& text, std::vector<int>& replay);


/**Funcja liczy najwieksze wspolne dzielniki wystepujacych obok siebie liczb w wektorze, wylania najczesniej pojawiajacy sie
@return zwraca najczesciej wystepujacy najwiekszy wspolny dzielnik liczb w wektorze
@param wektor z liczbami typu int*/
int NWD(std::vector<int>& v);


/**Funcja porownuje znak z kazdym kolejnym znakiem przekazanego tekstu, konczy jezeli sa one takie same
@return zwraca pozycje znaku w przekazanym napisie
@param znak ktoremu ustalamy pozycje w napisie
@param alf napis bedacy ciagiem znakow do porownywania ze znakiem*/
int pozycjaAlfabet(char znak, std::string alf); 


/**
* @brief Funcja wypisje instukcje na temat przekaZywania argumentow do programu w konsoli*/
void instrukcja();

#endif