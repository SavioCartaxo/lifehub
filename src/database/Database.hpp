#pragma once

#include <string>
#include <map>
#include "models/Task.hpp"
#include "sqlite3.h"

class Database {
private:
    sqlite3* db = nullptr;
public:
    bool open();
    void close();
    sqlite3* getConnection();
    void saveTask(const lifehub::Task& task);
    void removeTask(const std::string& title);
    std::map<std::string, lifehub::Task> loadTasks();
};