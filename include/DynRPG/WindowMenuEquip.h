#ifndef DYNRPG_WINDOW_MENU_EQUIP_H
#define DYNRPG_WINDOW_MENU_EQUIP_H

#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for equip menu from the main menu.

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowMenuEquip : public Window
{
public:
	int heroId; //!< Database ID of the hero selected
	Window* winInfo; //!< The sub-window for the equipment's description
	Window* winLeft; //!< The sub-window for the Selected hero's name and their stats
	Window* winRight; //!< The sub-window for the equipment slots and the currently equipped items
};
}

#endif // DYNRPG_WINDOW_MENU_EQUIP_H
