#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <map>

#define OPCODE(instruction) (decimalToHexa(binaryToDecimal(instruction.substr(0, 6))))
#define RS(instruction) (to_string(binaryToDecimal(instruction.substr(6, 5))))
#define RT(instruction) (to_string(binaryToDecimal(instruction.substr(11, 5))))
#define ADDRESS(instruction) (decimalToHexa(binaryToDecimal(instruction.substr(6, 31))))
#define IMMEDIATE(instruction) (decimalToHexa(binaryToDecimal(instruction.substr(15, 31))))

using namespace std;

template<typename T>
string decimalToHexa(T value);
string getInstructionType(string opcode);
int binaryToDecimal(string binary);
// void decodeRtypeInstruction(string instruction);
void decodeItypeInstruction(string instruction);
void decodeJtypeInstruction(string instruction);
 
int main(int argc, char *argv[])
{
    string instruction;
    cin >> instruction;

    string instructionType;
    instructionType = getInstructionType(OPCODE(instruction));

    if(instructionType == "R"){
        // Need to implement funct 
        // Decode based on the funct 
        // decodeRtypeInstruction();
    }
    else if(instructionType == "I"){
        decodeItypeInstruction(instruction);
    }
    else {
        decodeJtypeInstruction(instruction);
    }
}

int binaryToDecimal(string binary) {
    int decimalNumber = 0;
    int exponent = binary.length() - 1;

    for(int i = 0; i < binary.length(); i++){
        if(binary[i] == '1') {
            decimalNumber = decimalNumber + pow(2, exponent);
        }
        exponent--;
    }
    return decimalNumber;
}

template<typename T >
string decimalToHexa( T value){
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
}

string getInstructionType(string opcode){
    string intructionType;
    if(opcode == "0"){
        return "R";
    }
    else if (opcode == "2" || "3"){
        return "J";
    }
    else{
        return "I";
    }
    return intructionType;
}

void decodeItypeInstruction(string instruction){
    map<string, string> operationTable = {
        {"8", "addi",},
        {"9", "addiu",},
        {"c", "andi",},
        {"4", "beq",},
        {"5", "bne",},
        {"24", "lbu",},
        {"25", "lhu",},
        {"30", "ll",},
        {"f", "lui",},
        {"23", "lw",},
        {"d", "ori",},
        {"a", "slti",},
        {"b", "sltiu",},
        {"28", "sb",},
        {"29", "sh",},
        {"2b", "sw",}
        };

    cout << "Instruction Type: I" << endl;
    cout << "Operation: " + operationTable[OPCODE(instruction)]<< endl;
    cout << "Rs: $" + RS(instruction) << endl;
    cout << "Rt: $" + RT(instruction) << endl;
    cout << "Immediate: 0x" + IMMEDIATE(instruction)<< endl;
}

void decodeJtypeInstruction(string instruction){
    map<string, string> operationTable = {
        {"2", "j",},
        {"3", "jal",}
        };

    cout << "Instruction Type: J" << endl;
    cout << "Operation: " + operationTable[OPCODE(instruction)]<< endl;
    cout << "Immediate: 0x" + ADDRESS(instruction) << endl;
}

