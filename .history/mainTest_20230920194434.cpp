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
        std::cout << "User data loaded successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error loading user data." << std::endl;
        return 1; // Exit with an error code
    }
    // Print All Users
    std::vector<User> &users = userSystem.getUsers();
    // for (const User &user : users)
    // {
    //     std::cout << user << endl;
    // }

    // Load motorbike data from a text file
    if (userSystem.importMotorbikes())
    {
        std::cout << "Motorbike data loaded successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error loading motorbike data." << std::endl;
        return 1; // Exit with an error code
    }

    // userSystem.loadRentalRequestsFromFile("rental_requests.txt");

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
    cout << "\ns3805869, Student Name: Nguyen Truong Thinh.\nsXXXXXXX, Student Name:\nsXXXXXXX, Student Name:";

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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                        std::cout << motorbike << endl;
                    }
                    if (command == 1)
                    {
                        break;
                    }
                }
                else if (command == 3 || command == 4)
                {
                    // if (command == 3){cout << "In order to rent a bike, you need to register first.\n";}
                    // bike = member1.NEW_MEMBER();
                    // if (bike){
                    //     motorbike1.NEW_BIKE(member1.USERS_NAME);
                    // }

                    // // Add to appdata.txt
                    // // APPEND_USER_INFO(member1);
                    // // member1.showinfo();
                    // // if (bike){
                    // //     //
                    // //     APPEND_BIKE_INFO(motorbike1);
                    // //     motorbike1.showinfo();
                    // // }

                    /******* THINH ******/
                    /***** CODE REGISTER MEMBER SAI RUI, DUNG CAI addMember(...) trong `UserSystem.cpp` ay *****/
                    /**** CHUA CO CODE CHECK XEM Username existed chua ****/
                    addMember

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
            std::cout << "Enter your username:";
            std::cin >> username;
            std::cout << "Enter your password:";
            std::cin >> password;

            // // Check if the entered credentials are valid
            if (userSystem.checkLogin(username, password))
            {
                loggedInUser = userSystem.getLoggedInUser();
                std::cout << "Login successful. Welcome, " << loggedInUser.getFullName() << "!\n";

                while (1)
                {
                    cout << "\nThis is your menu:" << endl;
                    cout << "0. Exit\n1. View information\n2. List motorbike for renting\n3. Unlist motorbike from renting\n4. Search for motorbikes to rent\n5. Top up credit\n6. View renting requests of your motorbikes\n";
                    cout << "\nEnter your choice:";
                    cin >> command;

                    while (!(command >= 0 && command <= 7))
                    {
                        cin >> command;
                        if (cin.fail())
                        {
                            cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Invalid input. Please try again\n";
                        }
                    }

                    if (cin.fail())
                    {
                        cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                        cout << loggedInUser << endl;
                        // List motorbike of the current user
                        for (const Motorbike &motorbike : loggedInUser.getAvailableMotorbikes())
                        {
                            cout << motorbike << endl;
                        }
                    }
                    else if (command == 2)
                    {
                        // List motorbike for rent (with rental amount per day, minimum required renter-rating, and city)
                        double credit, rating;
                        std::string city;
                        cout << "Enter your `credit` required for renting: ";
                        cin >> credit;
                        cout << "Enter `minimum rating required from user` for renting: ";
                        cin >> rating;
                        cout << "Enter `city` of the motorbike for renting: ";
                        cin >> city;

                        for (Motorbike &motorbike : motorbikes)
                        {
                            if (motorbike.getOwnerUsername() == "linh")
                            {
                                userSystem.listMotorbikeForRent(motorbike, credit, rating, city);
                            }
                        }
                    }
                    else if (command == 3)
                    {
                        // Unlist motorbike (disable for renting), update in text file as well
                        for (Motorbike &motorbike : motorbikes)
                        {
                            if (motorbike.getOwnerUsername() == "linh")
                            {
                                // userSystem.unlistMotorbikeForRent(motorbike);
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
                            std::cin.ignore();
                            std::getline(cin, startTime);
                            if (!isValidDateTime(startTime))
                            {
                                std::cout << "Invalid format. Please re-enter 'Start time' in this format `YYYY-MM-DD HH:MM::SS`" << std::endl;
                            }
                        } while (!isValidDateTime(startTime));

                        do
                        {
                            cout << "\nEnd at: ";
                            std::getline(cin, endTime);
                            if (!isValidDateTime(endTime))
                            {
                                std::cout << "Invalid format. Please re-enter 'End time' in this format `YYYY-MM-DD HH:MM::SS`" << std::endl;
                            }
                        } while (!isValidDateTime(endTime));

                        cout << "\nEnter city you want to rent motorbike from: ";
                        std::getline(cin, city);

                        // Search Motorbikes available for 'a period of time' in 'a city' (suitable with the current user's 'credit points' and 'rating score')
                        std::vector<Motorbike> availableMotorbikes = userSystem.searchAvailableMotorbikes(motorbikes, startTime, endTime, city, loggedInUser);
                        cout << "\n***** Available motorbikes *****" << endl;
                        for (size_t i = 0; i < availableMotorbikes.size(); ++i)
                        {
                            std::cout << "Option " << (i + 1) << ":" << std::endl;
                            std::cout << availableMotorbikes[i] << std::endl;
                        }
                    }
                    else if (command == 5)
                    {
                        // Top up Credit
                        /*** THINH ****/
                    }
                    else if (command == 6)
                    {
                        // view all requests to the motorbike
                        /******NHAM*****/
                        // int choice = 0;

                        // std::cout << "Enter the number of the motorbike you want to request (0 to cancel): ";
                        // std::cin >> choice;

                        // if (choice >= 1 && choice <= availableMotorbikes.size())
                        // {
                        //     Motorbike selectedMotorbike = availableMotorbikes[choice - 1];
                        //     std::string ownerUsername = selectedMotorbike.getOwnerUsername();
                        //     std::string username = loggedInUser.getUsername();
                        //     // Prompt the user for additional information (credit, id, etc.)
                        //     double credit;
                        //     bool accepted = false;
                        //     bool rejected = false;

                        //     // Access startTime and endTime from selectedMotorbike
                        //     std::time_t startTime = selectedMotorbike.getStartTime();
                        //     std::time_t endTime = selectedMotorbike.getEndTime();

                        //     // Request to rent the selected motorbike
                        //     selectedMotorbike.requestToRentMotorbike(loggedInUser.getUsername(), ownerUsername, startTime, endTime, loggedInUser.getCreditPoints());

                        //     RentalRequest request(loggedInUser.getUsername(), ownerUsername, startTime, endTime, credit, accepted, rejected);

                        //     userSystem.storeRentalRequest(request);
                        // }
                        // else if (choice != 0)
                        // {
                        //     std::cout << "Invalid choice. Please try again." << std::endl;
                        // }

                        // userSystem.loadAndDisplayRentalRequests();

                        /*****************************/
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
            std::cout << "Enter the admin username:";
            std::cin >> username;
            std::cout << "Enter the admin password:";
            std::cin >> password;

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
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                            std::cout << motorbike << endl;
                        }
                        if (command == 1)
                        {
                            break;
                        }
                    }
                    else if (command == 3)
                    {
                        // Print All Users
                        std::vector<User> &users = userSystem.getUsers();
                        for (const User &user : users)
                        {
                            std::cout << user << endl;
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
                std::cout << "\nLogin failed. Invalid username or password.\n";
            }
        }
    }
}