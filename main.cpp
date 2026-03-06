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

        if (command == "EXIT" || command == "exit" || command == "Exit") {
            break;
        }

        if (command.empty())
            continue;

        engine.execute(command);
    }

    cout << "C;osing MiniSQL.\n";

    return 0;
}