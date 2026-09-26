#pragma once

#include <string>
#include <vector>

struct Engineer
{
    std::string id;
    std::string username;
    std::string password;
    std::string role;
    std::string clearance;
};

class AuthSystem
{
public:
    static bool login(const std::vector<Engineer>& engineers);

    static void loadEngineers(
        std::vector<Engineer>& engineers,
        std::string filename
    );
};