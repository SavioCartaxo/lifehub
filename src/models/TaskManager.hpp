#pragma once

#include <string>
#include <map>
#include <vector>
#include "Task.hpp"

namespace lifehub {

class TaskManager {

private:
    std::map<std::string, Task> task_list; // Nome da task será seu identificador unico (id)

public:
    TaskManager();

    void addTask(std::string& title, std::string& activityType);
    void addTask(std::string& title, std::string& activityType, std::string& description);
    void removeTask(std::string taskTitle);
    void finishTask(std::string taskTitle);
    void increaseTimeTask(std::string taskTitle, double incressedTime);
    std::vector<std::string> listTasks();
    std::map<std::string, Task> getTaskList();

    std::string getTaskActivityType(std::string taskTitle);
    std::string getTaskDescription(std::string taskTitle);
    bool getTaskIsFinished(std::string taskTitle);
    double getTaskInvestedTime(std::string taskTitle);

    void setTaskDescription(std::string taskTitle, std:: string description);
};

}