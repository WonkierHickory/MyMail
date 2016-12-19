#pragma region Includes

#include <iostream>
#include <string>

#include "User.h"
#include "Email.h"
#include "Attachment.h"

#pragma endregion

#pragma region Method Declarations
void mainMenu();
void newEmail();
void sendMail();
void viewEmails();
void deleteEmail();
void deleteAllEmails();
void searchBy();
void resetMail();
void demoEmail();
#pragma endregion

#pragma region Version Control

#pragma region Version 0.1
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 23/11/2016
	Updates: Added Includes, and set up Main Method.
	*/
#pragma endregion

#pragma region Version 0.2
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 24/11/2016
	Updates: Set up main menu UI. Replaced if statement with switch.
	*/
#pragma endregion

#pragma endregion

#pragma region Initialisation

int main()
{
	std::cout << "******** My Mail Server ********" << std::endl;
	//mainMenu();

	demoEmail();

	system("pause");
	return 0;
}

#pragma endregion

#pragma region Menu

void mainMenu()
{
	int user = 0;

#pragma region Menu Options

	std::cout << "******* Options ********" << std::endl;
	std::cout << "[1]New - Draft a new email" << std::endl;
	std::cout << "[2]Send - Send an email" << std::endl;
	std::cout << "[3]View - View emails" << std::endl;
	std::cout << "[4]Delete - Delete an email" << std::endl;
	std::cout << "[5]Delete All - Delete all emails" << std::endl;
	std::cout << "[6]Search By - Search by name/email" << std::endl;
	std::cout << "[7]Reset - Reset mail server" << std::endl;
	std::cout << "[8]Exit - Exit mail server" << std::endl;

#pragma endregion

	std::cin >> user;

	switch (user) {
	case 1:
		newEmail();
		break;
	case 2:
		sendMail();
		break;
	case 3:
		viewEmails();
		break;
	case 4:
		deleteEmail();
		break;
	case 5:
		deleteAllEmails();
		break;
	case 6:
		searchBy();
		break;
	case 7:
		resetMail();
		break;
	case 8:
		break;
	}
}

void newEmail()
{

}

void sendMail()
{

}

void viewEmails()
{

}

void deleteEmail()
{

}

void deleteAllEmails()
{

}

void searchBy()
{

}

void resetMail()
{

}

#pragma endregion

#pragma region Demo

void demoEmail()
{
	std::vector<User> demo;

	Attachment demoA;

	Email e = Email("Kieran", demo, "blah", "blah blah", demoA);

	e.print();
}

#pragma endregion



