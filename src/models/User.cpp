#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"
using namespace std;

// Default constructor
User::User() : username(""), fullName(""), phoneNumber(""), idType(0), idNumber(""), driverLicense(""), expiryDate(""), creditPoints(0), renterRatingScore(0){};

// Parameterized constructor
User::User(const std::string &username, const std::string &fullName, const std::string &password, std::string phoneNumber, int idType, const std::string &idNumber, const std::string &driverLicense, const std::string &expiryDate, int creditPoints, double renterRataingScore) : username(username), fullName(fullName), password(password), phoneNumber(phoneNumber), idType(idType), idNumber(idNumber), driverLicense(driverLicense), expiryDate(expiryDate), creditPoints(creditPoints), renterRatingScore(renterRataingScore) {}

/***** Getter *****/
std::string User::getUsername() const
{
    return username;
}

std::string User::getFullName() const
{
    return fullName;
}

std::string User::getPassword() const
{
    return password;
}

const std::vector<Motorbike> &User::getAvailableMotorbikes() const
{
    return availableMotorbikes;
}

/***** Setter *****/
void User::setUsername(const std::string &newUsername)
{
    username = newUsername;
}

void User::setFullName(const std::string &newFullName)
{
    fullName = newFullName;
}

void User::setPhoneNumber(std::string newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

void User::setIdType(int newIdType)
{
    idType = newIdType;
}

void User::setIdNumber(const std::string &newIdNumber)
{
    idNumber = newIdNumber;
}

void User::setDriverLicense(const std::string &newDriverLicense)
{
    driverLicense = newDriverLicense;
}

void User::setExpiryDate(const std::string &newExpiryDate)
{
    expiryDate = newExpiryDate;
}

void User::setConsumingCreditPoints(double newCreditPoints)
{
    creditPoints = newCreditPoints;
}

void User::setRenterRatingScore(double newRenterRatingScore)
{
    renterRatingScore = newRenterRatingScore;
}

/***** Operator *****/
std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "User's Name: " << user.username << std::endl;
    os << "Full Name: " << user.fullName << std::endl;
    os << "Password: " << user.password << std::endl;
    os << "Phone Number: " << user.phoneNumber << std::endl;
    os << "ID Type: " << user.idType << std::endl;
    os << "Driver's License: " << user.driverLicense << std::endl;
    os << "Expiration Date: " << user.expiryDate << std::endl;
    // os << "Bike Available: " << user.bikeavailable << std::endl;
    os << "Credit: " << user.creditPoints << std::endl;
    return os;
}

/***** Others *****/
// void User::viewMotorbikeDetails() const
// {
// if (!isMember()) {
//     //Non-member can only view Motobike details WITHOUT reviews
//     motorbike.viewMotorbikeDetails();
// } else {
//     // Display motorbike details WITH ratings for members
//     motorbike.viewMotorbikeDetails();
//     cout << "Motorbike Rating: ";
//     motorbike.getAverageMotorbikeRating();
//     cout << "Renter Rating: ";
//     motorbike.getAverageRenterRating();
// }
// }

// Implement the printAvailableMotorbikes function
void User::printAvailableMotorbikes() const
{
    std::cout << "Available Motorbikes:" << std::endl;
    for (const Motorbike &motorbike : availableMotorbikes)
    {
        cout << motorbike << endl;
    }
}

void User::addMotorbikeToUser(const Motorbike &motorbike)
{
    if (availableMotorbikes.size() == 0)
    {
        availableMotorbikes.push_back(motorbike);
    }
    else
    {
        cout << "You can only add one motorbike to your account." << endl;
    }
}

