#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <iostream>
#include <string> //use string function
#include <vector>
#include <ctime>
#include "User.h"
#include "RentalRequest.h"

class RentalRequest;

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
    double motorbikeRating; //average of `motorbikeRatings`

    double creditPerDay; // required credit for rent
    double minRenterRating;
    std::time_t startTime; // Implement this method
    std::time_t endTime;   // Implement this method
    std::string city;

    // vector to store pending rental requests
    std::vector<RentalRequest> pendingRequests;

public:
    Motorbike(const std::string &ownerUsername, const std::string &model, const std::string &color, const std::string &engineSize, const std::string &transmissionMode, int yearMade, const std::string &description, bool listedForRent, double motorbikeRating, double creditPerDay, double minRenterRating, std::time_t startTime, std::time_t endTime, std::string city);

    /*Getter*/
    std::string getOwnerUsername() const;
    bool getListedForRent();
    double getCreditPerDay() const;
    int getMinRenterRating() const;
    std::time_t getStartTime() const;
    std::time_t getEndTime() const;
    std::string getCity() const;

    /*Setter*/
    void setListedForRent(bool isListed);
    void setMotorbikeRating(double motorbikeRating);
    void setCreditPerDay(int creditPointsConsumed);
    // Set the minimum required renter rating for this motorbike
    void setMinRequiredRenterRating(int minRequiredRenterRating);
    void setCity(std::string city);

    /*Operator*/
    bool operator==(const Motorbike &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Motorbike &motorbike);

    /*Others*/
    double calcAverageMotorbikeRating() const; // return the average valuef for MotorbikeRating
    // Method to convert Motorbike data to a formatted string for writing to the file
    std::string toFileString() const;

    //function to request to rent the motorbike
    void requestToRentMotorbike(const std::string& requestingUser);

    //function to get pending rental requests
    const std::vector<RentalRequest>& getPendingRequests() const;

    void handlePendingRequest();

};

#endif
