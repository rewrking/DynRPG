#ifndef DYNRPG_ACTION_RESTRICTION_H
#define DYNRPG_ACTION_RESTRICTION_H

namespace RPG
{
/*! \brief Possible values for RPG::Condition::actionRestriction

	The type of action restriction as defined in the condition tab of the database.
*/
enum ActionRestriction
{
	AR_NONE,
	AR_NO_ACTION_ALLOWED,
	AR_ATTACK_ENEMIES_RANDOMLY,
	AR_ATTACK_ALLIES_RANDOMLY
};

//! One-byte version or RPG::ActionRestriction
typedef unsigned char ActionRestriction_T;
}

#endif // DYNRPG_ACTION_RESTRICTION_H
