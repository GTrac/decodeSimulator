

#include <iostream>
#include <bitset>

using namespace std;

void decode(uint32_t instruction){
    uint8_t opCode = (uint8_t)(instruction & 0b1111111); //retrieve opcode
    if(opCode == 0b0110011 | opCode == 0b0111011){
        cout << "Opcode Type: R" << endl;
        uint8_t funct7 = (uint8_t)(instruction >> 25);
        uint8_t rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        uint8_t rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        uint8_t funct3 = (uint8_t)((instruction >> 12) & 0b111);
        uint8_t rd = (uint8_t)((instruction >> 7) & 0b11111);

    }else if(opCode == 0b0010011 | opCode == 0b0000011 | opCode == 0b0011011){
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

    }else if(opCode == 0b1100011){
        cout << "Opcode Type: SB" << endl;
        bitset<12> imm{((instruction>>25 & 0b111111)<<5) + ((instruction>>8 & 0b1111)<<1) + ((instruction>>7 & 0b01)<<11) + (instruction>>30)};
        uint8_t rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        uint8_t rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        uint8_t funct3 = (uint8_t)((instruction >> 12) & 0b111);
        cout << "imm: " << imm << endl;
           
    }else if(opCode == 0b0110111 || opCode == 0b0010111){
        cout << "Opcode Type: U" << endl;
        bitset<20> imm{((instruction>>12 & 0b111111)<<5) + ((instruction>>31)<<20) + ((instruction>>7 & 0b01)<<11) + (instruction>>30)};
        uint8_t rd = (uint8_t)((instruction >> 7) & 0b11111);
    }else if(opCode == 0b1101111){
        cout << "Opcode Type: UJ" << endl;
        bitset<20> imm{(instruction>>12)};
        uint8_t rd = (uint8_t)((instruction >> 7) & 0b11111);
    }else{
        cout << "\n/////////////////ERROR//////////////" << endl;
    }
    cout << "Control Signals:\nreg_wen: " << << "reg_ren: " << << "alu_op: " << << "\nmem_wen: " << << "mem_ren: " << ;
    cout << "sel1: " << << "sel2: " << << "\nsel3: " << << "sel4: " << << "sel5: " << << "sel6: " << << "sel7: " << << "sel8: " << ;
    cout << "branch: " << << "auipc: " << << "lui: " << << endl;
}
    
