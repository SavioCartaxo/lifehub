#pragma once

#include "third_party/sqlite-amalgamation-3530200/sqlite-amalgamation-3530200/sqlite3.h"

class Database
{
private:
    sqlite3* db = nullptr;

public:
    bool open();
    void close();
};