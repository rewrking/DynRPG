#ifndef RPG_WINDOW_MENU_ITEM_HPP
#define RPG_WINDOW_MENU_ITEM_HPP

#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Used for item menu from the main menu.

	\sa RPG::SceneMenu
*/
struct WindowMenuItem : Window
{
	int heroId; //!< Database ID of the hero selected
	Window* winInfo; //!< The sub-window for the item description
};
}

#endif // RPG_WINDOW_MENU_ITEM_HPP
