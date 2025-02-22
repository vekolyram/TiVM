#pragma once
#include <cstdint>
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include <vector>

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


struct TiStruct {
	enum TiStructType {
		TiClass,
		TiInterface,
		TiFunc,
		TiCodeblock,
		TiEnum,
		TiIf,
		TiWhile,
		TiFor,
		TiRet
	};
	enum TiStructInfoField {
		TiName,
		TiFullName,
		TiConstructor,
		TiDestructor,
		TiParent,
		TiImpl
	};
	TiStructType type;
	std::map<TiStructInfoField, std::string> info;
};
struct TiInstruction {
	TiOpCode op;
    int r1;

};
struct MemChunk {
    uint64_t data;
};
class TiVM {
	int pc;
	bool running;
	TiInstruction* currentInstruction;
	TiInstruction* lastInstruction;
	std::stack<TiStruct*> structstack;
	std::istream* input;
	std::ostream* output;
	std::vector<uint8_t> code;
public:
	TiVM() : pc(0), running(false),currentInstruction(nullptr), lastInstruction(nullptr),input(&std::cin),output(&std::cout) {};
	void parseCode(TiInstruction* inst);
	void execropt(int r1, int address2, TiOpType type);
	void execrjmp(int address);
	void execgout(int r1);
	void execgin(int r1);
	void execrhalt();
	void execstructst(TiStruct tistruct);
	void execstructed();
	void execcall(int adress);
	void execret();
};