#pragma once

#include <string>
#include "Task.hpp"
#include <map>

namespace lifehub {

class TaskManager {

private:
    std::map<std::string, Task> task_list; // Nome da task será seu identificador unico (id)

public:
    TaskManager();

    std::string listTasks();
    void addTask(std::string& title, std::string& activityType);
    void addTask(std::string& title, std::string& activityType, std::string& description);
    void removeTask(std::string taskTitle);
    void finishTask(std::string taskTitle);
    void increaseTimeTask(std::string taskTitle, double incressedTime);
    std::map<std::string, Task>& getTaskList();

    std::string getTaskActivityType(std::string taskTitle);
    std::string getTaskDescription(std::string taskTitle);
    bool getTaskIsFinished(std::string taskTitle);
    double getTaskInvestedTime(std::string taskTitle);
};

}