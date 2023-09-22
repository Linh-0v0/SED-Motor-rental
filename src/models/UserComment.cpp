#include "../../include/models/UserComment.h"

#include <iostream>
#include <ctime>
#include <string>
#include "../../include/utils/Time.h"

// Constructor implementation
// Constructor implementation
UserComment::UserComment(const std::string &reviewer, const std::string &beingReviewed, const time_t &time, double score, const std::string &cmt)
    : reviewer(reviewer), beingReviewed(beingReviewed), endTime(time), score(score), comment(cmt) {}

// Getter implementations
std::string UserComment::getReviewer() const {
    return reviewer;
}

std::string UserComment::getBeingReviewed() const {
    return beingReviewed;
}

std::string UserComment::getComment() const {
    return comment;
}

time_t UserComment::getEndTime() const {
    return endTime;
}

double UserComment::getScore() const {
    return score;
}

// Setter implementations
void UserComment::setReviewer(const std::string &reviewer) {
    this->reviewer = reviewer;
}

void UserComment::setBeingReviewed(const std::string &beingReviewed) {
    this->beingReviewed = beingReviewed;
}

void UserComment::setComment(const std::string &comment) {
    this->comment = comment;
}

void UserComment::setEndTime(const time_t &endTime) {
    this->endTime = endTime;
}

void UserComment::setScore(double score) {
    this->score = score;
}

std::ostream &operator<<(std::ostream &os, const UserComment &comment) {
    os << "Reviewer: " << comment.reviewer << std::endl;
    os << "Being Reviewed: " << comment.beingReviewed << std::endl;
    os << "Time: " << timestampToString(comment.endTime) << std::endl;
    os << "Score: " << comment.score << std::endl;
    os << "Comment: " << comment.comment << std::endl;
    return os;
}
