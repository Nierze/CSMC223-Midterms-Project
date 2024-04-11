#include "../libraries/libraries.hpp"
#include "../libraries/components.hpp"
#include <iterator>
#include <string>
#include <utility>
using namespace std;

MemoryClass memory(64);



////////////////////////////////
// PROTOTYPES

void MOV(string operand, string memoryType, string data);
void PUT(string operand, string memoryType, string data);
void ADD(string operand, string memoryType, string data);
void SUB(string operand, string memoryType, string data);
void MUL(string operand, string memoryType, string data);
void DIV(string operand, string memoryType, string data);
void MOD(string operand, string memoryType, string data);
void CMP(string operand, string memoryType, string data);
void GTN(string operand, string memoryType, string data);
void LTN(string operand, string memoryType, string data);
void EQU(string operand, string memoryType, string data);
void GEQ(string operand, string memoryType, string data);
void LEQ(string operand, string memoryType, string data);
void JMP(string operand, string memoryType, string data);

int inputPrompt();
void runtimeLoop();
void showRegisters();
void showMemoryUsage();
void interpretLine(string line);
void startSystem(string inputFileName);



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
    {"RD4", new Register(0, "8", "RD4", 82)},
    {"CM1", new Register(0, "64", "CM1", 81)},
    {"CM2", new Register(0, "64", "CM2", 80)}
};

void interpretLine(string line) {
    string opCode = line.substr(0, 2);
    string operand = line.substr(2, 2);
    string memoryType = line.substr(4, 1);
    string data = line.substr(5, 4);
    
    if (opCode == "01") {
        
        MOV(operand, memoryType, data);
    } else if (opCode == "02") {
        PUT(operand, memoryType, data);
    } else if (opCode == "11") {
        ADD(operand, memoryType, data);
    } else if (opCode == "12") {
        SUB(operand, memoryType, data);
    } else if (opCode == "13") {
        DIV(operand, memoryType, data);
    } else if (opCode == "14") {
        MUL(operand, memoryType, data);
    } else if (opCode == "15") {
        MOD(operand, memoryType, data);
    } else if (opCode == "16") {
        CMP(operand, memoryType, data);
    } else if (opCode == "21") {
        GTN(operand, memoryType, data);
    } else if (opCode == "22") {
        LTN(operand, memoryType, data);
    } else if (opCode == "23") {
        EQU(operand, memoryType, data);
    } else if (opCode == "24") {
        GEQ(operand, memoryType, data);
    } else if (opCode == "25") {
        LEQ(operand, memoryType, data);
    } else if (opCode == "26") {
        JMP(operand, memoryType, data);
    }
    else {
        throw invalid_argument("Invalid OpCode: " + opCode);
    }
}

void startSystem(string inputFileName) {
    

    cout << "Starting system..." << endl;
    cout << "System started." << endl;

    memory.placeStringsInMemory(parseFile(inputFileName));
    runtimeLoop();

    // cout << "Memory Contents:" << endl;

    // for (const auto& pair : memory.getMemoryMap()) {
        
        
    //     cout << pair.first << ": " << pair.second << endl;
    //     interpretLine(pair.second);
    // }

    // cout << "Memory Contents After Execution:" << endl;

    // for (const auto& pair : memory.getMemoryMap()) {
    //     cout << pair.first << ": " << pair.second << endl;
    // }
}

int inputPrompt() {
    int choice;
    cout << "================================" << endl;
    cout << "| Menu                         |" << endl;
    cout << "================================" << endl;
    cout << "| 1 - Execute current          |" << endl; 
    cout << "|     instruction and go to    |" << endl;
    cout << "|     next                     |" << endl;
    cout << "| 2 - Stop program             |" << endl;
    cout << "| 3 - Show registers           |" << endl;
    cout << "| 4 - Show memory usage        |" << endl;
    cout << "| 5 - Execute all instructions |" << endl;
    cout << "================================" << endl;
    cout << "Input: ";
    cin >> choice;
    return choice;
}

void showRegisters() {
    cout << endl;
    cout << "=================================" << endl;
    cout << "| Registers:" << setw(21) << " |" << endl;
    for (const auto& pair : registerMap) {
        cout << "| " << pair.first << ": " << setw(24) << pair.second -> getData() <<  " |" << endl;
    }
    cout << "=================================" << endl;
}

