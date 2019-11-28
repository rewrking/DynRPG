#ifndef RPG_ANIMATION2_POSE_TYPE_HPP
#define RPG_ANIMATION2_POSE_TYPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::Animation2Pose::animType

	The type of the battler animation pose
*/
enum class Animation2PoseType : uchar
{
	CharacterPose,
	BattleAnimation
};

//! One-byte version of RPG::Animation2PoseType
//typedef uchar AnimationPoseType_T;
}

#endif // RPG_ANIMATION2_POSE_TYPE_HPP
