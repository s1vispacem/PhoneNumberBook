#include <string>
#include <functional>
#include "person.h"
#include "functions.h"
#include <iostream>
void addClient( person prs[],int contactPosNum,int numOfContacts) 
{
	std::string input;	
	bool flag = true;

		std::cout << "Enter name for contact\n" //achtung:: idea of creating num ruled by self
			<<"u can use numbers to mark someons phone number as alternative\n";
		std::getline(std::cin, input);
		prs[contactPosNum].name = input;

		std::cout << "Enter surname for contact\n";
		std::getline(std::cin, input);
		prs[contactPosNum].surname = input;

		while (flag) {
			std::cout << "Enter phone number\n";
			std::getline(std::cin, input);
			//TODO: find and check of existing phone number
			if (checkPhoneNumber(prs,input,numOfContacts))
			{
				prs[contactPosNum].phoneNumber = input;
				flag=false;
			}
			//Check phone number(input,prs)
		}

		flag = true;
		while (flag)
		{
			std::cout << "if u want add adress and age\n write y to add \n or n to don`t\n ";
				std::cout<< "(u can add or change them later )\n";
			std::getline(std::cin, input);
			if (input == "n")
			{
				prs[contactPosNum].adress = "unknown";
				prs[contactPosNum].age = 0;
					
				std::cout << "okke\n";
				return;
			}
			else if (input == "y")
			{
				std::cout << "enter adress\n";
				std::getline(std::cin, input);
				prs[contactPosNum].adress = input;
				bool flagSubLocal=true;
				while (flagSubLocal)
				{
					std::cout << "enter age\n";
					std::getline(std::cin, input);
					if (ageCheck(input))
					{
						flagSubLocal = false;
						prs[contactPosNum].age = std::stoi(input.c_str());
					}
					else
					{
						std::cout << "no-no, enter age\n";
					}
				}
			}
			else
			{
				std::cout <<"no-no, try again\n" ;
			}
		}
}

void searchInfo(std::string input, int * contactNum,std::function<bool(std::string input, int * contactNum,person prs[])>callableobj)
{
	for (int i = 0; i < *contactNum; i++)
	{
		if (callableobj) 
		{

		}
	}
}

bool callableobjForPhoneNumber(std::string input, int  i,person prs[])
{
	return input == prs[i].phoneNumber;
}


void printInterface()
{
	std::cout << "enter num for command\n"
		<< "1. Add client\n";
}

bool checkPhoneNumber(person contacts[], std::string input,int length)
{
	for (int i = 0; i < length; i++)//lenght = num of contacts
	{
			if (contacts[i].phoneNumber == input)
			{
				return false;
			}
			
	}
	return true;
	
}

int enteringCommand()
{
	std::string input;
	std::getline(std::cin, input);

		if (input.length()<2)// if entered by single num
		{
			return cmdNumCheck(input);
		}
		else		//if entered by word
		{
			return cmdWordCheck(input);
		}
		


	return 0;
}

int cmdWordCheck(std::string input)
{
	if(input=="add client")//add funcs during all dev or rework sys
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int cmdNumCheck(std::string input) 
{
	int i = 0;
	int minus_ctr = 0;
	if (input.length() == 1 && isdigit(input[0]))
	{
		//TODO: check by one num
		for (int i = 0; i < avaliableComands; i++)	//const int avaliableComands in functions.h
		{
			if (input[0] == i)
			{
				return i;
			}
		}
	}

	return true;
}

bool ageCheck(std::string input) 
{
	int i = 0;

	while (input[i] != static_cast<char>(0))
	{
		if (input[i] == ' ' || input[i] == '-' || !isdigit(input[i]))
		{
			return false;
		}
		i++;
	}
	return true;
}