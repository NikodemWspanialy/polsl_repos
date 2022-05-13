#pragma once
#include "User.h";
#include <vector>
#include "IDataSource.h"

class MockDataSource : public IDataSource
{
	std::vector<User> users;
	virtual void CreateUser(const User& user) {
		auto it = std::find_if(users.begin(), users.end(), [&](const auto& el) {
			return el.getID() == user.getID();
			});
			if (it != users.end()) throw std::exception();
			users.push_back(user);

	}
	virtual std::vector<User> ReadUser() {
		return{};
	}
	virtual void UpdateUser(const User& user) {
	
	}
	virtual void DeleteUser(const User& user) {
		auto it = std::find_if(users.begin(), users.end(), [&](const auto& el) {
			return el.getID() == user.getID();
			});
		users.erase(it);
	}
};

