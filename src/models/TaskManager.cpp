// C:\Users\savio\OneDrive\Documentos\Work\lifehub\src\models\TaskManager.hpp
#include "TaskManager.hpp"

namespace lifehub {

TaskManager::TaskManager() : database(nullptr) {}

TaskManager::TaskManager(Database& db) : database(&db) {
    task_list = database->loadTasks();
}

void TaskManager::addTask(const std::string& title, const std::string& activityType) {
    Task task(title, activityType);
    task_list.emplace(title, task);
    if (database) database->saveTask(task);
}

void TaskManager::addTask(const std::string& title, const std::string& activityType, const std::string& description) {
    Task task(title, activityType, description);
    task_list.emplace(title, task);
    if (database) database->saveTask(task);
}

void TaskManager::removeTask(const std::string& taskTitle) {
    task_list.erase(taskTitle);
    if (database) database->removeTask(taskTitle);
}

void TaskManager::finishTask(const std::string& taskTitle) {
    task_list.at(taskTitle).finish();
    if (database) database->saveTask(task_list.at(taskTitle));
}

void TaskManager::increaseTimeTask(const std::string& taskTitle, double increasedTime) {
    task_list.at(taskTitle).increaseTime(increasedTime);
    if (database) database->saveTask(task_list.at(taskTitle));
}

void TaskManager::setTaskDescription(const std::string& taskTitle, const std::string& description) {
    task_list.at(taskTitle).setDescription(description);
    if (database) database->saveTask(task_list.at(taskTitle));
}

std::vector<std::string> TaskManager::listTasks() {
    std::vector<std::string> out;
    for (auto& [title, task] : task_list)
        out.push_back(title);
    return out;
}

std::map<std::string, Task> TaskManager::getTaskList() {
    return task_list;
}

std::string TaskManager::getTaskActivityType(const std::string& taskTitle) {
    return task_list.at(taskTitle).getActivityType();
}

std::string TaskManager::getTaskDescription(const std::string& taskTitle) {
    return task_list.at(taskTitle).getDescription();
}

bool TaskManager::getTaskIsFinished(const std::string& taskTitle) {
    return task_list.at(taskTitle).isFinished();
}

double TaskManager::getTaskInvestedTime(const std::string& taskTitle) {
    return task_list.at(taskTitle).getInvestedTime();
}

}