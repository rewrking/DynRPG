#ifndef RPG_WEAPON_RANGED_TRAJECTORY_HPP
#define RPG_WEAPON_RANGED_TRAJECTORY_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Item::weaponTrajectory

	If ranged weapon, this is the movement of the ammunition.
*/
enum class WeaponRangedTrajectory
{
	FlyToTarget, //!< Fly Straight to Target (crossbows, bullets, etc.)
	ReturnToHero //!< Return to User after Striking (steel ball & chain, etc.)
};
}

#endif // RPG_WEAPON_RANGED_TRAJECTORY_HPP
