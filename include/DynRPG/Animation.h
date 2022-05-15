#ifndef DYNRPG_ANIMATION_H
#define DYNRPG_ANIMATION_H

#include <DynRPG/Enum/AnimationScope.h>
#include <DynRPG/Enum/AnimationYAxisLine.h>

#include <DynRPG/AnimationEffect.h>
#include <DynRPG/AnimationFrame.h>
#include <DynRPG/CatalogPtr.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/NamedCatalogPtr.h>

namespace RPG
{
/*! \brief Used to define a battle animation, its frames, and effects.
	\sa RPG::battleAnimations
	\sa RPG::AnimationEffect
	\sa RPG::AnimationScope
	\sa RPG::AnimationYAxisLine
	\sa RPG::AnimationFrame
*/

class Animation
{
public:
	void** vTable;
	int id; //!< ID of the animation
	DStringPtr name; //!< The name of the animation
	DStringPtr filename; //!< The filename of the animation's graphic
	bool isLargeAnimation; //!< Does the animation use a large animation file?
	bool _unknown_11;
	bool _unknown_12;
	bool _unknown_13;
	CatalogPtr<AnimationEffect*> effects; //!< Pointer to the RPG::AnimationEffect array
	AnimationScope_T scope; //!< The scope of the animation (See RPG::AnimationScope)
	AnimationYAxisLine_T yLine; //!< The location of the y-axis (See RPG::AnimationYAxisLine)
	bool _unknown_1A;
	bool _unknown_1B;
	CatalogPtr<AnimationFrame*> frames; //!< Pointer to the RPG::AnimationFrame array
};

/*! \ingroup game_objects
	\brief Array of battle animations from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing an animation.

	Example:
	\code
std::string animationName = RPG::battleAnimations[4]->filename.s_str());
	\endcode
*/
extern DYNRPG_API RPG::NamedCatalogPtr<RPG::Animation*>& battleAnimations;
}

#endif // DYNRPG_ANIMATION_H
