#include "tvm.h"
#include <iostream>
void TVM::parseCode(Instruction* inst) {
	currentInstruction = inst;
	int opcode = (inst->instruction >> 32) & 0xff;
	int r1 = (inst->instruction >> 16) & 0x0f;
    int r2 = (inst->instruction >> 8) & 0xff;
    int r3 = inst->instruction & 0xff;
	std::cout << inst->instruction << std::endl;
    lastInstruction = inst;
}
void TVM::execrmov(int r1, int r2) {regs[r1] = r2;}
void TVM::execradd(int r1, int r2, int r3) {regs[r1] = regs[r2] + regs[r3];}
void TVM::execrsub(int r1, int r2, int r3) {regs[r1] = regs[r2] - regs[r3];}
void TVM::execrmult(int r1, int r2, int r3) {regs[r1] = regs[r2] * regs[r3];}
void TVM::execrdiv(int r1, int r2, int r3) {regs[r1] = regs[r2] / regs[r3];}
void TVM::execrjmp(int address) {
	callstack.push(pc);
	pc = address;
}
void TVM::execrjz(int r1, int address) {
   	if (regs[r1] == 0) {
		callstack.push(pc);
       	pc = address;
  	}
}
void TVM::execrout(int r1) {
	*output << regs[r1];
}
void TVM::execrin(int r1) {
   	*input >> regs[r1];
}