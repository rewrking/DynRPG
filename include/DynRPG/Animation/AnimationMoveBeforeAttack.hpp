#ifndef RPG_ANIMATION_MOVE_BEFORE_ATTACK_HPP
#define RPG_ANIMATION_MOVE_BEFORE_ATTACK_HPP

namespace RPG
{
/*! \brief Possible values for RPG::WeaponAnimation::movement and RPG::SkillAnimation::movement

	These values describe the hero's movement before attacking
*/
enum class AnimationMoveBeforeAttack
{
	None, //!< No movement animation before attacking
	StepForward, //!< Step forward a little bit before attacking
	JumpForward, //!< Jump forward before attacking
	MoveToTarget //!< Quickly move to target before attacking
};
}

#endif // RPG_ANIMATION_MOVE_BEFORE_ATTACK_HPP
