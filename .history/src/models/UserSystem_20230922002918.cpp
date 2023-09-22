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
    std::ifstream inFile("./appdata/users.txt");
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
    std::ifstream inFile("./appdata/motorbikes.txt");
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
bool UserSystem::addUser(const User &user)
{
    users.push_back(user);
    // Add user to text file code
    std::ofstream outFile("./appdata/users.txt", std::ios::app);
    if (!outFile.is_open())
    {
        std::cerr << "Cannot open file for writing!" << std::endl;
        return false;
    }
    // Format the user data and write it to the file
    outFile << user.getUsername() << ","
            << user.getFullName() << ","
            << user.getPassword() << ","
            << user.getPhoneNumber() << ","
            << user.getIdType() << ","
            << user.getIdNumber() << ","
            << user.getDriverLicense() << ","
            << user.getExpiryDate() << ","
            << user.getCreditPoints() << ","
            << user.getRenterRatingScore() << "\n";

    outFile.close();
    return true;
}

// Method to add a Motorbike to the motorbikes vector
bool UserSystem::addMotorbike(const Motorbike &motorbike)
{
    motorbikes.push_back(motorbike);
    // Add motorbike to text file code
    std::ofstream outFile("./appdata/motorbikes.txt", std::ios::app); // Open in append mode to add new motorbike
    if (!outFile.is_open())
    {
        std::cerr << "Cannot open file for writing!" << std::endl;
        return false;
    }
    // Format the motorbike data and write it to the file
    outFile << motorbike.toFileString() << "\n";

    outFile.close();
    return true;
}

/***** Update data *****/
void UserSystem::updateUserInFile(const User &updatedUser)
{
    for (User &user : users)
    {
        if (user.getUsername() == updatedUser.getUsername())
        {
            user = updatedUser;
            break;
        }
    }
    std::ofstream outFile("./appdata/users.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Cannot open file for writing!";
        return;
    }
    // Write the data from data structure (e.g., vector or map) to the text file
    for (const User &user : users)
    {
        outFile << user.toFileString() << "\n";
    }

    outFile.close();
}

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

    std::ofstream outFile("./appdata/motorbikes.txt");
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

void UserSystem::updateLoggedInUserInfo()
{
    for (const User &user : users)
    {
        if (user.getUsername() == loggedInUser.getUsername())
        {
            // get lastest loggedInUser info considered user might be updated
            loggedInUser = user;
            cout << user << endl;
            break;
        }
    }
}

/***** Others *****/
bool UserSystem::registerNewUser(const std::string &username, const std::string &fullName, const std::string &password, std::string phoneNumber, int idType, const std::string &idNumber, const std::string &driverLicense, const std::string &expiryDate, double creditPoints)
{
    if (isUsernameExisted(username))
    {
        std::cout << "Username already exists. Registration failed." << std::endl;
        return false; // Registration failed
    }

    User newUser(username, fullName, password, phoneNumber, idType, idNumber, driverLicense, expiryDate, creditPoints, 10);
    // Add to System and txt file
    if (addUser(newUser))
    {
        std::cout << "Registration successful!" << std::endl;
    }
    else
    {
        std::cout << "Error in registration" << std::endl;
    }
    return true;
}

// Check if a username already exists in the system
bool UserSystem::isUsernameExisted(const std::string &username) const
{
    for (const User &user : users)
    {
        if (user.getUsername() == username)
        {
            return true; // Username exists
        }
    }
    return false; // Username does not exist
}

bool UserSystem::registerNewMotorbike(const Motorbike &newMotorbike)
{
    // Add the motorbike to the system and txt file
    if (addMotorbike(newMotorbike))
    {
        std::cout << "Motorbike registration successful!" << std::endl;
    }
    else
    {
        std::cout << "Error in motorbike registration" << std::endl;
    }
    return true;
}

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

// Function to top up credit points for a user
bool UserSystem::topUpUserCreditPoints(const std::string &username, double amount)
{
    for (User &user : users)
    {
        if (user.getUsername() == username)
        {
            user.topUpCreditPoints(amount);
            // Update user in txt file
            updateUserInFile(user);
            return true; // User found and credit points topped up
        }
    }
    return false; // User not found
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
    // Check if the ownerUsername already exists in the system
    for (const Motorbike &existingMotorbike : motorbikes)
    {
        if (existingMotorbike.getOwnerUsername() == motorbike.getOwnerUsername())
        {
            // Update list status in text file
            updateMotorbikeInFile(motorbike);
            cout << "Motorbike has been listed for renting.\n"
                 << endl;
        }
        else
        {
            addMotorbike(motorbike);
        }
    }
}

// Disable the motorbike from renting
void UserSystem::unlistMotorbikeForRent(Motorbike &motorbike)
{
    // Unset the motorbike as listed for rent
    motorbike.setListedForRent(false);
    // Update list status in text file
    updateMotorbikeInFile(motorbike);
    cout << "Motorbike has been unlisted from renting.\n"
         << endl;
}

