#include <iomanip>
#include <sstream>
#include <ctime>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"
#include "../../include/models/RentalRequest.h"
#include "../../include/utils/Time.h"
using namespace std;


// Implement the RentalRequest constructor
RentalRequest::RentalRequest( const std::string& requestingUser, const std::string& motorbikeOwner, std::time_t startTime, std::time_t endTime, bool accepted, bool rejected, bool rated)
    : requestingUser(requestingUser), motorbikeOwner(motorbikeOwner), startTime(startTime), endTime(endTime), accepted(accepted), rejected(rejected), rated(rated) { 
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

bool RentalRequest::isRejected() const {
    return rejected;
}

void RentalRequest::setRejected(bool value) {
    rejected = value;
}

bool RentalRequest::isRated() const {
    return rated;
}

void RentalRequest::setIsRated(bool value) {
    rated = value;
}

std::string RentalRequest::toFileString() const
{
    std::stringstream ss;
    ss << requestingUser << ","
       << motorbikeOwner << ","
       << startTime << ","
       << endTime << ","
       << accepted << ","
       << rejected << ","
       << rated;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const RentalRequest& request) {
    // You can format and output the attributes as desired
    os << "Requesting User: " << request.requestingUser << std::endl;
    os << "Motorbike Owner: " << request.motorbikeOwner << std::endl;
    os << "Start Time: " << std::put_time(std::localtime(&request.startTime), "%Y-%m-%d %H:%M:%S") << std::endl;
    os << "End Time: " << std::put_time(std::localtime(&request.endTime), "%Y-%m-%d %H:%M:%S") << std::endl;
    os << "Accepted: " << (request.accepted ? "Yes" : "No") << std::endl;
    os << "Rejected: " << (request.rejected ? "Yes" : "No") << std::endl;
    os << "Rated: " << (request.rated ? "Yes" : "No") << std::endl;

    return os;
}