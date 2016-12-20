#include "Attachment.h"

#include <iostream>

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

#pragma region Version 0.3
/*
Author : Kieran Hoey
Student Number: D00163930
Date: 1/12/2016
Updates: Fixed Attachment print method
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

Attachment::Attachment(std::string fileName, std::string fileSuffix)
{
	setFileName(fileName);
	setFileSuffix(fileSuffix);
}

Attachment::Attachment()
{

}

Attachment::~Attachment()
{

}

void Attachment::setFileName(std::string fileName)
{
	Attachment::fileName = (fileName.length() >= 8) ? fileName : "placeholder";
}

void Attachment::setFileSuffix(std::string fileSuffix)
{
	Attachment::fileSuffix = (fileSuffix.length() >= 2 && fileSuffix.length() <= 3) ? fileSuffix : "txt";
}


void Attachment::print()
{
	std::cout << fileName << "." << fileSuffix << ", ";
}


std::ostream& operator<<(std::ostream & outStream, const Attachment & email)
{
	outStream << "Name: ";
	return outStream;
}

std::istream& operator >> (std::istream & inStream, Attachment & email)
{
	std::string str;
	inStream >> str;
	return inStream;
}

bool Attachment::operator>(const Attachment &other)
{
	if (Attachment::getFileName() > other.fileName)
		return true;
	else
		return false;
}

bool Attachment::operator==(const Attachment & other)
{
	if (Attachment::getFileName() == other.fileName)
		return true;
	else
		return false;
}

bool Attachment::operator!=(const Attachment & other)
{
	if (Attachment::getFileName() != other.fileName)
		return true;
	else
		return false;
}
