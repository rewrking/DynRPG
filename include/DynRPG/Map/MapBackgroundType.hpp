#ifndef RPG_MAP_BACKGROUND_TYPE_HPP
#define RPG_MAP_BACKGROUND_TYPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::battleBgType

	The type of battle background defined on a map
*/
enum class MapBackgroundType : uchar
{
	SameAsParent,
	UseTerrainSettings,
	Specify
};

//! One-byte version or RPG::MapBgType
//typedef uchar MapBgType_T;
}

#endif // RPG_MAP_BACKGROUND_TYPE_HPP
