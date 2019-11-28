#ifndef RPG_ANIMATION2_POSE_HPP
#define RPG_ANIMATION2_POSE_HPP

#include <DynRPG/Animation2/Animation2PoseType.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Used to define a battler's character animation pose and pose parameters.
	\sa RPG::battlerAnimations
	\sa RPG::Animation2PoseType
	\sa RPG::Animation2
	\sa RPG::Animation2Weapon
*/
struct Animation2Pose
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the pose
	DStringPtr name; //!< The name of the pose
	DStringPtr battleCharsetFilename; //!< The name of BattleCharSet file used for the poses
	int battleCharsetId; //!< The pose's index in the BattleCharSet file (0-7)
		int _unknown_14;
		int _unknown_18;
	Animation2PoseType animType; //!< The pose's animation type
	int battleAnimId; //!< the battle animation ID if animTYpe is set to RPG::PT_BATTLE_ANIMATION (See RPG::Animation2PoseType)
	// clang-format on
};

}

#endif // RPG_ANIMATION2_POSE_HPP
