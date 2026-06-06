#include "Database.hpp"

bool Database::open()
{
    return sqlite3_open("lifehub.db", &db) == SQLITE_OK;
}

void Database::close()
{
    if (db)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}