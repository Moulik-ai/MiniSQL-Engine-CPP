#ifndef ENGINE_H
#define ENGINE_H

#include "database.h"
#include "parser.h"

class Engine {
    public:
    Database db;
    void execute(string command);
};

#endif