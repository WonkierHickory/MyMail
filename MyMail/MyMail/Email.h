#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <vector>

#include "Attachment.h"

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

#pragma region Version 0.4
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 3/12/2016
Updates: Added Overload operators
*/
#pragma endregion

#pragma endregion

class Email
{
	friend std::ostream& operator<<(std::ostream& outStream, const Email& user);
	friend std::istream& operator >> (std::istream& inStream, Email& user);

public:
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body, std::vector<Attachment> attachment);
	Email(std::string sender, std::vector<std::string> recipients, std::string body, std::vector<Attachment> attachment);
	Email(std::string sender, std::vector<std::string> recipients, std::string subject, std::string body);

	Email();
	~Email();

	static int emailCount;

	std::string getSender() { return sender; }
	std::time_t getDate();
	std::string getSubject() { return subject; }
	std::string getBody() { return body; }
	std::vector<Attachment> getAttachment() { return attachment; }
	unsigned int getId() { id; }


	void setId(unsigned int id) { Email::id = id; }
	void setSender(std::string sender);
	void setRecipients(std::vector<std::string> recipients);
	void setSubject(std::string subject);
	void setBody(std::string body);
	void setAttachment(std::vector<Attachment> attachment);

	void print();

	bool regexValidateEmail(std::string expression, std::string email);


	bool operator>(const Email& other);
	bool operator==(const Email& other);
	bool operator!=(const Email& other);

private:
	std::string sender;
	std::vector<std::string> recipients;
	std::time_t date;
	std::string subject;
	std::string body;	
	std::vector<Attachment> attachment;

	unsigned int id;

};