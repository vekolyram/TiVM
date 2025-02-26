#pragma once
#include "TiDep.h"
#include "TiCode.h"
typedef std::variant<int, double> TiNumType;
typedef std::string* TiSString;
typedef std::string TiLString;
typedef std::variant<TiSString, TiLString> TiStrType;
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
	const TiFuncPrototype* proto;
	std::span<TiInstruction> instructions;
public:
	TiFunc(TiFuncPrototype* proto_, std::span<TiInstruction> insts) : proto(proto_), instructions(insts) {}
};
static std::string getNormalFullName(std::stack<TiStruct*>& structstack, std::string name) {
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
	TiLString typeClassFullName;
	union vunion {
		bool b;
		int i;
	} value;

	TiVar(const TiLString& typeClassFullName, const vunion& value)
		: typeClassFullName(typeClassFullName), value(value)
	{
	}
};
static int getTiFuncSign(TiFuncPrototype* proto);
struct TiFuncPrototype {
	std::string fullName;
	int sign;
	std::string name;
	std::span<TiVar> params;
	std::span<TiVar> returns;
	int postion;
public:
	TiFuncPrototype(std::stack<TiStruct*>& structstack_, std::string name_) {
		fullName = getNormalFullName(structstack_, name);
		sign = getTiFuncSign(this);
		name = name_;
	}
};

union TiSpecialT {
	TiStrType str;
	TiFunc* func;
};