#ifndef USER_H
#define USER_H
#include<string>

#pragma once
using namespace std;

class User
{
public:
    string get_name() const; //Returning user's name
    long long get_id() const;        //Returning user's ID
    size_t get_age() const;     //Returning user's age

    void display_user() const; //Method that displays User's data name,ID,age

    User(string, long long, size_t); //3 args constructor initialization
    

private:
    string name; //User's name
    long long id;      //User's ID
    size_t age;     // User's age
};

#endif