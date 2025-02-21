#pragma once
#include <cstdint>
#include <stack>
constexpr int Regnum = 32;
//16 = ret
enum OPCode {
	rmov,
	radd,
	rsub,
	rmult,
	rdiv,
	rjmp,
	rjz,
	rprint,
	rhalt,
	rret,
	rload,
	rstore,
	lif,
	lwhile,
	lcodeblock,
	lfor
};

struct Instruction {
public:
	uint16_t instruction : 32;
};
struct StackInstruction : Instruction {
public:
	uint8_t opcode : 8;
	uint16_t address;
};
class TVM {
	int pc;
	bool running;
	int regs[16];
	Instruction* currentInstruction;
	Instruction* lastInstruction;
	std::stack<int> callstack;
	std::istream* input;
    std::ostream* output;
public:
	TVM() : regs{ -1 }, pc(0), running(false) {};
	void parseCode(Instruction* inst);
	void execrmov(int r1, int r2);
	void execradd(int r1, int r2, int r3);
	void execrsub(int r1, int r2, int r3);
	void execrmult(int r1, int r2, int r3);
	void execrdiv(int r1, int r2, int r3);
	void execrjmp(int address);
	void execrjz(int r1, int address);
	void execrout(int r1);
	void execrin(int r1);
	void execrhalt();
	void execrret();
	void execrload(int r1, int address);
	void execrstore(int r1, int address);
	void execlif(int r1, int address);
	void execlwhile(int r1, int address);
	void execlcodeblock(int address);
	void execlfor(int r1, int address);
};