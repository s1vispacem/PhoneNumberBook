#include <string>
#include <functional>
#include "person.h"
#include "functions.h"
#include <iostream>
void addClient(std::string name,std::string surname,std::string phoneNumber, person prs[],int numberOfContacs)
{
	std::cout << "add here function\n";
	bool flag = true;
	while (flag)
	{
		std::string input;

		std::getline(std::cin, input);

	}

}

void printInterface()
{
	std::cout << "enter num for command\n"
		<< "1. Add client\n";
}

bool checkPhoneNumber(person contacts[], int num, std::string phoneNumber,int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i != num) 
		{
			if (contacts[i].phoneNumber == phoneNumber)
			{
				return false;
			}
		}
		else
		{
			continue;
		}
	}
	return true;
	
}

int enteringCommand()
{
	std::string input;

		if (cmdNumCheck(input))
		{
			return std::stoi(input);
		}
	return 0;
}

bool cmdNumCheck(std::string input) 
{
	int i = 0;
	int minus_ctr = 0;

	if (input.length() > 0)
	{
		return false;
	}

	for (size_t i = 0; i < input.length(); i++)
	{
		//if()
	}
	return true;
}

