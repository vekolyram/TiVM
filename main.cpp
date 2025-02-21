#include "tvm.h"
#include <iostream>
int main() {
	TVM vm = TVM();
	Instruction inst = Instruction{ uint16_t(0xf234) };
	vm.parseCode(&inst);
}