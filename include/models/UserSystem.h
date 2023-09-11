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

    /*Update data*/
    void updateMotorbikeInFile(const Motorbike &updatedMotorbike);

    /*Others*/
    User registerUser(const std::string &username);
    bool checkAdmin(const std::string &inputUsername, const std::string &inputPassword);
    bool checkLogin(const std::string &username, const std::string &password);
    void logout();

    // Enable the motorbike for renting (require the owner to input the motorbike requirement)
    void listMotorbikeForRent(Motorbike &motorbike, double creditPointsConsumed, double minRequiredRenterRating, std::string city);
    // Disable the motorbike from renting
    void unlistMotorbikeForRent(Motorbike &motorbike);
    // Search Motorbikes available for a period of time
    std::vector<Motorbike> searchAvailableMotorbikes(
    std::vector<Motorbike>& motorbikes,
    std::string userStartTime,
    std::string userEndTime,
    std::string city,
    User& user
);
    
};

#endif
