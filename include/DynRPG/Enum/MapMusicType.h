#ifndef DYNRPG_MAP_MUSIC_TYPE_H
#define DYNRPG_MAP_MUSIC_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::bgmType

	The type of music defined on a map
*/
enum MapMusicType
{
	MAP_MUSIC_SAME_AS_PARENT,
	MAP_MUSIC_ENTRUST_TO_EVENT,
	MAP_MUSIC_SPECIFY
};

//! One-byte version or RPG::MapMusicType
typedef unsigned char MapMusicType_T;
}

#endif // DYNRPG_MAP_MUSIC_TYPE_H
