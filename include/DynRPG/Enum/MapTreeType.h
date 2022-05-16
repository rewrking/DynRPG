#ifndef DYNRPG_MAP_TREE_TYPE_H
#define DYNRPG_MAP_TREE_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::treeEntryType

	The type of entry in the map tree for a particular map.
*/
enum MapTreeType
{
	MAP_TREE_FOLDER, //!< The root directory (name of your game)
	MAP_TREE_MAP,
	MAP_TREE_AREA
};

//! One-byte version or RPG::MapTreeType
typedef unsigned char MapTreeType_T;
}

#endif // DYNRPG_MAP_TREE_TYPE_H
