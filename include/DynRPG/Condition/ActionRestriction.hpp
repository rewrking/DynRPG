#ifndef RPG_ACTION_RESTRICTION_HPP
#define RPG_ACTION_RESTRICTION_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::Condition::actionRestriction

	The type of action restriction as defined in the condition tab of the database.
*/
enum class ActionRestriction : uchar
{
	None,
	NoActionAllowed,
	AttackEnemiesRandomly,
	AttackAlliesRandomly
};

//! One-byte version or RPG::ActionRestriction
//typedef uchar ActionRestriction_T;
}

#endif // RPG_ACTION_RESTRICTION_HPP
