#include <iostream>
#include "engine.h"

using namespace std;

int main(int argc, char* argv[]) {
    Engine engine;
    string command;

    string databaseName = "default.db";

    if (argc > 1) {
        databaseName = argv[1];
    }

    cout << "MiniSQL Database Engine\n";
    cout << "Connected to " << databaseName << "\n\n";

    engine.db.loadAllTables();

    while (true) {

        cout << "MiniSQL> ";

        getline(cin, command);

        if (command == ".exit") {
            break;
        }

        if (command == ".help") {

            cout << "Available commands:\n";
            cout << "CREATE TABLE\n";
            cout << "INSERT INTO\n";
            cout << "SELECT\n";
            cout << "DELETE\n";
            cout << "CREATE INDEX\n";
            cout << "EXPLAIN\n";
            cout << ".tables\n";
            cout << ".exit\n";

            continue;
        }

        if (command == ".tables") {

            cout << "Tables:\n";

            for (auto &t : engine.db.tables)
                cout << t.first << endl;

            continue;
        }

        if (command == "Exit" || command == "exit" || command == "EXIT"){
            cout << "Closing MiniSQL, Hope you liked my project :)\n";
            break;
        }

        if (command.empty())
            continue;

            engine.execute(command);
    }
    return 0;
}