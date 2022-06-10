#pragma once
#include<string>

namespace nw{
class ISBN
{
	int isbn;
public:
	ISBN(const int& isbn) :isbn(isbn) {}

	std::string ToString() {
		std::string str = std::to_string(isbn);
		return str;
	}
};
}

