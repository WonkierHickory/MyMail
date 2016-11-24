#include "Attachment.h"

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
bugs: Won't let me print objects as required.
*/
#pragma endregion

#pragma endregion

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
	//std::cout << fileName << "." << fileSuffix << "\nContent: " << fileData << std::endl;
}
