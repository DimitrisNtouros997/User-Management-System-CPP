#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "User.h"
#include "DataBase.h"

using namespace std;

void display_menu() // Display menu function
{
    cout << setw(40) << "-------Main menu-----" << endl
         << endl;
    cout << setw(36) << "Add User, press A" << endl;
    cout << setw(37) << "Find User, press F" << endl;
    cout << setw(39) << "Delete User, press D" << endl;
    cout << setw(42) << "Load all Users, press L" << endl
         << endl;

    cout << setw(42) << "========================" << endl;
}

int main()
{

    display_menu();
    char choice;
    DataBase obj;

    do
    {
        cout << "\n\nPlease select an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 'a' || choice == 'A')
            obj.add_user();
        else if (choice == 'f' || choice == 'F')
            obj.find_user();
        else if (choice == 'l' || choice == 'L')
            obj.display_users();
        else if (choice == 'q' || choice == 'Q')
            break;
        else
            cout << "\nInvalid choice, please try again!" << endl;
    } while (choice != 'Q' && choice != 'q');

    return 0;
}