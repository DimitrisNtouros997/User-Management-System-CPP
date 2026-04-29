#include "User.h"
#include <iostream>

User::User(string name, long long id, size_t age) // 3 args Constructor implimantation
    : name(name), id(id), age(age)
{}

string User::get_name() const { return name; } // Returning user's name
long long User::get_id() const { return id; }  // Returning user's ID
int User::get_age() const { return age; }      // Returning user's age

void User::display_user() const // Display user method
{
    string indent(8, ' ');

    cout << "----------------------------" << endl;
    cout << indent << "USER INFO" << endl;
    cout << "----------------------------" << endl;

    cout << indent << "Name: " << name << endl;
    cout << indent << "ID: " << id << endl;
    cout << indent << "Age: " << age << endl;

    cout << endl;
}