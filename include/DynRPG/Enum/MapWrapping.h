#ifndef DYNRPG_MAP_WRAPPING_H
#define DYNRPG_MAP_WRAPPING_H

namespace RPG
{
//! Possible values for the RPG::MapProperties::wrapping member
enum MapWrapping
{
	MCL_NONE,
	MCL_VERTICAL,
	MCL_HORIZONTAL,
	MCL_BOTH
};

//! One-byte version of RPG::MapWrapping
typedef unsigned char MapWrapping_T;
}

#endif // DYNRPG_MAP_WRAPPING_H
