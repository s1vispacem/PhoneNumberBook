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
			if (prs.size() > 0)
			{
				printInfoAll(prs);
				syncContacts(prs);
			}
			else
			{
				std::cout << "nothing to print\n";
			}
			break;
		}
		case 3:// deleting contact
		{
			if (prs.size() > 0)
			{
				deleteContact(prs);
				syncContacts(prs);
			}
			else
			{
				std::cout << "nothing to delete\n";
			}
			break;
		}
		case 4: //modify contact
		{
			if (prs.size() > 0)
			{
				modifyContact(prs);
				syncContacts(prs);
			}
			else
			{
				std::cout << "nothing to modify\n";
			}
			break;
		}
		case 5://sortin by name or surname
		{
			if (prs.size() > 0)
			{
				sortContacts(prs);
				syncContacts(prs);
			}
			else
			{
				std::cout << "nothing to sort\n";
			}
			break;
		}
		case 6:
		{	if (prs.size() > 0)
			{ 
			searchContact(prs);//not working as planned
			syncContacts(prs);
			}
		else
		{
			std::cout << "nothing to print\n";
		}
			break;
		}
		case 7:
		{
			std::cout << "see you later\n";
			flagGloball = false;
		}
		default:
			break;
		}
		

    }
    return 0;
}