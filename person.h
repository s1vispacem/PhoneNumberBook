#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>


struct person
{
    std::string name="empty";    //temp default name
    std::string surname="empty";
    std::string adress="dadress";
    std::string phoneNumber="no number";
    int age=999;
};



#endif