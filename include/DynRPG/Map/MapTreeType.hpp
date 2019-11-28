#ifndef RPG_MAP_TREE_TYPE_HPP
#define RPG_MAP_TREE_TYPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::treeEntryType

	The type of entry in the map tree for a particular map.
*/
enum class MapTreeType : uchar
{
	Folder, //!< The root directory (name of your game)
	Map,
	Area
};

//! One-byte version or RPG::MapTreeType
//typedef uchar MapTreeType_T;
}

#endif // RPG_MAP_TREE_TYPE_HPP
