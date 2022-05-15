#ifndef DYNRPG_ANIMATION_FRAME_H
#define DYNRPG_ANIMATION_FRAME_H

#include <DynRPG/AnimationFrameCel.h>
#include <DynRPG/CatalogPtr.h>

namespace RPG
{
/*! \brief Used to define an animation's frame and its cels.
	\sa RPG::AnimationFrameCel
	\sa RPG::Animation
	\sa RPG::battleAnimations
*/
class AnimationFrame
{
public:
	void** vTable;
	int id; //!< ID of the frame
	int _unknown_08;
	CatalogPtr<AnimationFrameCel*> cels; //!< Pointer to the RPG::AnimationFrameCel array
};
}

#endif // DYNRPG_ANIMATION_FRAME_H
