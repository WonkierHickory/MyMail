#pragma region Includes

#include <iostream>
#include <string>

#include "User.h"
#include "Email.h"
#include "Attachment.h"

#pragma endregion

#pragma region Method Declarations
void mainMenu();
#pragma endregion

#pragma region Version Control

#pragma region Version 0.1
	/*
	Author : Kieran Hoey
	Student Number: D00163930
	Date: 23/11/2016
	Updates: Added Includes, and set up Main Method.
	*/
#pragma endregion

#pragma endregion

int main()
{
	std::cout << "My Mail Server" << std::endl;
	mainMenu();

	system("pause");
	return 0;
}

//Main Menu
void mainMenu()
{
	int check = 0;

	#pragma region Menu Options
	
	std::cout << "New" << std::endl;
	std::cout << "Send" << std::endl;
	std::cout << "View" << std::endl;
	std::cout << "Delete" << std::endl;
	std::cout << "Delete All" << std::endl;
	std::cout << "Search By" << std::endl;
	std::cout << "Reset" << std::endl;
		 
	#pragma endregion

	while (check = 0)
	{
		
	}
}