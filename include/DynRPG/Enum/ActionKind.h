#ifndef DYNRPG_ACTION_KIND_H
#define DYNRPG_ACTION_KIND_H

namespace RPG
{
//! Possible values for the RPG::Action::kind member
enum ActionKind
{
	AK_BASIC, //!< Basic action (attack, defense, escape, etc. - see RPG::BasicAction)
	AK_SKILL, //!< Use a skill
	AK_TRANSFORM, //!< Transform into another monster (do not use for actors)
	AK_ITEM, //!< Use an item (do not use for monsters)
	AK_NONE, //!< No action (last action was already executed)
	// Added for 0.30
	AK_RANDOM
};

//! One-byte version of RPG::ActionKind
typedef unsigned char ActionKind_T;
}

#endif // DYNRPG_ACTION_KIND_H
