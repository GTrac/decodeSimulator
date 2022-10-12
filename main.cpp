#include <iostream>
#include "decode.cpp"

using namespace std;

#define LB 0b00000000110000011000001110000011 // 12 | 3 | 000 | 7 | I type
#define LBU 0b00000000110000011100001110000011 // 12 | 3 | 100 | 7 | I type
#define SB 0b00000000001100001000011110100011 // 0 | 3 | 1 | 000 | 15 | S type
#define LH 0b00000000110000011001001110000011 // 12 | 3 | 001 | 7 | I type
#define LHU 0b00000000110000011101001110000011 // 12 | 3 | 101 | 7 | I type
#define SH 0b00000000001100001001011110100011 // 0 | 3 | 1 | 001 | 15 | S type
#define LW 0b00000000110000011010001110000011 // 12 | 3 | 010 | 7 | I type
//#define LWU 0b00000000110000011100001110000011 // DOESNT EXIST ///////////////////////////////////
#define SW 0b00000000001100001010011110100011 // 0 | 3 | 1 | 010 | 15 | S type
#define LD 0b00000000110000011011001110000011 // 12 | 3 | 011 | 7 | I type
#define SD 0b00000000001100001011011110100011 // 0 | 3 | 1 | 011 | 15 | S type
// #define FLW 0b00000000001100011010000010000111 // imm | rs1 | 010 | rd | 0000111
// #define FLD 0b00000000001100011011000010000111 // imm | rs1 | 011 | rd | 0000111
// #define FSW 0b00000000001100011010011110100111 // imm | rs2 | rs1 | 010 | imm | 0100111
// #define FSD 0b00000000001100011011011110100111 // imm | rs2 | rs1 | 011 | imm | 0100111
// #define FMVDX 0b11100010000000011000001111010011 // 1110001 00000 rs1 000 rd 1010011
// #define FMVXD 0b11100010000000011000001111010011  //1110001 00000 rs1 000 rd 1010011
// #define csrrw 0b00000000000100011001001111110011 //csr rs1 001 rd 1110011 
// #define csrrs 0b00000000000100011010001111110011 //csr rs1 010 rd 1110011 
// #define csrrc 0b00000000000100011011001111110011 //csr rs1 011 rd 1110011
// #define csrwi 0b00000000000100011101001111110011 //csr zimm 101 rd 1110011
// #define csrsi 0b00000000000100011110001111110011 //csr zimm 110 rd 1110011
// #define csrci 0b00000000000100011111001111110011 //csr zimm 111 rd 1110011
#define ADD 0b00000000000100010000000110110011 // 0 | 01 | 10 | 000 | 11 | ADD
#define ADDI 0b00000000111100001000000110010011 //imm[11:0] rs1 000 rd 0010011 
#define ADDW 0b00000000000100011000001110111011 // 0000000 rs2 rs1 000 rd 0111011
#define ADDIW 0b00000000111100001000000110011011 //imm[11:0] rs1 000 rd 0011011
#define SUB 0b01000000000100011000001110110011 // 0100000 rs2 rs1 000 rd 0110011
#define SUBW 0b01000000000100011000001110111011 // 0100000 rs2 rs1 000 rd 0111011
#define MUL 0b00000010000100011000001110110011 // 0000001 rs2 rs1 000 rd 0110011
#define MULW 0b00000010000100011000001110111011 // 0000001 rs2 rs1 000 rd 0111011
#define MULH 0b00000010000100011001001110110011 // 0000001 rs2 rs1 001 rd 0110011
#define MULHSU 0b0000001000010001101001110110011 // 0000001 rs2 rs1 010 rd 0110011
#define MULHU 0b00000010000100011011001110110011 // 0000001 rs2 rs1 011 rd 0110011
#define DIV 0b00000010000100011100001110110011 // 0000001 rs2 rs1 100 rd 0110011
#define DIVU 0b00000010000100011101001110110011 // 0000001 rs2 rs1 101 rd 0110011
#define REM 0b00000010000100011110001110110011 // 0000001 rs2 rs1 110 rd 0110011
#define REMU 0b00000010000100011111001110110011 // 0000001 rs2 rs1 111 rd 0110011
#define DIVW 0b00000010000100011100001110111011 // 0000001 rs2 rs1 100 rd 0111011
#define DIVUW 0b00000010000100011101001110111011 // 0000001 rs2 rs1 101 rd 0111011
#define REMW 0b00000010000100011110001110111011 // 0000001 rs2 rs1 110 rd 0111011
#define REMUW 0b00000010000100011111001110111011 // 0000001 rs2 rs1 111 rd 0111011
#define AND 0b00000000000100010111000110110011 // 0000000 rs2 rs1 111 rd 0110011
#define ANDI 0b00000000111100001111000110010011 //imm[11:0] rs1 000 rd 0010011 
#define OR 0b00000000000100011110001110110011 // 0000000 rs2 rs1 110 rd 0110011
#define ORI 0b00000000001100001110000110010011  //imm[11:0] rs1 110 rd 0010011 
#define XOR 0b00000000000100011100001110110011 // 0000000 rs2 rs1 100 rd 0110011 
#define XORI 0b00000000001100001100000110010011  //imm[11:0] rs1 100 rd 0010011 
#define LUI 0b00000000000000000001000010110111 //imm[31:12] rd 0110111
#define AUIPC 0b00000000000000000001000010010111 //imm[31:12] rd 0010111
#define SLL 0b00000000000100011001001110110011 // 0000000 rs2 rs1 001 rd 0110011 
#define SLLI 0b0000000 shamt rs1 001 rd 0010011 // 0000000 shamt rs1 001 rd 0010011
#define SRL 0b00000000000100011101001110110011 // 0000000 rs2 rs1 101 rd 0110011 
#define SRLI 0b0000000 shamt rs1 101 rd 0010011 // 0000000 shamt rs1 101 rd 0010011
#define SRA 0b01000000000100011101001110110011 // 0100000 rs2 rs1 101 rd 0110011 
#define SRAI 0b0100000 shamt rs1 101 rd 0010011 // 0100000 shamt rs1 101 rd 0010011
#define SLLW 0b00000000000100011001001110111011 // 0000000 rs2 rs1 001 rd 0111011
#define SLLIW 0b0000000 shamt rs1 001 rd 0011011 // 0000000 shamt rs1 001 rd 0011011
#define SRLW 0b00000000000100011101001110111011 // 0000000 rs2 rs1 101 rd 0111011
#define SRLIW 0b0000000 shamt rs1 101 rd 0011011 // 0000000 shamt rs1 101 rd 0011011
#define SRAW 0b01000000000100011101001110111011 // 0100000 rs2 rs1 101 rd 0111011
#define SRAIW 0b0100000 shamt rs1 101 rd 0011011 // 0100000 shamt rs1 101 rd 0011011
#define SLT 00000000000100011010001110110011 // 0000000 rs2 rs1 010 rd 0110011 
#define SLTI 0b00000000111100001010000110010011 //imm[11:0] rs1 010 rd 0010011
#define SLTU 0b00000000000100011011001110110011 // 0000000 rs2 rs1 011 rd 0110011 
#define SLTIU 0b00000000111100001011000110010011 //imm[11:0] rs1 011 rd 0010011
#define BEQ 0b00000000000100011000001101100011// imm[12|10:5] rs2 rs1 000 imm[4:1|11] 1100011 
#define BNE 0b00000000000100011001001101100011// imm[12|10:5] rs2 rs1 001 imm[4:1|11] 1100011 
#define BLT 0b00000000000100011100001101100011// imm[12|10:5] rs2 rs1 100 imm[4:1|11] 1100011 
#define BGE 0b00000000000100011101001101100011// imm[12|10:5] rs2 rs1 101 imm[4:1|11] 1100011 
#define BLTU 0b00000000000100011110001101100011// imm[12|10:5] rs2 rs1 110 imm[4:1|11] 1100011 
#define BGEU 0b00000000000100011111001101100011// imm[12|10:5] rs2 rs1 111 imm[4:1|11] 1100011 
#define JAL 0b00000000011000000000100011101111 // imm[20|10:1|11|19:12] rd 1101111 
#define JALR 0b00000000011100001000000111100111 // imm[11:0] rs1 000 rd 1100111

