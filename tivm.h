#pragma once
#include "TiObject.h"
#include "TiCode.h"
#include "TiDep.h"

class TiVM {
	bool running;
	TiRunState state;
	bool returning;
	std::stack<TiStruct*> structstack;
	std::istream* inputistream;
	std::ostream* outputostream;
	std::ostream* errorostream;
	//start willtoclass
	std::vector<TiStruct> structvector;
	std::vector<TiFunc> funcsvector;
	//end
	std::stack<TiRunState> callstack;
	std::unordered_set<int, TiFuncPrototype> funcptsset;
	std::unordered_set<int, std::string> sstringset;
	//TiInstruction* getCommand(int i);

public:
	TiVM() : running(false), inputistream(&std::cin), outputostream(&std::cout), errorostream(&std::cerr) {};
	void run();
	void execropt(const TiVar& r1, const TiVar& r2, TiVar& r3, TiInstruction::TiOpType type);
	void execgout(int r1);
	void execgin(int r1);
	void execgerr(int r1);
	void execrhalt();
	void execstructst(TiStruct tistruct);
	void execstructed();
	void execcall(TiFuncPrototype func);
	void execret();
	~TiVM();
};