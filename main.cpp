#include <iostream>
#include decode.cpp

using namespace std;

#DEFINE LB 0b00000000110000011000001110000011 // 12 | 3 | 000 | 7 | I type
#DEFINE LBU 0b00000000110000011100001110000011 // 12 | 3 | 100 | 7 | I type
#DEFINE SB 0b00000000001100001000011110100011 // 0 | 3 | 1 | 000 | 15 | S type
#DEFINE LH 0b00000000110000011001001110000011 // 12 | 3 | 001 | 7 | I type
#DEFINE LHU 0b00000000110000011101001110000011 // 12 | 3 | 101 | 7 | I type
#DEFINE SH 0b00000000001100001001011110100011 // 0 | 3 | 1 | 001 | 15 | S type
#DEFINE LW 0b00000000110000011010001110000011 // 12 | 3 | 010 | 7 | I type
//#DEFINE LWU 0b00000000110000011100001110000011 // DOESNT EXIST ///////////////////////////////////
#DEFINE SW 0b00000000001100001010011110100011 // 0 | 3 | 1 | 010 | 15 | S type
#DEFINE LD 0b00000000110000011011001110000011 // 12 | 3 | 011 | 7 | I type
#DEFINE SD 0b00000000001100001011011110100011 // 0 | 3 | 1 | 011 | 15 | S type
// #DEFINE FLW 0b00000000001100011010000010000111 // imm | rs1 | 010 | rd | 0000111
// #DEFINE FLD 0b00000000001100011011000010000111 // imm | rs1 | 011 | rd | 0000111
// #DEFINE FSW 0b00000000001100011010011110100111 // imm | rs2 | rs1 | 010 | imm | 0100111
// #DEFINE FSD 0b00000000001100011011011110100111 // imm | rs2 | rs1 | 011 | imm | 0100111
// #DEFINE FMVDX 0b11100010000000011000001111010011 // 1110001 00000 rs1 000 rd 1010011
// #DEFINE FMVXD 0b11100010000000011000001111010011  //1110001 00000 rs1 000 rd 1010011
// #DEFINE csrrw 0b00000000000100011001001111110011 //csr rs1 001 rd 1110011 
// #DEFINE csrrs 0b00000000000100011010001111110011 //csr rs1 010 rd 1110011 
// #DEFINE csrrc 0b00000000000100011011001111110011 //csr rs1 011 rd 1110011
// #DEFINE csrwi 0b00000000000100011101001111110011 //csr zimm 101 rd 1110011
// #DEFINE csrsi 0b00000000000100011110001111110011 //csr zimm 110 rd 1110011
// #DEFINE csrci 0b00000000000100011111001111110011 //csr zimm 111 rd 1110011
#DEFINE ADD 0b00000000000100010000000110110011 // 0 | 01 | 10 | 000 | 11 | ADD
#DEFINE ADDI 0b00000000111100001000000110010011 //imm[11:0] rs1 000 rd 0010011 
#DEFINE ADDW 0b00000000000100011000001110111011 // 0000000 rs2 rs1 000 rd 0111011
#DEFINE ADDIW 0b00000000111100001000000110011011 //imm[11:0] rs1 000 rd 0011011
#DEFINE SUB 0b01000000000100011000001110110011 // 0100000 rs2 rs1 000 rd 0110011
#DEFINE SUBW 0b01000000000100011000001110111011 // 0100000 rs2 rs1 000 rd 0111011
#DEFINE MUL 0b00000010000100011000001110110011 // 0000001 rs2 rs1 000 rd 0110011
#DEFINE MULW 0b00000010000100011000001110111011 // 0000001 rs2 rs1 000 rd 0111011
#DEFINE MULH 0b00000010000100011001001110110011 // 0000001 rs2 rs1 001 rd 0110011
#DEFINE MULHSU 0b0000001000010001101001110110011 // 0000001 rs2 rs1 010 rd 0110011
#DEFINE MULHU 0b00000010000100011011001110110011 // 0000001 rs2 rs1 011 rd 0110011
#DEFINE DIV 0b00000010000100011100001110110011 // 0000001 rs2 rs1 100 rd 0110011
#DEFINE DIVU 0b00000010000100011101001110110011 // 0000001 rs2 rs1 101 rd 0110011
#DEFINE REM 0b00000010000100011110001110110011 // 0000001 rs2 rs1 110 rd 0110011
#DEFINE REMU 0b00000010000100011111001110110011 // 0000001 rs2 rs1 111 rd 0110011
#DEFINE DIVW 0b00000010000100011100001110111011 // 0000001 rs2 rs1 100 rd 0111011
#DEFINE DIVUW 0b00000010000100011101001110111011 // 0000001 rs2 rs1 101 rd 0111011
#DEFINE REMW 0b00000010000100011110001110111011 // 0000001 rs2 rs1 110 rd 0111011
#DEFINE REMUW 0b00000010000100011111001110111011 // 0000001 rs2 rs1 111 rd 0111011
#DEFINE AND 0b00000000000100010111000110110011 // 0000000 rs2 rs1 111 rd 0110011
#DEFINE ANDI 0b00000000111100001111000110010011 //imm[11:0] rs1 000 rd 0010011 
#DEFINE OR 0b00000000000100011110001110110011 // 0000000 rs2 rs1 110 rd 0110011
#DEFINE ORI 0b00000000001100001110000110010011  //imm[11:0] rs1 110 rd 0010011 
#DEFINE XOR 0b00000000000100011100001110110011 // 0000000 rs2 rs1 100 rd 0110011 
#DEFINE XORI 0b00000000001100001100000110010011  //imm[11:0] rs1 100 rd 0010011 
#DEFINE LUI 0b00000000000000000001000010110111 //imm[31:12] rd 0110111
#DEFINE AUIPC 0b00000000000000000001000010010111 //imm[31:12] rd 0010111
#DEFINE SLL 0b00000000000100011001001110110011 // 0000000 rs2 rs1 001 rd 0110011 
#DEFINE SLLI 0b0000000 shamt rs1 001 rd 0010011 // 0000000 shamt rs1 001 rd 0010011
#DEFINE SRL 0b00000000000100011101001110110011 // 0000000 rs2 rs1 101 rd 0110011 
#DEFINE SRLI 0b0000000 shamt rs1 101 rd 0010011 // 0000000 shamt rs1 101 rd 0010011
#DEFINE SRA 0b01000000000100011101001110110011 // 0100000 rs2 rs1 101 rd 0110011 
#DEFINE SRAI 0b0100000 shamt rs1 101 rd 0010011 // 0100000 shamt rs1 101 rd 0010011
#DEFINE SLLW 0b00000000000100011001001110111011 // 0000000 rs2 rs1 001 rd 0111011
#DEFINE SLLIW 0b0000000 shamt rs1 001 rd 0011011 // 0000000 shamt rs1 001 rd 0011011
#DEFINE SRLW 0b00000000000100011101001110111011 // 0000000 rs2 rs1 101 rd 0111011
#DEFINE SRLIW 0b0000000 shamt rs1 101 rd 0011011 // 0000000 shamt rs1 101 rd 0011011
#DEFINE SRAW 0b01000000000100011101001110111011 // 0100000 rs2 rs1 101 rd 0111011
#DEFINE SRAIW 0b0100000 shamt rs1 101 rd 0011011 // 0100000 shamt rs1 101 rd 0011011
#DEFINE SLT 00000000000100011010001110110011 // 0000000 rs2 rs1 010 rd 0110011 
#DEFINE SLTI 0b00000000111100001010000110010011 //imm[11:0] rs1 010 rd 0010011
#DEFINE SLTU 0b00000000000100011011001110110011 // 0000000 rs2 rs1 011 rd 0110011 
#DEFINE SLTIU 0b00000000111100001011000110010011 //imm[11:0] rs1 011 rd 0010011
#DEFINE BEQ 0b00000000000100011000001101100011// imm[12|10:5] rs2 rs1 000 imm[4:1|11] 1100011 
#DEFINE BNE 0b00000000000100011001001101100011// imm[12|10:5] rs2 rs1 001 imm[4:1|11] 1100011 
#DEFINE BLT 0b00000000000100011100001101100011// imm[12|10:5] rs2 rs1 100 imm[4:1|11] 1100011 
#DEFINE BGE 0b00000000000100011101001101100011// imm[12|10:5] rs2 rs1 101 imm[4:1|11] 1100011 
#DEFINE BLTU 0b00000000000100011110001101100011// imm[12|10:5] rs2 rs1 110 imm[4:1|11] 1100011 
#DEFINE BGEU 0b00000000000100011111001101100011// imm[12|10:5] rs2 rs1 111 imm[4:1|11] 1100011 
#DEFINE JAL 0b00000000011000000000100011101111 // imm[20|10:1|11|19:12] rd 1101111 
#DEFINE JALR 0b00000000011100001000000111100111 // imm[11:0] rs1 000 rd 1100111

int main(){
    decode(LB);
    cout << "------------------------------------------" << endl;
}