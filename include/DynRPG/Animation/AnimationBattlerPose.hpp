#ifndef RPG_ANIMATION_BATTLER_POSE_HPP
#define RPG_ANIMATION_BATTLER_POSE_HPP

namespace RPG
{
/*! \brief Possible values for RPG::WeaponAnimation::battlerPose and RPG::SkillAnimation::battlerPose

	The animation pose ID of the battler.
	\note Each of these is numerical based starting from 0, but correspond to their value+1 in the database
	\note Use numerical values for poses 13-32. These are 0 based, so they will be defined as 12-31 here.
*/
enum class AnimationBattlerPose
{
	Stand, //!< Pose 1 in the database
	PunchRight, //!< Pose 2 in the database
	PunchLeft, //!< Pose 3 in the database
	Skill, //!< Pose 4 in the database
	Dead, //!< Pose 5 in the database
	Damage, //!< Pose 6 in the database
	Dazed, //!< Pose 7 in the database
	Block, //!< Pose 8 in the database
	Left, //!< Pose 9 in the database
	Right, //!< Pose 10 in the database
	Victory, //!< Pose 11 in the database
	Item		//!< Pose 12 in the database
};
}

#endif // RPG_ANIMATION_BATTLER_POSE_HPP
