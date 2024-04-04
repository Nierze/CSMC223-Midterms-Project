
#ifndef MEMORY_CLASS_H
#define MEMORY_CLASS_H

#include "libraries.hpp"
using namespace std;
class MemoryClass {
public:
    MemoryClass() {
        // Constructor
    }

    ~MemoryClass() {
        // Destructor
    }




    void parseFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << endl;
            return;
        }

        string line;
        int lineNumber = 0;
        map<int, string> memoryMap; // Declare memoryMap variable
        while (getline(file, line)) {
            memoryMap[lineNumber++] = line;
        }

        file.close();
    }
/*
MOV RC1 95
MOV RC2 96
MOV RC3 #RC1
ADD RC1 RC2
ADD RC1 RC3
MOV NIR 4
MOV NIR 4
PUT RC1 97
*/



private:
    int currentMemoryAmount;
    int maxMemoryAmount;
    map<int, string> memoryMap;
};

#endif // MEMORY_CLASS_H