void runtimeLoop() {
    registerMap.at("NIR") -> setData(1);
    bool executeAll = false;

    for (int i = registerMap.at("CIR") -> getData(); true;) {
        i = registerMap.at("CIR") -> getData();
        cout << endl;

        string arrow;

        cout << "Memory Contents:" << endl;
        for (const auto& pair : memory.getMemoryMap()) {
            arrow = (i == pair.first) ? " <--" : " ";
            cout << pair.first << ": " << pair.second << arrow << endl;
        } 

        if (executeAll == true) {
            if (memory.getMemory(i).substr(0,2) == "44" ) {
                cout << "Program has successfully ended." << endl;
                break;
            }

            if (memory.getMemory(i).substr(0,1) == "2") {

                interpretLine(memory.getMemory(i));

            } else {

                interpretLine(memory.getMemory(i));
                i++;
                registerMap.at("CIR") -> setData(i);
                registerMap.at("NIR") -> setData(i + 1);

            }
        } else {
            int input = inputPrompt();

            if(input == 1) {

                // if it is the end
                if (memory.getMemory(i).substr(0,2) == "44" ) {
                    cout << "Program has successfully ended." << endl;
                    break;
                }

                if (memory.getMemory(i).substr(0,1) == "2") {

                    interpretLine(memory.getMemory(i));

                } else {

                    interpretLine(memory.getMemory(i));
                    i++;
                    registerMap.at("CIR") -> setData(i);
                    registerMap.at("NIR") -> setData(i + 1);

                }


            } else if (input == 2) {
                cout << "Program has been stopped." << endl;
                break;
            } else if (input == 3) {
                showRegisters();
            } else if (input == 4) {
                showMemoryUsage();
            } else if (input == 5) {
                executeAll = true;
            }
        }

    }
}

void showMemoryUsage() {
    float consumedMemory = static_cast<float>(memory.getConsumedMemory()) / 8;
    consumedMemory = roundf(consumedMemory * 100) / 100; 
    float registerConsumedMemory = 0;
    for (auto reg : registerMap) {
        if ((reg.first != "NIR" && reg.first != "CIR") && reg.second -> getData() != 0) {
            registerConsumedMemory += stoi(reg.second -> getBitAmount());
        }
    }

    registerConsumedMemory = registerConsumedMemory / 8;
    registerConsumedMemory = roundf(registerConsumedMemory * 100) / 100;

    cout << endl;
    cout << "=================================" << endl;
    cout << "| -Memory Usage-" << setw(17) << "|" << endl;
    cout << "| Consumed Memory: " << setw(6) << consumedMemory << " bytes |" << endl;
    cout << "| Consumed Registers: " << setw(3) << registerConsumedMemory << " bytes |" << endl;
    cout << "=================================" << endl;
}


////////////////////////////////
// CPU OPERATIONS

void MOV(string operand, string memoryType, string data) {
    
    int index = hexToDecimal(operand);
    int address;
    
    if (checkIfRegister(data)) {
        address = stoi(data.substr(2,2));
    } else {
        address = hexToDecimal(data.substr(2,2));
    }
    string regAddress = convertToLetter(data.substr(2,2));


       if (memoryType == "0") {
            if (address >= 86 && address <= 99) { 
                
                registerMap[convertToLetter(operand)] ->
                setData(registerMap[regAddress] -> getData());
                
            } else {
                registerMap[convertToLetter(operand)] -> 
            
                setData(hexToDecimal(memory.getMemory(hexToDecimal(data))));
            }
        } else {
            registerMap[convertToLetter(operand)] -> setData(hexToDecimal(data));
        }
}

void PUT(string operand, string memoryType, string data) {

    // forgive me uwu
    int index = hexToDecimal(operand);
    if (checkIfRegister(operand)) { 
        index = registerMap[convertToLetter(operand)] -> getData();
    }

    int address;
    if (checkIfRegister(data)) {
        address = stoi(data.substr(2,2));
    } else {
        address = hexToDecimal(data.substr(2,2));
    }
    string regAddress = data.substr(2,2);

    if (memoryType == "0") {
        if (address >= 86 && address <= 99) {

            memory.insertIntoMemory(index, 
            (dataToMemory(registerMap[convertToLetter(regAddress)] -> getData())));

        } else {
            memory.insertIntoMemory(index, 
            memory.getMemory(hexToDecimal(data)));
        }  
    } else {
        string value = data;
        while (value.length() < 9) {
            value = '0' + value;
        }
        memory.insertIntoMemory(index, value);
    }
    
    memory.insertIntoMemory(index, negativeCheck(memory.getMemory(index)));
}

void ADD(string operand, string memoryType, string data) {
    int operandData = registerMap[convertToLetter(operand)] -> getData();
    string argumentRegister = convertToLetter(data.substr(2,2));

    if (memoryType == "0") {
        
        registerMap[convertToLetter(operand)] -> 
        setData(operandData + 
        registerMap[argumentRegister] -> getData());
    } else {
        
        registerMap[convertToLetter(operand)] -> 
        setData(operandData + hexToDecimal(data));
    }
}

