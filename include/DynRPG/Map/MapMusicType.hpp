#ifndef RPG_MAP_MUSIC_TYPE_HPP
#define RPG_MAP_MUSIC_TYPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::bgmType

	The type of music defined on a map
*/
enum class MapMusicType : uchar
{
	SameAsParent,
	EntrustToEvent,
	Specify
};

//! One-byte version or RPG::MapMusicType
//typedef uchar MapMusicType_T;
}

#endif // RPG_MAP_MUSIC_TYPE_HPP
