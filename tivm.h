#pragma once
#include <cstdint>
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include <vector>

enum class TiOpCode {
	ropt,
	rhalt,
	gin,
	gout,
	call,
	structst,
	structed
};
enum class TiOpType {
	mov,
	add,
	sub,
	mult,
	div
};


struct TiStruct {
	enum class TiStructType {
		TiTypeClass,
		TiTypeInterface,
		TiTypeFunc,
		TiTypeCodeblock,
		TiTypeEnum,
		TiTypeIf,
		TiTypeWhile,
		TiTypeFor
	};
	enum class TiStructInfoField {
		TiInfoName,
		TiInfoFullName,
		TiInfoConstructor,
		TiInfoDestructor,
		TiInfoParent,
		TiInfoImpl
	};
	TiStructType type;
	std::map<TiStructInfoField, std::string> info;
};
struct TiFunc : TiStruct {
	const TiStructType type = TiStructType::TiTypeFunc;
	std::vector<TiInstruction> instructions;
public:
	TiFunc()
};
struct TiInstruction {
	TiOpCode op;
    int r1;
	int 
};
struct TiRetState {
	TiInstruction* ret;
	int structStateCount;
};
struct TiCodeChunk {
	TiInstruction code[16];
	TiCodeChunk() {
		memset(code, 0, sizeof(code));
	}
};
class TiVM {
	bool running;
	int pc;
	std::vector<TiCodeChunk> code;
	std::stack<TiStruct*> structstack;
	std::istream* input;
	std::ostream* output;
	std::vector<TiStruct> structs;
	std::vector<TiFunc> funcs;
	std::stack<TiRetState> callstack;
public:
	TiVM() : running(false),input(&std::cin),output(&std::cout) {};
	void run();
	void addInstruction(TiInstruction inst);
	void setCodeVector(std::vector<TiCodeChunk>& code_);
	void execropt(int r1, int r2, TiOpType type);
	void execgout(int r1);
	void execgin(int r1);
	void execrhalt();
	void execstructst(TiStruct tistruct);
	void execstructed();
	void execcall(TiFunc func);
	void execret();
	~TiVM();
};