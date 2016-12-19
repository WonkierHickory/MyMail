#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <chrono>

#include "Attachment.h"
#include "User.h"

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
Updates: Added Date variable and setter
*/
#pragma endregion

#pragma endregion

class Email
{
public:
	Email(std::string sender, std::vector<User> recipients, std::string subject, std::string body, Attachment attachment);
	Email(std::string sender, std::vector<User> recipients, std::string body, Attachment attachment);
	Email();
	~Email();

	std::string getSender() { return sender; }
	std::vector<User> getRecipients() { return recipients; }
	std::time_t getDate();
	std::string getSubject() { return subject; }
	std::string getBody() { return body; }
	Attachment getAttachment(){ return attachment; }


	void setSender(std::string sender);
	void setRecipients(std::vector<User> recipients);
	void setSubject(std::string subject);
	void setBody(std::string body);
	void setAttachment(Attachment attachment);

	void print();

private:
	std::string sender;
	std::vector<User> recipients;
	std::time_t date;
	std::string subject;
	std::string body;	
	Attachment attachment;
};

