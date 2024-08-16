#include <iostream>
#include <cstdlib>///system
#include <windows.h>///sleep
#include <string>
#include "contactBook.h"

using namespace std;
///color
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);


struct mainDesign
{
    static inline void print(string s, bool newline = true)
    {
        ///instead of cout
        cout << s << (newline ? "\n" : "\t");
    }

    static void p_sleep(int x = 3)
    {
        ///sleep counter
        for (int i = 0; i < x; i++)
        {
            cout << ".";
            Sleep(1000);
        }
        cout << endl;
    }

    static void line(char c, int y)
    {
        //separator
        SetConsoleTextAttribute(cout_handle, 14);
        for (int i = 0; i < y; i++)
            cout << c;
        cout << endl;
        SetConsoleTextAttribute(cout_handle, 15);
    }

    static void mainMenue()
    {

        system("cls");
        line('_', 35);
        print("\nContactBook \x03, Choose a service...");
        print("1) Add a new contact ");
        print("2) Edit a contact ");
        print("3) Delete a contact ");
        print("4) Search for a contact");
        print("5) Display all contacts");
        print("6) Exit ");
        print("your choice ->", false);

    }


};







int main()
{
    int c;
    contactBook c1(100);
    while (true)
    {
        mainDesign::mainMenue();
        cin >> c;
        mainDesign::line('_', 35);

        switch (c)
        {  
        case 1:    
           //add
           c1.addContact();
           system("pause");
           break;
        case 2:
           //edit
           c1.EditAcontact();
           system("pause");
           break;
        case 3:
           //Delete a contact
           c1.DeleteAcontact();
           system("pause");
           break;
        case 4:
           // Search for a contact
           c1.searchAcontact();
           system("pause");
           break;
        case 5:
           //Display all contacts
           c1.FinalDisplay();
           system("pause");
           break;
        case 6:
           //Exit
           mainDesign::print("Thanks \x03");
           return 0;
        default:
           cout << "   Invalid choice,Try again \n";
           system("pause");

        }
  
    }
    return 0;
}
