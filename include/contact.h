#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include "phoneNumber.h"

using namespace std;

class contact
{
public:

    contact();
    virtual ~contact();
    ///add
    void Get_Contact();
    ///display
    void print_Contact();
    ///Edit
    void set_Fname(string fn);
    void set_Lname(string ln);
    void set_Email(string e);
    void set_city(string c);
    void set_age(int a);
    void set_gender(string g);
    ///search
    string get_Fname();
    string get_Lname();
    string get_City();
    int get_Age();


    bool get_numer(string);
    void EditPhone();
    void deletePhone();
    void add_newPhone(string, string);

protected:


private:
    string m_Fname;
    string m_Lname;
    int m_Age;
    string m_Gender;
    string m_City;
    string m_Email;
    phoneNumber* listOfPhones;
    int arrphone_size;
    int phone_count;
};

#endif // CONTACT_H

