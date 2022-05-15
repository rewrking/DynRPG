#ifndef DYNRPG_WEAPON_RANGED_TARGETING_H
#define DYNRPG_WEAPON_RANGED_TARGETING_H

namespace RPG
{
/*! \brief Possible values for RPG::Item::weaponTargetting

	If ranged weapon, this is the type of targetting that the weapon uses.
*/
enum WeaponRangedTargeting
{
	WEAPON_RANGED_TARGET_SINGLE, //!< Single Target
	WEAPON_RANGED_TARGET_SCREEN_CENTER, //!< Fly Down Center of Screen
	WEAPON_RANGED_TARGET_ALL_SIMUL, //!< Strike Each Enemy Simultaneously
	WEAPON_RANGED_TARGET_ALL_INTURN //!< STrike Each Enemy in Turn
};
}

#endif // DYNRPG_WEAPON_RANGED_TARGETTING_H
