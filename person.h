#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>


struct person
{
    std::string name="name";    //temp default name
    std::string surname="surname";
    std::string adress="adress";
    std::string phoneNumber="phone number";
    int age=999;
};



#endif