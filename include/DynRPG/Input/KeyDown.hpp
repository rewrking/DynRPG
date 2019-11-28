#ifndef RPG_KEY_DOWN_HPP
#define RPG_KEY_DOWN_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Detectable keys to determine whether one is pressed, tapped, or held
	\sa RPG::input::isPressed
	\sa RPG::input::isHeld
	\sa RPG::input::isTapped
*/
enum class KeyDown : uchar
{
	None,
	Down,
	Left,
	Right = 4,
	Up = 8,
	Decision = 16,
	Cancel = 32,
	MouseLeftButton = 64,
	MouseRightButton = 128
};

//! One-byte version of RPG::KeyDown
//typedef uchar KeyDown_T;
}

#endif // RPG_KEY_DOWN_HPP
