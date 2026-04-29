#include "DataBase.h"
#include <iostream>
#include <limits>
#include <iomanip>

void DataBase::add_user() // Add_user method
{

    string name{""}; // Variable to store the user's name
    size_t age{0};   // Variable to store the user's age, can't be negative

    cout << "\nEnter User name: ";
    getline(cin, name);

    cout << "\nEnter age: ";
    cin >> age;
    cin.ignore(); // Remove '\n' left by previous cin, clears the buffer

    long long id = static_cast<long long>(id_base) * 1000LL + id_counter; // ID creation
    id_counter++;
    puts(" ");

    User user(name, id, age); // User object
    users.push_back(user);    // Add the User object to vector
    cout << "\nUser added succesfully!" << endl;
}

void DataBase::display_users() const // Display users method
{
    if (users.empty()) // Check if the vector is empty
        cout << "\nList of Users is empty!" << endl
             << endl;
    else
    {
        for(const auto &i : users)
            i.display_user();
    }
}

void DataBase::find_user() const // Search user method
{
    string name_to_find{""};
    bool user_found{false};

    cout << "\nSearch User by name: ";
    getline(cin, name_to_find);

    for (auto &c : name_to_find)
        c = tolower(c); // Converts every character to lowercase

    for (const auto &i : users)
    {
        string stored_name = i.get_name();

        for (auto &c : stored_name)
            c = tolower(c); // Converts every character to lowercase

        if (name_to_find == stored_name) // If user was found
        {
            cout << "\nUser with name " << name_to_find << " found" << endl
                 << endl;
            cout << "ID: " << i.get_id() << " Age: " << i.get_age() << endl
                 << endl;

            user_found = true; // User found
            break;             // Exit the loop
        }
    }
    if (!user_found) // If user was not found
    {
        cout << "\nUser with name " << name_to_find << " not found" << endl
             << endl;
    }
}