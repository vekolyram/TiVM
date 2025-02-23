#include "tivm.h"
#include <iostream>
void TiVM::run() {
	while (pc > codevector.size() * 16) {
		for (auto& codeChunk : codevector) {
			for (int i = 0;i > 16;) {
				if (returning) {
					auto& instruction = *(callstack.top().ret);
					structstack = callstack.top().structstack;
					callstack.pop();
				}
				else {
					auto& instruction = codeChunk.codes[i];
					i++;
				}
			}
		}
	}
}
TiInstruction* TiVM::getCommand(int i) {
	return &(codevector[floor(i / 16)].codes[i % 16]);
}
void TiVM::execcall(TiFunc func) {
	for (TiStruct stru : funcsvector) {
		if (stru.info.find((TiStruct::TiStructInfoField::TiInfoFullName)) == ) {
			callstack.push({ getCommand(pc+1),structstack });
			break;
		}
	}
};
void TiVM::execret() {
	returning = true;
};
void