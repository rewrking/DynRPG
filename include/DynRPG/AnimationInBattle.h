#ifndef DYNRPG_ANIMATION_IN_BATTLE_H
#define DYNRPG_ANIMATION_IN_BATTLE_H

#include <DynRPG/Enum/AnimationTargetMonster.h>

#include <DynRPG/AnimationCurrent.h>

namespace RPG
{
/*! \brief Used to access battle animation data while an animation is on screen

	\sa RPG::AnimationTargetMonster
	\sa RPG::Animation
*/

class AnimationInBattle
{
public:
	void** vTable;
	int _unknown_04;
	void* _unknown_08; // battlers that are already pointed to in RPG::monsters and RPG::actors
	int monsterGroupId; //!< The ID of the monster group
		//int _unknown_0C;
	bool isAnimationPlaying; //!< Is a battle animation playing?
	AnimationCurrent* currentAnim; //!< The battle animation's data
	int currentAnimationId; //!< The ID of the battle animation currently playing
	int currentAnimTarget; //!< The target of the battle animation currently playing (See RPG::AnimationTargetMonster)
	int currentAnimationFrame; //!< Current animation frame playing
};
}

#endif // DYNRPG_ANIMATION_IN_BATTLE_H
