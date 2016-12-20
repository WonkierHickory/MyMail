#pragma once
#include <string>

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
Date: 3/12/2016
Updates: Added Overload operators
*/
#pragma endregion

#pragma endregion

class Attachment
{
	friend std::ostream& operator<<(std::ostream& outStream, const Attachment& user);
	friend std::istream& operator >> (std::istream& inStream, Attachment& user);

public:
	Attachment(std::string fileName, std::string fileSuffix);
	Attachment();
	~Attachment();

	std::string getFileName() { return fileName; }
	std::string getFileSuffix() { return fileSuffix; }
	char getFileData() { return fileData; }

	void setFileName(std::string fileName);
	void setFileSuffix(std::string fileSuffix);

	void print();

	bool operator>(const Attachment& other);
	bool operator==(const Attachment& other);
	bool operator!=(const Attachment& other);

private:
	std::string fileName;
	std::string fileSuffix;
	char fileData;
};

