#pragma once
#include <iostream>

class Attachment
{
public:
	Attachment(std::string fileName, std::string fileSuffix, char fileData);
	Attachment();
	~Attachment();

private:
	std::string fileName;
	std::string fileSuffix;
	char fileData;
};

