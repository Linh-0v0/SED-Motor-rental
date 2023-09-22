#include "../../include/models/Admin.h"

const std::string& Admin::getUsername() {
    return username;
}

const std::string& Admin::getPassword() {
    return password;
}

void Admin::viewAllMembers(const std::vector<User>& users) {
    // std::cout << "All Members:" << std::endl;
    // for (const User& user : users) {
    //     std::cout << "Username: " << user.getUsername() << ", Credit: " << user.getCredit() << ", Rating: " << user.getRating() << std::endl;
    // }
}

void Admin::viewAllMotorbikes(const std::vector<Motorbike>& motorbikes) {
    // std::cout << "All Motorbikes:" << std::endl;
    // for (const Motorbike& motorbike : motorbikes) {
    //     motorbike.viewDetails();
    // }
}