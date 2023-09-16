#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "include/models/UserSystem.h"
#include "include/models/RentalRequest.h"
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

    /******/
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
                break; // Stop searching for the User once found
            }
        }
    }

    // Print all motorbikes
    // cout << "***** All Motorbikes *****" << endl;
    // for (const Motorbike &motorbike : motorbikes)
    // {
    //     std::cout << motorbike << endl;
    // }

    /**** Login ****/
    std::string username, password;
    // Prompt the user for username and password
    std::cout << "Enter your username:";
    std::getline(cin, username);
    std::cout << "Enter your password:";
    std::getline(cin, password);

    if (userSystem.checkAdmin(username, password))
    {
        loggedInAdmin = userSystem.getAdmin();
        std::cout << "Welcome admin " << loggedInAdmin.getUsername() << "." << "\n";
    }
    else
    {
        // // Check if the entered credentials are valid
        if (userSystem.checkLogin(username, password))
        {
            loggedInUser = userSystem.getLoggedInUser();
            std::cout << "Login successful. Welcome, " << loggedInUser.getFullName() << "!\n";

            // Return User's Info
            cout << endl;
            cout << "**** USER'S INFO ****" << endl;
            cout << loggedInUser << endl;

            // Unlist motorbike (disable for renting), update in text file as well
            for (Motorbike &motorbike : motorbikes)
            {
                if (motorbike.getOwnerUsername() == "linh")
                {
                    // userSystem.unlistMotorbikeForRent(motorbike);
                }
            }

            // List motorbike for rent (with rental amount per day, minimum required renter-rating, and city)
            for (Motorbike &motorbike : motorbikes)
            {
                if (motorbike.getOwnerUsername() == "linh")
                {
                    // userSystem.listMotorbikeForRent(motorbike, 9, 5, "Sai Gon");
                }
            }

            // List motorbike of the current user
            for (const Motorbike &motorbike : loggedInUser.getAvailableMotorbikes())
            {
                cout << motorbike << endl;
            }

            // Search Motorbikes available for 'a period of time' in 'a city' (suitable with the current user's 'credit points' and 'rating score')
            std::vector<Motorbike> availableMotorbikes = userSystem.searchAvailableMotorbikes(motorbikes, "2023-09-02 08:00:00", "2023-09-03 18:00:00", "Sai Gon", loggedInUser);
            cout << "\n***** Available motorbikes *****" << endl;
            for (size_t i = 0; i < availableMotorbikes.size(); ++i) {
                std::cout << "Option " << (i + 1) << ":" << std::endl;
                std::cout << availableMotorbikes[i] << std::endl;
            }


            int choice = 0 ;

            std::cout << "Enter the number of the motorbike you want to request (0 to cancel): ";
            std::cin >> choice;

            if (choice >= 1 && choice <= availableMotorbikes.size()) {
                Motorbike selectedMotorbike = availableMotorbikes[choice - 1];
                std::string ownerUsername = selectedMotorbike.getOwnerUsername();
                std::string username = loggedInUser.getUsername();
                // Prompt the user for additional information (credit, id, etc.)
                double credit;
                bool accepted = false;
                bool rejected = false;
               
                // Access startTime and endTime from selectedMotorbike
                std::time_t startTime = selectedMotorbike.getStartTime();
                std::time_t endTime = selectedMotorbike.getEndTime();

                // Request to rent the selected motorbike
                selectedMotorbike.requestToRentMotorbike(loggedInUser.getUsername(), ownerUsername, startTime, endTime, loggedInUser.getCreditPoints());

                RentalRequest request(loggedInUser.getUsername(), ownerUsername, startTime, endTime, credit, accepted, rejected);
                
                userSystem.storeRentalRequest(request);

            } else if (choice != 0) {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }

            userSystem.loadAndDisplayRentalRequests();

            //// Logout the user when they're done
            // userSystem.logout();
            // std::cout << "Logged out.\n";

        }
        else
        {
            std::cout << "Login failed. Invalid username or password.\n";
        }
    }
}
