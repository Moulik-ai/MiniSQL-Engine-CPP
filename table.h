#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Row{
    vector<string> values;
};

class Table {
    public:
    string name;
    vector<string> columns;
    vector<Row> rows;

    Table() {}
    Table(string tableName, vector<string> cols) {
        name = tableName;
        columns = cols;
    }

    void insertRow(vector<string> values);
    void printTable();
};

#endif