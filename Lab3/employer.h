#pragma once
#include "Person.h";
#include "Pesel.h";
namespace nw {
	class employer : nw::person
	{
		Pesel pesel;
	public:
		employer(const Pesel& p ,const std::string& fn, const std::string& ln) : pesel(p), person(fn, ln) {}
		employer(const Pesel& p, const nw::person& per) : pesel(p), person(per) {}

		std::string ToString() const {
			return pesel.ToString() + " | " + person::ToString();
		}
	};
}


