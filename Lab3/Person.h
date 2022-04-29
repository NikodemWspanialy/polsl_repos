#pragma once
#include <string>
namespace nw {
	class person {
		std::string firstName;
		std::string lastName;
	public:
		person(const std::string& fn, const std::string& ln) : firstName(fn), lastName(ln){}
		std::string ToString() const {
			return(firstName + " " + lastName);
			}
	};
}