#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "include/models/UserSystem.h"
#include "include/models/User.h"
#include "include/models/Motorbike.h"
#include "include/services/RentalSystem.h"
using namespace std;

int main() {
    cout << "\nEEET2482/COSC2082 ASSIGNMENT";
    cout << "\nMOTORBIKE RENTAL APPLICATION";
    cout << "\nInstructor: Dr. Ling Huo Chong";
    cout << "\nGroup: Group No.";
    cout << "\ns3805869, Student Name: Nguyen Truong Thinh.\nsXXXXXXX, Student Name:\nsXXXXXXX, Student Name:";
    member member1;
    motorbike motorbike1;
    User user1;
    // Motorbike bike1;


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

    std::vector<Motorbike> &motorbikes = userSystem.getMotorbikes();

    // Add the Motorbike to corresponding User
    for (Motorbike &motorbike : motorbikes)
    {
        for (User &user:users)
        {
            if (user.getUsername() == motorbike.getOwnerUsername())
            {
                user.addMotorbikeToUser(motorbike);
                break; // Stop searching for the User once found
            }
        }
    }

    while (1){
        int USER_ROLE=10, bike=0, command=0;
        // Intro:
        cout << "\n\nUse the app as \n1. Guest \n2. Member[sign in required] \n3. Admin [sign in required]";
        cout << "\nEnter your choice:";

        //check role
        while (USER_ROLE<1 || USER_ROLE >3){
            cin >> USER_ROLE;
            if (cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid input. Please try again\n";
            }
        }

        
        // Access as Guest
        if (USER_ROLE==1){
            cout << "Access Granted!\n\nYou are accessed as ";
            cout << "Guest\n";
            while (1){
                cout << "As a guest, you can:\n1. Exit Program.\n2. View all motorbike details\n3. Rent a motorbike (register required)\n4. Sign up/ Register\n";
                cout << "\nEnter your choice:";
                cin >> command;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }else if (command == 1){
                    break;
                }else if (command == 2){
                    // Print all motorbikes
                    cout << "***** All Motorbikes *****" << endl;
                    for (const Motorbike &motorbike : motorbikes)
                    {
                        std::cout << motorbike << endl;
                    }
                    if (command == 1){
                        break;
                    }
                }else if (command == 3 || command == 4){
                    if (command == 3){cout << "In order to rent a bike, you need to register first.\n";}
                    bike = member1.NEW_MEMBER();
                    if (bike){
                        motorbike1.NEW_BIKE(member1.USERS_NAME);
                    }

                    cout << "\nYou are now a Member. Please sign in again.\n";

                    USER_ROLE=2;
                    break;
                }

                // Method to add a User to the users vector
                UserSystem::addUser(user1);

                // // Method to add a Motorbike to the motorbikes vector
                // UserSystem::addMotorbike(bike1);

            }
        }
        
        
        // Access as Member 
        else if (USER_ROLE==2){

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
            cout << "Access Granted!\n\nYou are accessed as ";
            cout << "Member\n";
            std::cout << "\nLogin successful. Welcome, " << loggedInUser.getFullName() << "!\n";

            //// Logout the user when they're done
            // userSystem.logout();
            // std::cout << "Logged out.\n";

            while (1){
                cout << "As a member, you can:\n1. Exit Program.\n2. View all motorbike details\n3. Rent a motorbike\n4. Show info\n5. Manage your bike\n6. Search for motorbike\n7. View requests\n8. Rating\n9. \u001b[31mAdd credit point\u001b[0m\n";
                cin >> command;
                if (cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again\n";
                }else if (command == 1){
                    break;
                }else if (command == 2){
                    
                    // Print all motorbikes
                    cout << "***** All Motorbikes *****" << endl;
                    for (const Motorbike &motorbike : motorbikes)
                    {
                        std::cout << motorbike << endl;                      
                    }
                    if (command == 1){
                        break;
                    }                   

                }else if (command == 3){



                    break;
                }else if (command == 4){

                    
                    // Return User's Info
                    cout << endl;
                    cout << "**** USER'S INFO ****" << endl;
                    cout << loggedInUser << endl;

                    // List motorbike of the current user
                    for (const Motorbike &motorbike : loggedInUser.getAvailableMotorbikes())
                    {
                        cout << motorbike << endl;
                    }
                    if (command == 1){
                        break;
                    }

                }else if (command == 5){

                    int rent;
                    while (1){
                    cout << "1. Put your bike on the rent list\n2. Remove your bike off the rent list\n";
                    cout << "\nEnter your choice:";
                    cin >> rent;
                    if (cin.fail()){
                        cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Invalid input. Please try again\n";

                    }else if (rent == 1){

                        // List motorbike for rent (with rental amount per day, minimum required renter-rating, and city)
                        for (Motorbike &motorbike : motorbikes)
                        {
                            if (motorbike.getOwnerUsername() == "linh")
                            {
                                userSystem.listMotorbikeForRent(motorbike, 9, 5, "Sai Gon");
                            }
                        }
                        break;
                    }else if (rent == 2){

                        // Unlist motorbike (disable for renting), update in text file as well
                        for (Motorbike &motorbike : motorbikes)
                        {
                            if (motorbike.getOwnerUsername() == "linh")
                            {
                                userSystem.unlistMotorbikeForRent(motorbike);
                            }
                            }
                            break;
                        }
                    }
                }else if (command == 6){

                    // Search Motorbikes available for 'a period of time' in 'a city' (suitable with the current user's 'credit points' and 'rating score')
                    std::vector<Motorbike> availableMotorbikes = userSystem.searchAvailableMotorbikes(motorbikes, "2023-09-02 08:00:00", "2023-09-03 18:00:00", "Sai Gon", loggedInUser);
                    cout << "\n***** Available motorbikes *****" << endl;
                    for (const Motorbike &motorbike : availableMotorbikes)
                    {
                        cout << motorbike << endl;
                    }
                    if (command == 1){
                        break;
                    }

                }else if (command == 7){
                    break;
                }else if (command == 8){
                    int rateCommand;
                    cout << "What do you want to rate:\n";
                    cout << "1. Bike you have rented\n2. Renter rents your bike\n";
                    cout << "\nEnter your choice:";
                    cin >> rateCommand;
                    if (rateCommand ==1){
                        // int list;
                        // cout << "Which bike do you want to rate:\n";
                        // cin >> list;

                        rateBike();
                    } else if (rateCommand == 2){
                        // int list;
                        // cout << "Which renter do you want to rate:\n";
                        // cin >> list;
                        
                        rateDriver();
                    }
                    break;
                }else if (command == 9){
                    member1.topsup();
                    if (command == 1){
                        break;
                    }
                }
            }
        } else {
            std::cout << "\nLogin failed. Invalid username or password.\n";
        }
    }    
        

        // Access as Admin
        else {

            /**** Login ****/
            std::string username, password;
            
            // Prompt the user for username and password
            std::cout << "Enter your username:";
            std::cin >> username;
            std::cout << "Enter your password:";
            std::cin >> password;
            

            // // Check if the entered credentials are valid
            if (userSystem.checkAdmin(username, password))
            {
                loggedInAdmin = userSystem.getAdmin();
                cout << "Access Granted!\n\nYou are accessed as ";
                cout << "Admin\n";
                    while(1){
                    cout << "As an admin, you can:\n1. Exit Program.\n2. View all motorbike details\n3. View all users detail.\n";
                    cin >> command;
                    if (cin.fail()){
                        cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "\nInvalid input. Please try again\n";
                    }else if (command == 1){
                        break;
                    }else if (command == 2){

                        // Print all motorbikes
                        cout << "***** All Motorbikes *****" << endl;
                        for (const Motorbike &motorbike : motorbikes)
                        {
                            std::cout << motorbike << endl;
                        }
                        if (command == 1){
                            break;
                        }

                    }else if (command == 3){
                        // Print All Users
                        std::vector<User> &users = userSystem.getUsers();
                        for (const User &user : users)
                        {
                            std::cout << user << endl;
                        }
                        if (command == 1){
                            break;
                        }
                    }
                }
            }  else {
                std::cout << "\nLogin failed. Invalid username or password.\n";
            }
        }
    }
}
