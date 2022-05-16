#include <DynRPG/DString.h>

namespace RPG
{
DString::operator std::string() const
{
	std::string s = "";
	if (this)
		s = std::string(reinterpret_cast<const char*>(this), reinterpret_cast<const int*>(this)[-1]);
	return s;
}

DString::operator char*() const
{
	return (char*)reinterpret_cast<const char*>(this);
}

int DString::length()
{
	if (this)
		return reinterpret_cast<const int*>(this)[-1];
	return 0;
}
}
