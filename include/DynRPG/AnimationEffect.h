#ifndef DYNRPG_ANIMATION_EFFECT_H
#define DYNRPG_ANIMATION_EFFECT_H

#include <DynRPG/Enum/AnimationEffectScope.h>

#include <DynRPG/Sound.h>

namespace RPG
{
/*! \brief Used to define an animation's effect from its effect array.
	\sa RPG::AnimationEffectScope
	\sa RPG::Animation
	\sa RPG::battleAnimations
*/
class AnimationEffect
{
public:
	void** vTable;
	int id; //!< ID of the animation effect
	int _unknown_08;
	int startFrame; //!< The frame the animation effect starts on
	Sound* soundEffect; //!< The sound effect
	AnimationEffectScope_T flashScope; //!< The flash scope of the animation effect (See RPG::AnimationEffectScope)
	bool _unknown_15;
	bool _unknown_16;
	bool _unknown_17;
	int red; //!< The red value
	int green; //!< The green value
	int blue; //!< The blue value
	int magnitude; //!< The strength of the color effect
	AnimationEffectScope_T shakeScope; //!< The shake scope of the animation effect (See RPG::AnimationEffectScope)
};
}

#endif // DYNRPG_ANIMATION_EFFECT_H
