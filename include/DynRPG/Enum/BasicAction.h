#ifndef DYNRPG_BASIC_ACTION_H
#define DYNRPG_BASIC_ACTION_H

namespace RPG
{
//! Possible values for the RPG::Action::basicActionId member
enum BasicAction
{
	BA_ATTACK, //!< Attack
	BA_DOUBLE_ATTACK, //!< Double attack
	BA_DEFEND, //!< Defend
	BA_OBSERVE, //!< Observe battle
	BA_CHARGE, //!< Charge up
	BA_SELF_DESTRUCT, //!< Self-destruct
	BA_ESCAPE, //!< Escape (will always succeed)
	BA_NONE, //!< No action
	BA_CHANGE_ROW //!< Change row (has no visible effects if used by monsters)
};

//! One-byte version of RPG::BasicAction
typedef unsigned char BasicAction_T;
}

#endif // DYNRPG_BASIC_ACTION_H
