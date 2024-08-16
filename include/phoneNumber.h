#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <string>
#include <iostream>
using namespace std;

class phoneNumber
{
public:
    phoneNumber();
    ///add
    phoneNumber(string n, string t);
    virtual ~phoneNumber();

    ///search
    string getM_number();
    ///display
    void printPhones() const;

protected:

private:
    string m_number;
    string m_type;


};


#endif // PHONENUMBER_H
