#pragma once

#include<string>
class Pesel
{
	std::string pesel;
	const static uint8_t w[];
public:
	Pesel(const std::string& p) : pesel(p){
	if(p.length() != 11) throw std::exception("bledna dlugosc");
	for (const auto c : pesel) {
		if (c < '0' || c > '9') throw std::exception("zle znaki ");
	}
	uint16_t sum = 0;
	for (size_t i = 0; i < pesel.length(); ++i) {
		sum += (pesel[i] - '0') * w[i];
	}
	if (sum % 10 != 0) throw std::exception("bledny");
	}
	std::string ToString() const {
		return pesel;
	}
};

