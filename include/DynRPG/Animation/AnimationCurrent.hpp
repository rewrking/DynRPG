#ifndef RPG_ANIMATION_CURRENT_HPP
#define RPG_ANIMATION_CURRENT_HPP

#include <DynRPG/Animation/Animation.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Graphics/Image.hpp>

namespace RPG
{
/*! \brief Used to access the data for the battle animation currently playing

	\sa RPG::AnimationInBattle
	\sa RPG::Animation
*/
class AnimationCurrent
{
	// clang-format off
	void** vTable;
	Animation* anim; //!< Animation structure of the current battle animation. 0 if BattleCharSets
	DStringPtr filename; //!< Filename of the animation that has been stored in memory
	Image* image; //!< The actual image data of the battle animation stored in memory. Only use with monsters
	Image* imageLarge; //!< The image data if it's a large battle animation, which has been stored in memory. Only use with monsters
		DStringPtr _unknown_14;
		DStringPtr _unknown_18;
		DStringPtr _unknown_1C;
	bool isMirrored; //!< Is the animation currently mirrored?
	// clang-format on
};

}

#endif // RPG_ANIMATION_CURRENT_HPP