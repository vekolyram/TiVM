#include "tivm.h"
#include <iostream>
void TiVM::run() {
	while (pc > code.size() * 16) {
		for (auto codeChunk : code) {
			for (auto instruction : codeChunk.code) {

			}
		}
	}
}
void TiVM::execcall(TiFunc func) {
	for (TiStruct stru : funcs) {
		if (stru.info.find((TiStruct::TiStructInfoField::TiInfoFullName)) == ) {
			
		}
	}
};
void TiVM::execret() {
	vector = callstack.top().ret;
};