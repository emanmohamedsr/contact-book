#include "contact.h"
#include <string>
#include <iostream>
using namespace std;
#include "phoneNumber.h"
contact::contact()
{
    arrphone_size = 5;
    listOfPhones = new phoneNumber[arrphone_size];
    phone_count = 0;
}
contact::~contact()
{
    delete[] listOfPhones;
}


void contact::set_Fname(string fn)
{
    m_Fname = fn;
}
void contact::set_Lname(string ln)
{
    m_Lname = ln;
}
void contact::set_Email(string e)
{
    m_Email = e;
}
void contact::set_city(string c)
{
    m_City = c;
}
void contact::set_age(int a)
{
    m_Age = a;
}
void contact::set_gender(string g)
{
    m_Gender = g;
}



string contact::get_Fname()
{
    return m_Fname;
}
string contact::get_Lname()
{
    return m_Lname;
}
int contact::get_Age()
{
    return m_Age;
}

string contact::get_City()
{
    return m_City;
}

bool contact::get_numer(string number)
{
    bool is = false;
    for (int i = 0; i < phone_count; i++) {
        if (number == listOfPhones[i].getM_number()) {
            is = true;
            break;
        }
        else
            is = false;
    }
    if (is)
        return true;
    else
        return false;

}




void contact::EditPhone()
{
    if (phone_count == 0)
    {
        cout << "There are no contacts yet \n";
        return;
    }
    string n;
    bool isExist = false;
    cout << "Enter a number to edit : ";
    cin >> n;
    ///search
    for (int i = 0; i < phone_count; i++)
    {
        if (listOfPhones[i].getM_number() == n)
        {
            isExist = true;
            ///get index of wanted number=i
            string n, t;
            cout << "Enter new number : ";
            cin >> n;
            cout << "new type : ";
            cin >> t;
            listOfPhones[i] = phoneNumber(n, t);
            cout << "Edited successfully " << endl;
            return;
        }
        else
            isExist = false;
    }
    if (isExist == false)
    {
        cout << "Edit failed, Maybe you misspelled the number" << endl;
    }

}

void contact::deletePhone()
{
    string n;
    bool isExist = false;
    cout << "Enter a number to delete : ";
    cin >> n;
    ///search
    for (int i = 0; i < phone_count; i++)
    {
        ///for loop->search
        if (listOfPhones[i].getM_number() == n)
        {
            isExist = true;
            ///get index of wanted number==i
            if (i == phone_count - 1)
                phone_count--;
            else
            {
                listOfPhones[i] = listOfPhones[phone_count - 1];
                phone_count--;
            }
            break;
        }
        else
            isExist = false;
    }
    if (isExist)
        cout << "Deleted successfully " << endl;
    else
        cout << "Delete failed, Maybe you misspelled the number" << endl;
}

void contact::add_newPhone(string n, string t)
{
    if (phone_count < arrphone_size)
    {
        phoneNumber* ptr_phone = new phoneNumber(n, t);
        listOfPhones[phone_count++] = *ptr_phone;
    }
    else
        cout << "Sorry can\'t add any more.";
}

void contact::Get_Contact()
{
    cout << "1-Enter first name : "; cin >> m_Fname;
    cout << "2-last name : "; cin >> m_Lname;
    cout << "3-Email : ";                  cin >> m_Email;
    do
    {
        cout << "4-Age : ";
        cin >> m_Age;
    } while (m_Age <= 0);

    cout << "5-Gender : ";                 cin >> m_Gender;
    cout << "6-City : ";                   cin >> m_City;
    int n;
    do
    {
        cout << "7-how many phone numbers (0:" << arrphone_size << ") : ";
        cin >> n;
    } while (n > arrphone_size);

    for (int i = 0; i < n; i++)
    {
        string n, t;
        cout << "Enter phone & type : ";
        cin >> n >> t;
        add_newPhone(n, t);

    }
    cout << "\nContact Added Successfully\n";

}




void contact::print_Contact()
{
    cout << "First Name: " << m_Fname
        << "\tLast Name : " << m_Lname
        << "\tEmail: " << m_Email
        << "\tAge: " << m_Age
        << "\tGender: " << m_Gender
        << "\tCity: " << m_City << endl;
    cout << "List of phones : " << endl;
    if (phone_count > 0)
    {
        for (int i = 0; i < phone_count; i++)
        {
            cout << i + 1 << ")  ";
            listOfPhones[i].printPhones();
        }
    }
}





