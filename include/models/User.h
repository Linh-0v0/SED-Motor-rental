#ifndef USER_H
#define USER_H
#include <iostream> //use string
#include <fstream>  //save to appdata.txt
#include <limits>   //check integer
#include <string>
#include <string.h> //use string function
#include "Motorbike.h"
using namespace std; // use std

class User
{
private:
    std::string username;
    std::string password; // You should securely hash and store passwords in practice
    std::string fullName;
    std::string phoneNumber;
    int idType; // 1. citizenship; 2.Passport
    std::string idNumber;
    std::string driverLicense;
    std::string expiryDate;
    double creditPoints;
    double renterRatingScore;
    std::vector<Motorbike> rentedMotorbikes;
    // motorbikes of user
    std::vector<Motorbike> availableMotorbikes;
    // std::vector<Motorbike> listedMotorbikes;

public:
    User();
    User(const std::string &username, const std::string &fullName, const std::string &password, std::string phoneNumber, int idType, const std::string &idNumber, const std::string &driverLicense, const std::string &expiryDate, int creditPoints, double renterRataingScore);

    /*Getter*/
    std::string getFullName() const;
    std::string getUsername() const;
    std::string getPassword() const;
    const std::vector<Motorbike> &getAvailableMotorbikes() const;

    /*Setter*/
    void setUsername(const std::string &newUsername);
    void setFullName(const std::string &newFullName);
    void setPassWord(const std::string &newPassword);
    void setPhoneNumber(std::string newPhoneNumber);
    void setIdType(int newIdType);
    void setIdNumber(const std::string &newIdNumber);
    void setDriverLicense(const std::string &newDriverLicense);
    void setExpiryDate(const std::string &newExpiryDate);
    void setConsumingCreditPoints(double newCreditPoints);
    void setRenterRatingScore(double newRenterRatingScore);

    /*Operator*/
    friend std::ostream &operator<<(std::ostream &os, const User &user);

    /*Others*/
    void printAvailableMotorbikes() const;
    void addMotorbikeToUser(const Motorbike &motorbike);
    // Enable the motorbike for renting (require the owner to input the motorbike requirement)
    void listMotorbikeForRent(Motorbike &motorbike, double creditPointsConsumed, double minRequiredRenterRating);
    // Disable the motorbike from renting
    void unlistMotorbikeForRent(Motorbike &motorbike);
    void searchAvailableMotorbikes(int startTime, int endTime, const std::string &city, int minRating);
};

#endif
