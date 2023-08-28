// #include "../../include/models/User.h"

// User::User(const std::string& username, const std::string& fullName)
//     : username(username), fullName(fullName), creditPoints(20) {}

// std::string User::getUsername() const {
//     return username;
// }

// std::string User::getFullName() const {
//     return fullName;
// }

// int User::getCreditPoints() const {
//     return creditPoints;
// }

#include "../../include/models/User.h"

User::User(const std::string& firstName, const std::string& lastName)
    : firstName(firstName), lastName(lastName), creditPoints(20) {}

std::string User::getFullName() const {
    return firstName + " " + lastName;
}

int User::getCreditPoints() const {
    return creditPoints;
}

