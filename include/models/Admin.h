#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include "User.h"
#include "Motorbike.h"

class Admin
{
private:
    std::string username;
    std::string password;

public:
    /*Getter*/
    const std::string &getUsername();
    const std::string &getPassword();

    /*Others*/
    void viewAllMembers(const std::vector<User> &users);
    void viewAllMotorbikes(const std::vector<Motorbike> &motorbikes);
};

#endif