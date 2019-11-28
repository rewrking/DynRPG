#ifndef RPG_ANIMATION2_WEAPON_HPP
#define RPG_ANIMATION2_WEAPON_HPP

#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Used to define a battler's weapon animations.
	\sa RPG::battlerAnimations
	\sa RPG::Animation2
	\sa RPG::Animation2Pose
*/
struct Animation2Weapon
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the pose
	DStringPtr name; //!< The name of the weapon
	DStringPtr battleWeaponFilename; //!< The name of BattleWeapon file used for the poses
	int battleCharsetId; //!< The weapon's index in the BattleWeapon file (0-7)
		int _unknown_14;
		int _unknown_18;
	// clang-format on
};
}

#endif // RPG_ANIMATION2_WEAPON_HPP
