#ifndef DYNRPG_LAYER_H
#define DYNRPG_LAYER_H

namespace RPG
{
//! Possible values for RPG::Character::layer
enum Layer
{
	LAYER_BELOW_HERO, //!< Below hero
	LAYER_SAME_LEVEL_AS_HERO, //!< Same level as hero
	LAYER_ABOVE_HERO //!< Above hero
};

//! One-byte version of RPG::Layer
typedef unsigned char Layer_T;
}

#endif // DYNRPG_LAYER_H
