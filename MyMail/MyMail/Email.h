#pragma once
#include <string>
#include <vector>

#include "Attachment.h"
#include "User.h"

class Email
{
public:
	Email(std::string sender, std::vector<User> recipients, std::string subject, std::string body, Attachment attachment);
	Email(std::string sender, std::vector<User> recipients, std::string body, Attachment attachment);
	Email();
	~Email();

	std::string getSender() { return sender; }
	std::vector<User> getRecipients() { return recipients; }
	//DateTime
	std::string getSubject() { return subject; }
	std::string getBody() { return body; }
	Attachment getAttachment(){ return attachment; }


	void setSender(std::string sender);
	void setRecipients(std::vector<User> recipients);
	//DateTime
	void setSubject(std::string subject);
	void setBody(std::string body);
	void setAttachment(Attachment attachment);

private:
	std::string sender;
	std::vector<User> recipients;
	//DateTime
	std::string subject;
	std::string body;	
	Attachment attachment;
};

