// #ifndef USER_H
// #define USER_H

// #include <string>

// class User {
// private:
//     std::string username;
//     std::string fullName;
//     std::string phoneNumber;
//     std::string idType;
//     std::string idNumber;
//     std::string driverLicenseNumber;
//     std::string expiryDate;
//     int creditPoints;

// public:
//     User(const std::string& username, const std::string& fullName,
//          const std::string& phoneNumber, const std::string& idType,
//          const std::string& idNumber, const std::string& driverLicenseNumber,
//          const std::string& expiryDate);

//     // Getter methods for all the member variables

//     void registerUser();
// };

// #endif

#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& firstName, const std::string& lastName);
    std::string getFullName() const;
    int getCreditPoints() const;

private:
    std::string firstName;
    std::string lastName;
    int creditPoints;
};

#endif
