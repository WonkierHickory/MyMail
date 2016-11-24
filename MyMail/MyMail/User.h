#pragma once
#include <string>
class User
{
public:
	User(std::string email, std::string password, std::string userName);
	User();
	~User();

	std::string getEmail() { return email; }
	std::string getPassword() { return password; }
	std::string getUserName() { return userName; }

	void setEmail(std::string email);
	void setPassword(std::string password);
	void setUserName(std::string userName);

	void print();

private:
	std::string email;
	std::string password;
	std::string userName;

};

