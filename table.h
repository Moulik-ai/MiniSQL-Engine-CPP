#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Row{
    vector<string> values;
};

class Table {
    public:
    string name;
    vector<string> columns;
    vector<Row> rows;
    unordered_map<string, unordered_map<string, vector<int>>> indexes; //hash functions (use of pure discrete mathematics) to create indexes for columns

    Table() {}
    Table(string tableName, vector<string> cols) {
        name = tableName;
        columns = cols;
    }

    void insertRow(vector<string> values);
    void printTable();
    void createIndex(string columnName);
};

#endif