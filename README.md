# User Management System (C++)

This is a simple command-line application written in C++ for managing users.

## Features

- Add new users (name and age)
- Automatic ID generation for each user
- Display all users
- Search user by name (case-insensitive)
- Simple console-based menu

## Project Structure

- `User` class: stores user data (name, id, age)
- `DataBase` class: manages a list of users using a vector
- `main.cpp`: handles menu and user interaction

## Notes

- IDs are generated automatically using a base number and counter
- Search functionality ignores uppercase/lowercase differences
- Data is currently stored in memory (no file storage yet)

## Future Improvements

- Save and load users from file
- Delete user functionality
- Improved search (partial matching)
- Better UI formatting

## Requirements

- C++ compiler (g++, clang, or MSVC)

## Author
Dimitris Ntouros

Created as a personal learning project in C++
