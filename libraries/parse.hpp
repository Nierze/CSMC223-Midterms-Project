#ifndef PARSE_HPP
#define PARSE_HPP
#include "libraries.hpp"
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

inline string convertToNum(string str) {
    string result;
    if (str == "MOV") {
        result = "00";
    } else if (str == "PUT") {
        result = "01";
    } else if (str == "PRN") {
        result = "02";
    } else if (str == "OBL") {
        result = "03";
    } else if (str == "ADD") {
        result = "10";
    } else if (str == "SUB") {
        result = "11";
    } else if (str == "DIV") {
        result = "12";
    } else if (str == "MUL") {
        result = "13";
    } else if (str == "MOD") {
        result = "14";
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
    } else if (str.at(0) == '[') {
        // Remove the square brackets from the string
        str = str.substr(1, str.length() - 2);
        // Convert the remaining string to an integer
        int num = stoi(str);
        // Convert the integer to a string
        result = decimalToHex(num);

        // Ensure the hex string has 4 characters
        while (result.length() < 4) {
            result = "0" + result;
        }
    }
    return result;
}

inline string decimalToHex(int decimalNum) {
    string hexStr = "";
    char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (decimalNum == 0) {
        hexStr = "0";
    } else {
        while (decimalNum > 0) {
            int remainder = decimalNum % 16;
            hexStr += hexChars[remainder];
            decimalNum /= 16;
        }
        reverse(hexStr.begin(), hexStr.end());
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
        // Convert each word to its corresponding number
        string num = convertToNum(word);
        // Append the number to the output string
        
        if (index == 3) {
            while (num.length() < 4) {
                num = "0" + num;
            }
        }
        output += num;
        index++;
    }

    return output;
}


#endif