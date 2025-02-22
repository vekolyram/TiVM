#pragma once
#include "string"
struct TiVar {
	std::string typeClassFullName;
	union {
		bool b;
		int i;
	} value;
};
union TiTNum {


};
