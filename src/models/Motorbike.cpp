#include <iomanip>
#include <sstream>
#include "../../include/models/User.h"
#include "../../include/models/Motorbike.h"

// Parameterized constructor
Motorbike::Motorbike(const std::string &ownerUsername, const std::string &model, const std::string &color, const std::string &engineSize, const std::string &transmissionMode, int yearMade, const std::string &description, bool listedForRent, double motorbikeRating, double creditPerDay, double minRenterRating) : ownerUsername(ownerUsername), model(model), color(color), engineSize(engineSize), transmissionMode(transmissionMode), yearMade(yearMade), description(description), listedForRent(false), motorbikeRating(motorbikeRating), creditPerDay(creditPerDay), minRenterRating(minRenterRating){};

/***** Getter *****/
const std::string &Motorbike::getOwnerUsername() const
{
    return ownerUsername;
}

double Motorbike::getCreditPerDay() const
{
    return creditPerDay;
}

int Motorbike::getMinRenterRating() const
{
    return minRenterRating;
}

double Motorbike::getAverageMotorbikeRating() const
{
    // if (motorbikeRatings.empty()) {
    //     return 0.0;
    // }
    // float sum = 0.0;
    // for (const ScoreRating& rating : motorbikeRatings) {
    //     sum += rating.getMotorbikeRating();
    // }
    // return sum / motorbikeRatings.size();
}

double Motorbike::getAverageRenterRating() const
{
    // if (renterRatings.empty()) {
    //     return 0.0;
    // }
    // float sum = 0.0;
    // for (float rating : renterRatings) {
    //     sum += rating;
    // }
    // return sum / renterRatings.size();
}

/***** Setter *****/
void Motorbike::setListedForRent(bool isListed)
{
    listedForRent = isListed;
}

void Motorbike::setCreditPerDay(int creditPointsConsumed)
{
    this->creditPerDay = creditPointsConsumed;
}

void Motorbike::setMinRequiredRenterRating(int minRequiredRenterRating)
{
    this->minRenterRating = minRequiredRenterRating;
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
    std::string isListedForRent = motorbike.listedForRent ? "yes" : "no";
    os << "This is a property of member: " << motorbike.ownerUsername << endl;
    os << "Model : " << motorbike.model << endl;
    os << "Color:  " << motorbike.color << endl;
    os << "Engine size: " << motorbike.engineSize << endl;
    os << "Transmission mode: " << motorbike.transmissionMode << endl;
    os << "Description: " << motorbike.description << endl;
    os << "Available for rent: " << isListedForRent << endl;
    os << "Motorbike rating: " << motorbike.motorbikeRating << endl;
    os << "Required credit per day: " << motorbike.creditPerDay << endl;
    os << "Minimum renter's score: " << motorbike.minRenterRating << endl;

    return os;
}

/***** Others *****/
void Motorbike::viewMotorbikeDetails()
{
    std::string isListedForRent = listedForRent ? "yes" : "no";
    cout << "***** MOTORBIKE *****" << endl;
    cout << "Model : " << model << endl;
    cout << "Color:  " << color << endl;
    cout << "Engine size: " << engineSize << endl;
    cout << "Transmission mode: " << transmissionMode << endl;
    cout << "Description: " << description << endl;
    cout << "Available for rent: " << isListedForRent << endl;
    cout << "Required Credit per day: " << creditPerDay << endl;
    cout << "Minimum renter's score: " << minRenterRating << endl;
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
    // Format the Motorbike data as a string
    std::string result = ownerUsername + "," + model + "," + color + "," + engineSize + "," + transmissionMode + "," + std::to_string(yearMade) + "," + description + "," + (listedForRent ? "true" : "false") + "," + oss1.str() + "," + oss2.str() + "," + oss3.str();

    return result;
}
