#include "../../include/models/User.h"
#include <iomanip>
#include <sstream>
#include <ctime>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"
#include "../../include/utils/Time.h"
using namespace std;

// void APPEND_BIKE_INFO(motorbike motorbike1){}

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
