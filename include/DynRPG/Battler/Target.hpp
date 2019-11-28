#ifndef RPG_TARGET_HPP
#define RPG_TARGET_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::Action::target member
enum class Target : uchar
{
	None, //!< No target (the sounds of the battle animation will still be audible)
	Actor, //!< Target is an actor, specified in the RPG::Action::targetId member
	AllActors, //!< Target are all actors at once
	Monster, //!< Target is a monster, specified in the RPG::Action::targetId member
	AllMonsters //!< Target are all mosnters at once
};

//! One-byte version of RPG::Target
//typedef uchar Target_T;

}

#endif // RPG_TARGET_HPP
