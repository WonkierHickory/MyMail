#pragma once
#include <string>
#include <vector>

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

#pragma endregion

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

	void print();

private:
	std::string fileName;
	std::string fileSuffix;
	char fileData;
};

