#ifndef DYNRPG_ANIMATION_EFFECT_SCOPE_H
#define DYNRPG_ANIMATION_EFFECT_SCOPE_H

namespace RPG
{
//! Possible values for RPG::AnimationEffect::flashScope and RPG::AnimationEffect::shakeScope
enum AnimationEffectScope
{
	ANIM_EFFECT_SCOPE_NONE,
	ANIM_EFFECT_SCOPE_TARGET,
	ANIM_EFFECT_SCOPE_SCREEN
};

//! One-byte version of RPG::AnimationScope
typedef unsigned char AnimationEffectScope_T;
}

#endif // DYNRPG_ANIMATION_EFFECT_SCOPE_H
