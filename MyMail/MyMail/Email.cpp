#include "Email.h"

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

Email::Email(std::string sender, std::vector<User> recipients, std::string subject, std::string body, Attachment attachment)
{
	setSender(sender);
	setRecipients(recipients);
	setSubject(subject);
	setBody(body);
	setAttachment(attachment);
}

Email::Email(std::string sender, std::vector<User> recipients, std::string body, Attachment attachment)
{
	setSender(sender);
	setRecipients(recipients);
	setBody(body);
	setAttachment(attachment);
}

Email::Email()
{

}

Email::~Email()
{

}

void Email::setSender(std::string sender)
{
	Email::sender = (sender.length() >= 8) ? sender : "defaultemail@email.com";
}

void Email::setRecipients(std::vector<User> recipients)
{
	for (int i = 0; i < recipients.size(); i++)
	{

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

void Email::setAttachment(Attachment attachment)
{
	Email::attachment = attachment;
}

void Email::print()
{
	std::cout << "From: " << Email::getSender << "\nRecipients: " << Email::getRecipients << "\nSubject: " << Email::getSubject <<
		"\nBody: " << Email::getBody << "\nAttachments: " << Email::getAttachment;
}