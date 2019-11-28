#ifndef RPG_MAP_ALLOW_TYPE_HPP
#define RPG_MAP_ALLOW_TYPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::entryType

	The properties for Teleport/Escape/Save as defined on a map
*/
enum class MapAllowType : uchar
{
	SameAsParent,
	Allow,
	Forbid
};

//! One-byte version or RPG::MapAllowType
//typedef uchar MapAllowType_T;
}

#endif // RPG_MAP_ALLOW_TYPE_HPP
