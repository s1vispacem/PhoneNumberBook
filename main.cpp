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
	//prs.resize(1);

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
			syncContacts(prs);
			break;
		}
		case 2: // info print all
		{
			printInfoAll(prs);
		//	syncContacts(prs);
			break;
		}
		case 3:// deleting contact
		{
			deleteContact(prs);
			syncContacts(prs);
			break;
		}
		case 4: //modify contact
		{
			modifyContact(prs);
			syncContacts(prs);
		}
		case 5:
		{
			sortContacts(prs);//not working
			syncContacts(prs);
		}
		case 6:
		{
			searchContact(prs);
			syncContacts(prs);
		}
		default:
			break;
		}
		

    }
    return 0;
}