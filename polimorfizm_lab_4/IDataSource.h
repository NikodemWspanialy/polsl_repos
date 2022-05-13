#pragma once
#include "User.h";
#include <vector>;
class IDataSource
{
public:
	virtual void CreateUser(const User& user) = 0;
	virtual std::vector<User> ReadUser() = 0;
	virtual void UpdateUser(const User& user) = 0;
	virtual void DeleteUser(const User& user) = 0;
};

