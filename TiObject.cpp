#include "TiObject.h"
static int getTiFuncSign(TiFuncPrototype* proto) {
	int ret = 0;
	std::hash<std::string> hasher;
	ret += hasher(proto->fullName);
	for (auto& param : proto->params) {
		ret += hasher(param.typeClassFullName);
	}
	for (auto& retn : proto->returns) {
		ret += hasher(retn.typeClassFullName);
	}
	return ret;
}
static int getStrSign(std::string& str) {
	std::hash<std::string> hasher;
	return hasher(str);
}