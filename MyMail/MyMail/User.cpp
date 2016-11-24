#include "User.h"
#include <iostream>

#pragma region Version Control

#pragma region Version 0.1
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 23/11/2016
Updates: Set up Constructors, Destructors
*/
#pragma endregion

#pragma region Version 0.2
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 24/11/2016
Updates: Implemented Setters and print method.
*/
#pragma endregion

#pragma endregion

User::User(std::string email, std::string password, std::string userName)
{
	setEmail(email);
	setPassword(password);
	setUserName(userName);
}

User::User()
{

}

User::~User()
{

}

void User::setEmail(std::string email)
{
	User::email = (email.length() >= 8) ? email : "defaultemail@email.com";
}

void User::setPassword(std::string password)
{
	User::password = (password.length() >= 8) ? password : "Password1";
}

void User::setUserName(std::string userName)
{
	User::userName = (userName.length() >= 8) ? email : "Default Name";
}

void User::print()
{
	std::cout << "Email: " << email << "\nPassword: " << password << "\nName: " << userName;
}
