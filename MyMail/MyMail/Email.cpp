#include "Email.h"

#include <iostream>
#include <iomanip>
#include <regex>
#pragma warning(disable : 4996)

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
Date: 28/11/2016
Updates: Added Date printing
Bugs: Get a break unless some ?warning? is disabled
*/
#pragma endregion

#pragma region Version 0.4
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 29/11/2016
Updates: Added Regex for email
Bugs: if Email is wrong, Vector out of bounds exception occurs
*/
#pragma endregion

#pragma region Version 0.5
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 3/12/2016
Updates: Added Overload operators
*/
#pragma endregion


#pragma endregion

int Email::emailCount = 0;

Email::Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body, std::vector<Attachment> attachment)
{
	Email::setId(emailCount++);
	setSender(sender);
	setRecipients(recipients);
	Email::date = std::time(0);
	setSubject(subject);
	setBody(body);
	setAttachment(attachment);
}

Email::Email(std::string sender, std::vector<std::string> recipients, std::string body, std::vector<Attachment> attachment)
{
	Email::setId(emailCount++);
	setSender(sender);
	setRecipients(recipients);
	Email::date = std::time(0);
	setBody(body);
	setAttachment(attachment);
}

Email::Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body)
{
	Email::setId(emailCount++);
	setSender(sender);
	setRecipients(recipients);
	Email::date = std::time(0);
	setSubject(subject);
	setBody(body);
}

Email::Email()
{

}

Email::~Email()
{

}

void Email::setSender(std::string sender)
{
	std::string regex = "[\\w]+@[\\w]+.[\\w]{2,3}";
	if (regexValidateEmail(regex, sender))
	{
		Email::sender = sender;
	}
	else
	{
		Email::sender = "defaultEmail@email.com";
	}
}

void Email::setRecipients(std::vector<std::string> recipients)
{
	for (int i = 0; i < recipients.size(); i++)
	{
		std::string regex = "[\\w]+@[\\w]+.[\\w]{2,3}";
		if (regexValidateEmail(regex, recipients[i]))
		{
			Email::recipients = recipients;
		}
		else
		{
			Email::recipients[i] = "defaultEmail@email.com";
		}
	}
}

bool Email::regexValidateEmail(std::string expression, std::string email)
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

void Email::setSubject(std::string subject)
{
	Email::subject = (subject.length() >= 0) ? subject : "";
}

void Email::setBody(std::string body)
{
	Email::body = (body.length() >= 1) ? body : "Hi, Lunch at 1pm in the Crowne Plaza? Regards, J.";
}

void Email::setAttachment(std::vector<Attachment> attachment)
{
	Email::attachment = attachment;
}

std::time_t Email::getDate()
{
	return Email::date;
}

void Email::print()
{
	std::cout << "From: " << sender << "\nRecipients: " /*<< recipients*/ << "\nDate & Time: " << std::put_time(localtime(&date), "%F %T") << "\nSubject: " << subject <<
		"\nBody: " << body << "\nAttachments: " /*<< attachment*/ << std::endl;
}


std::ostream& operator<<(std::ostream & outStream, const Email & email)
{
	outStream << "Name: ";
	return outStream;
}

std::istream& operator >> (std::istream & inStream, Email & email)
{
	std::string str;
	inStream >> str;
	return inStream;
}

bool Email::operator>(const Email &other)
{
	if (Email::getBody() > other.body)
		return true;
	else
		return false;
}

bool Email::operator==(const Email & other)
{
	if (Email::getBody() == other.body)
		return true;
	else
		return false;
}

bool Email::operator!=(const Email & other)
{
	if (Email::getBody() != other.body)
		return true;
	else
		return false;
}