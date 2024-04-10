#include "../libraries/libraries.hpp"
#include "../libraries/components.hpp"
#include <string>
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
    }
}
void startSystem(string inputFileName) {

    cout << "Starting system..." << endl;
    cout << "System started." << endl;

    memory.placeStringsInMemory(parseFile(inputFileName));
    cout << "Memory Contents:" << endl;
    for (const auto& pair : memory.getMemoryMap()) {
        
        
        cout << pair.first << ": " << pair.second << endl;
        interpretLine(pair.second);
    }

    cout << "Memory Contents After Execution:" << endl;

    for (const auto& pair : memory.getMemoryMap()) {
        cout << pair.first << ": " << pair.second << endl;
    }
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
    int index = hexToDecimal(operand);
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


