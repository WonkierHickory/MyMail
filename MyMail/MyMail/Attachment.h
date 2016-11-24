#pragma once
#include <iostream>

class Attachment
{
public:
	Attachment(std::string fileName, std::string fileSuffix, char fileData);
	Attachment();
	~Attachment();

	std::string getFileName() { return fileName; }
	std::string getFileSuffix() { return fileSuffix; }
	char getFileData() { return fileData; }

	void setFileName(std::string fileName);
	void setFileSuffix(std::string fileSuffix);
	void setFileData(char fileData);

private:
	std::string fileName;
	std::string fileSuffix;
	char fileData;
};

