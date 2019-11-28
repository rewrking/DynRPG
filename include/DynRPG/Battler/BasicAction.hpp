#ifndef RPG_BASIC_ACTION_HPP
#define RPG_BASIC_ACTION_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::Action::basicActionId member
enum class BasicAction : uchar
{
	Attack, //!< Attack
	DoubleAttack, //!< Double attack
	Defend, //!< Defend
	Observe, //!< Observe battle
	Charge, //!< Charge up
	SelfDestruct, //!< Self-destruct
	Escape, //!< Escape (will always succeed)
	None, //!< No action
	ChangeRow //!< Change row (has no visible effects if used by monsters)
};

//! One-byte version of RPG::BasicAction
//typedef uchar BasicAction_T;
}

#endif // RPG_BASIC_ACTION_HPP
