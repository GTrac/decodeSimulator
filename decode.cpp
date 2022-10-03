#include <iostream>
#include <bitset>

using namespace std;

void decode(uint32_t instruction){
    uint8_t opCode = (uint8_t)(instruction & 0b1111111); //retrieve opcode
    if(opCode == 0b0110011){
        cout << "Opcode Type: R" << endl;
        uint8_t funct7 = (uint8_t)(instruction >> 25);
        uint8_t rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        uint8_t rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        uint8_t funct3 = (uint8_t)((instruction >> 12) & 0b111);
        uint8_t rd = (uint8_t)((instruction >> 7) & 0b11111);

    }else if(opCode == 0b0010011 | opCode == 0b0000011){
        cout << "Opcode Type: I" << endl;
        bitset<12> imm{instruction >> 20};
        uint8_t rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        uint8_t rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        uint8_t funct3 = (uint8_t)((instruction >> 12) & 0b111);
        uint8_t rd = (uint8_t)((instruction >> 7) & 0b11111);

    }else if(opCode == 0b0100011){
        cout << "Opcode Type: S" << endl;
        bitset<12> imm{((instruction>>25)<<5) + (instruction>>7 & 0b11111)};
        cout << imm << endl;
        uint8_t rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        uint8_t rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        uint8_t funct3 = (uint8_t)((instruction >> 12) & 0b111);

    }else if()

    

    
    
    

}
