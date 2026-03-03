#include "parser.h"
#include <cctype>

vector<string> split(string input) {
    vector<string> tokens;
    string current = "";

    for (char ch : input) {
        if (isspace(ch) || ch == '(' || ch == ')' || ch == ',' || ch == ';') {
            if (!current.empty()) {
                tokens.push_back(current);
                current = "";
            }
        } else {
            current += ch;
        }
    }

    if(!current.empty()) {
        tokens.push_back(current);
    }


    return tokens;
}
