#ifndef RPG_ANIMATION_FRAME_HPP
#define RPG_ANIMATION_FRAME_HPP

#include <DynRPG/Animation/AnimationFrameCel.hpp>
#include <DynRPG/Catalog/CatalogPtr.hpp>

namespace RPG
{
/*! \brief Used to define an animation's frame and its cels.
	\sa RPG::AnimationFrameCel
	\sa RPG::Animation
	\sa RPG::battleAnimations

*/
struct AnimationFrame
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the frame
		int _unknown_08;
	CatalogPtr<AnimationFrameCel*> cels; //!< Pointer to the RPG::AnimationFrameCel array
	// clang-format on
};
}

#endif // RPG_ANIMATION_FRAME_HPP