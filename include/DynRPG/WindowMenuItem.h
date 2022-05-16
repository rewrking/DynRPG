#ifndef DYNRPG_WINDOW_MENU_ITEM_H
#define DYNRPG_WINDOW_MENU_ITEM_H

#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for item menu from the main menu.

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowMenuItem : public Window
{
public:
	int heroId; //!< Database ID of the hero selected
	Window* winInfo; //!< The sub-window for the item description
};
}

#endif // DYNRPG_WINDOW_MENU_ITEM_H
