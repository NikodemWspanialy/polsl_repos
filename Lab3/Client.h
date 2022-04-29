#pragma once
#include "Person.h";
#include "NIP.h";

namespace nw {
	class Client : nw::person
	{
		NIP nip;
	public:
		Client(const NIP& nip, const std::string& fn, std::string& ln) : nip(nip), person(fn, ln) {}
		Client(const NIP& nip, const nw::person& p) : nip(nip), person(p){}
		//Client(const NIP& nip, const std::string& fn, std::string& ln) : nip(nip), first {}

		std::string ToString() const {
			return nip.ToString() + " | " + person::ToString();
		}
	};
}
