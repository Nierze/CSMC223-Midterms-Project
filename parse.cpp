#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::vector<std::string>> parseFile(const std::string& filename) {
    std::vector<std::vector<std::string>> result;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> lineData;
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            lineData.push_back(word);
        }

        result.push_back(lineData);
    }

    return result;
}
