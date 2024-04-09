#ifndef PARSE_HPP
#define PARSE_HPP
#include "libraries.hpp"
#include <cctype>
#include <string>
using namespace std;

// inline vector<vector<string>> parseFile(const string& filename) {
//     vector<vector<string>> result;
//     ifstream file(filename);
//     string line;

//     while (getline(file, line)) {
//         vector<string> lineData;
//         istringstream iss(line);
//         string word;

//         while (iss >> word) {
//             lineData.push_back(word);
//         }

//         result.push_back(lineData);
//     }

//     return result;
// }

inline int hexToDecimal(string);
inline string decimalToHex(int);
inline string convertToNum(string);
inline string lineToNum(string);


inline vector<string> parseFile(string fileName) {
    vector<string> data;
    ifstream file(fileName);
    string line;

    while (getline(file, line)) {
        string content;
        data.push_back(lineToNum(line));
    }

    return data;
}

inline string convertToLetter(string str) {
    string result;

    if (str == "01") {
        result = "MOV";
    } else if (str == "02") {
        result = "PUT";
    } else if (str == "03") {
        result = "PRN";
    } else if (str == "04") {
        result = "OBL";
    } else if (str == "11") {
        result = "ADD";
    } else if (str == "12") {
        result = "SUB";
    } else if (str == "13") {
        result = "DIV";
    } else if (str == "14") {
        result = "MUL";
    } else if (str == "15") {
        result = "MOD";
    } else if (str == "21") {
        result = "GTN";
    } else if (str == "22") {
        result = "LTN";
    } else if (str == "23") {
        result = "EQU";
    } else if (str == "24") {
        result = "GEQ";
    } else if (str == "25") {
        result = "LEQ";
    } else if (str == "26") {
        result = "XXX";
    } else if (str == "99") {
        result = "NIR";
    } else if (str == "98") {
        result = "CIR";
    } else if (str == "97") {
        result = "RA1";
    } else if (str == "96") {
        result = "RB1";
    } else if (str == "95") {
        result = "RC1";
    } else if (str == "94") {
        result = "RD1";
    } else if (str == "93") {
        result = "RA2";
    } else if (str == "92") {
        result = "RB2";
    } else if (str == "91") {
        result = "RC2";
    } else if (str == "90") {
        result = "RD2";
    } else if (str == "89") {
        result = "RA3";
    } else if (str == "88") {
        result = "RB3";
    } else if (str == "87") {
        result = "RC3";
    } else if (str == "86") {
        result = "RD3";
    } else if (str == "85") {
        result = "RA4";
    } else if (str == "84") {
        result = "RB4";
    } else if (str == "83") {
        result = "RC4";
    } else if (str == "82") {
        result = "RD4";
    } else {
        result = str;
    }

    return result;
}

inline string convertToNum(string str) {
    char end = '0';
    string result;
    if (str == "MOV") {
        result = "01";
    } else if (str == "PUT") {
        result = "02";
    } else if (str == "PRN") {
        result = "03";
    } else if (str == "OBL") {
        result = "04";
    } else if (str == "ADD") {
        result = "11";
    } else if (str == "SUB") {
        result = "12";
    } else if (str == "DIV") {
        result = "13";
    } else if (str == "MUL") {
        result = "14";
    } else if (str == "MOD") {
        result = "15";
    } else if (str == "GTN") {
        result = "21";
    } else if (str == "LTN") {
        result = "22";
    } else if (str == "EQU") {
        result = "23";
    } else if (str == "GEQ") {
        result = "24";
    } else if (str == "LEQ") {
        result = "25";
    } else if (str == "XXX") {
        result = "26";
    } else if (str == "NIR") {
        result = "99";
    } else if (str == "CIR") {
        result = "98";
    } else if (str == "RA1") {
        result = "97";
    } else if (str == "RB1") {
        result = "96";
    } else if (str == "RC1") {
        result = "95";
    } else if (str == "RD1") {
        result = "94";
    } else if (str == "RA2") {
        result = "93";
    } else if (str == "RB2") {
        result = "92";
    } else if (str == "RC2") {
        result = "91";
    } else if (str == "RD2") {
        result = "90";
    } else if (str == "RA3") {
        result = "89";
    } else if (str == "RB3") {
        result = "88";
    } else if (str == "RC3") {
        result = "87";
    } else if (str == "RD3") {
        result = "86";
    } else if (str == "RA4") {
        result = "85";
    } else if (str == "RB4") {
        result = "84";
    } else if (str == "RC4") {
        result = "83";
    } else if (str == "RD4") {
        result = "82";
    } else  {
        if (str.at(0) == '[') {
            str = str.substr(1, str.length() - 2);
            end = '1';
        }
        // Convert the remaining string to an integer
        int num = stoi(str);
        // Convert the integer to a string
        result = decimalToHex(num);

        // Ensure the hex string has 4 characters
        while (result.length() < 4) {
            result = "0" + result;
        }
        result = ((end == '1') ? "1" : "0") + result;
    }
    return result;
}

inline int hexToDecimal(string hexStr) {
    string str = hexStr.substr(0,9);
    unsigned long decimalValue;  
    stringstream ss;

    ss << hex << str;  

    char* endptr;  
    decimalValue = strtol(str.c_str(), &endptr, 16);

    if (*endptr != '\0') {
        throw invalid_argument("Invalid hexadecimal string");
    }

    return (hexStr.at(hexStr.length()-1) == '1') ? decimalValue * -1 : decimalValue;
}

inline string decimalToHex(int decimalNum) {
    string hexStr = "";
    char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (decimalNum == 0) {
        hexStr = "0";
    } else {
        bool isNegative = false;
        if (decimalNum < 0) {
            isNegative = true;
            decimalNum = -decimalNum;
        }

        while (decimalNum > 0) {
            int remainder = decimalNum % 16;
            hexStr += hexChars[remainder];
            decimalNum /= 16;
        }
        reverse(hexStr.begin(), hexStr.end());

        if (isNegative) {
            hexStr = "-" + hexStr;
        }
    }

    return hexStr;
}

inline string lineToNum(string str) {
    string output;

    // Split the input string into words
    istringstream iss(str);
    string word;
    int index = 1;
    while (iss >> word) {
        string num;
        if (index == 2 && (!isalpha(word.at(0)))) {
            num = decimalToHex(stoi(word));
            while (num.length() < 2) {
                num = "0" + num;
            }
        } else {
            num = convertToNum(word);
        }
        
        if (index == 3) {
            while (num.length() < 5) {
                num = "0" + num;
            }
        }
        output += num;
        index++;
    }

    return output + '0';
}

inline string dataToMemory(int data) {
    string output(decimalToHex(data));
    while (output.length() < 9) {
        output = "0" + output;
    }
    return output;
}

inline string negativeCheck(string line) {
    string output = line;
    bool isNegative = false;
    for (auto& c : output) {
        if (c == '-') {
            c = '0'; // Replace '-' with '0'
            isNegative = true;
        }
    }
    output += (isNegative) ? '1' : '0'; // Concatenate '1' to the end of the string
    return output;
}


#endif