// C:\Users\savio\OneDrive\Documentos\Work\lifehub\src\models\Task.cpp

#include "Task.hpp"

namespace lifehub {

Task::Task(const std::string& title, const std::string& activityType)
    : title(title), activity_type(activityType),
      description(""), invested_time(0.0), is_finished(false) {}

Task::Task(const std::string& title, const std::string& activityType, const std::string& description)
    : title(title), activity_type(activityType),
      description(description), invested_time(0.0), is_finished(false) {}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
std::string Task::getActivityType() const { return activity_type; }
double Task::getInvestedTime() const { return invested_time; }
bool Task::isFinished() const { return is_finished; }

void Task::setActivityType(const std::string& activityType) {
    activity_type = activityType;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

void Task::setIsFinished(bool isFinished) {
    is_finished = isFinished;
}

void Task::setInvestedTime(double investedTime) {
    invested_time = investedTime;
}

void Task::increaseTime(double incressedTime) {
    invested_time += incressedTime;
}

void Task::finish() {
    is_finished = true;
}

}