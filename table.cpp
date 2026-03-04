#include "table.h"
#include <iostream>
#include <unordered_map>

using namespace std;

void Table::insertRow(vector<string> values) {
    if (values.size() != columns.size()){
        cout << "Coloumn count mismatch!\n";
        return;
    }
    rows.push_back({values});
    int newRowIndex = rows.size() - 1;

    for (auto &idx : indexes) {
        string colName = idx.first;

        for (int i = 0; i < columns.size(); i++) {
            if (columns[i] == colName) {
                string val = values[i];
                indexes[colName][val].push_back(newRowIndex);
                break;
            }
        }
    }
}

void Table::printTable() {
    for (auto col : columns)
        cout << col << "\t";
    cout << "\n";

    for (auto row : rows) {
        for (auto val : row.values)
        cout << val << "\t";
        cout << "\n";
    }
}

void Table::createIndex(string columnName) {
    int columnIndex = -1;

    for (int i = 0; i < columns.size(); i++) {
        if (columns[i] == columnName) {
            columnIndex = i;
            break;
        }
    }

    if (columnIndex == -1) {
        cout << "Column not found!\n";
        return;
    }

    unordered_map<string, vector<int>> indexMap;

    for (int i = 0; i < rows.size(); i++) {
        string value = rows[i].values[columnIndex];
        indexMap[value].push_back(i);
    }

    indexes[columnName] = indexMap;

    cout << "Index created on column: " << columnName << endl;
}