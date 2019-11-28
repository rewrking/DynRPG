#ifndef RPG_WINDOW_MENU_TARGET_HPP
#define RPG_WINDOW_MENU_TARGET_HPP

#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Used for skill/item target sub-menus (when a skill/item is used on a party member)

	\sa RPG::SceneMenu
*/
struct WindowMenuTarget : Window
{
	Window* winItemName; //!< The sub-window for the item name in the upper-left
	Window* winNumUses; //!< The sub-window for the amount owned/mp cost below the item name window
};
}

#endif // RPG_WINDOW_MENU_TARGET_HPP
