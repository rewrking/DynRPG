#ifndef RPG_LAYER_HPP
#define RPG_LAYER_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::Character::layer
enum class Layer : uchar
{
	BelowHero, //!< Below hero
	SameLevelAsHero, //!< Same level as hero
	AboveHero //!< Above hero
};

//! One-byte version of RPG::Layer
//typedef uchar Layer_T;
}

#endif // RPG_LAYER_HPP
