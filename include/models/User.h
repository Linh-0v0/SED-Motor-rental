#ifndef USER_H
#define USER_H
#include <iostream> //use string
#include <fstream>  //save to ./appdata/users.txt
#include <vector>
#include <limits>   //check integer
#include <string>
#include <string.h> //use string function
#include "Motorbike.h"
#include "RentalRequest.h"

class RentalRequest;

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
    std::vector<double> renterRatingScores;
    double renterRatingScore; // average of `renterRatingScores`
    // motorbikes that user rents from others
    std::vector<Motorbike> rentedMotorbikes;
    // motorbikes of user
    std::vector<Motorbike> availableMotorbikes;

    std::vector<RentalRequest> rentalRequests;

public:
    User();
    User(const std::string &username, const std::string &fullName, const std::string &password, std::string phoneNumber, int idType, const std::string &idNumber, const std::string &driverLicense, const std::string &expiryDate, double creditPoints, double renterRataingScore);

    /*Getter*/
    std::string getFullName() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getPhoneNumber() const;
    int getIdType() const;
    std::string getIdNumber() const;
    std::string getDriverLicense() const;
    std::string getExpiryDate() const;
    double getCreditPoints() const;
    double getRenterRatingScore() const;
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
    void setCreditPoints(double newCreditPoints);
    void setRenterRatingScore(double newRenterRatingScore);

    /*Operator*/
    friend std::ostream &operator<<(std::ostream &os, const User &user);

    /*Others*/
    void printAvailableMotorbikes() const;
    void addToRenterRatings(double rating);
    void addMotorbikeToUser(const Motorbike &motorbike);
    void topUpCreditPoints(double amount);
    double calcAverageRenterRating() const;

    void addRentalRequest(const RentalRequest &request);
    const std::vector<RentalRequest> &getRentalRequests() const;
    std::string toFileString() const;
};

#endif
