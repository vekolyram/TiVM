#include "tvm.h"
#include <iostream>
void TiVM::parseCode(TiInstruction* inst) {
	currentInstruction = inst;
	
	std::cout << inst->instruction << std::endl;
    lastInstruction = inst;
}
void TiVM::execrjmp(int address) {
	callstack.push(pc);
	pc = address;
}
void TiVM::execrout(int r1) {
	*output << regs[r1];
}
void TiVM::execrin(int r1) {
   	*input >> regs[r1];
}