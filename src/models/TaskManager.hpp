// C:\Users\savio\OneDrive\Documentos\Work\lifehub\src\models\TaskManager.hpp

#pragma once
#include <string>
#include <map>
#include <vector>
#include "models/Task.hpp"
#include "database/Database.hpp"

namespace lifehub {
class TaskManager {
private:
    Database* database;
    std::map<std::string, Task> task_list;
public:
    TaskManager();
    TaskManager(Database& db);
    void addTask(const std::string& title, const std::string& activityType);
    void addTask(const std::string& title, const std::string& activityType, const std::string& description);
    void removeTask(const std::string& taskTitle);
    void finishTask(const std::string& taskTitle);
    void increaseTimeTask(const std::string& taskTitle, double time);
    void setTaskDescription(const std::string& taskTitle, const std::string& description);
    std::vector<std::string> listTasks();
    std::map<std::string, Task> getTaskList();
    std::string getTaskActivityType(const std::string& taskTitle);
    std::string getTaskDescription(const std::string& taskTitle);
    bool getTaskIsFinished(const std::string& taskTitle);
    double getTaskInvestedTime(const std::string& taskTitle);
};
}