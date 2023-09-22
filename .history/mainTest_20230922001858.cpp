#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "include/models/UserSystem.h"
#include "include/models/RentalRequest.h"
#include "include/utils/Time.h"
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
        cout << "User data loaded successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error loading user data." << std::endl;
        return 1; // Exit with an error code
    }
    std::vector<User> &users = userSystem.getUsers();

    // Load motorbike data from a text file
    if (userSystem.importMotorbikes())
    {
        cout << "Motorbike data loaded successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error loading motorbike data." << std::endl;
        return 1; // Exit with an error code
    }
    std::vector<Motorbike> &motorbikes = userSystem.getMotorbikes();

    // Add the Motorbike to corresponding User
    for (Motorbike &motorbike : motorbikes)
    {
        for (User &user : users)
        {
            if (user.getUsername() == motorbike.getOwnerUsername())
            {
                user.addMotorbikeToUser(motorbike);
                break;
            }
        }
    }

    /***** INTERFACE *****/
    cout << "\nEEET2482/COSC2082 ASSIGNMENT";
    cout << "\nMOTORBIKE RENTAL APPLICATION";
    cout << "\nInstructor: Dr. Ling Huo Chong";
    cout << "\nGroup: Group No.";
    cout << "\ns3805869, Student Name: Nguyen Truong Thinh.\ns3878533, Student Name: Nguyen Hoang To Nhu.\ns3864120, Student Name: Vu Bui Khanh Linh";

    while (1)
    {
        int USER_ROLE = 0, command = 10;
        // Intro:
        cout << "\n\nUse the app as \n1. Guest \n2. Member[sign in required] \n3. Admin [sign in required]";
        cout << "\nEnter your choice:";

        // check role
        while (!(USER_ROLE >= 1 && USER_ROLE <= 3))
        {
            cin >> USER_ROLE;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
            }
        }

        // Access as Guest
        if (USER_ROLE == 1)
        {
            cout << "Access Granted!\n\nYou are accessed as ";
            cout << "Guest\n";
            while (1)
            {
                cout << "As a guest, you can:\n1. Exit Program.\n2. View all motorbike details\n3. Rent a motorbike (register required)\n4. Sign up/ Register\n";
                cout << "\nEnter your choice:";
                cin >> command;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }
                else if (command == 1)
                {
                    break;
                }
                else if (command == 2)
                {
                    // Print all motorbikes
                    cout << "***** All Motorbikes *****" << endl;
                    for (const Motorbike &motorbike : motorbikes)
                    {
                        cout << motorbike << endl;
                    }
                    if (command == 1)
                    {
                        break;
                    }
                }
                else if (command == 3 || command == 4)
                {
                    if (command == 3)
                    {
                        cout << "In order to rent a bike, you need to register first.\n";
                    }
                    std::string username, fullName, password, phoneNumber, idNumber, driverLicense, expiryDate;
                    int idType;
                    double creditPoints;
                    cout << "*** Register ***\n";

                    cout << "Enter username: ";
                    cin >> username;
                    if (userSystem.isUsernameExisted(username))
                    {
                        cout << "Username already exists.\n";
                        break;
                    }
                    cout << "Enter full name: ";
                    cin.ignore();
                    std::getline(cin, fullName);
                    cout << "Enter password: ";
                    cin >> password;
                    cout << "Enter phone number: ";
                    cin >> phoneNumber;
                    cout << "Enter ID type (1 for Citizen ID, 2 for Passport): ";
                    cin >> idType;
                    cout << "Enter ID number: ";
                    cin >> idNumber;
                    cout << "Enter driver's license: ";
                    cin >> driverLicense;
                    cout << "Enter expiry date (YYYY-MM-DD): ";
                    cin >> expiryDate;

                    bool validInput = false;
                    do
                    {
                        cout << "Top up your credit points, please enter a number: ";
                        if (cin >> creditPoints)
                        {
                            validInput = true; // Input is a valid double
                        }
                        else
                        {
                            cout << "Invalid input. Please enter a valid double." << std::endl;
                            cin.clear();                                                   // Clear error state
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                        }
                    } while (!validInput);
                    userSystem.registerNewUser(username, fullName, password, phoneNumber, idType, idNumber, driverLicense, expiryDate, creditPoints);

                    cout << "\nYou are now a Member. Please sign in again.\n";
                    USER_ROLE = 2;
                    break;
                }
            }
        }

        // Access as Member
        else if (USER_ROLE == 2)
        {
            /**** Login ****/
            std::string username, password;

            // Prompt the user for username and password
            cout << "Enter your username:";
            cin >> username;
            cout << "Enter your password:";
            cin >> password;

            // // Check if the entered credentials are valid
            if (userSystem.checkLogin(username, password))
            {
                cout << "Login successful. Welcome, " << loggedInUser.getFullName() << "!\n";
                loggedInUser = userSystem.getLoggedInUser();

                while (1)
                {

                    cout << "\nThis is your menu:" << endl;
                    cout << "0. Exit\n1. View information\n2. List motorbike for renting\n3. Unlist motorbike from renting\n4. Search for motorbikes to rent\n5. Top up credit\n6. View renting requests of your motorbikes\n7. Renter rating";
                    cout << "\nEnter your choice:";
                    cin >> command;

                    while (!(command >= 0 && command <= 7))
                    {
                        cin >> command;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Invalid input. Please try again\n";
                        }
                    }

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Invalid input. Please try again\n";
                    }
                    else if (command == 0)
                    {
                        break;
                    }
                    else if (command == 1)
                    {
                        // Return User's Info
                        cout << endl;
                        cout << "**** USER'S INFO ****" << endl;
                        // in case user's data is updated during executing updating request below
                        userSystem.updateLoggedInUserInfo();
                        // List motorbike of the current user
                        for (const Motorbike &motorbike : loggedInUser.getAvailableMotorbikes())
                        {
                            cout << motorbike << endl;
                        }
                        cout << "*****\n";
                    }
                    else if (command == 2)
                    {
                        bool isExisted = false;
                        double credit, rating;
                        int motorRegisterChoice;
                        std::string city;
                        // List motorbike for rent (with rental amount per day, minimum required renter-rating, and city)
                        for (Motorbike &motorbike : motorbikes)
                        {
                            // Check if the user already registered a motorbike
                            if (motorbike.getOwnerUsername() == loggedInUser.getUsername())
                            {
                                isExisted = true;
                                cout << "Enter your `credit` required for renting: ";
                                cin >> credit;
                                cout << "Enter `minimum rating required from user` for renting: ";
                                cin >> rating;
                                cout << "Enter `city` of the motorbike for renting: ";
                                cin >> city;
                                userSystem.listMotorbikeForRent(motorbike, credit, rating, city);
                                break;
                            }
                        }
                        if (isExisted == false)
                        {
                            cout << "You haven't registered a motorbike. Do you want to register now?\n1. Yes | 2. No\nEnter your choice: ";
                            cin >> motorRegisterChoice;
                            if (motorRegisterChoice == 1)
                            {
                                // Register the motorbike
                                cout << "\n***Register Motorbike***\n";
                                std::string model, color, engineSize, transmissionMode, description, listedForRentStr, startTimeStr, endTimeStr, city;
                                int yearMade;
                                double creditPerDay, minRenterRating;
                                bool listedForRent;

                                cout << "Model: ";
                                cin >> model;
                                cout << "Color: ";
                                cin >> color;
                                cout << "Engine Size: ";
                                cin >> engineSize;
                                cout << "Transmission Mode: ";
                                cin >> transmissionMode;
                                cout << "Year Made: ";
                                cin >> yearMade;
                                cin.ignore(); // Clear the newline character from the input buffer
                                cout << "Description: ";
                                std::getline(cin, description);
                                cout << "Listed for Rent (true/false): ";
                                cin >> listedForRentStr;
                                listedForRent = (listedForRentStr == "true");
                                std::time_t startTime, endTime;
                                if (listedForRent)
                                {
                                    cout << "Credit Per Day: ";
                                    cin >> creditPerDay;
                                    cout << "Minimum Renter Rating: ";
                                    cin >> minRenterRating;
                                    cin.ignore(); // Clear the newline character from the input buffer
                                    cout << "Start Time available for rent (YYYY-MM-DD HH:MM:SS): ";
                                    std::getline(cin, startTimeStr);
                                    startTime = stringToTimestamp(startTimeStr);
                                    cout << "End Time (YYYY-MM-DD HH:MM:SS): ";
                                    std::getline(cin, endTimeStr);
                                    endTime = stringToTimestamp(endTimeStr);
                                }
                                cout << "City: ";
                                cin >> city;

                                Motorbike newMotorbike(loggedInUser.getUsername(), model, color, engineSize, transmissionMode, yearMade, description, listedForRent, 10, creditPerDay, minRenterRating, startTime, endTime, city);
                                userSystem.registerNewMotorbike(newMotorbike);
                                loggedInUser.addMotorbikeToUser(newMotorbike);
                            }
                        }
                    }
                    else if (command == 3)
                    {
                        // Unlist motorbike (disable for renting), update in text file as well
                        for (Motorbike &motorbike : motorbikes)
                        {
                            if (motorbike.getOwnerUsername() == loggedInUser.getUsername())
                            {
                                userSystem.unlistMotorbikeForRent(motorbike);
                            }
                        }
                    }
                    else if (command == 4)
                    {
                        std::string startTime, endTime, city;
                        cout << "\nEnter the renting time you need in this format `YYYY-MM-DD HH:MM::SS`.";
                        do
                        {
                            cout << "\nStart from: ";
                            cin.ignore();
                            std::getline(cin, startTime);
                            if (!isValidDateTime(startTime))
                            {
                                cout << "Invalid format. Please re-enter 'Start time' in this format `YYYY-MM-DD HH:MM::SS`" << std::endl;
                            }
                        } while (!isValidDateTime(startTime));

                        do
                        {
                            cout << "\nEnd at: ";
                            std::getline(cin, endTime);
                            if (!isValidDateTime(endTime))
                            {
                                cout << "Invalid format. Please re-enter 'End time' in this format `YYYY-MM-DD HH:MM::SS`" << std::endl;
                            }
                        } while (!isValidDateTime(endTime));

                        cout << "\nEnter city you want to rent motorbike from: ";
                        std::getline(cin, city);

                        // Search Motorbikes available for 'a period of time' in 'a city' (suitable with the current user's 'credit points' and 'rating score')
                        std::vector<Motorbike> availableMotorbikes = userSystem.searchAvailableMotorbikes(motorbikes, startTime, endTime, city, loggedInUser);
                        cout << "\n***** Available motorbikes *****" << endl;
                        for (size_t i = 0; i < availableMotorbikes.size(); ++i)
                        {
                            cout << "Option " << (i + 1) << ":" << std::endl;
                            cout << availableMotorbikes[i] << std::endl;
                        }
                        userSystem.requestMotorbikeRental(userSystem, loggedInUser, availableMotorbikes);
                    }
                    else if (command == 5)
                    {
                        // Top up Credit
                        double amount;
                        cout << "Enter amount to top up: ";
                        cin >> amount;

                        if (userSystem.topUpUserCreditPoints(username, amount))
                        {
                            cout << "Credit points topped up successfully." << std::endl;
                        }
                        else
                        {
                            cout << "User not found. Top-up failed." << std::endl;
                        }
                    }
                    else if (command == 6)
                    {
                        userSystem.loadAndDisplayRentalRequests();
                    }
                    else if (command == 7){
                        if (userSystem.RenterRating()){
                            cout<<"rating available";
                        };
                    }
                }
            }
        }

        // Access as Admin
        else
        {
            /**** Login ****/
            std::string username, password;

            // Prompt the user for username and password
            cout << "Enter the admin username:";
            cin >> username;
            cout << "Enter the admin password:";
            cin >> password;

            // // Check if the entered credentials are valid
            if (userSystem.checkAdmin(username, password))
            {
                loggedInAdmin = userSystem.getAdmin();
                cout << "Access Granted!\n\nYou are accessed as ";
                cout << "Admin\n";
                while (1)
                {
                    cout << "As an admin, you can:\n1. Exit Program.\n2. View all motorbike details\n3. View all users detail.\n";
                    cin >> command;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "\nInvalid input. Please try again\n";
                    }
                    else if (command == 1)
                    {
                        break;
                    }
                    else if (command == 2)
                    {
                        // Print all motorbikes
                        cout << "***** All Motorbikes *****" << endl;
                        for (const Motorbike &motorbike : motorbikes)
                        {
                            cout << motorbike << endl;
                        }
                        if (command == 1)
                        {
                            break;
                        }
                    }
                    else if (command == 3)
                    {
                        // Print All Users
                        for (const User &user : users)
                        {
                            cout << user << endl;
                        }
                        if (command == 1)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                cout << "\nLogin failed. Invalid username or password.\n";
            }
        }
    }
}
