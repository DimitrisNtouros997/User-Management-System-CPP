#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include "User.h"

#pragma once

class DataBase
{
public:
    void add_user(); //Add user method
    void display_users() const; //Display user method
    void find_user() const; //Find user method
    void save_to_file(); //Add users to file
    void load_from_file(); //Load users from file

private:
    vector<User> users; //Vector of User objects
    int id_counter{0}; //Counter for the last 3 digits of ID
    const int id_base = 3212026; //ID standar base
};

#endif