#include "database.h"
#include <iostream>

using namespace std;

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

void Database::selectColumns(string tableName, vector<string> selectedColumns) {
    if (tables.find(tableName) == tables.end()) {
        cout << "Table not found!\n";
        return;
    }

    Table& table = tables[tableName];

    vector<int> columnIndexes;

    if (selectedColumns.size() == 1 && selectedColumns[0] == "*") {
        table.printTable();
        return;
    }

    for (auto selcol : selectedColumns) {
        bool found = false;
        for (int i = 0; i < table.columns.size(); i++) {
            if (table.columns[i] == selcol) {
                columnIndexes.push_back(i);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Column " << selcol << " not found!\n";
            return;
        }
    }

    for (auto selcol : selectedColumns)
        cout << selcol << "\t";
    cout << "\n";

    for (auto row : table.rows){
        for (auto idx : columnIndexes)
             cout << row.values[idx] << "\t";
        cout << "\n";
    }
}

void Database::selectColumnsWhere(string tableName, vector<string> selectedColumns, string column, string value) {
    if (tables.find(tableName) == tables.end()) {
        cout << "Table not found!\n";
        return;
    }

    Table& table = tables[tableName];

    int whereIndex = -1;

    for (int i = 0; i < table.columns.size(); i++) {
        if (table.columns[i] == column) {
            whereIndex = i;
            break;
        }
    }

    if (whereIndex == -1) {
        cout << "Column not found!\n";
        return;
    }

    vector<int> columnIndexes;

    if (selectedColumns.size() == 1 && selectedColumns[0] == "*") {
        for (int i = 0; i < table.columns.size(); i++)
            columnIndexes.push_back(i);

    }
    else {
        for (auto selcol : selectedColumns) {
            bool found = false;
            for (int i = 0; i < table.columns.size(); i++) {
                if (table.columns[i] == selcol) {
                    columnIndexes.push_back(i);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Column " << selcol << " not found!\n";
                return;
            }
        }
    }

    for (auto idx : columnIndexes)
        cout << table.columns[idx] << "\t";
    cout << "\n";

    if (table.indexes.find(column) != table.indexes.end()) {

        cout << "Using index for optimization\n";
        auto &indexMap = table.indexes[column];

        if (indexMap.find(value) != indexMap.end()) {

            vector<int> matchingRows = indexMap[value];

            for (int rowIndex : matchingRows) {
                for (auto idx : columnIndexes)
                    cout << table.rows[rowIndex].values[idx] << "\t";
                cout << "\n";
            }

            return;
        }
    }


    cout << "Performing full table scan\n";
    for (auto row : table.rows) {
        if (row.values[whereIndex] == value) {
            for (auto idx : columnIndexes)
                cout << row.values[idx] << "\t";
            cout << "\n";
        }
    }
}