#ifndef PARSE_HPP
#define PARSE_HPP
#include "libraries.hpp"
using namespace std;

// inline vector<vector<string>> parseFile(const string& filename) {
//     vector<vector<string>> result;
//     ifstream file(filename);
//     string line;

//     while (getline(file, line)) {
//         vector<string> lineData;
//         istringstream iss(line);
//         string word;

//         while (iss >> word) {
//             lineData.push_back(word);
//         }

//         result.push_back(lineData);
//     }

//     return result;
// }



inline vector<string> parseFile(string fileName) {
    vector<string> data;
    ifstream file(fileName);
    string line;

    while (getline(file, line)) {
        data.push_back(line);
    }

    return data;
}

#endif