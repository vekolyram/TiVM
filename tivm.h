#pragma once
#include <cstdint>
#include <iostream>
#include "TiObject.h"
#include <unordered_set>

struct TiInstruction {
	enum class TiOpCode {
		ropt,
		rhalt,
		gin,
		gout,
		gerr,
		call,
		structst,
		structed
	};
	enum class TiOpType {
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
class TiVM {
	bool running;
	int pc;
	bool returning;
	std::span<TiCodeChunk> codespan;
	std::stack<TiStruct*> structstack;
	std::istream* inputistream;
	std::ostream* outputostream;
	std::ostream* errorostream;
	std::vector<TiStruct> structvector;
	std::vector<TiFunc> funcsvector;
	std::stack<TiRetState> callstack;
	std::unordered_set<int, TiFuncPrototype> funcptsset;
	TiInstruction* getCommand(int i);

public:
	TiVM() : running(false), inputistream(&std::cin), outputostream(&std::cout), errorostream(&std::cerr) {};
	void run();
	void execropt(int r1, int r2, TiInstruction::TiOpType type);
	void execgout(int r1);
	void execgin(int r1);
	void execgerr(int r1);
	void execrhalt();
	void execstructst(TiStruct tistruct);
	void execstructed();
	void execcall(TiFunc func);
	void execret();
	~TiVM();
};