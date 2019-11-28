#ifndef RPG_ANIMATION_EFFECT_SCOPE_HPP
#define RPG_ANIMATION_EFFECT_SCOPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::AnimationEffect::flashScope and RPG::AnimationEffect::shakeScope
enum class AnimationEffectScope : uchar
{
	None,
	Target,
	Screen
};

//! One-byte version of RPG::AnimationScope
//typedef uchar AnimationEffectScope_T;
}

#endif // RPG_ANIMATION_EFFECT_SCOPE_HPP
