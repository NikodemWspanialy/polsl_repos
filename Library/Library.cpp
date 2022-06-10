//projekt semstralny biblioteka 1.1
#include <iostream>
#include<string>
#include "Menu.h"
#include "Login.h"

int main()
{
	using namespace nw;

	Start* p = new Start;
	do {		
		p->start();
	} while (p->loginGet() == "&");
	Menu m(p->loginGet(), p->getNumber());
	m.Menu_start();
	delete p;
}