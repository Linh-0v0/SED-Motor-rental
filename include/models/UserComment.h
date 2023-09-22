#ifndef USER_COMMENT_H
#define USER_COMMENT_H

#include <string>
#include <ctime>

struct UserComment
{
    std::string reviewer;
    std::string beingReviewed;
    std::string comment;
    time_t endTime; // endTime to check users allowed for rating
    double score;

    UserComment(const std::string &reviewer, const std::string &beingReviewed, const time_t &time, double score, const std::string &cmt);

    // Getter functions
    std::string getReviewer() const;
    std::string getBeingReviewed() const;
    std::string getComment() const;
    time_t getEndTime() const;
    double getScore() const;

    // Setter functions
    void setReviewer(const std::string &reviewer);
    void setBeingReviewed(const std::string &beingReviewed);
    void setComment(const std::string &comment);
    void setEndTime(const time_t &endTime);
    void setScore(double score);

    friend std::ostream &operator<<(std::ostream &os, const UserComment &comment);
};

#endif