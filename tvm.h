#pragma once
#include <cstdint>
#include <stack>

enum TiOpCode {
	ropt,
	rjmp,
	rhalt,
	rret,
	lif,
	lwhile,
	lcodeblockst,
	lcodeblocked,
	lfor,
	gin,
	gout,
	call
};
enum TiOpType {
	add,
	sub,
	mult,
	div
};
struct TiStruct {};
struct TiInstruction {
public:
	uint16_t instruction : 32;
};
class TiVM {
	int pc;
	bool running;
	TiInstruction* currentInstruction;
	TiInstruction* lastInstruction;
	std::stack<TiStruct> structstack;
	std::stack<int> callstack;
	std::istream* input;
    std::ostream* output;
public:
	TiVM() : pc(0), running(false) {};
	void parseCode(TiInstruction* inst);
	void execropt(int address,);
	void execrjmp(int address);
	void execrout(int r1);
	void execrin(int r1);
	void execrhalt();
	void execrret();
	void execlif(int r1, int address);
	void execlwhile(int r1, int address);
	void execlcodeblock(int address);
	void execlfor(int r1, int address);
};