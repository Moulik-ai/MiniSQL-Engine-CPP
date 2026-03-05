#include "engine.h"
#include <iostream>

void Engine::execute(string command) {
    vector<string> tokens = split(command);

    if (tokens.empty()) {
        return;
    }

    if (tokens[0] == "CREATE") {
        string tableName = tokens[2];

        vector<string> columns;
        for (int i = 3; i < tokens.size(); i++) {
            columns.push_back(tokens[i]);
        }

        db.createTable(tableName, columns);
    }

    else if (tokens[0] == "INSERT") {
        string tableName = tokens[2];

        vector<string> values;
        for (int i = 4; i < tokens.size(); i++) {
            values.push_back(tokens[i]);
        }

        for (auto t : tokens) 
            cout << t << " ";
        cout << endl;

        db.insertInto(tableName, values);
    }

    else if (tokens[0] == "SELECT"){

        vector<string> selectedColumns;
        int i = 1;

        while (tokens[i] != "FROM") {
            selectedColumns.push_back(tokens[i]);
            i++;
        }
        
        string tableName = tokens[i+1];

        if (tokens.size() > i+2 && tokens[i+2] == "WHERE"){

            string column = tokens[i+3];
            string value = tokens[i+5];
            db.selectColumnsWhere(tableName, selectedColumns, column, value);
        }
        else {
        db.selectColumns(tableName, selectedColumns);
    }
    }

    else if (tokens[0] == "CREATE" && tokens[1] == "INDEX") {

        string tableName = tokens[3];
        string columnName = tokens[4];
        
        db.tables[tableName].createIndex(columnName);
    }


    else if (tokens[0] == "DELETE") {

        string tableName = tokens[2];
        string column = tokens[4];
        string value = tokens[6];

        db.deleteWhere(tableName, column, value);
    }

    else if (tokens[0] == "UPDATE") {

        string column = tokens[7];
        string tableName = tokens[4];

        Table &table = db.tables[tableName];

        if (table.indexes.find(column) != table.indexes.end()) {

            cout << "Query Plan:\n";
            cout << "Index Scan on " << tableName << "(" << column << ")\n";
        }
    }

    else if (tokens[0] == "EXPLAIN") {

        if (tokens.size() < 9) {
            cout << "Invalid EXPLAIN syntax\n";
            return;
        }

        string tableName = tokens[4];
        string column = tokens[6];

        Table &table = db.tables[tableName];

        cout << "Query Plan: \n";

        if (table.indexes.find(column) != table.indexes.end()) {

            cout << "Index scan on "
                << tableName
                << "("
                << column
                << ")"
                << "\n";
        }
    }
    else {
        cout << "Invalid command\n";
    }
}