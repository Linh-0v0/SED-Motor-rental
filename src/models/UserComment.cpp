#include "../../include/models/UserComment.h"

#include <ctime>
#include <string>

// Constructor implementation
UserComment::UserComment(const std::string& uname, const std::string& cmt, const time_t& time)
    : username(uname), comment(cmt), endTime(time) {}

// Getter and Setter Function Implementations
const std::string& UserComment::getUsername() const {
    return username;
}

void UserComment::setUsername(const std::string& uname) {
    username = uname;
}

const std::string& UserComment::getComment() const {
    return comment;
}

void UserComment::setComment(const std::string& cmt) {
    comment = cmt;
}

const time_t& UserComment::getEndTime() const {
    return endTime;
}

void UserComment::setEndTime(const time_t& time) {
    endTime = time;
}