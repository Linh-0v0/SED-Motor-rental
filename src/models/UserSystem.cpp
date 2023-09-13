#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include "../../include/models/UserSystem.h"
#include "../../include/models/RentalRequest.h"
#include "../../include/utils/Time.h"
using namespace std;

UserSystem::UserSystem()
{
    // Default constructor implementation
    loggedInUser = User(); // Default-constructed User for loggedInUser
    loggedInAdmin = Admin();
}

/***** Getter *****/
std::vector<User> &UserSystem::getUsers()
{
    return users;
}

std::vector<Motorbike> &UserSystem::getMotorbikes()
{
    return motorbikes;
}

const Admin &UserSystem::getAdmin()
{
    return loggedInAdmin;
}

const User &UserSystem::getLoggedInUser()
{
    return loggedInUser;
}

/***** Import-Add Data *****/
bool UserSystem::importUsers()
{
    // Implementation to read and populate User objects from the file
    std::ifstream inFile("appdata.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Cannot open file!";
    };
    std::string line;

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string username, fullName, password, phoneNumber, idNumber, driverLicense, expiryDate;
        int idType;
        double creditPoints, renterRatingScore;

        // Use std::getline and std::stoi to parse the comma-separated values
        if (std::getline(ss, username, ',') &&
            std::getline(ss, fullName, ',') &&
            std::getline(ss, password, ',') &&
            std::getline(ss, phoneNumber, ',') &&
            ss >> idType && ss.ignore() &&
            std::getline(ss, idNumber, ',') &&
            std::getline(ss, driverLicense, ',') &&
            std::getline(ss, expiryDate, ',') &&
            ss >> creditPoints && ss.ignore() && // Read the double values
            ss >> renterRatingScore)
        {

            // Create a User object and add it to the users vector
            User user(username, fullName, password, phoneNumber, idType, idNumber, driverLicense, expiryDate, creditPoints, renterRatingScore);

            users.push_back(user);
        }
        else
        {
            std::cerr << "Error parsing line: " << line << endl;
        }
    };
    inFile.close();
    return true;
}

bool UserSystem::importMotorbikes()
{
    // Implementation to read and populate User objects from the file
    std::ifstream inFile("motorbikes.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Cannot open file!";
    };
    std::string line;

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string ownerUsername, model, color, engineSize, transmissionMode, description, listedForRent, startTimeString, endTimeString, city;
        int yearMade;
        double motorbikeRating, creditPerDay, minRenterRating;
        bool convertedlistedForRent;

        // Use std::getline and std::stoi to parse the comma-separated values
        if (std::getline(ss, ownerUsername, ',') &&
            std::getline(ss, model, ',') &&
            std::getline(ss, color, ',') &&
            std::getline(ss, engineSize, ',') &&
            std::getline(ss, transmissionMode, ',') &&
            ss >> yearMade && ss.ignore() &&
            std::getline(ss, description, ',') &&
            std::getline(ss, listedForRent, ',') &&
            ss >> motorbikeRating && ss.ignore() && // Read the double values
            ss >> creditPerDay && ss.ignore() &&
            ss >> minRenterRating && ss.ignore() &&
            std::getline(ss, startTimeString, ',') &&
            std::getline(ss, endTimeString, ',') &&
            std::getline(ss, city))
        {
            listedForRent == "yes" ? convertedlistedForRent = true : convertedlistedForRent = false;

            std::time_t startTime = stringToTimestamp(startTimeString);
            std::time_t endTime = stringToTimestamp(endTimeString);

            // Create a User object and add it to the users vector
            Motorbike motorbike(ownerUsername, model, color, engineSize, transmissionMode, yearMade, description, convertedlistedForRent, motorbikeRating, creditPerDay, minRenterRating, startTime, endTime, city);

            motorbikes.push_back(motorbike);
        }
        else
        {
            std::cerr << "Error parsing line: " << line << endl;
        }
    };
    inFile.close();
    return true;
}

// Method to add a User to the users vector
void UserSystem::addUser(const User &user)
{
    users.push_back(user);
    /////// Add to text file code
}

// Method to add a Motorbike to the motorbikes vector
void UserSystem::addMotorbike(const Motorbike &motorbike)
{
    motorbikes.push_back(motorbike);
    /////// Add to text file code
}

/***** Update data *****/
void UserSystem::updateMotorbikeInFile(const Motorbike &updatedMotorbike)
{
    for (Motorbike &motorbike : motorbikes)
    {
        if (motorbike.getOwnerUsername() == updatedMotorbike.getOwnerUsername())
        {
            motorbike = updatedMotorbike;
            break;
        }
    }

    std::ofstream outFile("motorbikes.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Cannot open file for writing!";
        return;
    }

    // Write the data from your data structure (e.g., vector or map) to the text file
    for (const Motorbike &motorbike : motorbikes)
    {
        outFile << motorbike.toFileString() << "\n";
    }

    outFile.close();
}

/***** Others *****/
bool UserSystem::checkAdmin(const std::string &inputUsername, const std::string &inputPassword)
{
    return (inputUsername == "linhsieuquay" && inputPassword == "dobiet");
}

