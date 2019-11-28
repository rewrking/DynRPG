#ifndef RPG_ANIMATION_TYPE_HPP
#define RPG_ANIMATION_TYPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::Character::animationType
enum class AnimationType : uchar
{
	Normal, //!< "Non-continuous"
	Stepping, //!< "Continuous" (always stepping)
	FixedDirNormal, //!< "Non-continous", fixed direction
	FixedDirStepping, //!< "Continuous", fixed direction
	FixedGraphic, //!< Fixed graphic (no stepping, fixed direction)
	SpinAround //!< Spinning around
};

//! One-byte version of RPG::AnimationType
//typedef uchar AnimationType_T;
}

#endif // RPG_ANIMATION_TYPE_HPP
