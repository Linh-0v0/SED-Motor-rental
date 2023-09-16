// RentalRequest.h

#ifndef RENTALREQUEST_H
#define RENTALREQUEST_H

#include <string>

class RentalRequest {
public:
    RentalRequest(const std::string& requestingUser, const std::string& motorbikeOwner, std::time_t startTime, std::time_t endTime, double credit, bool accepted, bool rejected);
    //Getter
    const std::string& getRequestingUser() const;
    const std::string& getMotorbikeOwner() const;
    std::time_t getStartTime() const;
    std::time_t getEndTime() const;
    double getCredit() const;
    bool isAccepted() const; 
    bool isRejected() const;
    void setAccepted(bool value);
    void setRejected(bool value);


private:
    std::string requestingUser;
    std::string motorbikeOwner;
    std::time_t startTime;
    std::time_t endTime;
    double credit;
    bool accepted;
    bool rejected;
};

#endif
