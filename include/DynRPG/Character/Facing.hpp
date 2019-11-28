#ifndef RPG_FACING_HPP
#define RPG_FACING_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::EventPage::charsetDir and RPG::Character::facing
enum class Facing : uchar
{
	Up, //!< %Character looks up
	Right, //!< %Character looks to the right
	Down, //!< %Character looks down
	Left //!< %Character looks to the left
};

//! One-byte version of RPG::Facing
//typedef uchar Facing_T;
}

#endif // RPG_FACING_HPP
