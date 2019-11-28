#ifndef RPG_ANIMATION_TARGET_MONSTER_HPP
#define RPG_ANIMATION_TARGET_MONSTER_HPP

namespace RPG
{
/*! \brief Possible values for RPG::AnimationInBattle::currentAnimTarget

	The current target of the battle animation
*/
enum class AnimationTargetMonster
{
	None = -2,
	AllEnemies = -1,
	Enemy1 = 0,
	Enemy2 = 1,
	Enemy3 = 2,
	Enemy4 = 3,
	Enemy5 = 4,
	Enemy6 = 5,
	Enemy7 = 6,
	Enemy8 = 7,
};
}

#endif // RPG_ANIMATION_TARGET_MONSTER_HPP
