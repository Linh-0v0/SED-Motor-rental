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

float Motorbike::getAverageMotorbikeRating() const
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

float Motorbike::getAverageRenterRating() const
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
    os << "This is a property of member: " << motorbike.ownerUsername << endl;
    os << "Model : " << motorbike.model << endl;
    os << "Color:  " << motorbike.color << endl;
    os << "Engine size: " << motorbike.engineSize << endl;
    os << "Transmission mode: " << motorbike.transmissionMode << endl;
    os << "Description: " << motorbike.description << endl;
    os << "Available for rent: " << motorbike.listedForRent ? "yes" : "no";
    os << "Motorbike rating: " << motorbike.motorbikeRating << endl;
    os << "Required credit per day: " << motorbike.creditPerDay << endl;
    os << "Minimum renter's score: " << motorbike.minRenterRating << endl;

    return os;
}

/***** Others *****/
void Motorbike::viewMotorbikeDetails()
{
    cout << "***** MOTORBIKE *****" << endl;
    cout << "Model : " << model << endl;
    cout << "Color:  " << color << endl;
    cout << "Engine size: " << engineSize << endl;
    cout << "Transmission mode: " << transmissionMode << endl;
    cout << "Description: " << description << endl;
    cout << "Available for rent: " << listedForRent ? "yes" : "no";
    cout << "Required Credit per day: " << creditPerDay << endl;
    cout << "Minimum renter's score: " << minRenterRating << endl;
}
