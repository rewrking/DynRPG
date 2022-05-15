#ifndef DYNRPG_ANIMATION_TARGET_MONSTER_H
#define DYNRPG_ANIMATION_TARGET_MONSTER_H

namespace RPG
{
/*! \brief Possible values for RPG::AnimationInBattle::currentAnimTarget

	The current target of the battle animation
*/
enum AnimationTargetMonster
{
	ATM_NONE = -2,
	ATM_ALL_ENEMIES = -1,
	ATM_ENEMY_1 = 0,
	ATM_ENEMY_2 = 1,
	ATM_ENEMY_3 = 2,
	ATM_ENEMY_4 = 3,
	ATM_ENEMY_5 = 4,
	ATM_ENEMY_6 = 5,
	ATM_ENEMY_7 = 6,
	ATM_ENEMY_8 = 7,
};
}

#endif // DYNRPG_ANIMATION_TARGET_MONSTER_H
