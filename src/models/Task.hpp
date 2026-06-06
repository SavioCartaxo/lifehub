#pragma once
#include <string>

namespace lifehub {
class Task {
private:
    std::string title;
    std::string description;
    std::string activity_type;
    double invested_time;
    bool is_finished;
public:
    Task(const std::string& title, const std::string& activityType);
    Task(const std::string& title, const std::string& activityType, const std::string& description);
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getActivityType() const;
    double getInvestedTime() const;
    bool isFinished() const;
    void setActivityType(const std::string& activityType);
    void setDescription(const std::string& description);
    void setIsFinished(bool isFinished);
    void setInvestedTime(double investedTime);
    void increaseTime(double t);
    void finish();
};
}