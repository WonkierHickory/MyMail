#include "Email.h"

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
	Email::subject = (subject.length() >= 0) ? subject : "Subject";
}

void Email::setBody(std::string body)
{
	Email::body = (body.length() >= 1) ? body : "Hi, Lunch at 1pm in the Crowne Plaza? Regards, J.";
}

void Email::setAttachment(Attachment attachment)
{
	Email::attachment = attachment;
}
