#ifndef DYNRPG_ANIMATION_MOVE_BEFORE_ATTACK_H
#define DYNRPG_ANIMATION_MOVE_BEFORE_ATTACK_H

namespace RPG
{
/*! \brief Possible values for RPG::WeaponAnimation::movement and RPG::SkillAnimation::movement

	These values describe the hero's movement before attacking
*/
enum AnimationMoveBeforeAttack
{
	ANIM_MOVE_BEFORE_ACTION_NONE, //!< No movement animation before attacking
	ANIM_MOVE_BEFORE_ACTION_STEP_FORWARD, //!< Step forward a little bit before attacking
	ANIM_MOVE_BEFORE_ACTION_JUMP_FORWARD, //!< Jump forward before attacking
	ANIM_MOVE_BEFORE_ACTION_MOVE_TO_TARGET //!< Quickly move to target before attacking
};
}

#endif // DYNRPG_ANIMATION_MOVE_BEFORE_ATTACK_H
