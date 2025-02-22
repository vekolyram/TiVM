#include "tivm.h"
#include <iostream>
void TiVM::parseCode(TiInstruction* inst) {
	currentInstruction = inst;
	
	std::cout << inst->instruction << std::endl;
    lastInstruction = inst;
}
void TiVM::execrjmp(int address) {
	pc = address;
}
void TiVM::execcall(int address) {
	
	pc = address;
};
void TiVM::execret() {
	
};