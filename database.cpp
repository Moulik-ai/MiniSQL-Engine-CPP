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

void Database::selectWhere(string tableName, string column, string value) {
    if (tables.find(tableName) == tables.end()) {
        cout << "Table not found!\n";
        return;
    }

    Table& table = tables[tableName];

    int columnIndex = -1;

    for (int i = 0; i < table.columns.size(); i++) {
        if (table.columns[i] == column) {
            columnIndex = i;
            break;
        }
    }

    if (columnIndex == -1) {
        cout << "Column not found!\n";
        return;
    }

    for (auto col : table.columns)
        cout << col << "\t";
    cout << "\n";

    for (auto row : table.rows) {
        if (row.values[columnIndex] == value){
            for (auto val : row.values)
                cout << val << "\t";
        cout << "\n";
        }
    }
}