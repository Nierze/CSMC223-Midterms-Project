#ifndef PARSE_HPP
#define PARSE_HPP
#include "libraries.hpp"
using namespace std;

inline vector<vector<string>> parseFile(const string& filename) {
    vector<vector<string>> result;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        vector<string> lineData;
        istringstream iss(line);
        string word;

        while (iss >> word) {
            lineData.push_back(word);
        }

        result.push_back(lineData);
    }

    return result;
}



inline vector<string> parseLine() {
    string filename = "/path/to/your/file.txt";
    vector<vector<string>> data = parseFile(filename);

    return data;
}

#endif