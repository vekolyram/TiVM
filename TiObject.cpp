#include "TiObject.h"
static int getTiFuncSign(std::string fullName, std::span<TiVar> params, std::span<TiVar> returns) {
	int ret = 0;
	std::hash<std::string> hasher;
	ret += hasher(fullName);
	for (auto& param : params) {
		ret += hasher(param.typeClassFullName);
	}
	for (auto& retn : returns) {
		ret += hasher(retn.typeClassFullName);
	}
	return ret;
}