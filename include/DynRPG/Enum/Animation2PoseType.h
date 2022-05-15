#ifndef DYNRPG_ANIMATION2_POSE_TYPE_H
#define DYNRPG_ANIMATION2_POSE_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::Animation2Pose::animType

	The type of the battler animation pose
*/
enum Animation2PoseType
{
	PT_CHARACTER_POSE,
	PT_BATTLE_ANIMATION
};

//! One-byte version of RPG::Animation2PoseType
typedef unsigned char Animation2PoseType_T;
}

#endif // DYNRPG_ANIMATION2_POSE_TYPE_H
