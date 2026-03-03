#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map> 
#include "table.h"

using namespace std;

class Database {
    public:
    unordered_map<string, Table> tables;

    void createTable(string name, vector<string> columns);
    void insertInto(string tableName, vector<string> values);
    void selectAll(string tableName);
    void selectWhere(string tableName, string column, string value);
};
#endif