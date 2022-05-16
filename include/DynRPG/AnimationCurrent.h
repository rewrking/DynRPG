#ifndef DYNRPG_ANIMATION_CURRENT_H
#define DYNRPG_ANIMATION_CURRENT_H

#include <DynRPG/Animation.h>
#include <DynRPG/DString.h>
#include <DynRPG/Image.h>

namespace RPG
{
/*! \brief Used to access the data for the battle animation currently playing

	\sa RPG::AnimationInBattle
	\sa RPG::Animation
*/

class AnimationCurrent
{
public:
	void** vTable;
	Animation* anim; //!< Animation structure of the current battle animation. 0 if BattleCharSets
	DStringPtr filename; //!< Filename of the animation that has been stored in memory
	Image* image; //!< The actual image data of the battle animation stored in memory. Only use with monsters
	Image* imageLarge; //!< The image data if it's a large battle animation, which has been stored in memory. Only use with monsters
	DStringPtr _unknown_14;
	DStringPtr _unknown_18;
	DStringPtr _unknown_1C;
	bool isMirrored; //!< Is the animation currently mirrored?
};
}

#endif // DYNRPG_ANIMATION_CURRENT_H
