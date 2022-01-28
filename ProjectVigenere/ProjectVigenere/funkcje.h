#ifndef FUNKCJE_H
#define FUNKCJE_H


/**Funkcja sprawdza poprawnoœæ oraz iloœæ przes³anych argumentów
@return zwraca liczbe przypisana do konkretnej operacji, ktora chce wykonac uzytkownik
		0 - blad
		1 - szyfrowani
		2 - odszyfrowanie
		3 - lamanie
@param C liczba argumentow przekazanego przez uzytkownika
@param argv[] argumenty przekazane
@param wejscie napis opisujacy nazwe pliku wejsciowego odczytywany w funkcji
@param wyjscie napis opisujacy nazwe pliku wyjsciowego odczytywany w funkcji
@param klucz napis opisuj¹cy nazwe pliku z kluczem odczytywany w funkcji*/
int check(int c, char* argv[], std::string& wejscie, std::string& wyjscie, std::string& klucz);


/**Funkcja otwiera plik z kluczem, jezeli jest to mozliwe to pobiera z pliku klucz, naspetnie sprawdza poprawnosc klucza(czy nie ma nie legalnych znakow)
@return zwraca true, jezeli odczytywanie i poprawnosc klucza jest poprane 
		zwraca false, jezeli odczytywanie i poprawnosc klucza jest niepoprane
@param klucz wchodzi do funcji jako nazwa pliku z kluczem, jezeli uda sie odczytac klucz to jest w tej zmiennej zapisany klucz*/
bool pobklucz(std::string& klucz);


/**Funkcja otwiera pliki wejsciowe i wyjsciowe, sprawdza pomyslnosc operacji, 
	tekst zapisany w pliku wejsciowym jest przekazywany do bufora, 
	gdzie jest szyfrowany za pomoca przekazanego klucza a nastepnie wpisywany do pliku wyjsciowego
@return zwraca true, jezeli operacja wykonala sie pomyslnie
		zwraca false, jezeli operacja nie wykonala sie poprawnie
@param wej nazwa pliku wejsciowego
@param wyj nazwa pliku wyjsciowego
@param klucz ciag znakow ktory jest kluczem do szyfrowania**/
bool szyfruj(std::string &wej, std::string& wyj, std::string& klucz);


/**Funkcja otwiera pliki wejsciowe i wyjsciowe, sprawdza pomyslnosc operacji,
	tekst zapisany w pliku wejsciowym jest przekazywany do bufora,
	gdzie jest odszyfrowywany za pomoca przekazanego klucza a nastepnie wpisywany do pliku wyjsciowego
@return zwraca true, jezeli operacja wykonala sie pomyslnie
		zwraca false, jezeli operacja nie wykonala sie poprawnie
@param wej nazwa pliku wejsciowego
@param wyj nazwa pliku wyjsciowego
@param klucz ciag znakow ktory jest kluczem do odszyfrowania**/
bool odszyfruj(std::string& wej, std::string wyj, std::string& klucz);


/**Funcja otwiera plik wejsciowy sprawdza poprawnosc operacji
	na podstwie powtorzen ciagow znakow tekscie wyznacza dlugosc klucza, na podstawie powtarzalnosci liter w tekscie 
	oraz najpopularniejszych liter w alfabecie angielskim wyznacza dlugosc oraz znaki klucza
@return zwraca true, jezeli operacja wykonala sie pomyslnie
		zwraca false, jezeli operacja nie wykonala sie poprawnie
@param wej nazwa pliku z tekstem do lamania klucza/szyfru
@param klucz fukcja zapisuje w ten zmiennej zlamany klucz*/
bool zlam(std::string& wej, std::string& klucz);


/**Funcja liczy najwieksze wspolne dzielniki wystepujacych obok siebie liczb w wektorze, wylania najczesniej pojawiajacy sie
@return zwraca najczesciej wystepujacy najwiekszy wspolny dzielnik liczb w wektorze
@param wektor z liczbami typu int*/
int NWD(std::vector<int>& v);


/**Funcja porownuje znak z kazdym kolejnym znakiem przekazanego tekstu, konczy jezeli sa one takie same
@return zwraca pozycje znaku w przekazanym napisie
@param znak ktoremu ustalamy pozycje w napisie
@param alf napis bedacy ciagiem znakow do porownywania ze znakiem*/
int pozycjaAlfabet(char znak, std::string alf); 


/**Funcja wypisje instukcje na temat przekaZywania argumentow do programu w konsoli*/
void instrukcja();
#endif