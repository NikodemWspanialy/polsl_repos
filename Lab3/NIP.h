#pragma once
#include "Person.h";
#include <string>

class NIP
{
	std::string nip;
public:
	NIP(const std::string& nip) : nip(nip){}
	std::string ToString() const {
		return nip;
	}
};

