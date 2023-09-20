#include "../../include/models/User.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"
#include "../../include/models/RentalRequest.h"
using namespace std;


// void READ_USER_INFO(){}

// void APPEND_USER_INFO(member member1){
//     cout << "\nYour infomation will be added in to our data base.";
//     std::ofstream outfile;
//     outfile.open("../../appdata.txt", std::ios_base::app); // append instead of overwrite
    
//     outfile << member1.USERS_NAME;
// }

// void MODIFY_USER_INFO(){}

// Default constructor
User::User() : username(""), fullName(""), phoneNumber(""), idType(0), idNumber(""), driverLicense(""), expiryDate(""), creditPoints(0), renterRatingScore(0){};

// Parameterized constructor
User::User(const std::string &username, const std::string &fullName, const std::string &password, std::string phoneNumber, int idType, const std::string &idNumber, const std::string &driverLicense, const std::string &expiryDate, int creditPoints, double renterRatingScore) : username(username), fullName(fullName), password(password), phoneNumber(phoneNumber), idType(idType), idNumber(idNumber), driverLicense(driverLicense), expiryDate(expiryDate), creditPoints(creditPoints), renterRatingScore(renterRatingScore) {}

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
string getPhoneNumber(std::string newPhoneNumber){}
int getIdType(int newIdType);
string getIdNumber(const std::string &newIdNumber);
string getDriverLicense(const std::string &newDriverLicense);
string getExpiryDate(const std::string &newExpiryDate);
double User::getCreditPoints() const
{
    return creditPoints;
}

double User::getRenterRatingScore() const
{
    return renterRatingScore;
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
    os << "User's Name: " << user.username << endl;
    os << "Full Name: " << user.fullName << endl;
    os << "Password: " << user.password << endl;
    os << "Phone Number: " << user.phoneNumber << endl;
    os << "ID Type: " << user.idType << endl;
    os << "Driver's License: " << user.driverLicense << endl;
    os << "Expiration Date: " << user.expiryDate << endl;
    // os << "Bike Available: " << user.bikeavailable << endl;
    os << "Credit: " << user.creditPoints << endl;
    os << "Personal renting score: " << user.renterRatingScore << endl;
    return os;
}

/***** Others *****/
// Implement the printAvailableMotorbikes function
void User::printAvailableMotorbikes() const
{
    cout << "Available Motorbikes:" << endl;
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

double User::calcAverageRenterRating() const
{
    if (renterRatingScores.empty()) {
        return 0.0;
    }
    float sum = 0.0;
    for (float rating : renterRatingScores) {
        sum += rating;
    }
    return sum / renterRatingScores.size();
}

void User::addRentalRequest(const RentalRequest& request) {
    rentalRequests.push_back(request);
}

const std::vector<RentalRequest>& User::getRentalRequests() const {
    return rentalRequests;
}