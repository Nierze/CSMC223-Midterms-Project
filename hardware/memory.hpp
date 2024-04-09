
#ifndef MEMORY_CLASS_H
#define MEMORY_CLASS_H

#include "../libraries/libraries.hpp"
#include <string>
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
    
    map<int, string> getMemoryMap() {
        return memoryMap;
    }

    void insertIntoMemory(int index, string data) {
        auto it = memoryMap.find(index);
        if (it != memoryMap.end()) {
            it->second = data;
        } else {
            memoryMap.insert(make_pair(index, data));
        }
    }

private:
    int currentMemoryAmount;
    int maxMemoryAmount;
    map<int, string> memoryMap;
};

#endif // MEMORY_CLASS_H