#pragma once
#include<string>

namespace nw {
	class Author {
		std::string firstName;
		std::string lastName;
	public:
		Author(const std::string& fn, const std::string& ln) : firstName(fn), lastName(ln) {}
		std::string ToString() const {
			return(firstName + " " + lastName);
		}
		std::string getFirstName() {
			return firstName;
		}
		std::string getLastName() {
			return lastName;
		}
	};
}