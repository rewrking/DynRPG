#ifndef DYNRPG_ANIMATION_TYPE_H
#define DYNRPG_ANIMATION_TYPE_H

namespace RPG
{
//! Possible values for RPG::Character::animationType
enum AnimationType
{
	ANI_NORMAL, //!< "Non-continuous"
	ANI_STEPPING, //!< "Continuous" (always stepping)
	ANI_FIXED_DIR_NORMAL, //!< "Non-continous", fixed direction
	ANI_FIXED_DIR_STEPPING, //!< "Continuous", fixed direction
	ANI_FIXED_GRAPHIC, //!< Fixed graphic (no stepping, fixed direction)
	ANI_SPIN_AROUND //!< Spinning around
};

//! One-byte version of RPG::AnimationType
typedef unsigned char AnimationType_T;
}

#endif // DYNRPG_ANIMATION_TYPE_H
