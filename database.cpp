#include "database.h"
#include <iostream>

void Database::createTable(string name, vector<string> columns) {
    if (tables.find(name) != tables.end()) {
        cout << "Table already exists!\n";
        return;
    }
    tables[name] = Table(name, columns);
    cout << "Tables created successfully.\n";
}

void Database::insertInto(string tableName, vector<string> values) {
    if (tables.find(tableName) == tables.end()){
        cout << "Table not found!\n";
        return;
    }
    tables[tableName].insertRow(values);
}

void Database::selectAll(string tableName) {
    if (tables.find(tableName) == tables.end()) {
        cout << "Table not found!\n";
        return;
    }
    tables[tableName].printTable();
}