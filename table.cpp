#include "table.h"

void Table::insertRow(vector<string> values) {
    if (values.size() != columns.size()){
        cout << "Coloumn count mismatch!\n";
        return;
    }
    rows.push_back({values});
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