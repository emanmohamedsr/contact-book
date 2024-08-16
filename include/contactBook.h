#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include "contact.h"
#include "phoneNumber.h"


class contactBook

{
public:
    contactBook(int);
    virtual ~contactBook();

    void addContact();
    void searchAcontact();
    void searchAcontactbyNumber();
    void searchAcontactbyFName();
    void searchAcontactbyLName();
    void searchAcontactbyCity();
    void DeleteAcontact();
    void EditAcontact();
    void Display_Contact()const;
    void sortBYFname();
    void sortBYLname();
    void sortBYCity();
    void sortBYAge();
    void FinalDisplay();

    void swapTwo(int a, int b);

private:
    int m_arrcontact_size;
    ///dynamic array of contacts
    contact* listOFcontacts;
    int m_contact_count;


};

#endif // CONTACTBOOK_H



