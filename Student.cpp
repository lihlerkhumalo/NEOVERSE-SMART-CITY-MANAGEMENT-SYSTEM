#include <iostream>
#include <fstream>
#include <algorithm>

#include "Student.h"

void StudentSystem::loadStudents(
    std::vector<Student>& students,
    std::string filename)
{
    std::ifstream file(filename);

    Student s;

    while (file >> s.id
                >> s.username
                >> s.password
                >> s.role)
    {
        students.push_back(s);
    }

    file.close();
}

bool StudentSystem::login(
    const std::vector<Student>& students)
{
    const int MAX_ATTEMPTS = 3;

    for (int attempt = 1;
         attempt <= MAX_ATTEMPTS;
         attempt++)
    {
        std::string username;
        std::string password;

        std::cout << "\n====== STUDENT LOGIN ======\n";

        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        auto it = std::find_if(
            students.begin(),
            students.end(),
            [&username, &password](const Student& s)
            {
                return s.username == username &&
                       s.password == password;
            });

        if (it != students.end())
        {
            std::cout << "\nLogin Successful!\n";
            return true;
        }

        std::cout << "\nInvalid Login Details.\n";
        std::cout << "Remaining Attempts: "
                  << MAX_ATTEMPTS - attempt
                  << "\n";
    }

    std::cout << "\nMaximum Attempts Reached.\n";

    return false;
}