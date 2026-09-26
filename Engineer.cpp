#include <iostream>
#include <fstream>
#include <algorithm>

#include "Engineer.h"

void AuthSystem::loadEngineers(
    std::vector<Engineer>& engineers,
    std::string filename)
{
    std::ifstream file(filename);

    Engineer e;

    while (file >> e.id
                >> e.username
                >> e.password
                >> e.role
                >> e.clearance)
    {
        engineers.push_back(e);
    }

    file.close();
}

bool AuthSystem::login(const std::vector<Engineer>& engineers)
{
    const int MAX_ATTEMPTS = 3;

    for (int attempts = 1; attempts <= MAX_ATTEMPTS; attempts++)
    {
        std::string username;
        std::string password;

        std::cout << "\nUsername: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        auto it = std::find_if(
    engineers.begin(),
    engineers.end(),
    [&username, &password](const Engineer& e)
    {
        return e.username == username &&
               e.password == password;
    });
        if (it != engineers.end())
        {
            std::cout << "\nLogin Successful!\n";
            return true;
        }

        std::cout << "\nInvalid username or password.\n";
        std::cout << "Attempts remaining: "
                  << MAX_ATTEMPTS - attempts
                  << "\n";
    }

    std::cout << "\nMaximum login attempts reached.\n";

    return false;
}