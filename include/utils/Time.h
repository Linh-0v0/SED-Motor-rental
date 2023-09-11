#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <string>

std::time_t stringToTimestamp(const std::string& timeStr);
std::string timestampToString(std::time_t timestamp);

#endif