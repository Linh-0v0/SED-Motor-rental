#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "../../include/utils/Time.h"
using namespace std;

// Convert a time string to a Unix timestamp
std::time_t stringToTimestamp(std::string timeStr) {
    std::tm tm = {};
    std::istringstream ss(timeStr);

    // Define the expected time string format (YYYY-MM-DD HH:MM:SS)
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        // Handle parsing error
        throw std::invalid_argument("Invalid time string format");
    }

    // Convert the std::tm structure to a Unix timestamp
    return std::mktime(&tm);
}

// Convert a Unix timestamp to a time string
std::string timestampToString(std::time_t timestamp) {
    // the str format "YYYY-MM-DD HH:MM:SS"
    std::tm tm = *std::localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

bool isValidDateTime(const std::string& input) {
    std::tm tm = {};
    std::istringstream ss(input);

    // Define the expected time string format (YYYY-MM-DD HH:MM:SS)
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    return !ss.fail();
}