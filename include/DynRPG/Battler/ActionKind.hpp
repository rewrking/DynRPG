#ifndef RPG_ACTION_KIND_HPP
#define RPG_ACTION_KIND_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::Action::kind member
enum class ActionKind : uchar
{
	Basic, //!< Basic action (attack, defense, escape, etc. - see RPG::BasicAction)
	Skill, //!< Use a skill
	Transform, //!< Transform into another monster (do not use for actors)
	Item, //!< Use an item (do not use for monsters)
	None, //!< No action (last action was already executed)
	Random
};

//! One-byte version of RPG::ActionKind
//typedef uchar ActionKind_T;
}

#endif // RPG_ACTION_KIND_HPP
