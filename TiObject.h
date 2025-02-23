#pragma once
#include "string"
#include <map>
#include <stack>
#include <vector>
#include <string>
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
		TiInfoParams,
		TiInfoReturns
	};
	TiStructType type;
	std::map<TiStructInfoField, std::string> info;
};
struct TiFunc : TiStruct {
	const TiStructType type = TiStructType::TiTypeFunc;
	std::vector<TiInstruction> instructions;
public:
	TiFunc(std::stack<TiStruct*>& structstack, std::string name) {
		info.insert(std::map<TiStructInfoField, std::string>::value_type(TiStructInfoField::TiInfoFullName, getFullName(structstack,name)));
	}
};
std::string getFullName(std::stack<TiStruct*>& structstack, std::string name) {
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
struct TiFuncPrototype : TiFunc {
};
struct TiVar {
	std::string typeClassFullName;
	union {
		bool b;
		int i;
	} value;
};
union TiNumT {
};
