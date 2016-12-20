#pragma region Includes

#include "User.h"
#include "Email.h"
#include "Attachment.h"
#include "MailType.h"

#include <iostream>
#include <string>

#pragma endregion


#pragma region Method Declarations
void mainMenu(User *activeUser);
void newEmail(User *activeUser);
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

#pragma region Version 0.3
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 28/11/2016
	Updates: Added method for creating new email.
	*/
#pragma endregion

#pragma endregion



#pragma region Initialisation

int main()
{
	User activeUser("Kieran Hoey", "Password1", "KieranHoey1995@gmail.com");

	std::cout << "******** My Mail Server ********" << std::endl;
	mainMenu(&activeUser);

	//demoEmail();

	system("pause");
	return 0;
}

#pragma endregion

#pragma region Menu

void mainMenu(User *activeUser)
{
	int user = 0;
	int exit = 0;

#pragma region Menu Options
	while(exit != 1)
	{
	std::cout << "******* Options ********" << std::endl;
	std::cout << "[1]New - Draft a new email and send" << std::endl;
	std::cout << "[2]View - View emails" << std::endl;
	std::cout << "[3]Delete - Delete an email" << std::endl;
	std::cout << "[4]Delete All - Delete all emails" << std::endl;
	std::cout << "[5]Search By - Search by name/email" << std::endl;
	std::cout << "[6]Reset - Reset mail server" << std::endl;
	std::cout << "[7]Exit - Exit mail server" << std::endl;

#pragma endregion

	std::cin >> user;

	switch (user) {
	case 1:
		newEmail(activeUser);
		break;
	case 2:
		viewEmails();
		break;
	case 3:
		deleteEmail();
		break;
	case 4:
		deleteAllEmails();
		break;
	case 5:
		searchBy();
		break;
	case 6:
		resetMail();
		break;
	case 7:
		exit = 1;
		break;
	}
	}
}

void newEmail(User *activeUser)
{
	int j = 1;
	int count;
	int attachment;
	std::vector<std::string> recipients;
	std::string recipient; 
	std::string subject; 
	std::string body; 

	std::cout << "How many people are you sending this to?" << std::endl;
	std::cin >> count;
	

	for (int i = 0; i < count; i++)
	{
		std::cout << "Enter Recipient " << j + i << ": ";
		std::cin >> recipient;
		recipients.push_back(recipient);
		std::cin.ignore();
	}

	std::cout << "Enter Subject: ";
	std::getline(std::cin, subject);

	std::cout << "Enter Body: ";
	std::getline(std::cin, body);


	int uCheck = 0;
	while (uCheck != 1)
	{
		std::cout << "Any Attachments?\n[1] - Yes\n[2] - No" << std::endl;
		std::cout << std::endl;
		std::cin >> attachment;
		if (attachment == 1)
		{
			int aCount;
			std::cout << "How many Attachments do you want to add?" << std::endl;
			std::cin >> aCount;

			std::vector<Attachment> attachments;
			for (int i = 0; i < aCount; i++)
			{
				std::string fileName, fileSuffix;
				std::cout << "Enter File Name: ";
				std::cin >> fileName;
				std::cout << "Enter File Suffix: ";
				std::cin >> fileSuffix;
				attachments.push_back(Attachment(fileName, fileSuffix));
			}

			activeUser->createNewEmail(Email(activeUser->getEmail(), recipients, subject, body, attachments));
			std::cout << "Email sent!" << std::endl;
			uCheck = 1;
		}
		else if (attachment == 2)
		{
			activeUser->createNewEmail(Email(activeUser->getEmail(), recipients, subject, body));
			std::cout << "Email sent!" << std::endl;
			uCheck = 1;
		}
		else
			std::cout << "Please enter an appropriate response" << std::endl;
	}

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
	std::vector<std::string> demo;

	std::vector<Attachment> demoA;

	Email e = Email("Kieran", demo, "blah", "blah blah", demoA);

	e.print();
}

#pragma endregion



