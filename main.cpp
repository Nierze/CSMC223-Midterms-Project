#include "libraries/libraries.hpp"
#include "libraries/components.hpp"
using namespace std;




int main() {
    MemoryClass testMem(64);
    vector<string> testStrings = {"Hello", "World", "This", "Is", "A", "Test"};
    testMem.placeStringsInMemory(testStrings);
    cout << testMem.getMemory(0) << endl;
    cout << testMem.getMemory(1) << endl;
    
    return 0;
}