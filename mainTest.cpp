#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "include/models/UserSystem.h"
using namespace std;

int main()
{
    /***** Import Data*****/
    cout << "Start Reading." << std::endl;
    UserSystem userSystem;
    Admin loggedInAdmin;
    User loggedInUser;
    // Load user data from a text file
    if (userSystem.importUsers())
    {
        std::cout << "User data loaded successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error loading user data." << std::endl;
        return 1; // Exit with an error code
    }
    // Access the users vector
    std::vector<User> &users = userSystem.getUsers();
    // for (const User &user : users)
    // {
    //     // Access user attributes, e.g., user.getUsername(), user.getFullName(), etc.
    //     std::cout << user << endl;
    // }

    /******/
    // Load motorbike data from a text file
    if (userSystem.importMotorbikes())
    {
        std::cout << "Motorbike data loaded successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error loading motorbike data." << std::endl;
        return 1; // Exit with an error code
    }
    // Access the users vector
    std::vector<Motorbike> &motorbikes = userSystem.getMotorbikes();
    // Add the Motorbike to corresponding User
    for (const Motorbike &motorbike : motorbikes)
    {
        for (User &user : users)
        {
            if (user.getUsername() == motorbike.getOwnerUsername())
            {
                // Add the Motorbike to the User's list of motorbikes
                user.addMotorbikeToUser(motorbike);
                break; // Stop searching for the User once found
            }
        }
    }
    for (const User &user : users)
    {
        for (const Motorbike &motorbike : user.getAvailableMotorbikes())
        {
            cout << motorbike << endl;
        }
    }

    // Access userMap and perform operations on it
    // std::map<std::string, User>& userMap = userSystem.getUserMap();
    // for (const auto &pair : userMap)
    // {
    //     const std::string &username = pair.first;
    //     const User &user = pair.second;

    //     cout << "User Info: " << username << endl;
    //     cout << user << endl;
    // }

    // /**** Login ****/
    // std::string username, password;
    // // Prompt the user for username and password
    // std::cout << "Enter your username:";
    // std::getline(cin, username);
    // std::cout << "Enter your password:";
    // std::getline(cin, password);

    // if (userSystem.checkAdmin(username, password))
    // {
    //     loggedInAdmin = userSystem.getAdmin();
    //     std::cout << "Welcome admin " << loggedInAdmin.getUsername() << "."
    //               << "\n";
    // }
    // else
    // {
    //     // // Check if the entered credentials are valid
    //     if (userSystem.checkLogin(username, password))
    //     {
    //         loggedInUser = userSystem.getLoggedInUser();
    //         std::cout << "Login successful. Welcome, " << loggedInUser.getFullName() << "!\n";

    //         // Return User's Info
    //         cout << endl;
    //         cout << "**** USER'S INFO ****" << endl;
    //         cout << loggedInUser << endl;

    //         //// Logout the user when they're done
    //         // userSystem.logout();
    //         // std::cout << "Logged out.\n";
    //     }
    //     else
    //     {
    //         std::cout << "Login failed. Invalid username or password.\n";
    //     }
    // }
}
