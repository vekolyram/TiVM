#include "TiObject.h"
static int getTiFuncSign(TiFuncPrototype* proto) {
	int hash = 0;
	std::hash<std::string> hasher;
	hash += hasher(proto->fullName);
	for (auto& param : proto->prmret) {
		hash += hasher(param.typeClassFullName);
	}
	return hash;
}
static int getStrSign(std::string& str) {
	std::hash<std::string> hasher;
	return hasher(str);
}