#include "User.h"
#include "Email.h"

#include <iostream>
#include <regex>

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

#pragma region Version 0.3
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 29/11/2016
Updates: Added Regex for email and password
Bugs: if Email is wrong, Vector out of bounds exception occurs
*/
#pragma endregion

#pragma region Version 0.4
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 3/12/2016
Updates: Added Overload operators
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
	std::string regex = "[\\w]+@[\\w]+.[\\w]{2,3}";
	if (regexValidate(regex, email))
	{
		User::email = email;
	}
	else
	{
		User::email = "defaultemail@email.com";
	}
}

bool User::regexValidate(std::string expression, std::string email)
{
	std::regex ex(expression);
	if (regex_match(email, ex)) {
		return true;
		std::cout << "true";
	}
	else
	{
		return false;
	}
}

void User::setPassword(std::string password)
{
	std::string regex = "^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$";
	if (regexValidate(regex, password))
	{
		User::password = password;
	}
	else
	{
		User::password = "Password1";
	}
}

void User::setUserName(std::string userName)
{
	User::userName = (userName.length() >= 8) ? email : "Default Name";
}


void User::createNewEmail(Email email)
{
	User::outbox.push(email);
}

void User::print()
{
	std::cout << "Email: " << email << "\nPassword: " << password << "\nName: " << userName;
}



std::ostream& operator<<(std::ostream & outStream, const User & user)
{
	outStream << "Name: " << user.userName << "\nEmail: " << user.email << std::endl;
	return outStream;
}

std::istream& operator >> (std::istream & inStream, User & user)
{
	std::string str;
	inStream >> str;
	return inStream;
}

bool User::operator>(const User &other)
{
	if (User::userName > other.userName)
		return true;
	else
		return false;
}

bool User::operator==(const User & other)
{
	if (User::userName == other.userName)
		return true;
	else
		return false;
}

bool User::operator!=(const User & other)
{
	if (User::userName != other.userName)
		return true;
	else
		return false;
}