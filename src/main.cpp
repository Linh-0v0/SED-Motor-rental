// #include <iostream>
// #include "include/models/User.h"

// int main() {
//     std::string username, fullName;

//     std::cout << "Welcome to the Motorbike Rental App!" << std::endl;
//     std::cout << "Please enter your username: ";
//     std::cin >> username;
//     std::cout << "Please enter your full name: ";
//     std::cin >> fullName;
//     std::cin.ignore(); // Clear newline character from buffer
//     std::getline(std::cin, fullName);

//     User newUser(username, fullName);

//     std::cout << "Registration successful!" << std::endl;
//     std::cout << "Hello, " << newUser.getFullName() << "! Your credit points: " << newUser.getCreditPoints() << std::endl;

//     return 0;
// }

#include <iostream>
#include "../include/models/User.h" 

int main() {
    member user("John", "Doe");
    std::cout << "Full Name: " << user.getFullName() << std::endl;
    std::cout << "Credit Points: " << user.getCreditPoints() << std::endl;
    return 0;
}