int main(){
    decode(LB);
    cout << "\n------------------------------------------" << endl;
    decode(LBU);
    cout << "\n------------------------------------------" << endl;
    decode(SB);
    cout << "\n------------------------------------------" << endl;
    decode(LH);
    cout << "\n------------------------------------------" << endl;
    decode(LHU);
    cout << "\n------------------------------------------" << endl;
    decode(SH);
    cout << "\n------------------------------------------" << endl;
    decode(LW);
    cout << "\n------------------------------------------" << endl;
    //decode(LWU);
    //cout << "\n------------------------------------------" << endl;
    decode(SW);
    cout << "\n------------------------------------------" << endl;
    decode(LD);
    cout << "\n------------------------------------------" << endl;
    decode(SD);
    cout << "\n------------------------------------------" << endl;
    decode(ADD);
    cout << "\n------------------------------------------" << endl;
    decode(ADDI);
    cout << "\n------------------------------------------" << endl;
    decode(ADDW);
    cout << "\n------------------------------------------" << endl;
    decode(ADDIW);
    cout << "\n------------------------------------------" << endl;
    decode(SUB);
    cout << "\n------------------------------------------" << endl;
    decode(SUBW);
    cout << "\n------------------------------------------" << endl;
    decode(MUL);
    cout << "\n------------------------------------------" << endl;
    decode(MULW);
    cout << "\n------------------------------------------" << endl;
    decode(MULH);
    cout << "\n------------------------------------------" << endl;
    decode(MULHSU);
    cout << "\n------------------------------------------" << endl;
    decode(MULHU);
    cout << "\n------------------------------------------" << endl;
    decode(DIV);
    cout << "\n------------------------------------------" << endl;
    decode(DIVU);
    cout << "\n------------------------------------------" << endl;
    decode(REM);
    cout << "\n------------------------------------------" << endl;
    decode(REMU);
    cout << "\n------------------------------------------" << endl;
    decode(DIVW);
    cout << "\n------------------------------------------" << endl;
    decode(DIVUW);
    cout << "\n------------------------------------------" << endl;
    decode(REMW);
    cout << "\n------------------------------------------" << endl;
    decode(REMUW);
    cout << "\n------------------------------------------" << endl;
    decode(AND);
    cout << "\n------------------------------------------" << endl;
    decode(ANDI);
    cout << "\n------------------------------------------" << endl;
    decode(OR);
    cout << "\n------------------------------------------" << endl;
    decode(ORI);
    cout << "\n------------------------------------------" << endl;
    decode(XOR);
    cout << "\n------------------------------------------" << endl;
    decode(XORI);
    cout << "\n------------------------------------------" << endl;

}