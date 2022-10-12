

#include <iostream>
#include <bitset>

using namespace std;
int x =0;
void decode(uint32_t instruction){
    bitset<7> opCode = (uint8_t)(instruction & 0b1111111); //retrieve opcode
    if(opCode == 0b0110011 | opCode == 0b0111011){
        cout << "Opcode Type: R" << endl;
        bitset<8> funct7 = (uint8_t)(instruction >> 25);
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);

        cout << "Control Signals:\nreg_wen: " << x << " reg_ren: " << x << " alu_op: " << funct7[5] << funct3.to_string() << "\nmem_wen: " << x << " mem_ren: " << x;
        cout << " sel1: " << opCode[0] << " sel2: " << opCode[1] << "\nsel3: " << opCode[2] << " sel4: " << opCode[3] << " sel5: " << opCode[4] << " sel6: " << opCode[5] << " sel7: " << opCode[6];
        cout << " branch: " << x << " auipc: " << x << " lui: " << x << endl;
    }else if(opCode == 0b0010011 | opCode == 0b0000011 | opCode == 0b0011011){
        cout << "Opcode Type: I" << endl;
        bitset<12> imm{instruction >> 20};
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);
        

    }else if(opCode == 0b0100011){
        cout << "Opcode Type: S" << endl;
        bitset<12> imm{((instruction>>25)<<5) + (instruction>>7 & 0b11111)};
        cout << imm << endl;
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);

    }else if(opCode == 0b1100011){
        cout << "Opcode Type: SB" << endl;
        bitset<12> imm{((instruction>>25 & 0b111111)<<5) + ((instruction>>8 & 0b1111)<<1) + ((instruction>>7 & 0b01)<<11) + (instruction>>30)};
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);
        cout << "imm: " << imm << endl;
           
    }else if(opCode == 0b0110111 || opCode == 0b0010111){
        cout << "Opcode Type: U" << endl;
        bitset<20> imm{((instruction>>12 & 0b111111)<<5) + ((instruction>>31)<<20) + ((instruction>>7 & 0b01)<<11) + (instruction>>30)};
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);
    }else if(opCode == 0b1101111){
        cout << "Opcode Type: UJ" << endl;
        bitset<20> imm{(instruction>>12)};
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);
    }else{
        cout << "\n/////////////////ERROR//////////////" << endl;
    }
    
}
    
