#ifndef DYNRPG_ANIMATION2_WEAPON_H
#define DYNRPG_ANIMATION2_WEAPON_H

#include <DynRPG/DStringPtr.h>

namespace RPG
{
/*! \brief Used to define a battler's weapon animations.
	\sa RPG::battlerAnimations
	\sa RPG::Animation2
	\sa RPG::Animation2Pose
*/
class Animation2Weapon
{
public:
	void** vTable;
	int id; //!< ID of the pose
	DStringPtr name; //!< The name of the weapon
	DStringPtr battleWeaponFilename; //!< The name of BattleWeapon file used for the poses
	int battleCharsetId; //!< The weapon's index in the BattleWeapon file (0-7)
	int _unknown_14;
	int _unknown_18;
};
}

#endif // DYNRPG_ANIMATION2_WEAPON_H
