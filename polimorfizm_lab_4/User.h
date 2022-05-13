#pragma once
#include"string";
class User
{
	size_t id;
	std::string imie;
	std::string nazwisko;
public:
	User(const size_t id, const std::string& f, const std::string& n) : id(id), imie(f), nazwisko(n) {}

	size_t getID() const noexcept{
		return id;
}
};

