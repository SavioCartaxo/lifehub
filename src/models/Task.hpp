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
    Task(std::string& title, std::string& activityType);
    Task(std::string& title, std::string& activityType, std::string& description);

    std::string getTitle();
    std::string getDescription();
    std::string getActivityType();
    double getInvestedTime();
    bool isFinished();

    void setActivityType(std::string& activityType);
    void setDescription(std::string& description);
    void setIsFinished(bool isFinished);
    void setInvestedTime(double investedTime);

    /**
     * @brief Increases the time invested in this activity.
     * 
     * @param incressedTime Amount of time to add, as double.
     */
    void increaseTime(double incressedTime);

    /**
     * @brief Marks this actvity as finished.
     */
    void finish();
};

}