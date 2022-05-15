#ifndef DYNRPG_WINDOW_MENU_STATUS_H
#define DYNRPG_WINDOW_MENU_STATUS_H

#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for quit menu from the main menu.

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowMenuStatus : public Window
{
public:
	int heroId; //!< Database ID of the hero selected
	Window* winHpMpExp; //!< The sub-window for HP/MP/Exp (Upper-right)
	Window* winMain; //!< The sub-window for  the hero's name/class/title/condition/level
	Window* winEquipment; //!< The sub-window for the quipment
};
}

#endif // DYNRPG_WINDOW_MENU_STATUS_H
