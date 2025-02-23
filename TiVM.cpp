#include "tivm.h"
void TiVM::run() {
	while (pc > codespan.size() * 16) {
		for (auto& codeChunk : codespan) {
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
	return &(codespan[floor(i / 16)].codes[i % 16]);
}
void TiVM::execcall(TiFuncPrototype funcpt) {
	for (TiFunc func : funcsvector) {
		if (func.proto.fullName == funcpt.fullName) {
			callstack.push({ getCommand(pc + 1),structstack });
			break;
		}
	}
};
void TiVM::execret() {
	returning = true;
};