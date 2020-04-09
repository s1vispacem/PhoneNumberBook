#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <string>
#include <functional>
#include <vector>

//TODO: add fx-s for adding client, removing, finding with std::functions + lambda
// search by name,surname and number at same time, sort by name or surname
//in fuctions add checks

const int avaliableComands = 7;

void addClient(std::vector<person>& prs);

void deleteContact(std::vector<person> &prs);

void printInfoByNumber(std::string);

void printInfoAll(std::vector<person>& prs  );

int searchInfo(std::string input, std::function<bool(std::string input, std::vector<person> &prs)>callableobj, std::vector<person>&prs);

void changeInfo(std::string phoneNumber);

void sortContacts(std::function<bool(std::string sortCondition)>condition);
                                            /*TODO: may be sorted by name or surname */
void printInterface();

bool checkPhoneNumber(std::vector<person>&prs,std::string input);

int enteringCommand();

int cmdNumCheck(std::string input);

int cmdWordCheck(std::string input);

int getContactPos(person prs);// for adding client blanc

bool ageCheck(std::string input);

void genContacts(std::vector<person>&prsVec);

void testFillVector(std::vector<person>& prs);

void syncContacts(std::vector<person>& prs);

void deleteContact(std::vector<person> &prs);

void modifyContact(std::vector<person>&prs);

void searchContact(std::vector<person>& prs);

void sortContacts(std::vector<person>& prs);

void swap_prs(std::vector<person>& prs, int pos1, int pos2);

void sortByName(std::vector<person>&prs);

void sortBySurname(std::vector<person>&prs);

void printInfo(std::vector<person>&prs, int pos);

#endif//