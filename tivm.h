#pragma once
#include <cstdint>
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include <vector>

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
	TiFunc(std::stack<TiStruct>& structstack,std::string name){
		info.insert(TiStructInfoField::TiInfoFullName,);
	}
};
struct TiFuncPrototype : TiFunc {
	
};
struct TiInstruction {
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
	TiOpCode op;
};
struct TiRetState {
	TiInstruction* ret;
	int structStateCount;
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
	std::vector<TiCodeChunk> codevector;
	std::stack<TiStruct*> structstack;
	std::istream* inputistream;
	std::ostream* outputostream;
	std::vector<TiStruct> structvector;
	std::vector<TiFunc> funcsvector;
	std::stack<TiRetState> callstack;
	std::map<std::string, TiFuncPrototype> funcmap;
	TiInstruction* getCommand(int i);
public:
	TiVM() : running(false), inputistream(&std::cin), outputostream(&std::cout) {};
	void run();
	void addInstruction(TiInstruction inst);
	void setCodeVector(std::vector<TiCodeChunk>& code_);
	void execropt(int r1, int r2, TiInstruction::TiOpType type);
	void execgout(int r1);
	void execgin(int r1);
	void execrhalt();
	void execstructst(TiStruct tistruct);
	void execstructed();
	void execcall(TiFunc func);
	void execret();
	~TiVM();
};