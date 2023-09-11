#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "../../include/utils/Time.h"

// Convert a time string to a Unix timestamp
std::time_t stringToTimestamp(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream ss(timeStr);

    // Define the expected time string format (YYYY-MM-DD HH:MM:SS)
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        // Handle parsing error if needed
        // For example, you can throw an exception or return an error code
        throw std::invalid_argument("Invalid time string format");
    }

    // Convert the std::tm structure to a Unix timestamp
    return std::mktime(&tm);
}

// Convert a Unix timestamp to a time string
std::string timestampToString(std::time_t timestamp) {
    std::tm tm = *std::localtime(&timestamp);

    // Format the time string in the desired format (YYYY-MM-DD HH:MM:SS)
    std::ostringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

    return ss.str();
}