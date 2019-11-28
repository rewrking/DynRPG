#ifndef RPG_KEY_MODIFIER_DOWN_HPP
#define RPG_KEY_MODIFIER_DOWN_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Special keys to determine whether one is pressed, tapped, or held
	\sa RPG::input::isShiftCtrlPressed
	\sa RPG::input::isShiftCtrlHeld
	\sa RPG::input::isShiftCtrlTapped
*/
enum class KeyModifierDown : uchar
{
	None,
	Shift,
	Ctrl
};

//! One-byte version of RPG::KeyDownAlt
//typedef uchar KeyModifierDown_T;
}

#endif // RPG_KEY_MODIFIER_DOWN_HPP
