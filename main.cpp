#include <iostream>
#include "person.h"
#include "functions.h"
#include <string>


int main(int argc, char* argv[])
{
   // std::string input;     // will be using through entire program//denied
    bool flagGloball=true;
    //TODO: add calculating number of contacts by file
    int numOfContacts=5;
	int numCmd = 0;
    person* contact=new person[numOfContacts];
	
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
			int contactPos = 5;	// blanc=> add funcs and replace
			addClient(contact,contactPos, numOfContacts);
			std::cout << "test call function addClient\n";
		}
		default:
			break;
		}
		

    }
    return 0;
}