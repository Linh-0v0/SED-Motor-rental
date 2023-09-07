#include "../../include/models/Admin.h"

const std::string& Admin::getUsername() const {
    return username;
}

const std::string& Admin::getPassword() const {
    return password;
}

void Admin::viewAllMembers(const std::vector<User>& users) const {
    // std::cout << "All Members:" << std::endl;
    // for (const User& user : users) {
    //     std::cout << "Username: " << user.getUsername() << ", Credit: " << user.getCredit() << ", Rating: " << user.getRating() << std::endl;
    // }
}

void Admin::viewAllMotorbikes(const std::vector<Motorbike>& motorbikes) const {
    // std::cout << "All Motorbikes:" << std::endl;
    // for (const Motorbike& motorbike : motorbikes) {
    //     motorbike.viewDetails();
    // }
}