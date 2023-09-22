/* Manage the whole system */
#ifndef USERSYSTEM_H
#define USERSYSTEM_H

#include <vector>
#include <string>
#include <map>
#include "Admin.h"
#include "User.h"
#include "Motorbike.h"

class UserSystem
{
private:
    std::vector<User> users;
    std::vector<Motorbike> motorbikes;

    Admin loggedInAdmin;
    User loggedInUser;
    std::vector<RentalRequest> rentalRequests;


public:
    UserSystem();

    /*Getter*/
    std::vector<User> &getUsers();
    std::vector<Motorbike> &getMotorbikes();
    std::map<std::string, User> &getUserMap();
    const Admin &getAdmin();
    const User &getLoggedInUser();

    /*Setter*/

    /*Import-Add Data*/
    bool importUsers();
    bool importMotorbikes();
    // Add new user to System
    bool addUser(const User &user);
    // Add new motorbike to System
    bool addMotorbike(const Motorbike &motorbike);
    // Add the Motorbike to corresponding User
    // void mapMotorbikeToUser();
    /*Update data*/
    void updateUserInFile(const User &updatedUser);
    void updateMotorbikeInFile(const Motorbike &updatedMotorbike);
    void updateLoggedInUserInfo();

    /*Others*/
    bool registerNewUser(const std::string &username, const std::string &fullName, const std::string &password, std::string phoneNumber, int idType, const std::string &idNumber, const std::string &driverLicense, const std::string &expiryDate, double creditPoints);
    bool registerNewMotorbike(const Motorbike &newMotorbike);

    bool isUsernameExisted(const std::string& username) const;
    bool checkAdmin(const std::string &inputUsername, const std::string &inputPassword);
    bool checkLogin(const std::string &username, const std::string &password);
    void logout();

    // Function to top up credit points for a user
    bool topUpUserCreditPoints(const std::string& username, double amount);

    // Enable the motorbike for renting (require the owner to input the motorbike requirement)
    void listMotorbikeForRent(Motorbike &motorbike, double creditPointsConsumed, double minRequiredRenterRating, std::string city);
    // Disable the motorbike from renting
    void unlistMotorbikeForRent(Motorbike &motorbike);
    // Search Motorbikes available for a period of time
    std::vector<Motorbike> searchAvailableMotorbikes(
    std::vector<Motorbike>& motorbikes,
    std::string userStartTime,
    std::string userEndTime,
    std::string city,
    User& user 
    );

    void addPendingRequestToOwner(const RentalRequest& request);
    User* findUserByUsername(const std::string& username);
    void storeRentalRequest(const RentalRequest& request);
    void requestMotorbikeRental(UserSystem& userSystem, const User& loggedInUser, const std::vector<Motorbike>& availableMotorbikes);
    void updateRentalRequestsToFile(const std::string& filename, const std::vector<RentalRequest>& updatedRequests); 
    void saveRentalRequestsToFile(const std::string& filename);
    void loadAndDisplayRentalRequests();
    void acceptOrRejectRequest();
     RenterRating();
};

#endif
