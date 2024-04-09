#include "../libraries/libraries.hpp"
#include "../libraries/components.hpp"
using namespace std;

MemoryClass memory(64);



map<string, Register*> registerMap {
    {"NIR", new Register(0, "1", "NIR", 99)},
    {"CIR", new Register(0, "1", "CIR", 98)}, 
    {"RA1", new Register(0, "64", "RA1", 97)}, 
    {"RB1", new Register(0, "32", "RB1", 96)},
    {"RC1", new Register(0, "16", "RC1", 95)},
    {"RD1", new Register(0, "8", "RD1", 94)},
    {"RA2", new Register(0, "64", "RA2", 93)},
    {"RB2", new Register(0, "32", "RB2", 92)},
    {"RC2", new Register(0, "16", "RC2", 91)},
    {"RD2", new Register(0, "8", "RD2", 90)},
    {"RA3", new Register(0, "64", "RA3", 89)},
    {"RB3", new Register(0, "32", "RB3", 88)},
    {"RC3", new Register(0, "16", "RC3", 87)},
    {"RD3", new Register(0, "8", "RD3", 86)},
    {"RA4", new Register(0, "64", "RA4", 85)},
    {"RB4", new Register(0, "32", "RB4", 84)},
    {"RC4", new Register(0, "16", "RC4", 83)},
    {"RD4", new Register(0, "8", "RD4", 82)}
};


// void interpretLine(vector<vector<string>> instructions) {
//     for (vector<string> line : instructions) {
//         for (int i = 0; i < line.size(); i++) {
//             string token = line[i];
//             if (token == "MOV") {
//                 registerMap[line[i+1]]->setData(registerMap[line[i+2]]->getData());
//             }
//             else if (token == "PUT") {
                
//             }
//         }
//     }
// }
void startSystem(string inputFileName) {

    cout << "Starting system..." << endl;
    cout << "System started." << endl;

    cout << "Enter name of input file: " << endl;
    memory.placeStringsInMemory(parseFile(inputFileName));
    cout << "Memory Contents:" << endl;
    for (const auto& pair : memory.getMemoryMap()) {
        cout << pair.first << ": " << pair.second << endl;
    }

    

    



}



