#ifndef DYNRPG_MAP_ALLOW_TYPE_H
#define DYNRPG_MAP_ALLOW_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::MapTreeProperties::entryType

	The properties for Teleport/Escape/Save as defined on a map
*/
enum MapAllowType
{
	MAP_TES_SAME_AS_PARENT,
	MAP_TES_ALLOW,
	MAP_TES_FORBID
};

//! One-byte version or RPG::MapAllowType
typedef unsigned char MapAllowType_T;
}

#endif // DYNRPG_MAP_ALLOW_TYPE_H