// Check if a user with the given username and password exists in the users vector
bool UserSystem::checkLogin(const std::string &username, const std::string &password)
{
    for (const User &user : users)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            loggedInUser = user; // Set the currently logged-in user
            return true;
            break;
        }
    }
    return false; // User not found
}

// Logout the currently logged-in user
void UserSystem::logout()
{
    loggedInUser = User();
}

// Enable for motorbike renting (require the owner to input the motorbike requirement)
void UserSystem::listMotorbikeForRent(Motorbike &motorbike, double creditPointsConsumed, double minRequiredRenterRating, std::string city)
{
    // Set the attributes for the motorbike
    motorbike.setCreditPerDay(creditPointsConsumed);
    motorbike.setMinRequiredRenterRating(minRequiredRenterRating);
    motorbike.setCity(city);
    // Set the motorbike as listed for rent
    motorbike.setListedForRent(true);
    // Update list status in text file
    updateMotorbikeInFile(motorbike);
    cout << "Motorbike has been listed for renting." << endl;
}

// Disable the motorbike from renting
void UserSystem::unlistMotorbikeForRent(Motorbike &motorbike)
{
    // Unset the motorbike as listed for rent
    motorbike.setListedForRent(false);
    // Update list status in text file
    updateMotorbikeInFile(motorbike);
    cout << "Motorbike has been unlisted from renting." << endl;
}

// Function to search for available motorbikes in a specified period
std::vector<Motorbike> UserSystem::searchAvailableMotorbikes(
    std::vector<Motorbike> &motorbikes,
    std::string userStartTime,
    std::string userEndTime,
    std::string city,
    User& user)
{
    std::vector<Motorbike> availableMotorbikes;
    std::time_t startTime = stringToTimestamp(userStartTime);
    std::time_t endTime = stringToTimestamp(userEndTime);

    for (Motorbike &motorbike : motorbikes)
    {
        std::time_t motorbikeStartTime = motorbike.getStartTime();
        std::time_t motorbikeEndTime = motorbike.getEndTime();

        if (endTime <= motorbikeEndTime && 
        startTime >= motorbikeStartTime && 
        motorbike.getListedForRent() == true && 
        motorbike.getCity() == city &&
        user.getCreditPoints() >= motorbike.getCreditPerDay() &&
        user.getRenterRatingScore() >= motorbike.getMinRenterRating())
        {
            // Motorbike is available for the user's desired period
            availableMotorbikes.push_back(motorbike);
        }
    }

    return availableMotorbikes;
}

void UserSystem::addPendingRequestToOwner(const RentalRequest& request) {
    // Find the owner user by their username
    for (User& user : users) {
        if (user.getUsername() == request.getMotorbikeOwner()) {
            user.addPendingRequest(request);
            return; // Exit the loop once the owner is found and the request is added
        }
    }
}


User* UserSystem::findUserByUsername(const std::string& username) {
    for (User& user : users) {
        if (user.getUsername() == username) {
            return &user; // Return a pointer to the user if found
        }
    }
    return nullptr; // Return nullptr if the user is not found
}


// void UserSystem::loadRentalRequestsFromFile(const std::string& filename) {
//     std::ifstream inputFile(filename);

//     if (!inputFile.is_open()) {
//         std::cerr << "Failed to open file: " << filename << std::endl;
//         return;
//     }

//     rentalRequests.clear(); // Clear existing requests before loading from file

//     std::string line;
//     while (std::getline(inputFile, line)) {
//         std::istringstream iss(line);
//         std::string requestingUser, motorbikeOwner;
//         bool accepted;

//         if (iss >> requestingUser >> motorbikeOwner >> accepted) {
//             RentalRequest request(requestingUser, motorbikeOwner);
//             request.setAccepted(accepted);
//             rentalRequests.push_back(request);
//         } else {
//             std::cerr << "Failed to parse line: " << line << std::endl;
//         }
//     }

//     inputFile.close();
// }

// UserSystem.cpp

void UserSystem::saveRentalRequestsToFile(const std::string& filename) {
    // Open the file for writing
    std::ofstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    // Iterate through the rentalRequests vector and save each request to the file
    for (const RentalRequest& request : rentalRequests) {
        // Format the data and write it to the file
        file << request.getRequestingUser() << " "
             << request.getMotorbikeOwner() << " "
             << (request.isAccepted() ? "1" : "0") << " "<< "\n";
    }

    // Flush the file to ensure immediate writing
    file.flush();

    // Close the file
    file.close();
}


void UserSystem::storeRentalRequest(const RentalRequest& request,int& requestId) {
    // Generate a unique request ID (you can implement this logic)
    requestId = request.getRequestId();

    // Update the rental request with start and end times
    RentalRequest updatedRequest = request;

    // Add the updated request to the list of rental requests
    rentalRequests.push_back(updatedRequest);

    // Save the updated list of rental requests to a file
    saveRentalRequestsToFile("rental_requests.txt");
}
