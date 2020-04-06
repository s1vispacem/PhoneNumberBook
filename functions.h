#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <string>
#include <functional>
#include <vector>

//TODO: add fx-s for adding client, removing, finding with std::functions + lambda
// search by name,surname and number at same time, sort by name or surname
//in fuctions add checks

const int avaliableComands = 2;

void addClient(std::vector<person>& prs);

void removeclient(std::string phoneNumber);

void printInfoByNumber(std::string);

void printInfoAll(std::vector<person>& prs  );

void searchInfo(std::string input, int * contactNum, std::function<bool(std::string input, int * contactNum, std::vector<person> &prs)>callableobj);

void changeInfo(std::string phoneNumber);

void sortContacts(std::function<bool(std::string sortCondition)>condition);
                                            /*TODO: may be sorted by name or surname */
void printInterface();

bool checkPhoneNumber(std::vector<person>&prs,std::string phoneNumber,int length);

int enteringCommand();

int cmdNumCheck(std::string input);

int cmdWordCheck(std::string input);

int getContactPos(person prs);// for adding client blanc

bool ageCheck(std::string input);

void genContacts(std::vector<person>&prsVec);

void testFillVector(std::vector<person>& prs);

#endif