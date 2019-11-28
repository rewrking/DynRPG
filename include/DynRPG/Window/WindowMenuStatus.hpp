#ifndef RPG_WINDOW_MENU_STATUS_HPP
#define RPG_WINDOW_MENU_STATUS_HPP

#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Used for quit menu from the main menu.

	\sa RPG::SceneMenu
*/
struct WindowMenuStatus : Window
{
	int heroId; //!< Database ID of the hero selected
	Window* winHpMpExp; //!< The sub-window for HP/MP/Exp (Upper-right)
	Window* winMain; //!< The sub-window for  the hero's name/class/title/condition/level
	Window* winEquipment; //!< The sub-window for the quipment
};
}

#endif // RPG_WINDOW_MENU_STATUS_HPP
