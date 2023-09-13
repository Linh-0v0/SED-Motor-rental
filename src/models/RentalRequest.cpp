#include <iomanip>
#include <sstream>
#include <ctime>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"
#include "../../include/models/RentalRequest.h"
#include "../../include/utils/Time.h"
using namespace std;

int RentalRequest::requestIdCounter = 1;

// Implement the RentalRequest constructor
RentalRequest::RentalRequest(const std::string& requestingUser, const std::string& motorbikeOwner)
    : requestingUser(requestingUser), motorbikeOwner(motorbikeOwner),accepted(false) {
    // Generate a unique ID for the request
    requestId = requestIdCounter++;
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

bool RentalRequest::isAccepted() const {
    return accepted;
}

void RentalRequest::setAccepted(bool value) {
    accepted = value;
}

int RentalRequest::getRequestId() const
{
        return 0;
}