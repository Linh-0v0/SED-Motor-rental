// RentalRequest.h

#ifndef RENTALREQUEST_H
#define RENTALREQUEST_H

#include <string>

class RentalRequest {
public:
    RentalRequest(const std::string& requestingUser, const std::string& motorbikeOwner);

    //Getter
    int getRequestId() const;
    const std::string& getRequestingUser() const;
    const std::string& getMotorbikeOwner() const;
    bool isAccepted() const; 

    // Declare the setAccepted member function
    void setAccepted(bool value);


private:
    static int requestIdCounter; //generate unique request IDs
    int requestId; // Request ID for each request instance
    std::string requestingUser;
    std::string motorbikeOwner;
    bool accepted;
};

#endif
