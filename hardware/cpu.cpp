#include "../libraries/libraries.hpp"
#include "../libraries/components.hpp"
using namespace std;

map<string, Register*> registerMap {
    {"RA1", new Register(0, "64", "RA1")},
    {"RB1", new Register(0, "32", "RB1")},
    {"RC1", new Register(0, "16", "RC1")},
    {"RD1", new Register(0, "8", "RD1")},
    {"RA2", new Register(0, "64", "RA2")},
    {"RB2", new Register(0, "32", "RB2")},
    {"RC2", new Register(0, "16", "RC2")},
    {"RD2", new Register(0, "8", "RD2")},
    {"RA3", new Register(0, "64", "RA3")},
    {"RB3", new Register(0, "32", "RB3")},
    {"RC3", new Register(0, "16", "RC3")},
    {"RD3", new Register(0, "8", "RD3")},
    {"RA4", new Register(0, "64", "RA4")},
    {"RB4", new Register(0, "32", "RB4")},
    {"RC4", new Register(0, "16", "RC4")},
    {"RD4", new Register(0, "8", "RD4")},
    {"CIR", new Register(0, "1", "CIR")},
    {"NIR", new Register(0, "1", "NIR")}
};

void interpretLine(vector<vector<string>> instructions) {
    for (vector<string> line : instructions) {
        for (int i = 0; i < line.size(); i++) {
            string token = line[i];
            if (token == "MOV") {
                registerMap[line[i+1]]->setData(registerMap[line[i+2]]->getData());
            }
            else if (token == "PUT") {
                
            }
        }
    }
}
void startSystem() {
    string inputFileName;
    vector<vector<string>> data;
    cout << "Starting system..." << endl;
    cout << "System started." << endl;

    cout << "Enter name of input file: " << endl;
    cin >> inputFileName;

    data = parseFile(inputFileName);
    



}



