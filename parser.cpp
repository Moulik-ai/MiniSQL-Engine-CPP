#include "parser.h"
#include <sstream>

vector<string> split(string input) {
    stringstream ss(input);
    string word;
    vector<string> tokens;

    while (ss >> word) {
        tokens.push_back(word);
    }

    return tokens;
}
