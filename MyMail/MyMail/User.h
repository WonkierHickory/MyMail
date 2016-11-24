#pragma once
#include <string>

#pragma region Version Control

#pragma region Version 0.1
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 23/11/2016
Updates: Set up variables and created Constructor
*/
#pragma endregion

#pragma region Version 0.2
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 24/11/2016
Updates: Set up Getter/Setter methods and print method
*/
#pragma endregion

#pragma endregion

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

