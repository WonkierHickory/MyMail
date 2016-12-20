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
void viewEmails(User *activeUser);
void deleteEmail(User *activeUser);
void deleteAllEmails(User *activeUser);
void searchBy();
void resetMail(User *activeUser);

std::vector<Attachment> addAttachments(int aCount);

void demoUser();
void demoEmail();
void demoAttachment();
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

#pragma region Version 0.3
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 4/12/2016
	Updates: Added method for viewing emails.
	*/
#pragma endregion

#pragma region Version 0.4
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 10/12/2016
	Updates: Added method for resetting all emails.
	*/
#pragma endregion

#pragma region Version 0.5
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 11/12/2016
	Updates: Fixed inefficient methods. (removed all initialisations inside for loops / if statements / e.t.c
	*/
#pragma endregion

#pragma region Version 0.6
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 15/12/2016
	Updates: Added methods for deleting emails
	*/
#pragma endregion

#pragma endregion



#pragma region Initialisation

int main()
{
	User activeUser("Kieran Hoey", "Password1", "KieranHoey1995@gmail.com");

	std::cout << "******** My Mail Server ********" << std::endl;
	mainMenu(&activeUser);

	#pragma region demo
	/*demoUser();
	demoEmail();
	demoAttachment();*/
	#pragma endregion

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
	while (exit != 1)
	{
		std::cout << "******* Options ********" << std::endl;
		std::cout << "[1]New - Draft a new email and send" << std::endl;
		std::cout << "[2]View - View emails" << std::endl;
		std::cout << "[3]Delete - Delete an email" << std::endl;
		std::cout << "[4]Delete All - Delete all emails" << std::endl;
		std::cout << "[5]Search By - Search by id/email" << std::endl;
		std::cout << "[6]Reset - Reset mail server" << std::endl;
		std::cout << "[7]Exit - Exit mail server" << std::endl;

#pragma endregion

		std::cin >> user;

		switch (user) {
		case 1:
			newEmail(activeUser);
			break;
		case 2:
			viewEmails(activeUser);
			break;
		case 3:
			deleteEmail(activeUser);
			break;
		case 4:
			deleteAllEmails(activeUser);
			break;
		case 5:
			searchBy();
			break;
		case 6:
			resetMail(activeUser);
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
	std::vector<Attachment> attachments;
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
	int aCount;

	while (uCheck != 1)
	{
		std::cout << "Any Attachments?\n[1] - Yes\n[2] - No" << std::endl;
		std::cout << std::endl;
		std::cin >> attachment;

		switch (attachment)
		{
		case 1:
			std::cout << "How many Attachments do you want to add?" << std::endl;
			std::cin >> aCount;
			std::cin.ignore();

			attachments = addAttachments(aCount);

			activeUser->createNewEmail(new Email(activeUser->getEmail(), recipients, subject, body, attachments));
			std::cout << "Email sent!" << std::endl;
			uCheck = 1;
			break;
		case 2:
			activeUser->createNewEmail(new Email(activeUser->getEmail(), recipients, subject, body));
			std::cout << "Email sent!" << std::endl;
			uCheck = 1;
			break;
		default:
			std::cout << "Please enter an appropriate response" << std::endl;
			break;
		}
	
	}

}

std::vector<Attachment> addAttachments(int aCount)
{
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
	return attachments;
}

void viewEmails(User *activeUser)
{
	int uCheck = 0;
	int uChoice;

	while (uCheck != 1)
	{		
		std::cout << "[1] - View Inbox" << std::endl;
		std::cout << "[2] - View Outbox" << std::endl;
		std::cout << "[3] - Back to Main Menu" << std::endl;
		std::cin >> uChoice;
		switch (uChoice)
		{
		case 1:
			activeUser->printMail(Inbox);
			break;

		case 2:
			activeUser->printMail(Outbox);
			break;
		case 3:
			uCheck = 1;
			break;

		default:
			std::cout << "Please enter an appropriate response" << std::endl;
		}


	}
}

void deleteEmail(User *activeUser)
{
	int uCheck = 0;
	int uChoice;
	int menuOption;

	while (uCheck != 1)
	{
		std::cout << "[1] - Delete email from Inbox" << std::endl;
		std::cout << "[2] - Delete email from Outbox" << std::endl;
		std::cout << "[3] - Back to Main Menu" << std::endl;
		std::cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			std::cout << "Enter the id of the email you want to delete:" << std::endl;
			std::cin >> uChoice;
			activeUser->deleteEmail(Inbox, uChoice);
			break;
		case 2:
			std::cout << "Enter the id of the email you want to delete:" << std::endl;
			std::cin >> uChoice;
			activeUser->deleteEmail(Outbox, uChoice);
			break;
		case 3:
			uCheck = 1;
			break;
		default:
			std::cout << "Please enter an appropriate response" << std::endl;
		}
	}
}

void deleteAllEmails(User *activeUser)
{
	int uCheck = 0;
	int uChoice;
	int menuOption;

	while (uCheck != 1)
	{
		std::cout << "[1] - Delete all emails from the Inbox" << std::endl;
		std::cout << "[2] - Delete all emails from the Outbox" << std::endl;
		std::cout << "[3] - Back to Main Menu" << std::endl;
		std::cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			std::cin >> uChoice;
			activeUser->deleteAllEmails(Inbox);
			break;
		case 2:
			std::cin >> uChoice;
			activeUser->deleteAllEmails(Outbox);
			break;
		case 3:
			uCheck = 1;
			break;
		default:
			std::cout << "Please enter an appropriate response" << std::endl;
		}
	}
}

void searchBy()
{

}


void searchBy(User *activeUser)
{
	int uCheck = 0;
	std::string uChoice;
	int id;
	MailType mailType;
	int menuOption;

	while (uCheck != 1)
	{
		
		std::cout << "[1] - Inbox" << std::endl;
		std::cout << "[2] - Outbox" << std::endl;
		std::cout << "[3] - Back to Main Menu" << std::endl;
		std::cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			mailType = Inbox;
			uCheck = 1;
			break;
		case 2:
			mailType = Outbox;
			uCheck = 1;
			break;
		case 3:
			uCheck = 1;
			break;
		default:
			std::cout << "Please enter an appropriate response" << std::endl;
		}

	}

	std::vector<Email*> temp;

	while (uCheck != 0)
	{
		std::cout << "[1] - Search by id" << std::endl;
		std::cout << "[2] - Search by email" << std::endl;
		std::cout << "[3] - Back to Main Menu" << std::endl;
		std::cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			std::cin >> id;
			std::cout << activeUser->searchByID(id, mailType);
			break;
		case 2:
			std::cin >> uChoice;
			temp = activeUser->searchByEmail(uChoice, mailType);
			for (int i = 0; i < temp.size(); i++)
				std::cout << temp[i];
			break;
		case 3:
			uCheck = 0;
			break;
		default:
			std::cout << "Please enter an appropriate response";
		}
	}
}










void resetMail(User *activeUser)
{
	int uCheck = 0;
	int uChoice;
	while (uCheck != 1)
	{
		uCheck = 0;
		std::cout << "Do you want to reset the mail server?\n[1] - Yes\n[2] - No" << std::endl;
		std::cin >> uChoice;

		switch (uChoice)
		{
		case 1: 
			activeUser->~User();
			uCheck = 1;
			break;
		case 2:
			uCheck = 1;
			break;
		default:
			std::cout << "Please enter an appropriate response" << std::endl;
		}
	}
}

#pragma endregion

#pragma region Demo

void demoUser()
{
	User u = User("Kieran Hoey", "Marmite1", "Kieran_hoey@hotmail.com");

	u.print();
}

void demoEmail()
{
	std::vector<std::string> demo;

	std::vector<Attachment> demoA;

	Email e = Email("KieranHoey1995@gmail.com", demo, "blah", "blah blah", demoA);

	e.print();
}

void demoAttachment()
{
	Attachment a = Attachment("Banter", "txt");

	a.print();
}
#pragma endregion



