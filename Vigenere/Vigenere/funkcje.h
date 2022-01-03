#ifndef FUNKCJE_H
#define FUNKCJE_H
bool prerequed(int c, char* v[], std::string alf); //funkcja sprawdza czy argumenty wejsciowe zawieraja tylko znaki zawierajace sie  w przekazanym tekscie(alfabecie)

bool test(std::string text, std::string alf); //funkcja sprawdza czy przekazany tekst posiada tylko znaki  alfabetu

bool check(int c, char* argv[], int& operacja, std::string& wejscie, std::string& wyjscie, std::string& klucz); //funkcja sprawdza poprawnosc przeslanych argumentow i oraz przypisuje je do zmiennych

int pozycjaAlfabet(char znak, std::string alf); // funkcja zwraca liczbe odpowiadajaca danej literze

void szyfruj(std::string tekst, std::string klucz, std::string alf, std::string& wynik); // szyfrowanie

void odszyfruj(std::string tekst, std::string klucz, std::string alf, std::string& wynik); //odszyfrowywanie

void lamanie(std::string nieszyf, std::string zaszyf, std::string alf, std::string& klucz); //lamanie kodu kod wraca nie skrocony

void zamiana(std::string& s, std::string alf); //zamienia duze na male litery

#endif

