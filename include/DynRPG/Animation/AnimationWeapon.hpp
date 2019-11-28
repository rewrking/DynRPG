#ifndef RPG_ANIMATION_WEAPON_HPP
#define RPG_ANIMATION_WEAPON_HPP

#include <DynRPG/Animation/AnimationBattlerPose.hpp>
#include <DynRPG/Animation/AnimationMoveBeforeAttack.hpp>
#include <DynRPG/Animation/WeaponNumberOfAttacks.hpp>
#include <DynRPG/Animation/WeaponRangedAnimSpeed.hpp>

namespace RPG
{
/*! \brief Used to define a weapon animation for a particular battler.
	\sa RPG::AnimationBattlerPose
	\sa RPG::AnimationMoveBeforeAttack
	\sa RPG::AnimationAfterImage
	\sa RPG::WeaponNumberOfAttacks
	\sa RPG::WeaponRangedAnimSpeed
	\sa RPG::Item
	\sa RPG::items
*/
struct AnimationWeapon
{
	//!< Weapon Animation sub-screen
	// clang-format off
	void** vTable;
	int id; //!< ID of the hero to have the weapon animation
		int _unknown_08;
		int _unknown_0C;
	AnimationBattlerPose battlerPose; //!< pose # of the hero. Default is 3. (See RPG::AnimationBattlerPose)
	bool isBattleAnim; //!< Weapon animation or Battle animation?
	int battleAnimId; //!< Battle animation ID
		int _unknown_1C;
	AnimationMoveBeforeAttack movement; //!< Movement before attack (See RPG::AnimationMoveBeforeAttack)
	bool addAfterImage; //!< "Add" the after image?
	WeaponNumberOfAttacks numAttacks; //!< Number of attacks (See RPG::WeaponNumberOfAttacks)
	bool isRangedWeapon; //!< Is ranged weapon?
	int rangedAnimId; //!< ID of ranged animation
	WeaponRangedAnimSpeed rangedAnimSpeed; //!< Ranged animation speed? (See RPG::WeaponRangedAnimSpeed)
	// clang-format on
};
}

#endif // RPG_ANIMATION_WEAPON_HPP