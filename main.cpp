#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

string getInstructionType(string opcode);
int binaryToDecimal(string binary);
template<typename T>
string decimalToHexa(T value);
void decodeRtypeInstruction();
void decodeItypeInstruction();
void decodeJtypeIntruction();
 
int main(int argc, char *argv[])
{
    string input;
    string instructionType;

    cin >> input;
    instructionType = getInstructionType(input.substr(0, 6));

    if(instructionType == "R"){

    }
    else if(instructionType == "I"){

    }
    else {

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
    string instructionNumber = decimalToHexa(binaryToDecimal(opcode));
   return "R";
}