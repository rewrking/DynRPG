#ifndef DYNRPG_ANIMATION_SCOPE_H
#define DYNRPG_ANIMATION_SCOPE_H

namespace RPG
{
/*! \brief Possible values for RPG::Animation::scope

	Does the battle animation target a single opponent or all?
*/
enum AnimationScope
{
	ANIM_SCOPE_LOCAL,
	ANIM_SCOPE_GLOBAL
};

//! One-byte version of RPG::AnimationScope
typedef unsigned char AnimationScope_T;
}

#endif // DYNRPG_ANIMATION_SCOPE_H
