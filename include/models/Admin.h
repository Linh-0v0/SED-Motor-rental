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
    const std::string &getUsername() const;
    const std::string &getPassword() const;

    /*Others*/
    void viewAllMembers(const std::vector<User> &users) const;
    void viewAllMotorbikes(const std::vector<Motorbike> &motorbikes) const;
};

#endif