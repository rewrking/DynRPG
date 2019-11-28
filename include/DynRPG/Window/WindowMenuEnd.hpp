#ifndef RPG_WINDOW_MENU_END_HPP
#define RPG_WINDOW_MENU_END_HPP

#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Used for quit menu from the main menu.

	\sa RPG::SceneMenu
*/
struct WindowMenuEnd : Window
{
	Window* winQuitMsg; //!< The sub-window for the "Are you sure" message
};
}

#endif // RPG_WINDOW_MENU_END_HPP
