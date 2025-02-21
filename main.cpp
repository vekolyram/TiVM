#include "tivm.h"
#include <iostream>
int main() {
	TiVM vm = TiVM();
	TiInstruction inst = TiInstruction{ uint16_t(0xf234) };
	vm.parseCode(&inst);
}