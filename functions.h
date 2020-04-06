#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <string>
#include <functional>

//TODO: add fx-s for adding client, removing, finding with std::functions + lambda
// search by name,surname and number at same time, sort by name or surname
//in fuctions add checks

const int avaliableComands = 2;

void addClient(person prs[], int contactPosNum, int numOfContacts);

void removeclient(std::string phoneNumber);

void printInfoByNumber(std::string);

void printInfoAll(person prs[],int numOfContacts  );

void searchInfo(std::string input);

void changeInfo(std::string phoneNumber);

void sortContacts(std::function<bool(std::string sortCondition)>condition);
                                            /*TODO: may be sorted by name or surname */
void printInterface();

bool checkPhoneNumber(person contacts[],std::string phoneNumber,int length);

int enteringCommand();

int cmdNumCheck(std::string input);

int cmdWordCheck(std::string input);

int getContactPos(person prs);// for adding client blanc

bool ageCheck(std::string input);

#endif