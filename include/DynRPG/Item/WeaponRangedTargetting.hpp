#ifndef RPG_WEAPON_RANGED_TARGETTING_HPP
#define RPG_WEAPON_RANGED_TARGETTING_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Item::weaponTargetting

	If ranged weapon, this is the type of targetting that the weapon uses.
*/
enum class WeaponRangedTargetting
{
	Single, //!< Single Target
	ScreenCenter, //!< Fly Down Center of Screen
	TargetAllSimultaneously, //!< Strike Each Enemy Simultaneously
	TargetAllInTurn //!< STrike Each Enemy in Turn
};
}

#endif // RPG_WEAPON_RANGED_TARGETTING_HPP
