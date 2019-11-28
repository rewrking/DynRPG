#ifndef RPG_ANIMATION_SCOPE_HPP
#define RPG_ANIMATION_SCOPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::Animation::scope

	Does the battle animation target a single opponent or all?
*/
enum class AnimationScope : uchar
{
	Local,
	Global
};

//! One-byte version of RPG::AnimationScope
//typedef uchar AnimationScope_T;
}

#endif // RPG_ANIMATION_SCOPE_HPP
