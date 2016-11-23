#pragma once
#include <string>
class User
{
public:
	User(std::string email, std::string password, std::string userName);
	User();
	~User();

private:
	std::string email;
	std::string password;
	std::string userName;

};

