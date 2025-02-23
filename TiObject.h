#pragma once
#include "TiDep.h"
#include "TiCode.h"
typedef std::variant<int, double> TiNumType;
typedef std::string& TiSString;
typedef std::string TiString;
union TiString {
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
		TiInfoImpl,
		TiLocalVarList
	};
	TiStructType type;
	std::map<TiStructInfoField, std::string> info;
};
struct TiFunc {
	const TiFuncPrototype proto;
	std::span<TiInstruction> instructions;
public:
	TiFunc(TiFuncPrototype proto_, std::span<TiInstruction> insts) : proto(proto_), instructions(insts) {}
};
std::string getNormalFullName(std::stack<TiStruct*>& structstack, std::string name) {
	std::string fullname = "";
	for (auto& struct_ : structstack._Get_container()) {
		TiStruct::TiStructType type = struct_->type;
		fullname += std::to_string(static_cast<int>(type));
		fullname += struct_->info.find(TiStruct::TiStructInfoField::TiInfoName)->second;
		fullname += ".";
	}
	fullname += name;
	return fullname;
}
struct TiVar {
	std::string typeClassFullName;
	union {
		bool b;
		int i;
	} value;
};
int getTiFuncSign(std::string fullName, std::span<TiVar> params, std::span<TiVar> returns);
struct TiFuncPrototype {
	std::string fullName;
	long sign;
	std::string name;
	std::span<TiVar> params;
	std::span<TiVar> returns;
	int postion;
public:
	TiFuncPrototype(std::stack<TiStruct*>& structstack_, std::string name_) {
		fullName = getNormalFullName(structstack_, name);
		sign = getTiFuncSign(fullName, params, returns);
		name = name_;
	}
};

union TiSpecialT {
	std::string str;
	TiFunc* func;
};