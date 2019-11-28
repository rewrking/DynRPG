#ifndef RPG_ANIMATION_EFFECT_HPP
#define RPG_ANIMATION_EFFECT_HPP

#include <DynRPG/Animation/AnimationEffectScope.hpp>
#include <DynRPG/Audio/Sound.hpp>

namespace RPG
{
/*! \brief Used to define an animation's effect from its effect array.
	\sa RPG::AnimationEffectScope
	\sa RPG::Animation
	\sa RPG::battleAnimations

*/
struct AnimationEffect
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the animation effect
		int _unknown_08;
	int startFrame; //!< The frame the animation effect starts on
	Sound* soundEffect; //!< The sound effect
	AnimationEffectScope flashScope; //!< The flash scope of the animation effect (See RPG::AnimationEffectScope)
		bool _unknown_15;
		bool _unknown_16;
		bool _unknown_17;
	int red; //!< The red value
	int green; //!< The green value
	int blue; //!< The blue value
	int magnitude; //!< The strength of the color effect
	AnimationEffectScope shakeScope; //!< The shake scope of the animation effect (See RPG::AnimationEffectScope)
	// clang-format on
};
}

#endif // RPG_ANIMATION_EFFECT_HPP