#include "Task.hpp"

namespace lifehub {

Task::Task(std::string& title, std::string& activityType) {
    this->title = title;
    this->activity_type = activityType;

    this->description = "";
    this->invested_time = 0.0;
    this->is_finished = false;
}

Task::Task(std::string& title, std::string& activityType, std::string& description) {
    this->title = title;
    this->activity_type = activityType;
    this->description = description;

    this->invested_time = 0.0;
    this->is_finished = false;
}

void Task::increaseTime(double incressedTime) {
    this->invested_time += incressedTime;
}

void Task::finish() {
    this->is_finished = true;
}

// Geters

std::string Task::getTitle() {
    return this->title;
}

std::string Task::getDescription() {
    return this->description;
}

std::string Task::getActivityType() {
    return this->activity_type;
}

double Task::getInvestedTime() {
    return this->invested_time;
}

bool Task::isFinished() {
    return this->is_finished;
}

// Seters

void Task::setActivityType(std::string& activityType) {
    this->activity_type = activityType;
}

void Task::setDescription(std::string& description) {
    this->description = description;
}

void Task::setIsFinished(bool isFinished) {
    this->is_finished = isFinished;
}

void Task::setInvestedTime(double investedTime) {
    this->invested_time = investedTime;
}

}