#pragma once
#include<string>
#include <iostream>
namespace nw{
class Status
{
	std::string status;
public:
	Status(const std::string status) :status(status) {
		change();
	}
	void change() {
		if (status == "n") {
			status = "notavailbe";
		}
		if (status == "a") {

			status = "availbe";
		}
	}
	std::string ToString() {
		return (status);
	}
	void write() {
		std::cout << ", status: "<< status;
	}
	};
}

