#include "tivm.h"
#include <iostream>
void TiVM::parseCode(TiInstruction* inst) {
	currentInstruction = inst;
	
    lastInstruction = inst;
}
void TiVM::execrjmp(int address) {
	pc = address;
}
void TiVM::execcall(int address) {
	
	pc = address;
};
void TiVM::execret() {
	while (structstack.top()->type == TiStruct::TiRet) {
		structstack.pop();
	}
	
    structstack.top()->info.find(TiStruct::TiAddress);
};