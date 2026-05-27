#include "TaskManager.hpp"

namespace lifehub {

TaskManager::TaskManager() {
    task_list;
}

void TaskManager::addTask(std::string& title, std::string& activityType) {
    Task task(title, activityType);
    task_list[title] = task;
}

void TaskManager::addTask(std::string& title, std::string& activityType, std::string& description) {
    Task task(title, activityType, description);
    task_list[title] = task;
}

void TaskManager::removeTask(std::string taskTitle) {
    task_list.erase(taskTitle);
}

void TaskManager::finishTask(std::string taskTitle) {
    task_list[taskTitle].finish();
}

void TaskManager::increaseTimeTask(std::string taskTitle, double incressedTime) {
    task_list[taskTitle].increaseTime(incressedTime);
}

std::vector<std::string> TaskManager::listTasks() {
    std::vector<std::string> out;
    
    for (auto& [title, task] : task_list) {
        out.push_back(title);
    }

    return out;
}

std::map<std::string, Task> TaskManager::getTaskList() {
    return task_list;
}

void TaskManager::setTaskDescription(std::string taskTitle, std:: string description) {
    task_list[taskTitle].setDescription(description);
}

std::string getTaskActivityType(std::string taskTitle);
std::string getTaskDescription(std::string taskTitle);
bool getTaskIsFinished(std::string taskTitle);
double getTaskInvestedTime(std::string taskTitle);


};
