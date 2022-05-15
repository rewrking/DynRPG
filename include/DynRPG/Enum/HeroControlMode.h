#ifndef DYNRPG_HERO_CONTROL_MODE_H
#define DYNRPG_HERO_CONTROL_MODE_H

namespace RPG
{
//! Hero control mode (see RPG::Hero::setControlMode)
enum HeroControlMode
{
	CONTROL_EVERYTHING, //!< Everything works normally
	CONTROL_EVERYTHING_EXCEPT_MOVEMENT, //!< Opening menu and activating events works, but movement is disabled
	CONTROL_NOTHING //!< No control possible (checking key state still works, of course)
};
}

#endif // DYNRPG_HERO_CONTROL_MODE_H
