/* Manage the whole system */
#ifndef USERSYSTEM_H
#define USERSYSTEM_H

#include <vector>
#include <string>
#include <map>
#include "Admin.h"
#include "User.h"
#include "Motorbike.h"

class UserSystem
{
private:
    std::vector<User> users;
    std::vector<Motorbike> motorbikes;

    Admin loggedInAdmin;
    User loggedInUser;

public:
    UserSystem();

    /*Getter*/
    std::vector<User> &getUsers();
    std::vector<Motorbike> &getMotorbikes();
    std::map<std::string, User> &getUserMap();
    const Admin &getAdmin();
    const User &getLoggedInUser();

    /*Setter*/

    /*Import-Add Data*/
    bool importUsers();
    bool importMotorbikes();
    // Add new user to System
    void addUser(const User &user);
    // Add new motorbike to System
    void addMotorbike(const Motorbike &motorbike);

    /*Others*/
    User registerUser(const std::string &username);
    bool checkAdmin(const std::string &inputUsername, const std::string &inputPassword);
    bool checkLogin(const std::string &username, const std::string &password);
    void logout();
};

#endif
