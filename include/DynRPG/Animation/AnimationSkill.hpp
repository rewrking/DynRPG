#ifndef RPG_ANIMATION_SKILL_HPP
#define RPG_ANIMATION_SKILL_HPP

#include <DynRPG/Animation/AnimationBattlerPose.hpp>
#include <DynRPG/Animation/AnimationMoveBeforeAttack.hpp>

namespace RPG
{
/*! \brief Used to define a skill animation for a particular battler.
	\sa RPG::AnimationBattlerPose
	\sa RPG::AnimationMoveBeforeAttack
	\sa RPG::AnimationAfterImage
	\sa RPG::Skill
	\sa RPG::skills
*/
struct AnimationSkill
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the hero
		int _unknown_08;
		int _unknown_0C;
	AnimationBattlerPose battlerPose; //!< pose # of the hero. Default is 3? (See RPG::AnimationBattlerPose)
		int _unknown_14; // Weapon animation or Battle animation?
		int _unknown_18; // Battle animation ID?
		int _unknown_1C;
	AnimationMoveBeforeAttack movement; //!< Movement before attack (See RPG::AnimationMoveBeforeAttack)
	bool addAfterImage; //!< After Image None (0) / Add (1)
	/*
		int _unknown_28;
		int _unknown_2C;
		int _unknown_30;
		int _unknown_34;
	*/
	// clang-format on
};
}

#endif // RPG_ANIMATION_SKILL_HPP