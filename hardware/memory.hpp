
#ifndef MEMORY_CLASS_H
#define MEMORY_CLASS_H

#include "../libraries/libraries.hpp"
using namespace std;
class MemoryClass {
public:
    MemoryClass(int maxMemoryAmount) 
    : maxMemoryAmount(maxMemoryAmount), currentMemoryAmount(0){
        // Constructor
    }

    ~MemoryClass() {
        // Destructor
    }

    void placeStringsInMemory(const vector<string>& strings) {
        for (int i = 0; i < strings.size(); i++) {
            memoryMap.insert(make_pair(i, strings[i]));
        }
    }

    string getMemory(int index) {
        return memoryMap[index];
    }

    int getCurrentMemoryAmount() {
        return currentMemoryAmount;
    }

    int getMaxMemoryAmount() {
        return maxMemoryAmount;
    }

private:
    int currentMemoryAmount;
    int maxMemoryAmount;
    map<int, string> memoryMap;
};

#endif // MEMORY_CLASS_H