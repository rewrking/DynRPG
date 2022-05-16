#ifndef DYNRPG_MAP_BG_TYPE_H
#define DYNRPG_MAP_BG_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::battleBgType

	The type of battle background defined on a map
*/
enum MapBgType
{
	MAP_BG_SAME_AS_PARENT,
	MAP_BG_USE_TERRAIN_SETTINGS,
	MAP_BG_SPECIFY
};

//! One-byte version or RPG::MapBgType
typedef unsigned char MapBgType_T;
}

#endif // DYNRPG_MAP_BG_TYPE_H
