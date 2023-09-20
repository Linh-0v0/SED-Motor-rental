#include <iostream>     //use string
#include <fstream>      //save to appdata.txt
#include <limits>       //check integer
#include <string.h>     //use string function
using namespace std;    //use std

#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <string> //use string function
#include <vector>
#include <ctime>
#include "User.h"
#include "RentalRequest.h"

class RentalRequest;

class motorbike{
public:
    string OWNER, MODEL, COLOR, ENGINE_SIZE, TRANSMISSION_MODE, DESCRIPTION;
    int YEAR_MADE=0;
    void NEW_BIKE(string USERS_NAME){
        
        OWNER= USERS_NAME;
        cout << "\nThis bike is a property of user " <<OWNER;

        cout << "\nEnter your bike model:\n";
        cin >> MODEL;

        cout << "Enter your bike color:\n";
        cin >> COLOR;

        cout << "Enter your bike's engine size:\n";
        cin >> ENGINE_SIZE;
        
        cout << "Enter your bike's transmission mode:\n";
        cin >> TRANSMISSION_MODE;

        while (YEAR_MADE<1500 || YEAR_MADE>2023){
            cout << "Enter the year yor bike made:\n";
            cin >> YEAR_MADE;
            if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
            }
        }
        
        cout << "Enter your bike description:\n";
        cin >> DESCRIPTION;
        
    }
    void showinfo(){
        cout << "\nThis bike is a property of member: " << OWNER;
        cout << "\nThis bike model : " << MODEL;
        cout << "\nThis bike color:  " << COLOR;
        cout << "\nThis bike engine size: " << ENGINE_SIZE;
        cout << "\nThis bike transmission mode: " << TRANSMISSION_MODE;
        cout << "\nThis bike description: " << DESCRIPTION;
    }
};
// void APPEND_BIKE_INFO(motorbike motorbike1){}



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
    void requestToRentMotorbike(const std::string& requestingUser, const std::string& motorbikeOwner,  std::time_t startTime,std::time_t endTime, double credit);


};

#endif
