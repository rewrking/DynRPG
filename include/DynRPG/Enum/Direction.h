#ifndef DYNRPG_DIRECTION_H
#define DYNRPG_DIRECTION_H

namespace RPG
{
//! Possible values for RPG::Character::direction
enum Direction
{
	DIR_UP, //!< %Character moves down
	DIR_RIGHT, //!< %Character moves to the right
	DIR_DOWN, //!< %Character moves down
	DIR_LEFT, //!< %Character moves to the left
	DIR_UP_RIGHT, //!< %Character moves diagonally up-right
	DIR_DOWN_RIGHT, //!< %Character moves diagonally down-right
	DIR_DOWN_LEFT, //!< %Character moves diagonally down-left
	DIR_UP_LEFT //!< %Character moves diagonally up-left
};

//! One-byte version of RPG::Direction
typedef unsigned char Direction_T;
}

#endif // DYNRPG_DIRECTION_H
