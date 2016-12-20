#pragma once
#include <string>
#include <stack>
#include <vector>

#include "Email.h"
#include "MailType.h"

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

#pragma region Version 0.3
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 28/11/2016
Updates: Added enum support to print method
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

class User
{
	friend std::ostream& operator<<(std::ostream& outStream, const User& user);
	friend std::istream& operator >> (std::istream& inStream, User& user);

public:
	User(std::string name, std::string password, std::string emailAddress);
	User();
	~User();

	void setEmail(std::string email);
	void setPassword(std::string password);
	void setUserName(std::string userName);

	std::string getEmail() { return email; }
	std::string getPassword() { return password; }
	std::string getUserName() { return userName; }
	std::stack<Email*, std::vector<Email*>> getInbox() { return inbox; }


	void createNewEmail(Email *email);
	
	void print();
	void printMail(MailType mailType);
	std::stack<Email*, std::vector<Email*>>* getMailType(MailType mailType);


	bool regexValidate(std::string expression, std::string email);

	bool operator>(const User& other);
	bool operator==(const User& other);
	bool operator!=(const User& other);

private:
	std::stack<Email*, std::vector<Email*>> inbox, outbox;
	std::string email;
	std::string password;
	std::string userName;
};
