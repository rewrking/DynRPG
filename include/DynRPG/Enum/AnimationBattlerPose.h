#ifndef DYNRPG_ANIMATION_BATTLER_POSE_H
#define DYNRPG_ANIMATION_BATTLER_POSE_H

namespace RPG
{
/*! \brief Possible values for RPG::WeaponAnimation::battlerPose and RPG::SkillAnimation::battlerPose

	The animation pose ID of the battler.
	\note Each of these is numerical based starting from 0, but correspond to their value+1 in the database
	\note Use numerical values for poses 13-32. These are 0 based, so they will be defined as 12-31 here.
*/
enum AnimationBattlerPose
{
	ANIM_POSE_STAND, //!< Pose 1 in the database
	ANIM_POSE_PUNCH_RIGHT, //!< Pose 2 in the database
	ANIM_POSE_PUNCH_LEFT, //!< Pose 3 in the database
	ANIM_POSE_SKILL, //!< Pose 4 in the database
	ANIM_POSE_DEAD, //!< Pose 5 in the database
	ANIM_POSE_DAMAGE, //!< Pose 6 in the database
	ANIM_POSE_DAZED, //!< Pose 7 in the database
	ANIM_POSE_BLOCK, //!< Pose 8 in the database
	ANIM_POSE_RUN_LEFT, //!< Pose 9 in the database
	ANIM_POSE_RUN_RIGHT, //!< Pose 10 in the database
	ANIM_POSE_VICTORY, //!< Pose 11 in the database
	ANIM_POSE_ITEM //!< Pose 12 in the database
};
}

#endif // DYNRPG_ANIMATION_BATTLER_POSE_H
