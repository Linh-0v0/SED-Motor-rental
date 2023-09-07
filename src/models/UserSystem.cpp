#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "../../include/models/UserSystem.h"
using namespace std;

UserSystem::UserSystem()
{
    // Default constructor implementation
    loggedInUser = User(); // Default-constructed User for loggedInUser
    loggedInAdmin = Admin();
}

/***** Getter *****/
std::vector<User> &UserSystem::getUsers()
{
    return users;
}

std::vector<Motorbike> &UserSystem::getMotorbikes()
{
    return motorbikes;
}

const Admin &UserSystem::getAdmin()
{
    return loggedInAdmin;
}

const User &UserSystem::getLoggedInUser()
{
    return loggedInUser;
}

/***** Import-Add Data *****/
bool UserSystem::importUsers()
{
    // Implementation to read and populate User objects from the file
    std::ifstream inFile("appdata.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Cannot open file!";
    };
    std::string line;

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string username, fullName, password, phoneNumber, idNumber, driverLicense, expiryDate;
        int idType;
        double creditPoints, renterRatingScore;

        // Use std::getline and std::stoi to parse the comma-separated values
        if (std::getline(ss, username, ',') &&
            std::getline(ss, fullName, ',') &&
            std::getline(ss, password, ',') &&
            std::getline(ss, phoneNumber, ',') &&
            ss >> idType && ss.ignore() &&
            std::getline(ss, idNumber, ',') &&
            std::getline(ss, driverLicense, ',') &&
            std::getline(ss, expiryDate, ',') &&
            ss >> creditPoints && ss.ignore() && // Read the int values
            ss >> renterRatingScore)
        {

            // Create a User object and add it to the users vector
            User user(username, fullName, password, phoneNumber, idType, idNumber, driverLicense, expiryDate, creditPoints, renterRatingScore);

            users.push_back(user);
        }
        else
        {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    };
    inFile.close();
    return true;
}

bool UserSystem::importMotorbikes()
{
    // Implementation to read and populate User objects from the file
    std::ifstream inFile("motorbikes.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Cannot open file!";
    };
    std::string line;

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string ownerUsername, model, color, engineSize, transmissionMode, description, listedForRent;
        int yearMade;
        double motorbikeRating, creditPerDay, minRenterRating;
        bool convertedlistedForRent = false;
        // Use std::getline and std::stoi to parse the comma-separated values
        if (std::getline(ss, ownerUsername, ',') &&
            std::getline(ss, model, ',') &&
            std::getline(ss, color, ',') &&
            std::getline(ss, engineSize, ',') &&
            std::getline(ss, transmissionMode, ',') &&
            ss >> yearMade && ss.ignore() &&
            std::getline(ss, description, ',') &&
            std::getline(ss, listedForRent, ',') &&
            ss >> motorbikeRating && ss.ignore() && // Read the double values
            ss >> creditPerDay && ss.ignore() &&
            ss >> minRenterRating)
        {

            if (listedForRent == "true")
            {
                convertedlistedForRent = true;
            }
            // Create a User object and add it to the users vector
            Motorbike motorbike(ownerUsername, model, color, engineSize, transmissionMode, yearMade, description, convertedlistedForRent, motorbikeRating, creditPerDay, minRenterRating);

            motorbikes.push_back(motorbike);
        }
        else
        {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    };
    inFile.close();
    return true;
}

// Method to add a User to the users vector
void UserSystem::addUser(const User &user)
{
    users.push_back(user);
    /////// Add to text file code
}

// Method to add a Motorbike to the motorbikes vector
void UserSystem::addMotorbike(const Motorbike &motorbike)
{
    motorbikes.push_back(motorbike);
    /////// Add to text file code
}

/***** Others *****/
bool UserSystem::checkAdmin(const std::string &inputUsername, const std::string &inputPassword)
{
    return (inputUsername == "linhsieuquay" && inputPassword == "dobiet");
}

// Check if a user with the given username and password exists in the users vector
bool UserSystem::checkLogin(const std::string &username, const std::string &password)
{
    for (const User &user : users)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            loggedInUser = user; // Set the currently logged-in user
            return true;
            break;
        }
    }
    return false; // User not found
}

// Logout the currently logged-in user
void UserSystem::logout()
{
    loggedInUser = User(); // Reset the currently logged-in user to a default-constructed User
}
