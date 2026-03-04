#include <iostream>
#include "engine.h"

using namespace std;

int main() {
    Engine engine;
    string command;

    cout << "Mini SQL Engine Started\n";

    engine.db.loadAllTables();

    while (true) {
        cout << ">>";
        getline(cin, command);

        if (command == "EXIT")
            break;

        engine.execute(command);
    }

    return 0;
}