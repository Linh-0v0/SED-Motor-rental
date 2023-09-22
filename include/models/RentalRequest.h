// RentalRequest.h

#ifndef RENTALREQUEST_H
#define RENTALREQUEST_H

#include <string>

class RentalRequest {
public:
    RentalRequest(const std::string& requestingUser, const std::string& motorbikeOwner, std::time_t startTime, std::time_t endTime, bool accepted, bool rejected, bool rated);
    //Getter
    const std::string& getRequestingUser() const;
    const std::string& getMotorbikeOwner() const;
    std::time_t getStartTime() const;
    std::time_t getEndTime() const; // endTime of Motorbike to check users allowed for rating
    bool isAccepted() const; 
    bool isRejected() const;
    bool isRated() const;
    void setAccepted(bool value);
    void setRejected(bool value);
    void setIsRated(bool value);
    std::string toFileString() const;
    friend std::ostream& operator<<(std::ostream& os, const RentalRequest& request);

private:
    std::string requestingUser;
    std::string motorbikeOwner;
    std::time_t startTime;
    std::time_t endTime;
    bool accepted;
    bool rejected;
    bool rated;
};

#endif
