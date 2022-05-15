#ifndef DYNRPG_WEAPON_NUMBER_OF_ATTACKS_H
#define DYNRPG_WEAPON_NUMBER_OF_ATTACKS_H

namespace RPG
{
/*! \brief Possible values for RPG::Item::WeaponAnimation::numAttacks

	This is the number of times a weapon will attack.
	\note If the weapon has the attackTwice flag set, the number of attacks will double.
*/
enum WeaponNumberOfAttacks
{
	WEAPON_NUM_ATTACKS_ONCE,
	WEAPON_NUM_ATTACKS_TWICE,
	WEAPON_NUM_ATTACKS_THREE_TIMES
	// Note: Are more values possible? (3+)
};
}

#endif // DYNRPG_WEAPON_NUMBER_OF_ATTACKS_H
