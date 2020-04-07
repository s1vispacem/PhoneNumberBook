#include <string>
#include <functional>
#include "person.h"
#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

static const std::string path = "DB.txt";

void addClient( std::vector<person>& prs) 
{
	person temp;
	std::string input;	
	bool flag = true;

		std::cout << "Enter name for contact\n" //achtung:: idea of creating num ruled by self
			<<"u can use numbers to mark someons phone number as alternative\n";
		std::getline(std::cin, input);
		temp.name = input;

		std::cout << "Enter surname for contact\n";
		std::getline(std::cin, input);
		temp.surname = input;

		while (flag) {	//entering phone number
			std::cout << "Enter phone number\n";
			std::getline(std::cin, input);
			//TODO: find and check of existing phone number
			int length = prs.size();
			if (checkPhoneNumber(prs,input,length))
			{
				temp.phoneNumber = input;
				flag=false;
			}
			//Check phone number(input,prs)
		}

		flag = true;
		while (flag)// extra: adding adres + age by option
		{
			std::cout << "if u want add adress and age\n write y to add \n or n to don`t\n ";
				std::cout<< "(u can add or change them later )\n";
			std::getline(std::cin, input);
			if (input == "n")
			{
				temp.adress = "unknown";
				temp.age = 0;
					
				std::cout << "okke\n";
				prs.push_back(temp);
				return;
			}
			else if (input == "y")
			{
				std::cout << "enter adress\n";
				std::getline(std::cin, input);
				temp.adress = input;
				bool flagSubLocal=true;
				while (flagSubLocal)
				{
					std::cout << "enter age\n";
					std::getline(std::cin, input);
					if (ageCheck(input))
					{
						flagSubLocal = false;
						temp.age = std::stoi(input.c_str());
					}
					else
					{
						std::cout << "no-no, enter age\n";
					}
					flag = false;
				}
			}
			else
			{
				std::cout <<"no-no, try again\n" ;
			}
		}

		//prs.resize(prs.size() + 1);
		prs.push_back(temp);
		std::cout << "pushed back\n";
}

int searchInfo(std::string input,std::function<bool(std::string input, std::vector<person> &prs)>callableobj, std::vector<person>&prs)
{
	for (int i = 0; i < prs.size(); i++)
	{
		if (callableobj(input,i,prs)) 
		{
			return i;
		}
	}
	std::cout << "data not found\n";

}

bool callableobjForPhoneNumber(std::string input, int  i,std::vector<person> &prs)
{
	
	return input == prs.at(i).phoneNumber;
}

bool callableobjForName(std::string input, int  i, std::vector<person> &prs)
{

	return input == prs.at(i).name;
}
bool callableobjForSurname(std::string input, int  i, std::vector<person> &prs)
{

	return input == prs.at(i).surname;
}

void printInterface()
{
	std::cout << "enter num for command\n"
		<< "1. Add client\n"
		<< "2. print info all\n";
}

bool checkPhoneNumber(std::vector<person>& prs, std::string input,int length)
{
	for (int i = 0; i < length; i++)//lenght = num of contacts
	{
			if (prs.at(i).phoneNumber == input)
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
	else if(input=="print info all")
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int cmdNumCheck(std::string input) 
{
	//int i = 0;
	if (input.length() == 1 && isdigit(input[0]))
	{
		//TODO: check by one num
		for (int i = 0; i <= avaliableComands; i++)	//const int avaliableComands in functions.h
		{
			int castedInput =std::atoi(input.c_str());
			if (castedInput == i)
			{
				return i;
			}
		}
	}

	return 0;
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

void printInfoAll(std::vector<person>& prs) {
	int width = 10;
	int length = prs.size();
	std::cout << "length =" << length<<"\n\n";

	std::cout<<std::setw(width) << "name\t"<<std::setw(width)
		<<"   surname\t" << std::setw(width) 
		<<"phone number\t" << std::setw(width)
		<< "    adress \t"<< std::setw(width)
		<<"       age\t\n";
	for (size_t i = 0; i < length; i++)
	{
		std::cout<< std::setw(width)<<  prs.at(i).name << "\t" <<
			std::setw(width) <<prs.at(i).surname << "\t" <<
			std::setw(width) << prs.at(i).phoneNumber << "\t" <<
			std::setw(width) << prs.at(i).adress << "\t" <<
			std::setw(width) << prs.at(i).age << "\t" <<
			std::endl;
			  
		
	}
}

void genContacts(std::vector<person>&prs)
{
	person temp;
	
	std::fstream fs;
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	while (fs.read((char*)&temp, sizeof(person)))
	{
		prs.push_back(temp);

	}
	fs.close();
}

void syncContacts(std::vector<person>& prs)
{
	std::fstream fs;
	fs.open(path , std::fstream::out);
	fs.clear();

	for (int i = 0; i < prs.size(); i ++ )
	{
		fs.write((char*)&prs.at(i), sizeof(person));
	}

	fs.close();

}

void testFillVector(std::vector<person>& prs)
{
	
	//prs.at(prs.size() - 1).name = "namam";
	prs.at(0).name = "namam";
	prs.at(0).surname = "surnamam";
	prs.at(0).phoneNumber = "=3231";
}

void deleteContact(std::vector<person> &prs)
{
	std::string input;
	person temp;
	size_t length = prs.size();
	std::cout << "enter phone number to delete\n";
	std::cin >> input;

	searchInfo(input, callableobjForPhoneNumber, prs);

	/*for (size_t i = 0; i < length; i++)
	{
		if (prs.at(i).phoneNumber == input)
		{
			prs.erase(prs.begin() + i);
		}
	}*/


}