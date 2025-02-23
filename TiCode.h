#pragma once
#include "TiDep.h"
#include "TiObject.h"
struct TiInstruction {
	static enum class TiOpCode {
		ropt,
		rhalt,
		gin,
		gout,
		gerr,
		call,
		structst,
		structed
	};
	static enum class TiOpType {
		add,
		sub,
		mult,
		div
	};
	TiOpCode op;
};
struct TiRetState {
	TiInstruction* ret;
	std::stack<TiStruct*> structstack;
};
struct TiCodeChunk {
	TiInstruction codes[16];
	TiCodeChunk() {
		memset(codes, 0, sizeof(codes));
	}
};