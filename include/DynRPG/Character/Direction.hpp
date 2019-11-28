#ifndef RPG_DIRECTION_HPP
#define RPG_DIRECTION_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::Character::direction
enum class Direction : uchar
{
	Up, //!< %Character moves down
	Right, //!< %Character moves to the right
	Down, //!< %Character moves down
	Left, //!< %Character moves to the left
	UpRight, //!< %Character moves diagonally up-right
	DownRight, //!< %Character moves diagonally down-right
	DownLeft, //!< %Character moves diagonally down-left
	UpLeft //!< %Character moves diagonally up-left
};

//! One-byte version of RPG::Direction
//typedef uchar Direction_T;
}

#endif // RPG_DIRECTION_HPP
