#pragma once
#include <string>
#include "Attachment.h"

class Email
{
public:
	Email(std::string sender, std::string recipients, std::string subject, std::string body, Attachment attachment);
	Email();
	~Email();

private:
	std::string sender;
	std::string recipients;
	//DateTime
	std::string subject;
	std::string body;	
	Attachment attachment;
};

