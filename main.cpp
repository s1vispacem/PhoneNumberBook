#include <iostream>
#include "person.h"
#include "functions.h"
#include <string>


int main(int argc, char* argv[])
{
   // std::string input;     // will be using through entire program//denied
    bool flagGloball=true;
    //TODO: add calculating number of contacts by file
    int numOfContacts;


	int numCmd = 0;
    person* contact=new person[numOfContacts];
	
	FILE save;
	
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
			//int contactPos = getContactPos();
			int contactPos = 0;	// blanc=> add funcs and replace
			addClient(contact,contactPos, numOfContacts);
			std::cout << "test call function addClient\n";
			break;
		}
		case 2: //temp pos for info print all
		{
			printInfoAll(contact, numOfContacts);
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