#include "User.h"

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
