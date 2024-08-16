#include "phoneNumber.h"
#include <string>
#include <iostream>
using namespace std;

phoneNumber::phoneNumber()
{
    //ctor
}
string phoneNumber::getM_number()
{
    return m_number;
}

phoneNumber::phoneNumber(string n, string t) :m_number(n), m_type(t)
{

}
phoneNumber::~phoneNumber()
{
    //dtor
}

void phoneNumber::printPhones() const
{
    cout << "Phone: \t" << m_number << " ,\t" << m_type << endl;
}






