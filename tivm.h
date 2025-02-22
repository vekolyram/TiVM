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
	TiStructType type = TiStructType::TiTypeFunc;
public:
	TiFunc()
};
struct TiInstruction {
	TiOpCode op;
    int r1;

};
//struct TiMemChunk {
//	int size;
//};
//struct TiBigMemChunk : TiMemChunk {
//	uint64_t* data;
//	int size = sizeof(data);
//};
//struct TiSmallMemChunk : TiMemChunk {
//    uint16_t* data;
//	int size = sizeof(data);
//};
//struct TiMidMemChunk : TiMemChunk {
//    uint32_t* data;
//   	int size = sizeof(data);
//};
class TiVM {
	bool running;
	TiInstruction* currentInstruction;
	TiInstruction* lastInstruction;
	TiInstruction* nextInstruction;
	std::stack<TiStruct*> structstack;
	std::istream* input;
	std::ostream* output;
	std::vector<TiStruct> structs;
	std::vector<TiFunc> funcs;
	std::stack<TiInstruction*> callstack;
public:
	TiVM() : running(false),currentInstruction(nullptr), lastInstruction(nullptr),input(&std::cin),output(&std::cout) {};
	void parseCode(TiInstruction* inst);
	void execropt(int r1, int address2, TiOpType type);
	void execgout(int r1);
	void execgin(int r1);
	void execrhalt();
	void execstructst(TiStruct tistruct);
	void execstructed();
	void execcall(int adress);
	void execret();
};