#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <string>
#include <functional>

//TODO: add fx-s for adding client, removing, finding with std::functions + lambda
// search by name,surname and number at same time, sort by name or surname
//in fuctions add checks

void addClient(std::string name, std::string surname, std::string phoneNumber);

void removeclient(std::string phoneNumber);

void printInfoByNumber(std::string);

void printInfoAll(std::string  );

void searchInfo(std::string name, std::string surname, std::string phoneNumber);

void changeInfo(std::string phoneNumber);

void sortContacts(std::function<bool(std::string sortCondition)>condition);
                                            /*TODO: may be sorted by name or surname */


#endif