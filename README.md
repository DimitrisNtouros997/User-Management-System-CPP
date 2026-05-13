# User Management System (C++) - v1.0

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

# User Management System (C++) – v2.0


## Key Features

- **Add users** – Provide name and age; ID is generated automatically.
- **Find users** – Case‑insensitive search by name (searches in currently loaded users).
- **Display all users** – Shows the list of users currently in memory.
- **Automatic file storage** – Users are saved to `Users.txt` immediately after each addition.
- **Load on startup** – Existing users are loaded from `Users.txt` when the program starts.
- **Input validation** – Prevents empty names.
- **ID continuation** – After loading, new IDs continue from the last stored ID.

## How ID Generation Works

- Base number: `3212026` (stored as `id_base`)
- 3‑digit counter (`id_counter`), starting from 0
- Final ID = `id_base * 1000 + id_counter`
- Example: first user → `3212026000`, second → `3212026001`, etc.
- When loading from file, the counter is set to `(max_existing_id - id_base*1000) + 1`, so new users get the next available ID.


## Requirements

- C++ compiler (g++, clang, or MSVC)

## Author
Dimitris Ntouros

Created as a personal learning project in C++
