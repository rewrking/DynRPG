#ifndef RPG_WINDOW_MENU_EQUIP_HPP
#define RPG_WINDOW_MENU_EQUIP_HPP

#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Used for equip menu from the main menu.

	\sa RPG::SceneMenu
*/
struct WindowMenuEquip : Window
{
	int heroId; //!< Database ID of the hero selected
	Window* winInfo; //!< The sub-window for the equipment's description
	Window* winLeft; //!< The sub-window for the Selected hero's name and their stats
	Window* winRight; //!< The sub-window for the equipment slots and the currently equipped items
};
}

#endif // RPG_WINDOW_MENU_EQUIP_HPP
