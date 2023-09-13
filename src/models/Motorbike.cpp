#include <iomanip>
#include <sstream>
#include <ctime>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"
#include "../../include/models/RentalRequest.h"
#include "../../include/utils/Time.h"
using namespace std;

// Parameterized constructor
Motorbike::Motorbike(const std::string &ownerUsername, const std::string &model, const std::string &color, const std::string &engineSize, const std::string &transmissionMode, int yearMade, const std::string &description, bool listedForRent, double motorbikeRating, double creditPerDay, double minRenterRating, std::time_t startTime, std::time_t endTime, std::string city) : ownerUsername(ownerUsername), model(model), color(color), engineSize(engineSize), transmissionMode(transmissionMode), yearMade(yearMade), description(description), listedForRent(listedForRent), motorbikeRating(motorbikeRating), creditPerDay(creditPerDay), minRenterRating(minRenterRating), startTime(startTime), endTime(endTime), city(city){};

/***** Getter *****/
std::string Motorbike::getOwnerUsername() const
{
    return ownerUsername;
}

bool Motorbike::getListedForRent()
{
    return listedForRent;
}

double Motorbike::getCreditPerDay() const
{
    return creditPerDay;
}

int Motorbike::getMinRenterRating() const
{
    return minRenterRating;
}

std::time_t Motorbike::getStartTime() const
{
    return startTime;
}

std::time_t Motorbike::getEndTime() const
{
    return endTime;
}

std::string Motorbike::getCity() const
{
    return city;
}

/***** Setter *****/
void Motorbike::setListedForRent(bool isListed)
{
    listedForRent = isListed;
}

void Motorbike::setMotorbikeRating(double motorbikeRating)
{
    this->motorbikeRating = motorbikeRating;
}

void Motorbike::setCreditPerDay(int creditPointsConsumed)
{
    this->creditPerDay = creditPointsConsumed;
}

void Motorbike::setMinRequiredRenterRating(int minRequiredRenterRating)
{
    this->minRenterRating = minRequiredRenterRating;
}

void Motorbike::setCity(std::string city)
{
    this->city = city;
}

/***** Operator *****/
bool Motorbike::operator==(const Motorbike &other) const
{
    // Define how two Motorbike objects are considered equal
    return (model == other.model &&
            color == other.color &&
            engineSize == other.engineSize &&
            transmissionMode == other.transmissionMode &&
            yearMade == other.yearMade &&
            description == other.description);
}

/* Operator */
std::ostream &operator<<(std::ostream &os, const Motorbike &motorbike)
{
    std::string startTimeString = timestampToString(motorbike.getStartTime());
    std::string endTimeString = timestampToString(motorbike.getEndTime());

    os << "This is a property of member: " << motorbike.ownerUsername << endl;
    os << "Model : " << motorbike.model << endl;
    os << "Color:  " << motorbike.color << endl;
    os << "Engine size: " << motorbike.engineSize << endl;
    os << "Transmission mode: " << motorbike.transmissionMode << endl;
    os << "Description: " << motorbike.description << endl;
    os << "Available for rent: " << (motorbike.listedForRent ? "yes" : "no") << endl;
    os << "Motorbike rating: " << motorbike.motorbikeRating << endl;
    os << "Required credit per day: " << motorbike.creditPerDay << endl;
    os << "Minimum renter's score: " << motorbike.minRenterRating << endl;
    os << "Start time: " << startTimeString << endl;
    os << "End time: " << endTimeString << endl;
    os << "City: " << motorbike.city << endl;

    return os;
}

/***** Others *****/
double Motorbike::calcAverageMotorbikeRating() const
{
    if (motorbikeRatings.empty())
    {
        return 0.0;
    }
    float sum = 0.0;
    for (double mr : motorbikeRatings)
    {
        sum += mr;
    }
    return sum / motorbikeRatings.size();
}

// Implement the toFileString() method
std::string Motorbike::toFileString() const
{
    std::ostringstream oss1, oss2, oss3;
    oss1 << std::fixed << std::setprecision(1); // Set precision to 1 decimal place
    oss2 << std::fixed << std::setprecision(1);
    oss3 << std::fixed << std::setprecision(1);
    // Convert the double to a string with the specified format
    oss1 << motorbikeRating;
    oss2 << creditPerDay;
    oss3 << minRenterRating;
    std::string startTimeString = timestampToString(getStartTime());
    std::string endTimeString = timestampToString(getEndTime());

    // Format the Motorbike data as a string
    std::string result = ownerUsername + "," + model + "," + color + "," + engineSize + "," + transmissionMode + "," + std::to_string(yearMade) + "," + description + "," + (listedForRent ? "yes" : "no") + "," + oss1.str() + "," + oss2.str() + "," + oss3.str() + "," + startTimeString + "," + endTimeString + "," + city;

    return result;
}


// Implement the requestToRentMotorbike function
void Motorbike::requestToRentMotorbike(const std::string& requestingUser) {
    // Check if the motorbike is available for rent
    if (listedForRent) {
        // Create a rental request and add it to the pending requests
        RentalRequest request(requestingUser, ownerUsername);
        pendingRequests.push_back(request);

        cout << "Request to rent the motorbike has been sent." << endl;
    } else {
        cout << "This motorbike is not available for rent at the moment." << endl;
    }
}

// Implement the getPendingRequests function
const std::vector<RentalRequest>& Motorbike::getPendingRequests() const {
    return pendingRequests;
}

// Implement the handlePendingRequest function
void Motorbike::handlePendingRequest() {
    // Display the pending rental requests for the motorbike
    std::cout << "Pending Rental Requests for Motorbike: " << model << std::endl;

    int requestIndex = 1;

    for (const RentalRequest& request : pendingRequests) {
        std::cout << "Request " << requestIndex << ":" << std::endl;
        std::cout << "Requesting User: " << request.getRequestingUser() << std::endl;
        std::cout << "Accepted: " << (request.isAccepted() ? "Yes" : "No") << std::endl;
        std::cout << std::endl;
        requestIndex++;
    }

    // Allow the owner to choose and handle a request
    int choice;

    do {
        std::cout << "Enter the number of the request you want to handle (0 to exit): ";
        std::cin >> choice;

        if (choice >= 1 && choice <= pendingRequests.size()) {
            // Handle the selected request (e.g., accept or reject it)
            RentalRequest& selectedRequest = pendingRequests[choice - 1];

            // You can implement the logic to accept or reject the request here
            // For example, set selectedRequest as accepted and others as rejected

            std::cout << "Request " << choice << " has been handled." << std::endl;
            break; // Exit the loop
        } else if (choice != 0) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
}

