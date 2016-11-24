#include "Attachment.h"

Attachment::Attachment(std::string fileName, std::string fileSuffix, char fileData)
{
	setFileName(fileName);
	setFileSuffix(fileSuffix);
	setFileData(fileData);
}

Attachment::Attachment()
{

}

Attachment::~Attachment()
{

}

void Attachment::setFileName(std::string fileName)
{
	Attachment::fileName = (fileName.length() >= 8) ? fileName : "banter";
}

void Attachment::setFileSuffix(std::string fileSuffix)
{
	Attachment::fileSuffix = (fileSuffix.length() >= 2 && fileSuffix.length() <= 3) ? fileSuffix : "txt";
}

void Attachment::setFileData(char fileData)
{
	Attachment::fileData = (fileData != NULL) ? fileData : 1;
}

void Attachment::print()
{
	std::cout << Attachment::getFileName << "." << Attachment::getFileSuffix << "\nContent: " << Attachment::getFileData << std::endl;
}
