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
	void execgout(int r1);
	void execgin(int r1);
	void execrhalt();
	void execstructst(TiStruct tistruct);
	void execstructed();
};