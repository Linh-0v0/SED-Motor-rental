#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <iostream>
#include <string> //use string function
#include <vector>
#include "User.h"
using namespace std; // use std

class Motorbike
{
private:
    std::string ownerUsername;
    std::string model;
    std::string color;
    std::string engineSize;
    std::string transmissionMode;
    int yearMade;
    std::string description;
    bool listedForRent;
    std::vector<std::string> reviews;
    std::vector<double> motorbikeRatings;
    double motorbikeRating;

    double creditPerDay; // required credit for rent
    double minRenterRating;

public:
    Motorbike(const std::string &ownerUsername, const std::string &model, const std::string &color, const std::string &engineSize, const std::string &transmissionMode, int yearMade, const std::string &description, bool listedForRent, double motorbikeRating, double creditPerDay, double minRenterRating);

    /*Getter*/
    const std::string &getOwnerUsername() const;
    double getCreditPerDay() const;
    int getMinRenterRating() const;
    float getAverageMotorbikeRating() const;
    float getAverageRenterRating() const;

    /*Setter*/
    void setListedForRent(bool isListed);
    void setCreditPerDay(int creditPointsConsumed);
    // Set the minimum required renter rating for this motorbike
    void setMinRequiredRenterRating(int minRequiredRenterRating);

    /*Operator*/
    bool operator==(const Motorbike &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Motorbike &motorbike);

    /*Others*/
    void viewMotorbikeDetails();
};

#endif
