#ifndef DYNRPG_TARGET_H
#define DYNRPG_TARGET_H

namespace RPG
{
//! Possible values for the RPG::Action::target member
enum Target
{
	TARGET_NONE, //!< No target (the sounds of the battle animation will still be audible)
	TARGET_ACTOR, //!< Target is an actor, specified in the RPG::Action::targetId member
	TARGET_ALL_ACTORS, //!< Target are all actors at once
	TARGET_MONSTER, //!< Target is a monster, specified in the RPG::Action::targetId member
	TARGET_ALL_MONSTERS //!< Target are all mosnters at once
};

//! One-byte version of RPG::Target
typedef unsigned char Target_T;
}

#endif // DYNRPG_TARGET_H
