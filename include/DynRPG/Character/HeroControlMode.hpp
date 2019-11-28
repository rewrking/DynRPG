#ifndef RPG_HERO_CONTROL_MODE_HPP
#define RPG_HERO_CONTROL_MODE_HPP

namespace RPG
{
//! Hero control mode (see RPG::Hero::setControlMode)
enum class HeroControlMode
{
	ControlEverything, //!< Everything works normally
	ControlEverythingExceptMovement, //!< Opening menu and activating events works, but movement is disabled
	ControlNothing //!< No control possible (checking key state still works, of course)
};
}

#endif // RPG_HERO_CONTROL_MODE_HPP