void SUB(string operand, string memoryType, string data) {
    int operandData = registerMap[convertToLetter(operand)] -> getData();
    string argumentRegister = convertToLetter(data.substr(2,2));
    if (memoryType == "0") {
        registerMap[convertToLetter(operand)] -> 
        setData(operandData - 
        registerMap[argumentRegister] -> getData());
    } else {

        registerMap[convertToLetter(operand)] -> 
        setData(operandData - hexToDecimal(data));
    }
}

void MUL(string operand, string memoryType, string data) {
    int operandData = registerMap[convertToLetter(operand)] -> getData();
    string argumentRegister = convertToLetter(data.substr(2,2));
    if (memoryType == "0") {
        registerMap[convertToLetter(operand)] -> 
        setData(operandData * 
        registerMap[argumentRegister] -> getData());
    } else {
        registerMap[convertToLetter(operand)] -> 
        setData(operandData * hexToDecimal(data));
    }
}

void DIV(string operand, string memoryType, string data) {
    int operandData = registerMap[convertToLetter(operand)] -> getData();
    string argumentRegister = convertToLetter(data.substr(2,2));
    if (memoryType == "0") {
        registerMap[convertToLetter(operand)] -> 
        setData(operandData / 
        registerMap[argumentRegister] -> getData());
    } else {
        registerMap[convertToLetter(operand)] -> 
        setData(operandData / hexToDecimal(data));
    }
}

void MOD(string operand, string memoryType, string data) {
    int operandData = registerMap[convertToLetter(operand)] -> getData();
    string argumentRegister = convertToLetter(data.substr(2,2));
    if (memoryType == "0") {
        registerMap[convertToLetter(operand)] -> 
        setData(operandData % 
        registerMap[argumentRegister] -> getData());
    } else {
        registerMap[convertToLetter(operand)] -> 
        setData(operandData % hexToDecimal(data));
    }
}

void CMP(string operand, string memoryType, string data) {
    registerMap["CM1"] -> setData(registerMap[convertToLetter(operand)] -> getData());
    registerMap["CM2"] -> setData(registerMap[convertToLetter(data.substr(2,2))] -> getData());
}

void GTN(string operand, string memoryType, string data) {

    if (registerMap["CM1"] -> getData() > registerMap["CM2"] -> getData()) {
        registerMap["CIR"] -> setData(hexToDecimal(data));
        registerMap["NIR"] -> setData(hexToDecimal(data) + 1);
    } else {
        registerMap["CIR"] -> setData(registerMap["CIR"] -> getData() + 1);
        registerMap["NIR"] -> setData(registerMap["CIR"] -> getData() + 2);
    }
}

void LTN(string operand, string memoryType, string data) {
    if (registerMap["CM1"] -> getData() < registerMap["CM2"] -> getData()) {
        registerMap["CIR"] -> setData(hexToDecimal(data));
        registerMap["NIR"] -> setData(hexToDecimal(data) + 1);
    } else {
        registerMap["CIR"] -> setData(registerMap["CIR"] -> getData() + 1);
        registerMap["NIR"] -> setData(registerMap["CIR"] -> getData() + 2);
    }
}

void EQU(string operand, string memoryType, string data) {
    if (registerMap["CM1"] -> getData() == registerMap["CM2"] -> getData()) {
        registerMap["CIR"] -> setData(hexToDecimal(data));
        registerMap["NIR"] -> setData(hexToDecimal(data) + 1);
    } else {
        registerMap["CIR"] -> setData(registerMap["CIR"] -> getData() + 1);
        registerMap["NIR"] -> setData(registerMap["CIR"] -> getData() + 2);
    }
}

void GEQ(string operand, string memoryType, string data) {
    if (registerMap["CM1"] -> getData() >= registerMap["CM2"] -> getData()) {
        registerMap["CIR"] -> setData(hexToDecimal(data));
        registerMap["NIR"] -> setData(hexToDecimal(data) + 1);
    } else {
        registerMap["CIR"] -> setData(registerMap["CIR"] -> getData() + 1);
        registerMap["NIR"] -> setData(registerMap["CIR"] -> getData() + 2);
    }
}

void LEQ(string operand, string memoryType, string data) {
    if (registerMap["CM1"] -> getData() <= registerMap["CM2"] -> getData()) {
        registerMap["CIR"] -> setData(hexToDecimal(data));
        registerMap["NIR"] -> setData(hexToDecimal(data) + 1);
    } else {
        registerMap["CIR"] -> setData(registerMap["CIR"] -> getData() + 1);
        registerMap["NIR"] -> setData(registerMap["CIR"] -> getData() + 2);
    }
}

void JMP(string operand, string memoryType, string data) {
    registerMap["CIR"] -> setData(hexToDecimal(data));
    registerMap["NIR"] -> setData(hexToDecimal(data) + 1);
}





