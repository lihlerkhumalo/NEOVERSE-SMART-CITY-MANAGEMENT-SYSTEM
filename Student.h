#pragma once

#include <string>
#include <vector>

struct Student
{
    std::string id;
    std::string username;
    std::string password;
    std::string role;
};

class StudentSystem
{
public:
    static bool login(const std::vector<Student>& students);

    static void loadStudents(
        std::vector<Student>& students,
        std::string filename
    );
};