// Function to search for available motorbikes in a specified period
std::vector<Motorbike> UserSystem::searchAvailableMotorbikes(
    std::vector<Motorbike> &motorbikes,
    std::string userStartTime,
    std::string userEndTime,
    std::string city,
    User &user)
{
    std::vector<Motorbike> availableMotorbikes;
    std::time_t startTime = stringToTimestamp(userStartTime);
    std::time_t endTime = stringToTimestamp(userEndTime);

    for (Motorbike &motorbike : motorbikes)
    {
        std::time_t motorbikeStartTime = motorbike.getStartTime();
        std::time_t motorbikeEndTime = motorbike.getEndTime();

        if ((motorbikeEndTime >= endTime && motorbikeStartTime <= startTime) &&
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

User *UserSystem::findUserByUsername(const std::string &username)
{
    for (User &user : users)
    {
        if (user.getUsername() == username)
        {
            return &user; // Return a pointer to the user if found
        }
    }
    return nullptr; // Return nullptr if the user is not found
}

void UserSystem::saveRentalRequestsToFile(const std::string &filename)
{
    // Open the file for writing (in append mode)
    std::ofstream file(filename, std::ios::app);

    // Check if the file is open
    if (!file.is_open())
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    // Iterate through the rentalRequests vector and save each request to the file
    for (const RentalRequest &request : rentalRequests)
    {
        // Format the data and write it to the file
        file << request.getRequestingUser() << ","
             << request.getMotorbikeOwner() << ","
             << request.getStartTime() << "," // Save startTime
             << request.getEndTime() << ","   // Save endTime
             << request.getCredit() << ","    // Save credit
             << (request.isAccepted() ? "1" : "0") << ","
             << (request.isRejected() ? "1" : "0") << "\n";
    }

    // Flush the file to ensure immediate writing
    file.flush();

    // Close the file
    file.close();
}

void UserSystem::updateRentalRequestsToFile(const std::string &filename, const std::vector<RentalRequest> &updatedRequests)
{
    std::ofstream outFile(filename);

    if (!outFile.is_open())
    {
        std::cerr << "Cannot open file for writing: " << filename << std::endl;
        return;
    }

    for (const RentalRequest &request : updatedRequests)
    {
        outFile << request.getRequestingUser() << ","
                << request.getMotorbikeOwner() << ","
                << request.getStartTime() << ","
                << request.getEndTime() << ","
                << request.getCredit() << ","
                << request.isAccepted() << ","
                << request.isRejected() << std::endl;
    }

    outFile.close();
}

void UserSystem::storeRentalRequest(const RentalRequest &request)
{
    // Update the rental request with start and end times
    RentalRequest updatedRequest = request;

    // Add the updated request to the list of rental requests
    rentalRequests.push_back(updatedRequest);

    // Save the updated list of rental requests to a file
    saveRentalRequestsToFile("./appdata/rental_requests.txt");
}

void UserSystem::requestMotorbikeRental(UserSystem &userSystem, const User &loggedInUser, const std::vector<Motorbike> &availableMotorbikes)
{
    int choice = 0;

    std::cout << "Enter the number of the motorbike you want to request (0 to cancel): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= availableMotorbikes.size())
    {
        Motorbike selectedMotorbike = availableMotorbikes[choice - 1];
        std::string ownerUsername = selectedMotorbike.getOwnerUsername();

        // Access startTime and endTime from selectedMotorbike
        std::time_t startTime = selectedMotorbike.getStartTime();
        std::time_t endTime = selectedMotorbike.getEndTime();

        // Request to rent the selected motorbike
        selectedMotorbike.requestToRentMotorbike(loggedInUser.getUsername(), ownerUsername, startTime, endTime, loggedInUser.getCreditPoints());

        bool accepted = false;
        bool rejected = false;

        RentalRequest request(loggedInUser.getUsername(), ownerUsername, startTime, endTime, loggedInUser.getCreditPoints(), accepted, rejected);

        userSystem.storeRentalRequest(request);
    }
    else if (choice != 0)
    {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void UserSystem::loadAndDisplayRentalRequests()
{
    // Load rental requests from the file
    std::ifstream inFile("./appdata/rental_requests.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Cannot open rental requests file!" << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;            // Keep track of the line number being processed
    bool ownerHasRequests = false; // Flag to check if the owner has any requests
    int requestNumber = 0;

    while (std::getline(inFile, line))
    {
        lineNumber++; // Increment line number
        std::stringstream ss(line);
        std::ostringstream ossCredit;
        ossCredit << std::fixed << std::setprecision(1);
        std::string requestingUser, motorbikeOwner;
        time_t startTime, endTime;
        double credit;
        bool accepted;
        bool rejected;

        if (std::getline(ss, requestingUser, ',') &&
            std::getline(ss, motorbikeOwner, ',') &&
            ss >> startTime && ss.ignore() &&
            ss >> endTime && ss.ignore() &&
            ss >> credit && ss.ignore() &&
            ss >> accepted && ss.ignore() &&
            ss >> rejected)
        {
            // Check if the motorbike owner matches the logged-in user's username
            if (motorbikeOwner == loggedInUser.getUsername())
            {
                ownerHasRequests = true; // Owner has requests
                requestNumber++;

                // Create a RentalRequest object
                RentalRequest request(requestingUser, motorbikeOwner, startTime, endTime, credit, accepted, rejected);

                // Add the request to the rentalRequests vector
                rentalRequests.push_back(request);

                // Display the rental request information
                std::cout << "ALL RENTAL REQUEST OF YOUR MOTORBIKE" << std::endl;
                std::cout << "-----------------------------" << std::endl;
                std::cout << "Request " << requestNumber << " from: " << request.getRequestingUser() << std::endl;
                std::cout << "Motorbike owner: " << request.getMotorbikeOwner() << std::endl;
                std::cout << "Start Time: " << timestampToString(request.getStartTime()) << std::endl;
                std::cout << "End Time: " << timestampToString(request.getEndTime()) << std::endl;
                ossCredit << request.getCredit();
                std::cout << "Credit: " << ossCredit.str() << std::endl;
                std::cout << "Accepted: " << request.isAccepted() << ", Rejected: " << request.isRejected() << std::endl;
                if (request.isAccepted())
                {
                    std::cout << "Status: Accepted" << std::endl;
                }
                else if (request.isRejected())
                {
                    std::cout << "Status: Rejected" << std::endl;
                }
                else
                {
                    std::cout << "Status: Pending" << std::endl;
                }
                std::cout << "-----------------------------" << std::endl;
            }
        }
        else
        {
            std::cerr << "Error parsing line " << lineNumber << ": " << line << std::endl;
        }
    }

    inFile.close();
    if (!ownerHasRequests)
    {
        std::cout << "You don't have any pending requests." << std::endl;
        return;
    }

    int choice = 0;
    do
    {
        std::cout << "Enter the number of the request to accept (0 to exit): ";
        std::cin >> choice;

        if (choice >= 1 && choice <= rentalRequests.size())
        {
            RentalRequest &request = rentalRequests[choice - 1];
            if (!request.isAccepted() && !request.isRejected())
            {
                // Process the selected request
                request.setAccepted(true); // Accept the selected request
                std::cout << "Request accepted." << std::endl;

                // Update the status of other requests with the same renting time
                for (RentalRequest &otherRequest : rentalRequests)
                {
                    if (&otherRequest != &request && !otherRequest.isAccepted() && !otherRequest.isRejected() &&
                        otherRequest.getStartTime() <= request.getEndTime() &&
                        otherRequest.getEndTime() >= request.getStartTime())
                    {
                        otherRequest.setRejected(true); // Mark as "Rejected"
                    }
                }

                // Save the updated requests to the file
                updateRentalRequestsToFile("./appdata/rental_requests.txt", rentalRequests);
            }
            else
            {
                std::cout << "Request has already been accepted or rejected." << std::endl;
            }
        }
        else if (choice != 0)
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();                                                   // Clear any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        }
    } while (choice != 0);
}

void UserSystem::renterRating()
{
    // Load rental requests from the file
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    std::ifstream inFile("./appdata/rental_requests.txt");
    if (!inFile.is_open())
    {
        std::cerr << "Cannot open rental requests file!" << std::endl;
        return;
    }
    std::string line;
    int lineNumber = 0;            // Keep track of the line number being processed
    bool ownerHasRequests = false; // Flag to check if the owner has any requests
    int requestNumber = 0;
    std::time_t time_now = std::time(0); 
    bool x=false;
    while (std::getline(inFile, line))
    {
        lineNumber++; // Increment line number
        std::stringstream ss(line);
        std::ostringstream ossCredit;
        ossCredit << std::fixed << std::setprecision(1);
        std::string requestingUser, motorbikeOwner;
        time_t startTime, endTime;
        double credit;
        bool accepted;
        bool rejected;

        if (std::getline(ss, requestingUser, ',') &&
            std::getline(ss, motorbikeOwner, ',') &&
            ss >> startTime && ss.ignore() &&
            ss >> endTime && ss.ignore() &&
            ss >> credit && ss.ignore() &&
            ss >> accepted && ss.ignore() &&
            ss >> rejected)
        {
            // Check if the motorbike owner matches the logged-in user's username
            if (motorbikeOwner == loggedInUser.getUsername())
            {
                string eTime;
                
                ss<<endTime;
                ss>>eTime;

                if (accepted==true && eTime<buf){
                    x = true;
                    cout << requestingUser<< " has finished renting your bike.\nRating available now.\n";
                }
        }
        else
        {
            std::cerr << "Error parsing line " << lineNumber << ": " << line << std::endl;
            return;
        }
    }

    inFile.close();
    if (!x)
    {
        std::cout << "You don't have any pending requests." << std::endl;
    }
    return;
    }
}