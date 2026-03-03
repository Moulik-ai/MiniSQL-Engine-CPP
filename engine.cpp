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
        string tableName = tokens[3];

        if (tokens.size() > 4 && tokens[4] == "WHERE"){

            string column = tokens[5];
            string value = tokens[7];
            db.selectWhere(tableName, column, value);
        }
        else {
        db.selectAll(tableName);
    }
    }

    else {
        cout << "Invalid command\n";
    }
}