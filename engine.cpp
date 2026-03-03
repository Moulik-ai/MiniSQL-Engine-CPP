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

    else {
        cout << "Invalid command\n";
    }
}