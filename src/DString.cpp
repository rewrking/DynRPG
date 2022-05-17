#include <DynRPG/DString.h>

namespace RPG
{
DString::operator std::string() const
{
	return std::string(reinterpret_cast<const char*>(this), reinterpret_cast<const int*>(this)[-1]);
}

DString::operator char*() const
{
	return (char*)reinterpret_cast<const char*>(this);
}

int DString::length()
{
	return reinterpret_cast<const int*>(this)[-1];
}
}
