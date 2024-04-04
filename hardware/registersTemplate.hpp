#include "../libraries/libraries.hpp"
using namespace std;

class Register {
public:
    // Constructor
    Register() {
        data = 0;
        bitAmount = "0";
        registerName = "";
    }

    Register(int data, string bitAmount, string registerName) {
        this->data = data;
        this->bitAmount = bitAmount;
        this->registerName = registerName;
    }

    // Destructor
    ~Register() {
    }

    // Getter for data
    int getData() const {
        return data;
    }

    // Setter for data
    void setData(int newData) {
        data = newData;
    }

    // Getter for bitAmount
    string getBitAmount() const {
        return bitAmount;
    }

    // Setter for bitAmount
    void setBitAmount(const string& newBitAmount) {
        bitAmount = newBitAmount;
    }

    // Getter for registerName
    string getRegisterName() const {
        return registerName;
    }

    // Setter for registerName
    void setRegisterName(const string& newRegisterName) {
        registerName = newRegisterName;
    }

    bool checkBitAmount(int inputData) {
        return (sizeof(inputData) * stoi(bitAmount)) <= stoi(bitAmount);
    }

private:
    // Private members
    int data;
    string bitAmount;
    string registerName;
};



class Register64 : public Register {
public:
    // Constructor
    Register64() : Register(0, "64", "Register64") {
    }

    Register64(string name) : Register(0, "64", name) {
    }

    // Destructor
    ~Register64() {
    }
};

class Register32 : public Register {
public:
    // Constructor
    Register32() : Register(0, "32", "Register32") {
    }

    Register32(string name) : Register(0, "32", name) {
    }

    Register32(int data, string name) : Register(0, "32", name) {
    }

    // Destructor
    ~Register32() {
    }
};

class Register16 : public Register {
public:
    // Constructor
    Register16() : Register(0, "16", "Register16") {
    }

    Register16(string name) : Register(0, "16", name) {
    }

    Register16(int data, string name) : Register(data, "16", name) {
    }

    // Destructor
    ~Register16() {
    }
};


class Register8 : public Register {
public:
    // Constructor
    Register8() : Register(0, "8", "Register8") {
    }

    Register8(string name) : Register(0, "8", name) {
    }

    // Destructor
    ~Register8() {
    }
};

class RegisterSpecial {
public:
    RegisterSpecial() {
        data = 0;
        registerName = "RegisterSpecial";
    }

    RegisterSpecial(int data, const string& registerName) {
        this->data = data;
        this->registerName = registerName;
    }   

    RegisterSpecial(const string& registerName) {
        data = 0;
        this->registerName = registerName;
    }  

    int getData() const {
        return data;
    }   

    void setData(int newData) {
        data = newData;
    }

    string getRegisterName() const {
        return registerName;
    }

    void setRegisterName(const string& newRegisterName) {
        registerName = newRegisterName;
    }

    int getBitAmount() const {
        return bitAmount;
    }

    void setBitAmount(int newBitAmount) {
        bitAmount = newBitAmount;
    }
    
private:
    int data;
    int bitAmount = 8;
    string registerName;
};







