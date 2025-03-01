#pragma once
#include "TiDep.h"
#include "TiCode.h"
#include "TiVMFac.h"
typedef std::variant<int, double> TiNumType;
typedef std::string* TiSString;
typedef std::string TiLString;
typedef std::variant<TiSString, TiLString> TiStrType;
typedef struct TiFunc {
	const TiFuncPrototype* proto;
	const TiCodeBlock cb;
	const TiStruct parent;
public:
	TiFunc(TiFuncPrototype* proto_, TiCodeBlock cb_, TiStruct parent_) : proto(proto_), cb(cb_), parent(parent_) {}
};
typedef struct TiVar {
	TiLString typeClassFullName;
	union vunion {
		bool b;
		int i;
	} value;

	TiVar(const TiLString& typeClassFullName, const vunion& value)
		: typeClassFullName(typeClassFullName), value(value)
	{
	}
}; //update
struct TiStruct {
	enum class TiStructType {
		TiTypeClass,
		TiTypeInterface,
		TiTypeFunc,
		//TiTypeIf,
		//TiTypeWhile,
		//TiTypeFor
		//  tologic
	};
	enum class TiStructInfoField {
		TiInfoName,
		TiInfoFullName,
		//fullname to classfield
		TiInfoConstructor,
		TiInfoDestructor,
		TiInfoParent,
		TiInfoImpl
	};
	const TiStructType type;
	const std::map<TiStructInfoField, std::string> info;
	//class need magic func
};
typedef struct TiCodeBlock {
public:
	std::span<TiInstruction&> insts;
};
typedef struct TiFuncPrototype {
	TiLString fullName;
	TiStrType name;
	bool inited = false;
	int sign;
	std::span<TiVar> prmret;
	TiRunState postion;
public:
	TiFuncPrototype(std::stack<TiStruct*>& structstack_, TiLString name_) {
		fullName = getNormalFullName(structstack_, name_);
		sign = getTiFuncSign(this);
		name = name_;
	}
	TiFunc init(TiVMFac fac) {
		inited = true;
		fac.
	}
};

static TiLString getNormalFullName(std::stack<TiStruct*>& structstack, std::string name) {
	TiLString fullname = "";
	for (auto& struct_ : structstack._Get_container()) {
		TiStruct::TiStructType type = struct_->type;
		fullname += std::to_string(static_cast<int>(type));
		fullname += struct_->info.find(TiStruct::TiStructInfoField::TiInfoName)->second;
		fullname += ".";
	}
	fullname += name;
	return fullname;
}

static int getTiFuncSign(TiFuncPrototype* proto);

union TiSpecialT {
	TiStrType str;
	TiFunc* func;
};