#include "tivm.h"
#include <iostream>
void TiVM::parseCode(TiInstruction* inst) {
	currentInstruction = inst;
	
    lastInstruction = inst;
}
void TiVM::execcall(int address) {
	for (TiStruct stru : funcs) {
		if (stru.info.find()) {
		}
	}
};
void TiVM::execret() {
    nextInstruction = callstack.top()
};