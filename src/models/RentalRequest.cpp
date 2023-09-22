#include <iomanip>
#include <sstream>
#include <ctime>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"
#include "../../include/models/RentalRequest.h"
#include "../../include/utils/Time.h"
using namespace std;


// Implement the RentalRequest constructor
RentalRequest::RentalRequest( const std::string& requestingUser, const std::string& motorbikeOwner, std::time_t startTime, std::time_t endTime, bool accepted, bool rejected)
    : requestingUser(requestingUser), motorbikeOwner(motorbikeOwner), startTime(startTime), endTime(endTime), accepted(accepted), rejected(rejected) { 
    this->requestingUser = requestingUser;
    this->motorbikeOwner = motorbikeOwner;

}


// Implement the getRequestingUser function
const std::string& RentalRequest::getRequestingUser() const {

    return requestingUser;
}

// Implement the getMotorbikeOwner function
const std::string& RentalRequest::getMotorbikeOwner() const {
    return motorbikeOwner;
}


std::time_t RentalRequest::getStartTime() const {
    return startTime;
}

std::time_t RentalRequest::getEndTime() const {
    return endTime;
}

bool RentalRequest::isAccepted() const {
    return accepted;
}

void RentalRequest::setAccepted(bool value) {
    accepted = value;
}

bool  RentalRequest::isRejected() const {
    return rejected;
}

void RentalRequest::setRejected(bool value) {
    rejected = value;
}
