#ifndef RPG_WINDOW_MENU_ORDER_HPP
#define RPG_WINDOW_MENU_ORDER_HPP

#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Used for quit menu from the main menu.

	\sa RPG::SceneMenu
*/
struct WindowMenuOrder : Window
{
	Window* winNewConfig; //!< The sub-window for the new configuration
	Window* winConfirm; //!< The sub-window for the new config confirmation
};
}

#endif // RPG_WINDOW_MENU_ORDER_HPP
