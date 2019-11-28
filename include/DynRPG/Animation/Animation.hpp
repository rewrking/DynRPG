#ifndef RPG_ANIMATION_HPP
#define RPG_ANIMATION_HPP

#include <DynRPG/Animation/AnimationEffect.hpp>
#include <DynRPG/Animation/AnimationFrame.hpp>
#include <DynRPG/Animation/AnimationScope.hpp>
#include <DynRPG/Animation/AnimationYAxisLine.hpp>
#include <DynRPG/Catalog/CatalogPtr.hpp>
#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Used to define a battle animation, its frames, and effects.
	\sa RPG::battleAnimations
	\sa RPG::AnimationEffect
	\sa RPG::AnimationScope
	\sa RPG::AnimationYAxisLine
	\sa RPG::AnimationFrame
*/
struct Animation
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the animation
	DStringPtr name; //!< The name of the animation
	DStringPtr filename; //!< The filename of the animation's graphic
	bool isLargeAnimation; //!< Does the animation use a large animation file?
		bool _unknown_11;
		bool _unknown_12;
		bool _unknown_13;
	CatalogPtr<AnimationEffect*> effects; //!< Pointer to the RPG::AnimationEffect array
	AnimationScope scope; //!< The scope of the animation (See RPG::AnimationScope)
	AnimationYAxisLine yLine; //!< The location of the y-axis (See RPG::AnimationYAxisLine)
		bool _unknown_1A;
		bool _unknown_1B;
	CatalogPtr<AnimationFrame*> frames; //!< Pointer to the RPG::AnimationFrame array
	// clang-format on
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
static NamedCatalogPtr<Animation*>& battleAnimations = (**reinterpret_cast<NamedCatalogPtr<Animation*>**>(0x4CDDC4));
}

#endif // RPG_ANIMATION_HPP
