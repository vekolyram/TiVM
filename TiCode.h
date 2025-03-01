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
struct TiRunState {
	int pc;
	int file;
	std::stack<TiStruct*> structstack;
};