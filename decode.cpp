

#include <iostream>
#include <bitset>

using namespace std;
int x =0;
void decode(uint32_t instruction){
    bitset<7> opCode = (uint8_t)(instruction & 0b1111111); //retrieve opcode
    if(opCode == 0b0110011 || opCode == 0b0111011){
        cout << "Opcode Type: R" << endl;
        bitset<8> funct7 = (uint8_t)(instruction >> 25);
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);
        bool sel8 = funct7[0] && (funct3[2]==0) && (funct3[1] || funct3[0]);
        cout << "Control Signals:\nreg_wen: " << 1 << " reg_ren: " << 1 << " alu_op: " << funct7[5] << funct3.to_string() << "\nmem_wen: " << 0 << " mem_ren: " << 0;
        cout << " sel1: " << 0 << " sel2: " << 0 << "\nsel3: " << 0 << " sel4: " << 0 << " sel5: " << 0 << " sel6: " << 1 << " sel7: " << 0 << " sel8: " << sel8;
        cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 0 << endl;

    }else if(opCode == 0b0010011 || opCode == 0b0000011 || opCode == 0b0011011 || opCode == 0b1100111){
        cout << "Opcode Type: I" << endl;
        bitset<12> imm{instruction >> 20};
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);
        if(opCode == 0b0010011 && (funct3[2] & funct3[0])==1 ){
            cout << "Control Signals:\nreg_wen: " << 1 << " reg_ren: " << 1 << " alu_op: " << imm[10] << funct3.to_string() << "\nmem_wen: " << 0 << " mem_ren: " << 0;
            cout << " sel1: " << 1 << " sel2: " << 1 << "\nsel3: " << 0 << " sel4: " << 0 << " sel5: " << 0 << " sel6: " << 1 << " sel7: " << 0 << " sel8: " << 0;
            cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 0 << endl;
        }else if(opCode == 0b0010011){
            cout << "Control Signals:\nreg_wen: " << 1 << " reg_ren: " << 1 << " alu_op: " << 0 << funct3.to_string() << "\nmem_wen: " << 0 << " mem_ren: " << 0;
            cout << " sel1: " << 1 << " sel2: " << 1 << "\nsel3: " << 0 << " sel4: " << 0 << " sel5: " << 0 << " sel6: " << 1 << " sel7: " << 0 << " sel8: " << 0;
            cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 0 << endl;
        }else if(opCode == 0b0000011){
            cout << "Control Signals:\nreg_wen: " << 1 << " reg_ren: " << 1 << " alu_op: " << 0 << funct3.to_string() << "\nmem_wen: " << 0 << " mem_ren: " << 0;
            cout << " sel1: " << 0 << " sel2: " << 1 << "\nsel3: " << 1 << " sel4: " << 0 << " sel5: " << 0 << " sel6: " << 1 << " sel7: " << 1 << " sel8: " << 0;
            cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 0 << endl;
        }else if(opCode == 0b1100111){
            cout << "Control Signals:\nreg_wen: " << 1 << " reg_ren: " << 1 << " alu_op: " << 0 << funct3.to_string() << "\nmem_wen: " << 0 << " mem_ren: " << 0;
            cout << " sel1: " << 1 << " sel2: " << 1 << "\nsel3: " << 0 << " sel4: " << 1 << " sel5: " << 1 << " sel6: " << 1 << " sel7: " << 0 << " sel8: " << 0;
            cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 0 << endl;
        }else{
            cout << "/////////////ERROR/////////" <<endl;
        }
        

    }else if(opCode == 0b0100011){
        cout << "Opcode Type: S" << endl;
        bitset<12> imm{((instruction>>25)<<5) + (instruction>>7 & 0b11111)};
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);
        cout << "Control Signals:\nreg_wen: " << 0 << " reg_ren: " << 1 << " alu_op: " << 0 << funct3.to_string() << "\nmem_wen: " << 1 << " mem_ren: " << 0;
        cout << " sel1: " << 0 << " sel2: " << 1 << "\nsel3: " << 0 << " sel4: " << 0 << " sel5: " << 0 << " sel6: " << 1 << " sel7: " << 0 << " sel8: " << 0;
        cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 0 << endl;

    }else if(opCode == 0b1100011){
        cout << "Opcode Type: SB" << endl;
        bitset<12> imm{((instruction>>25 & 0b111111)<<5) + ((instruction>>8 & 0b1111)<<1) + ((instruction>>7 & 0b01)<<11) + (instruction>>30)};
        bitset<5> rs2 = (uint8_t)((instruction >> 20) & 0b11111);
        bitset<5> rs1 = (uint8_t)((instruction >> 15) & 0b11111);
        bitset<3> funct3 = (uint8_t)((instruction >> 12) & 0b111);
        cout << "imm: " << imm << endl;
        cout << "Control Signals:\nreg_wen: " << 0 << " reg_ren: " << 1 << " alu_op: " << 0 << funct3.to_string() << "\nmem_wen: " << 0 << " mem_ren: " << 0;
        cout << " sel1: " << 0 << " sel2: " << 0 << "\nsel3: " << 0 << " sel4: " << 0 << " sel5: " << 1 << " sel6: " << 1 << " sel7: " << 0 << " sel8: " << 0;
        cout << " branch: " << 1 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 0 << endl;
        
    }else if(opCode == 0b0110111 || opCode == 0b0010111){
        cout << "Opcode Type: U" << endl;
        bitset<20> imm{(instruction>>12)};       
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);
        if(opCode == 0b0110111){
            cout << "Control Signals:\nreg_wen: " << 0 << " reg_ren: " << 1 << " alu_op: " << 0000 << "\nmem_wen: " << 0 << " mem_ren: " << 0;
            cout << " sel1: " << 0 << " sel2: " << 0 << "\nsel3: " << 0 << " sel4: " << 0 << " sel5: " << 0 << " sel6: " << 0 << " sel7: " << 0 << " sel8: " << 0;
            cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 1 << "jal: " << 0 << endl;
        }else if(opCode == 0b0010111){
            cout << "Control Signals:\nreg_wen: " << 0 << " reg_ren: " << 1 << " alu_op: " << 0000 << "\nmem_wen: " << 0 << " mem_ren: " << 0;
            cout << " sel1: " << 0 << " sel2: " << 0 << "\nsel3: " << 0 << " sel4: " << 0 << " sel5: " << 0 << " sel6: " << 0 << " sel7: " << 0 << " sel8: " << 0;
            cout << " branch: " << 0 << " auipc: " << 1 << " lui: " << 0 << "jal: " << 0 << endl;
        }

    }else if(opCode == 0b1101111){
        cout << "Opcode Type: UJ" << endl;
        bitset<20> imm{((instruction>>12 & 0b111111)<<5) + ((instruction>>31)<<20) + ((instruction>>7 & 0b01)<<11) + (instruction>>30)};
        bitset<5> rd = (uint8_t)((instruction >> 7) & 0b11111);
        cout << "Control Signals:\nreg_wen: " << 1 << " reg_ren: " << 0 << " alu_op: " << 0000 << "\nmem_wen: " << 0 << " mem_ren: " << 0;
        cout << " sel1: " << 0 << " sel2: " << 0 << "\nsel3: " << 0 << " sel4: " << 1 << " sel5: " << 0 << " sel6: " << 0 << " sel7: " << 0 << " sel8: " << 0;
        cout << " branch: " << 0 << " auipc: " << 0 << " lui: " << 0 << "jal: " << 1 << endl;

    }else{
        cout << "\n/////////////////ERROR//////////////" << endl;
    }
    
}
    
