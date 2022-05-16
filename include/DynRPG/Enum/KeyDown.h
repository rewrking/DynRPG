#ifndef DYNRPG_KEY_DOWN_H
#define DYNRPG_KEY_DOWN_H

namespace RPG
{
/*! \brief Detectable keys to determine whether one is pressed, tapped, or held
	\sa RPG::input::isPressed
	\sa RPG::input::isHeld
	\sa RPG::input::isTapped
*/
enum KeyDown
{
	KEYD_NONE,
	KEYD_DOWN,
	KEYD_LEFT,
	KEYD_RIGHT = 4,
	KEYD_UP = 8,
	KEYD_DECISION = 16,
	KEYD_CANCEL = 32,
	KEYD_MOUSE_LBUT = 64,
	KEYD_MOUSE_RBUT = 128
};

//! One-byte version of RPG::KeyDown
typedef unsigned char KeyDown_T;
}

#endif // DYNRPG_KEY_DOWN_H
