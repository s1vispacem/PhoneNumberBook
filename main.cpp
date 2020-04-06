#include <iostream>
#include "person.h"
#include "functions.h"
#include <string>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
   
    bool flagGloball=true;
    //TODO: add calculating number of contacts by file
    int numOfContacts=1;
	int numCmd = 0;

	std::vector<person> prs;

	genContacts(prs);
	//if (argc > 1)
	if(argc>1)
	{
		prs.resize(2);
		testFillVector(prs);
	}
	
	
    while(flagGloball)
    {

		bool flag = true;		//flag for local while-s
		while (flag)
		{
			printInterface();
			numCmd = enteringCommand();
			if(numCmd!=0)
			{
				flag = false;
			}
		}

		switch (numCmd)
		{
		case 1: //adding client
		{		
			addClient(prs);
			std::cout << "test call function addClient\n";
			break;
		}
		case 2: //temp pos for info print all
		{
			printInfoAll(prs);
			break;
		}
		case 3:// deleting contact
		{
			break;
		}
		default:
			break;
		}
		

    }
    return 0;
}