#pragma once
#include <cstdint>
#include <stack>

enum TiOpCode {
	ropt,
	rjmp,
	rhalt,
	gin,
	gout,
	call,
	structst,
	structed
};
enum TiOpType {
	mov,
	add,
	sub,
	mult,
	div
};
enum TiStructType {
	TiClass,
	TiImpl,
	TiFunc,
	TiCodeblock,
	TiEnum,
	TiIf,
	TiWhile,
	TiFor,
	TiRet
};
struct TiStruct {
	TiStructType type;

};
struct TiInstruction {
};
class TiVM {
	int pc;
	bool running;
	TiInstruction* currentInstruction;
	TiInstruction* lastInstruction;
	std::stack<TiStruct> structstack;
	std::istream* input;
    std::ostream* output;
public:
	TiVM() : pc(0), running(false) {};
	void parseCode(TiInstruction* inst);
	void execropt(int r1,int address2,TiOpType type);
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