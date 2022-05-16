#ifndef DYNRPG_WINDOW_MENU_TARGET_H
#define DYNRPG_WINDOW_MENU_TARGET_H

#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for skill/item target sub-menus (when a skill/item is used on a party member)

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowMenuTarget : public Window
{
public:
	Window* winItemName; //!< The sub-window for the item name in the upper-left
	Window* winNumUses; //!< The sub-window for the amount owned/mp cost below the item name window
};
}

#endif // DYNRPG_WINDOW_MENU_TARGET_H
