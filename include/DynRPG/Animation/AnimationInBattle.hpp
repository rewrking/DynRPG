#ifndef RPG_ANIMATION_IN_BATTLE_HPP
#define RPG_ANIMATION_IN_BATTLE_HPP

#include <DynRPG/Animation/AnimationCurrent.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Used to access battle animation data while an animation is on screen

	\sa RPG::AnimationTargetMonster
	\sa RPG::Animation
*/

struct AnimationInBattle
{
	// clang-format off
	void** vTable;
		int _unknown_04;
		StubPtr _unknown_08; // battlers that are already pointed to in RPG::monsters and RPG::actors
	int monsterGroupId; //!< The ID of the monster group
								   //int _unknown_0C;
	bool isAnimationPlaying; //!< Is a battle animation playing?
	AnimationCurrent* currentAnim; //!< The battle animation's data
	int currentAnimationId; //!< The ID of the battle animation currently playing
	int currentAnimTarget; //!< The target of the battle animation currently playing (See RPG::AnimationTargetMonster)
	int currentAnimationFrame; //!< Current animation frame playing
	// clang-format on
};
}

#endif // RPG_ANIMATION_IN_BATTLE_HPP