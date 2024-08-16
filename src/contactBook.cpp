#include "contactBook.h"
#include "contact.h"
#include "phoneNumber.h"
#include <string>

contactBook::contactBook(int ContanctSize = 100)
{
    m_arrcontact_size = ContanctSize;
    listOFcontacts = new contact[m_arrcontact_size];
    m_contact_count = 0;
}
contactBook::~contactBook()
{
    delete[] listOFcontacts;
}





void contactBook::addContact()
{
    if (m_contact_count < m_arrcontact_size)
    {
        ///pointer to get object of contacts
        contact* ptr_newContact = new contact();
        ptr_newContact->Get_Contact();
        listOFcontacts[m_contact_count++] = *ptr_newContact;
    }
    else
        cout << "Sorry you can\'t add any more.";

}

void contactBook::EditAcontact()
{
    if (m_contact_count == 0)
    {
        cout << "There are no contacts yet \n";
        return;
    }

    string n1, n2;
    int ch;
    cout << "Enter first name to edit a contact : ";
    cin >> n1 ;
    bool is = false;
    for (int i = 0; i < m_contact_count; i++)
    {
        if (listOFcontacts[i].get_Fname() == n1 )
        {
            is = true;
            cout << "Some Options : \n"
                << "1)Edit first name \n"
                << "2)Edit last name \n"
                << "3)Edit city  \n"
                << "4)Edit age  \n"
                << "5)Edit gender \n"
                << "6)Edit from number list \n"
                << "Your choice -> ";
            cin >> ch;
            string fname, lname, city, gender;
            int age;
            switch (ch)
            {
            case 1:
                cout << "Enter new first name : ";
                cin >> fname;
                listOFcontacts[i].set_Fname(fname);
                break;
            case 2:
                cout << "Enter new last name : ";
                cin >> lname;
                listOFcontacts[i].set_Lname(lname);
                break;
            case 3:
                cout << "Enter new city : ";
                cin >> city;
                listOFcontacts[i].set_city(city);
                break;
            case 4:
                cout << "Enter new age : ";
                cin >> age;
                listOFcontacts[i].set_age(age);
                break;
            case 5:
                cout << "Enter new gender : ";
                cin >> gender;
                listOFcontacts[i].set_gender(gender);
                break;
            case 6:
                listOFcontacts[i].EditPhone();
                break;
            default:
                cout << "Oops,invalid choice\n";
            }
            break;
        }
        else
            is = false;
    }
    if (is == false)
    {
        cout << "Search failed, Maybe you misspelled the name\n";
    }

}

void contactBook::DeleteAcontact()
{

    if (m_contact_count == 0)
    {
        ///check if there is any elements
        cout << "There are no any contacts yet \n";
        return;
    }
    string n1, n2;
    cout << "Enter first name to delete : ";
    cin >> n1 ;
    bool is = false;
    for (int i = 0; i < m_contact_count; i++)
    {
        ///for loop ->to search and get index
        if (listOFcontacts[i].get_Fname() == n1 )
        {
            is = true;
            ///if element is already at the end of array
            ///just reduce size to erase
            if (i == m_contact_count - 1)
                m_contact_count--;
            else
            {
                ///erased one->initialize it with the last element &reduce size
                listOFcontacts[i] = listOFcontacts[m_contact_count - 1];
                m_contact_count--;
            }
            break;
        }
        else
            is = false;
    }
    if (is)
        cout << "Name has been deleted successfully\n";
    else
        cout << "delete failed, Maybe you misspelled the name\n";

}





void contactBook::searchAcontactbyNumber()
{
    if (m_contact_count == 0)
        cout << "There are no contacts yet \n";
    else
    {
        bool is = false;
        string num;
        cout << "Enter number to search : ";
        cin >> num;
        for (int i = 0; i < m_contact_count; i++)
        {
            if (listOFcontacts[i].get_numer(num))
            {
                is = true;
                cout << "number has been found successfully \n";
                break;
            }
        }
        if (is == false)
            cout << "Search failed, Maybe you misspelled the name\n";
    }
}

void contactBook::searchAcontactbyFName()
{
    if (m_contact_count == 0)
        cout << "There are no contacts yet \n";
    else
    {
        string n1;
        cout << "Enter first name to search : ";
        cin >> n1;
        bool is = false;
        for (int i = 0; i < m_contact_count; i++)
        {
            if (listOFcontacts[i].get_Fname() == n1)
            {
                is = true;
                cout << "Name has been found successfully\n";
                break;
            }
        }
        if (is == false)
            cout << "Search failed, Maybe you misspelled the name\n";
    }

}


void contactBook::searchAcontactbyLName()
{
    if (m_contact_count == 0)
        cout << "There are no contacts yet \n";
    else
    {
        string n2;
        cout << "Enter last name to search : ";
        cin >> n2;
        bool is = false;
        for (int i = 0; i < m_contact_count; i++)
        {
            if (listOFcontacts[i].get_Lname() == n2)
            {
                is = true;
                cout << "Name has been found successfully\n";
                break;
            }
        }
        if (is == false)
            cout << "Search failed, Maybe you misspelled the name\n";
    }

}

