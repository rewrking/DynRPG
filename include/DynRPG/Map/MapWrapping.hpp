#ifndef RPG_MAP_WRAPPING_HPP
#define RPG_MAP_WRAPPING_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::MapProperties::wrapping member
enum class MapWrapping : uchar
{
	None,
	Vertical,
	Horizontal,
	Both
};

//! One-byte version of RPG::MapWrapping
//typedef uchar MapWrapping_T;
}

#endif // RPG_MAP_WRAPPING_HPP
