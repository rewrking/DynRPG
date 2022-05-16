#ifndef DYNRPG_WEAPON_RANGED_TRAJECTORY_H
#define DYNRPG_WEAPON_RANGED_TRAJECTORY_H

namespace RPG
{
/*! \brief Possible values for RPG::Item::weaponTrajectory

	If ranged weapon, this is the movement of the ammunition.
*/
enum WeaponRangedTrajectory
{
	WEAPON_RANGED_TRAJ_FLY_TO_TARGET, //!< Fly Straight to Target (crossbows, bullets, etc.)
	WEAPON_RANGED_TRAJ_RETURN_TO_HERO //!< Return to User after Striking (steel ball & chain, etc.)
};
}

#endif // DYNRPG_WEAPON_RANGED_TRAJECTORY_H
