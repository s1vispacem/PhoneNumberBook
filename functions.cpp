#include <string>
#include <functional>
#include "person.h"
#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

static const std::string path = "DB.txt";
const std::string extraInfoPath="eip.txt";

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
			int length = prs.size();
			if (checkPhoneNumber(prs,input))
			{
				temp.phoneNumber = input;
				flag=false;
			}
			else 
			{
				std::cout << "number already has been taken\n";
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

// try of making unificated func for search info, which will be using in checking phoneNumber, searching contact, deleting, sorting, modifying
int searchInfo(std::string input,std::function<bool(std::string input, std::vector<person> &prs)>callableobj, std::vector<person>&prs)
{
	for (int i = 0; i < prs.size(); i++)
	{
		if (callableobj) 
		{
			return i;//returns pos in vector for prs.at(i).*;
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
		<< "2. print info all\n"
		<<"3. delete contact\n"
		<<"4. modify contact\n"
		<<"5. sort contacts\n"
		<<"6. search contact\n"
		<<"7. exit\n";
}

bool checkPhoneNumber(std::vector<person>& prs, std::string input)
{
	for (int i = 0; i < prs.size(); i++)//lenght = num of contacts
	{
			if (prs.at(i).phoneNumber == input)
			{
				return true;
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
	else if (input == "delete contact")
	{
		return 3;
	}
	else if (input == "modify contact")
	{
		return 4;
	}
	else if (input == "sort contacts")
	{
		return 5;
	}
	else if (input == "search contact")
	{
		return 6;
	}
	else if (input == "exit")
	{
		return 7;
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

void genContacts(std::vector<person>&prs)//fix genering contacts from file
{
	person temp;
	int amountOfRecs;
	std::fstream fs;
	fs.open(extraInfoPath, std::fstream::in);
	fs.read((char*)&amountOfRecs, sizeof(int));
	fs.close();
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
	/*while (fs.read((char*)&temp, sizeof(person)) && !fs.bad() &&!fs.eof() && !fs.fail())
	{
		prs.push_back(temp);
	}*/
	for (int i = 0; i < amountOfRecs; i++)
	{
		fs.read((char*)&temp, sizeof(person));
		prs.push_back(temp);
	}

	fs.close();
}

void syncContacts(std::vector<person>& prs)// fix sync with file
{

	std::fstream fs;
	fs.open(extraInfoPath, std::fstream::out);
	int amount = prs.size();
	fs.write((char*)&amount, sizeof(int));
	fs.close();

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
	bool flagDel = true;
	
	
		std::cout << "enter phone number to delete\n(type out to exit deleting)\n";
		std::cin >> input;
		if (input == "out")
		{
			std::cout << "okke\n";
			flagDel = false;
			
		}
		 if (checkPhoneNumber(prs, input))
		{

			for (size_t i = 0; i < length; i++)
			{
				if (prs.at(i).phoneNumber == input)
				{
					prs.erase(prs.begin() + i);
					flagDel = false;
					break;
				}
			}
		}
		else
		{
			std::cout << "phone not found\n";
		}
}
	//int pos =searchInfo(input, callableobjForPhoneNumber, prs);


void modifyContact(std::vector<person>&prs)
{
	std::string input;
	size_t length = prs.size();
	int pos;
	bool flagCheck = false;
	bool flag = true;
	while (flag)
	{
		std::cout << "enter phone number to modify contact\n";
		std::cin >> input;

		for (size_t i = 0; i < length; i++)
		{
			if (prs.at(i).phoneNumber == input)
			{
				pos = i;
				flagCheck = true;
				break;
			}

		}
		if (flagCheck)
		{
			flag = false;
		}
		else
		{
			std::cout << "phone number not found\n try again\n";
		}
	}
	flag = true;
	while (flag)
	{
		std::cout << "enter num to modify:\n"
			<< "1 to change name\n "
			<< "2 to change surname\n "
			<< "3 to change adress\n "
			<< "4 to change phone number\n "
			<< "5 to change age\n "
			<< "0 to exit\n";
		std::cin >> input;
		int num = std::stoi(input);
		if (num == 1)
		{
			std::cout << "enter new name\n";
			std::cin >> input;
			prs.at(pos).name = input;

		}
		else if (num == 2)
		{

			std::cout << "enter new surname\n";
			std::cin >> input;
			prs.at(pos).surname = input;
		}
		else if (num == 3)
		{

			std::cout << "enter new adress\n";
			std::cin >> input;
			prs.at(pos).adress = input;
		}
		else if (num == 4)
		{
			flag = true;
			while (flag)
			{
				std::cout << "enter new phone number\n";
				std::cin >> input;
				if (checkPhoneNumber(prs, input))
				{
					prs.at(pos).phoneNumber = input;
					flag = false;
				}
				else
				{
					std::cout << "this phone number already taken\n";
				}
			}
		}
		else if (num == 5)
		{
			flag = true;
			while (flag)
			{
				std::cout << "enter age\n";
				std::cin >> input;
				if (ageCheck(input))
				{
					prs.at(pos).age = std::stoi(input);
					flag = false;
				}
				else
				{
					std::cout << "error: bad data\n try again\n";
				}

			}

		}
		else if (num == 0)
		{
			std::cout << "decline called\n exiting\n";
		}
		else
		{
			std::cout << "bad data input\n try again\n";
		}


	}
}

void searchContact(std::vector<person>&prs)
{
	bool flag = true;
	std::string input;
	size_t length = prs.size();
	while (flag)
	{
		std::cout << "enter name, surname or adress\n";
		std::cin >> input;

		for (size_t i = 0; i < length; i++)
		{
			if (prs.at(i).name == input)
			{
				printInfo(prs, i);
			}
			if (prs.at(i).surname == input)
			{
				printInfo(prs, i);
			}
			if (prs.at(i).adress == input)
			{
				printInfo(prs, i);
			}
		}

		while (1) {
			std::cout << "repeat search ? \n ( y / n)\n";
			std::cin >> input;
			if (input == "y")
			{
				std::cout << "okke\n";
				break;
			}
			else if (input == "n")
			{
				flag = false;
				break;
			}
			else
			{
				std::cout << "try again\n";
			}
		}

	}
}

void printInfo(std::vector<person>&prs, int pos)
{
	std::cout << "name:" << prs.at(pos).name<<std::endl
		<< "surname:" << prs.at(pos).surname << std::endl
		<< "adress:" << prs.at(pos).adress << std::endl
		<< "phone number:" << prs.at(pos).phoneNumber << std::endl
		<< "age:" << prs.at(pos).age << std::endl;
}

void sortContacts(std::vector<person>&prs)
{
	bool flag = true;
	std::string input;
	int num;
	while (flag)
	{
		std::cout << "choose how to sort contacts\n"
			<<"1 to sort by name\n"
			<<"2 to sort by surname\n";
		std::cin >> input;
		num = std::stoi(input);
		if (num == 1)
		{
			sortByName(prs);
			flag = false;
			std::cout << "sorted\n";
		}
		else if (num == 2)
		{
			sortBySurname(prs);
			flag = false;
			std::cout << "sorted\n";
		}
		else
		{
			std::cout << "no-no, try again\n";
		}
	}
}

void swap_prs(std::vector<person>&prs,int pos1, int pos2)
{
	person temp;

	temp = prs.at(pos1);
	prs.at(pos1) = prs.at(pos2);
	prs.at(pos2) = temp;
}
void sortByName(std::vector<person>&prs) //question: how to unificate sort func for using with name and surname
{
	size_t length = prs.size();
	bool b = true;
	
	int beg = -1;

	int end = prs.size() - 1;
	while (b)
	{
		b = false;
		beg++;
		for (size_t i = beg; i < end; i++)
		{
			if (prs.at(i).name[0] > prs.at(i + 1).name[0])
			//if(callobjsortname(prs.at(i).name[0],prs.at(i + 1).name[0]))// doesnt make much sense
			{
				swap_prs(prs, i, i + 1);
				b = true;
			}
		}
		if(!b)
		{
			break;
		}
		end--;
		for (size_t i = end; i > beg; i--)
		{
			if (prs.at(i).name[0] < prs.at(i - 1).name[0])
			{
				swap_prs(prs, i, i + 1);
				b = true;
			}
		}
	}
}

void sortBySurname(std::vector<person>&prs) //question: how to unificate sort func for using with name and surname
{
	size_t length = prs.size();
	bool b = true;
	//person beg=prs.at(0);
	int beg = -1;
	//person end = prs.at(prs.size()-1);
	int end = prs.size() - 1;
	while (b)
	{
		b = false;
		beg++;
		for (size_t i = beg; i < end; i++)
		{
			if (prs.at(i).surname[0] > prs.at(i + 1).surname[0])
				//if(callobjsortname(prs.at(i).name[0],prs.at(i + 1).name[0]))// doesnt make much sense
			{
				swap_prs(prs, i, i + 1);
				b = true;
			}
		}
		if (!b)
		{
			break;
		}
		end--;
		for (size_t i = end; i > beg; i--)
		{
			if (prs.at(i).surname[0] < prs.at(i - 1).surname[0])
			{
				swap_prs(prs, i, i + 1);
				b = true;
			}
		}
	}
}