void contactBook::searchAcontactbyCity()
{
    if (m_contact_count == 0)
    {
        cout << "There are no contacts yet \n";
        return;
    }
    string city;
    cout << "Enter City to search : ";
    cin >> city;
    if (m_contact_count == 1 && listOFcontacts[0].get_City() == city)
    {
        cout << "found successfully ( 1 ) contact from " << city << endl;
        return;
    }
    int index = 0;
    int Count = 0;
    bool is = false;
    do
    {
        for (int j = index; j < m_contact_count; j++)
        {
            if (listOFcontacts[j].get_City() == city)
            {
                is = true;
                Count++;
                index = j + 1;///j is already acceptable [infinite loop]
                break;
            }
            else
                is = false;
        }

    } while (is && index < m_contact_count);

    if (is)
    {
        cout << "found successfully ( " << Count << " ) contacts from " << city << endl;
    }
    else
        cout << "Search failed, Maybe you misspelled the City\n";

}

void contactBook::searchAcontact()
{
    int n;
    cout << "Some Options : \n"
        << "1) Search for contact by first name \n"
        << "2) Search for contact by last name \n"
        << "3) Search for contact by phone number \n"
        << "4) search for contact by City \n";
    cin >> n;
    switch (n)
    {
    case 1:
        searchAcontactbyFName();
        break;
    case 2:
        searchAcontactbyLName();
        break;
    case 3:
        searchAcontactbyNumber();
        break;
    case 4:
        searchAcontactbyCity();
        break;
    default:
        cout << "Invalid choice \n";
    }

}






void contactBook::Display_Contact() const
{

    if (m_contact_count == 0)
    {
        cout << "There are no contacts yet \n";
    }
    else
    {
        for (int i = 0; i < m_contact_count; i++)
        {
            cout << endl;
            cout << "[" << i + 1 << "]*******************************\n";
            listOFcontacts[i].print_Contact();
        }
    }

}

void contactBook::swapTwo(int a, int b)
{
    contact x = listOFcontacts[a];
    listOFcontacts[a] = listOFcontacts[b];
    listOFcontacts[b] = x;
}

void contactBook::sortBYFname()
{
    if (m_contact_count == 2 && listOFcontacts[0].get_Fname().at(0) > listOFcontacts[1].get_Fname().at(0))
    {
        swapTwo(0, 1);
        Display_Contact();
        return;
    }
    for (int j = 0; j < m_contact_count - 1; j++)
    {
        for (int i = 0; i < m_contact_count - 1; i++)
        {
            if (listOFcontacts[i].get_Fname().at(0) > listOFcontacts[i + 1].get_Fname().at(0))
                swapTwo(i, i + 1);
            else
                continue;
        
        }

    }
    Display_Contact();
}


void contactBook::sortBYLname()
{
    if (m_contact_count == 2 && listOFcontacts[0].get_Lname().at(0) > listOFcontacts[1].get_Lname().at(0))
    {
        swapTwo(0, 1);
        Display_Contact();
        return;
    }
    for (int j = 0; j < m_contact_count - 1; j++)
    {
        for (int i = 0; i < m_contact_count - 1; i++)
        {
            if (listOFcontacts[i].get_Lname().at(0) > listOFcontacts[i + 1].get_Lname().at(0))
                swapTwo(i, i + 1);
            else
                continue;
        }

    }
    Display_Contact();
}


void contactBook::sortBYCity()
{
    if (m_contact_count == 2 && listOFcontacts[0].get_City().at(0) > listOFcontacts[1].get_City().at(0))
    {
        swapTwo(0, 1);
        Display_Contact();
        return;
    }
    for (int j = 0; j < m_contact_count - 1; j++)
    {
        for (int i = 0; i < m_contact_count - 1; i++)
        {
            if (listOFcontacts[i].get_City().at(0) > listOFcontacts[i + 1].get_City().at(0))
                swapTwo(i, i + 1);
            else
                continue;
        }

    }
    Display_Contact();
}


void contactBook::sortBYAge()
{
    if (m_contact_count == 2 && listOFcontacts[0].get_Age() > listOFcontacts[1].get_Age())
    {
        swapTwo(0, 1);
        Display_Contact();
        return;
    }
    for (int j = 0; j < m_contact_count - 1; j++)
    {
        for (int i = 0; i < m_contact_count - 1; i++)
        {
            if (listOFcontacts[i].get_Age() > listOFcontacts[i + 1].get_Age())
                swapTwo(i, i + 1);
            else
                continue;
        }

    }
    Display_Contact();
}


void contactBook::FinalDisplay()
{
    int n;
    cout << "Some Options : \n"
        << "1) Display in order of first names \n"
        << "2) Display in order of last names \n"
        << "3) Display in order of Cities \n"
        << "4) Display in order of Ages \n";
    cin >> n;
    switch (n)
    {
    case 1:
        sortBYFname();
        break;
    case 2:
        sortBYLname();
        break;
    case 3:
        sortBYCity();
        break;
    case 4:
        sortBYAge();
        break;
    default:
        cout << "Invalid choice ";
    }

}



