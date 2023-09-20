#ifndef USER_H
#define USER_H
#include <iostream>     //use string
#include <fstream>      //save to appdata.txt
#include <limits>       //check integer
#include <string>
#include <string.h>     //use string function
#include "Motorbike.h"
using namespace std;    //use std



#include "Motorbike.h"

class member {
private:
    
    int CHECK1=0;
public:
    string USERS_NAME;
    int ID_TYPE=0, CREDIT=20, BIKE_AVAILABLE=10, PHONE_NUMBER=1, DOLLAR, RATE;
    string DRIVER_LICENSE, PASSWORD, FULL_NAME,EXP_DATE, IDx;
    double ID=0;
    int NEW_MEMBER(){
        while (CHECK1==0){
            cout << "Enter username:\n";
            cin >> USERS_NAME;

            cout << "Enter your password:\n";
            cin >> PASSWORD;

            cout << "Enter your full name:\n";
            while (FULL_NAME==""){
                getline(cin, FULL_NAME);
            }
            while (PHONE_NUMBER==1){
                cout << "Enter your phone number:\n";
                cin >> PHONE_NUMBER;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                    PHONE_NUMBER=1;
                }
            }

            while(ID_TYPE!= 1 && ID_TYPE!= 2){
                cout << "Enter your ID type:\n1.Citizen ID\n2.Passport\n";
                cin >> ID_TYPE;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }
            }

            while (ID==0){
                cout << "Enter your ID:\n";
                cin >> IDx;
                if (strspn( IDx.c_str(), "-.0123456789" ) == IDx.size()){ID=1;}else{ID=0;cout << "Invalid input. Please try again\n";};
                
            }

            while (DRIVER_LICENSE==""){
                cout << "Enter your driver license:\n";
                cin >> DRIVER_LICENSE;
                if (strspn( DRIVER_LICENSE.c_str(), "-.0123456789" ) == DRIVER_LICENSE.size()){ID=1;}else{ID=0;cout << "Invalid input. Please try again\n";};
            }

            cout << "Enter your driver license expiration date:\n";
            cin >> EXP_DATE;

            
            while(BIKE_AVAILABLE!= 0 && BIKE_AVAILABLE!= 1){
                cout << "Do you have a motorbike available to rent?\n0.No\n1.Yes\n";
                cin >> BIKE_AVAILABLE;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }
            }

            cout << "Is this infomation correct? [Yes to register, No to discard and fill this form again.]\n0.No\n1.Yes\n";
            cin >> CHECK1;
            if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
            }
            if (CHECK1==0){
                ID_TYPE=10;
                BIKE_AVAILABLE=10;
            }
        }
        if (BIKE_AVAILABLE==1){
            return 1;
        }
        return 0;
    }
    void showinfo(){
        cout << "\nUser name: " << USERS_NAME;
        cout << "\nFull name: " << FULL_NAME;
        cout << "\nPhone number: (+84)" << PHONE_NUMBER;
        cout << "\nUser ID: " << IDx;
        cout << "\nUser driver license: " << DRIVER_LICENSE << " with expiration date:"<< EXP_DATE;
        cout << "\nOwn a motorbike: " << BIKE_AVAILABLE;
        cout << "\nCredit score: " << CREDIT;
        cout << "\nCurently renting a bike: ";
        cout << "\nRating count: ";
        cout << "\nRating score: " << RATE;
    }
    void topsup(){
        cout << "\nHow much credit do you want to purchase?\n$";
        while (1){
            cin >> DOLLAR;
            if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
            }else{
                CREDIT=CREDIT+DOLLAR;
                cout << "Your current credit is: "<< CREDIT << " Credit(s)";
                break;
            }

        }

    }

};

// void READ_USER_INFO(){}
// void APPEND_USER_INFO(member member1){}
// void MODIFY_USER_INFO(){}


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
    double renterRatingScore; //average of `renterRatingScores`
    // motorbikes that user rents from others
    std::vector<Motorbike> rentedMotorbikes;
    // motorbikes of user
    std::vector<Motorbike> availableMotorbikes;

public:
    User();
    User(const std::string &username, const std::string &fullName, const std::string &password, std::string phoneNumber, int idType, const std::string &idNumber, const std::string &driverLicense, const std::string &expiryDate, int creditPoints, double renterRataingScore);

    /*Getter*/
    std::string getFullName() const;
    std::string getUsername() const;
    std::string getPassword() const;
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
    void setConsumingCreditPoints(double newCreditPoints);
    void setRenterRatingScore(double newRenterRatingScore);

    /*Operator*/
    friend std::ostream &operator<<(std::ostream &os, const User &user);

    /*Others*/
    void printAvailableMotorbikes() const;
    void addMotorbikeToUser(const Motorbike &motorbike);
    double calcAverageRenterRating() const;
};

#endif
