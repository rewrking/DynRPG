#ifndef DYNRPG_KEY_DOWN_ALT_H
#define DYNRPG_KEY_DOWN_ALT_H

namespace RPG
{
/*! \brief Special keys to determine whether one is pressed, tapped, or held
	\sa RPG::input::isShiftCtrlPressed
	\sa RPG::input::isShiftCtrlHeld
	\sa RPG::input::isShiftCtrlTapped
*/
enum KeyDownAlt
{
	KEYH_NONE,
	KEYH_SHIFT,
	KEYH_CTRL
};

//! One-byte version of RPG::KeyDownAlt
typedef unsigned char KeyDownAlt_T;
}

#endif // DYNRPG_KEY_DOWN_ALT_H
