#include "DataBase.h"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>

void DataBase::add_user() // Add_user method
{

    string name{""}; // Variable to store the user's name
    size_t age{0};   // Variable to store the user's age, can't be negative

    do
    {
        cout << "\nEnter User name : ";
        getline(cin, name);

        if (name.empty()) // If the user enters empty name
            cout << "\nName cannoot be empty, please try again." << endl;
    } while (name.empty());

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

void DataBase::save_to_file() // Save users to file method
{
    ofstream outfile{"Users.txt"}; // ofstream object to write into the file

    if (outfile)
    {
        for (const auto &i : users) // loop through existing vector
        {
            outfile << i.get_name() << ","
                    << i.get_id() << ","
                    << i.get_age() << endl;
        }
    }
    else
        cout << "\nError,τhe file could not be created!" << endl
             << endl;

    outfile.close(); // file closed
}

void DataBase::load_from_file() // Load users from file method
{
    ifstream infile{"Users.txt"}; // ifstream object to read from file

    if (infile.is_open())
    {
        users.clear(); // Clears the vector avoiding duplicate records
        string line;
        while (getline(infile, line))
        {
            stringstream ss(line); // converts a string to streamF
            string name;
            string id_str;
            string age_str;

            // Reading from ss untli finds ','
            getline(ss, name, ',');
            getline(ss, id_str, ',');
            getline(ss, age_str, ',');

            long long id = stoll(id_str); // used to convert the given string to integer value of type long int and long long
            int age = stoi(age_str);

            users.push_back(User(name, id, age)); // adds a User object to vector
        }
        infile.close();
    }

    else
    {
        cout << "\nError opening or finding the file!" << endl;
        id_counter = 0;
        return;
    }

    if (users.empty())
    {
        id_counter = 0;
        return;
    }

    long long max_id = users[0].get_id();

    for (const auto &i : users)
    {
        if (i.get_id() > max_id)
            max_id = i.get_id();
    }
    long long base_part = static_cast<long long>(id_base) * 1000LL;
    id_counter = static_cast<int>(max_id - base_part + 1);

    if (id_counter < 0)
        id_counter = 0;
}
void DataBase::display_users() const // Display users method
{
    if (users.empty()) // Check if the vector is empty
        cout << "\nList of Users is empty!" << endl
             << endl;
    else
    {
        for (const auto &i : users)
            i.display_user(); // All users displayed
    }
}

void DataBase::find_user() const // Search user method
{
    string name_to_find{""};

    cout << "\nSearch User by name: ";
    getline(cin, name_to_find);

    // Convert user input to lowercase
    for (auto &c : name_to_find)
        c = tolower(c);

    bool user_found{false};

    // Search directly inside the vector
    for (const auto &i : users)
    {
        string name_lower = i.get_name();

        // Convert stored name to lowercase
        for (auto &c : name_lower)
            c = tolower(c);

        if (name_lower == name_to_find)
        {
            string indent(8, ' ');

            cout << endl;
            cout << indent << "User found!" << endl
                 << endl;

            cout << indent << "Name: " << i.get_name() << endl;
            cout << indent << "ID: " << i.get_id() << endl;
            cout << indent << "Age: " << i.get_age() << endl
                 << endl;

            user_found = true;
            break;
        }
    }

    if (!user_found)
    {
        cout << "\nUser with name " << name_to_find
             << " not found" << endl
             << endl;
    }
}