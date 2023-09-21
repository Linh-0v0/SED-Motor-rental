#ifndef USER_COMMENT_H
#define USER_COMMENT_H

#include <string>
#include <ctime>

struct UserComment
{
    std::string username;
    std::string comment;
    time_t endTime; // endTime to check users allowed for rating

    UserComment(const std::string &uname, const std::string &cmt, const time_t &time);

    // Getter and Setter Functions
    const std::string &getUsername() const;
    void setUsername(const std::string &uname);
    const std::string &getComment() const;
    void setComment(const std::string &cmt);
    const time_t &getEndTime() const;
    void setEndTime(const time_t &time);
};

#endif