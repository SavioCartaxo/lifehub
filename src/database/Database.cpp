// C:\Users\savio\OneDrive\Documentos\Work\lifehub\src\database\Database.cpp

#include "Database.hpp"
#include "models/Task.hpp"
#include <map>

bool Database::open()
{
    if (sqlite3_open("lifehub.db", &db) != SQLITE_OK)
        return false;

    const char* sql =
        "CREATE TABLE IF NOT EXISTS tasks ("
        "title TEXT PRIMARY KEY,"
        "description TEXT,"
        "activity_type TEXT,"
        "duration REAL,"
        "is_finished INTEGER"
        ");";

    sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    return true;
}

void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

sqlite3* Database::getConnection() {
    return db;
}

void Database::saveTask(const lifehub::Task& task)
{
    const char* sql =
        "INSERT OR REPLACE INTO tasks "
        "(title, description, activity_type, duration, is_finished) "
        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, task.getTitle().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, task.getDescription().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, task.getActivityType().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 4, task.getInvestedTime());
    sqlite3_bind_int(stmt, 5, task.isFinished() ? 1 : 0);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void Database::removeTask(const std::string& title)
{
    const char* sql = "DELETE FROM tasks WHERE title = ?;";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

std::map<std::string, lifehub::Task> Database::loadTasks() {
    std::map<std::string, lifehub::Task> tasks;
    const char* sql = "SELECT title, activity_type, description, duration, is_finished FROM tasks;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string title      = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string act_type   = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string desc       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        double duration        = sqlite3_column_double(stmt, 3);
        bool is_finished       = sqlite3_column_int(stmt, 4) != 0;
        lifehub::Task task(title, act_type, desc);
        task.setInvestedTime(duration);
        if (is_finished) task.finish();
        tasks.emplace(title, task);
    }
    sqlite3_finalize(stmt);
    return tasks;
}